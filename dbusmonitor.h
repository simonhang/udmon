#ifndef DBUSMONITOR_H
#define DBUSMONITOR_H

// ********************************* NOTICE ***************************************
//         THIS CLASS IS THE ONLY PLACE WHERE A NEW DEVICE WILL BE BORN
// ********************************* NOTICE ***************************************

#include <QObject>
#include <QtDBus/QtDBus>
#include <QDBusObjectPath>
#include <QDBusMessage>

#include "dbusdevice.h"

class DbusMonitor : public QObject
{
    Q_OBJECT
public:
    explicit DbusMonitor(QObject *parent = 0);

signals:
    void deviceAdded(DbusDevice *device);
    
private slots:
    void onDeviceAdded(const QDBusObjectPath& o);
    
};

#endif // DBUSMONITOR_H
