#include "dbusaction.h"

DbusAction::DbusAction()
{
}

// result defaults to an empty string which indicates a non-successfull mount
// At this time the livetime of the device object pointer ends!
void DbusAction::mountFileSystem(DbusDevice *device) {

    QDBusInterface dbus(
            "org.freedesktop.UDisks",
            device->theObjectPath(),
            "org.freedesktop.UDisks.Device",
            QDBusConnection::systemBus(),
            0
    );

    if(dbus.isValid()) {

        // again an empty argument list
        QList<QVariant> args;
        args << QVariant(QString()) << QVariant(QStringList());

        QDBusMessage msg = dbus.callWithArgumentList(QDBus::AutoDetect, "FilesystemMount", args);
        if(msg.type() == QDBusMessage::ReplyMessage) {
            QString path = msg.arguments().at(0).toString();
            if(!path.isEmpty()) {
                device->MountedPath = path;
            } else {
                device->LastError = "DBUS call succeeded but mounted path is empty!";
            }
        } else if (msg.type() == QDBusMessage::ErrorMessage) {
            device->LastError = msg.errorMessage();
        }
    }
}

bool DbusAction::umountFileSystem(const QString& objectPath) {

    // the next 3 lines where directly stolen from kdelibs because nothing else really worked for me
    QDBusMessage c = QDBusMessage::createMethodCall("org.freedesktop.UDisks", objectPath, "org.freedesktop.UDisks.Device", "FilesystemUnmount");
    c << QStringList();   // options, unused now
    QDBusMessage msg = QDBusConnection::systemBus().call(c);

    switch(msg.type()) {
    case QDBusMessage::ReplyMessage:
        return true;
    default:
        qDebug() << msg.errorMessage();
        return false;
    }
}
