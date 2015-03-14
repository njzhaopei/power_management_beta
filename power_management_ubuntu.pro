#-------------------------------------------------
#
# Project created by QtCreator 2015-03-10T14:22:39
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = power_management_ubuntu
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    tittlewidget.cpp \
    mainwidget.cpp \
    footwidget.cpp \
    personalsavemode.cpp

HEADERS  += mainwindow.h \
    tittlewidget.h \
    common.h \
    footwidget.h \
    mainwidget.h \
    personalsavemode.h

FORMS    += mainwindow.ui

RESOURCES += \
    tittlebutton.qrc
