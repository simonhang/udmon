#include "utray.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    if (!QSystemTrayIcon::isSystemTrayAvailable()) {
        QMessageBox::critical(0, QObject::tr("UDMon - UDisks monitor"),
                                 QObject::tr("I couldn't detect any system tray on this system."));
        return 1;
    }

    // dont quit on configure window closing
    QApplication::setQuitOnLastWindowClosed(false);

    Utray tray;
    tray.setVisible(false);
    
    return a.exec();
}
