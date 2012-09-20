#ifndef DBUSACTION_H
#define DBUSACTION_H

#include <QObject>
#include <QDBusInterface>
#include <QDBusPendingCall>
#include <QDebug>

#include "dbusdevice.h"

class DbusAction
{
public:
    explicit DbusAction();

    static void mountFileSystem(DbusDevice *device);
    static bool umountFileSystem(const QString &objectPath);
};

#endif // DBUSACTION_H
