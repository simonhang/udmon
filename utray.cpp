#include "utray.h"
#include "ui_utray.h"

Utray::Utray(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Utray)
{
    ui->setupUi(this);

    quitAction = new QAction(tr("&Quit"), this);
    connect(quitAction, SIGNAL(triggered()), qApp, SLOT(quit()));

    configAction = new QAction(tr("&Configure"), this);
    connect(configAction, SIGNAL(triggered()), this, SLOT(onConfigurationDialogReqested()));

    QFont font;
    font.setBold(true);
    titleAction = new QAction(tr("UDMon - UDisks monitor"), this);
    titleAction->setDisabled(true);
    titleAction->setIcon(QIcon(":/icons/drive.png"));
    titleAction->setFont(font);

    dbusmonitor = new DbusMonitor(this);
    connect(dbusmonitor, SIGNAL(deviceAdded(DbusDevice*)), this, SLOT(onDeviceAdded(DbusDevice*)));

    // initialize the mountMap to store the relation between the objectPath of an object
    // and its mounted path
    mountMap = new QMap<QString, QString>();

    createTrayIcon();
}

Utray::~Utray()
{
    delete mountMap;
    delete dbusmonitor;
    delete trayIconMenu;
    delete trayIcon;
    delete ui;
}

void Utray::createTrayIcon()
{
    trayIconMenu = new QMenu(this);
    trayIconMenu->addAction(titleAction);
    trayIconMenu->addSeparator();
    trayIconMenu->addAction(configAction);
    trayIconMenu->addAction(quitAction);
    trayIconMenu->addSeparator();

    trayIcon = new QSystemTrayIcon(this);
    trayIcon->setContextMenu(trayIconMenu);
    trayIcon->setIcon(QIcon(":/icons/drive.png")); // thats a KDE icon
    trayIcon->show();
}

void Utray::onConfigurationDialogReqested() {
    Settings s;
    s.exec();
}

void Utray::onDeviceAdded(DbusDevice *d) {
    DbusAction::mountFileSystem(d);
    if(!d->theMountedPath().isEmpty()) {
        trayIcon->showMessage(tr("Device mounted"), d->theMountedPath(), QSystemTrayIcon::Information, 3000);
        startApplication(d);
    } else {
        trayIcon->showMessage(tr("Device NOT mounted"), d->LastError, QSystemTrayIcon::Warning, 3000);
    }

    // save the relation between object path and mounted path because on
    // unmounting we have no more Device* object and I will not show an
    // ugly objectPath to the user when the device was properly unmounted
    // or not unmounted...
    mountMap->insert(d->theObjectPath(), d->theMountedPath());
}

void Utray::startApplication(DbusDevice *d) {
    bool found = false;

    QList<QAction*> actions = trayIconMenu->actions();
    foreach(QAction *a, actions) {
        if(a->objectName() == d->IdUuid) {
            found = true;
            break;
        }
    }

    if(!found) {
        QAction *action = new QAction(QString("Unmount %1").arg(d->theMountedPath()), this);
        action->setObjectName(d->theObjectPath());
        connect(action, SIGNAL(triggered()), this, SLOT(onUmountRequested()));
        trayIconMenu->addAction(action);
    }

    QSettings cfg("udmon", "udmon");

    QProcess p;
    QStringList args;
    args << d->theMountedPath();
    p.startDetached(cfg.value("execute").toString(), args);

    // here it ends: throw it away
    delete d;
}

void Utray::onUmountRequested() {
    QList<QAction*> actions = trayIconMenu->actions();
    foreach(QAction *a, actions) {
        if(a->objectName() == this->sender()->objectName()) {

            // get the mounted path for the objectPath from the mountMap
            QString mountedPath = mountMap->value(a->objectName());

            if(DbusAction::umountFileSystem(a->objectName())) {
                trayIconMenu->removeAction(a);
                trayIcon->showMessage(tr("Device removed"), mountedPath, QSystemTrayIcon::Information, 3000);

                // remove the item from the list
                mountMap->remove(a->objectName());
            } else {
                trayIcon->showMessage(tr("Device NOT removed"), mountedPath, QSystemTrayIcon::Warning, 3000);
            }
        }
    }
}
