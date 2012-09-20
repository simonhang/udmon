#ifndef UTRAY_H
#define UTRAY_H

#include <QtGui>
#include <QDialog>
#include <QMenu>
#include <QSystemTrayIcon>
#include <QProcess>
#include <QMap>
#include <QSettings>

#include "dbusmonitor.h"
#include "dbusaction.h"
#include "settings.h"

namespace Ui {
class Utray;
}

class Utray : public QDialog
{
    Q_OBJECT
    
public:
    explicit Utray(QWidget *parent = 0);
    ~Utray();
    
private:
    Ui::Utray *ui;
    QSystemTrayIcon *trayIcon;
    QMenu *trayIconMenu;
    QAction *quitAction;
    QAction *titleAction;
    QAction *configAction;
    DbusMonitor *dbusmonitor;
    QMap<QString, QString> *mountMap;

    void createTrayIcon();
    void startApplication(DbusDevice *d);

private slots:
    void onDeviceAdded(DbusDevice *d);
    void onUmountRequested();
    void onConfigurationDialogReqested();
};

#endif // UTRAY_H
