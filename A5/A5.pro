#-------------------------------------------------
#
# Project created by QtCreator 2016-09-30T12:28:58
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = A5
TEMPLATE = app


SOURCES += main.cpp\
    mainwindow.cpp \
    timermodel.cpp

HEADERS  += \
    mainwindow.h \
    timermodel.h

FORMS    += mainwindow.ui

QMAKE_MAC_SDK = macosx10.11
