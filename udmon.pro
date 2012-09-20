#-------------------------------------------------
#
# Project created by QtCreator 2012-09-18T18:07:17
#
#-------------------------------------------------

QT       += core gui dbus xml

TARGET = udmon
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app

target.path = /usr/bin/udmon
INSTALLS += target

SOURCES += main.cpp \
    utray.cpp \
    dbusaction.cpp \
    dbusmonitor.cpp \
    dbusdevice.cpp \
    settings.cpp

HEADERS += \
    utray.h \
    dbusaction.h \
    dbusmonitor.h \
    dbusdevice.h \
    dbusconstants.h \
    settings.h

FORMS += \
    utray.ui \
    settings.ui

RESOURCES += \
    images.qrc
