#-------------------------------------------------
#
# Project created by QtCreator 2012-11-15T21:35:22
#
#-------------------------------------------------

QT       += gui
QT       += sql
QT       += core
QT       += webkit
QT       += network

TARGET    = REMOTE_SERVER

TEMPLATE  = app

SOURCES  += main.cpp

HEADERS  += controlmodule.h \
            databasemodule.h \
            diagnosemodule.h \
            communicationmodule.h \
            structure/position.h \
            structure/node.h \
            structure/edge.h \
            structure/sensor.h \
            structure/problematicsensor.h \
            structure/command.h \
            structure/receiver.h \
            structure/sensorfactory.h \
            structure/sensorcollection.h \
            structure/observer.h

FORMS    += controlmodule.ui
