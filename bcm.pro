#-------------------------------------------------
#
# Project created by QtCreator 2017-05-05T11:48:21
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = bcm
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp\
        mainwindow.cpp \
    pin.cpp \
    gpio.cpp \
    bcm_lib.c \
    server.cpp \
    thread_base.cpp \
    thread.cpp \
    configpanel.cpp \
    infopanel.cpp \
    logframe.cpp \
    logpanel.cpp \
    log.cpp \
    connection.cpp

HEADERS  += mainwindow.h \
    pin.h \
    macros.h \
    gpio.h \
    bcm_lib.h \
    server.h \
    thread_base.h \
    thread.h \
    ui_mainwindow.h \
    logpanel.h \
    logframe.h \
    infopanel.h \
    configpanel.h \
    log.h \
    connection.h

FORMS    += mainwindow.ui
