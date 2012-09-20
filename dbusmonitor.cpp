#include "dbusmonitor.h"
#include "dbusconstants.h"

DbusMonitor::DbusMonitor(QObject *parent) :
    QObject(parent)
{
    if(QDBusConnection::systemBus().connect(
                DBUS_IFACE,
                DBUS_PATH,
                DBUS_IFACE,
                "DeviceAdded",
                "o",
                this,
                SLOT(onDeviceAdded(QDBusObjectPath))))
    {
        qDebug() << "got connection to system bus";
    }
}

/*
 * Gets called when a device is added.
 * The only relevant property in QDBusObjectPath is path()
 **/
void DbusMonitor::onDeviceAdded(const QDBusObjectPath &o) {
    // get all properties known by the system about the device connected
    QDBusMessage call = QDBusMessage::createMethodCall(DBUS_IFACE, o.path(), DBUS_INTERFACE_PROPS, "GetAll");

    // define a somewhat *empty* argument list
    QList<QVariant> args;
    args.append(DBUS_DEVICE_INTERFACE);
    call.setArguments(args);

    // now make the call (this is -again- a call to the systembus - dont know a better way yet!)
    QDBusPendingReply<QVariantMap> reply = QDBusConnection::systemBus().asyncCall(call);
    reply.waitForFinished();

    QVariantMap map = reply.value();
    if(map.value("IdUsage", "").toString() == "filesystem") {
        DbusDevice *d = new DbusDevice();
        d->ObjectPath = o.path();
        d->IdLabel    = map.value("IdLabel","").toString();
        d->IdType     = map.value("IdType", "").toString();
        d->IdUuid     = map.value("IdUuid", "has-no-uuid!").toString();
        d->DeviceFile = map.value("DeviceFile", "").toString();

        emit(deviceAdded(d));
    }
}
