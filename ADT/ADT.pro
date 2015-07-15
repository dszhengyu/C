TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.c \
    error.c \
    _LIST_.c

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    error.h \
    _LIST_H.h

