#include "dbusdevice.h"

DbusDevice::DbusDevice()
{
}

// ********************************* NOTICE ***************************************
// the following 3 are only there because some DBUS methods require const arguments
// ********************************* NOTICE ***************************************

QString DbusDevice::theObjectPath() const {
    return ObjectPath;
}

QString DbusDevice::theLabel() const {
    if(this->IdLabel.isEmpty())
        return this->IdUuid;

    return this->IdLabel;
}

QString DbusDevice::theMountedPath() const {
    return this->MountedPath;
}
