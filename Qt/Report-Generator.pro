#-------------------------------------------------
#
# Project created by QtCreator 2014-07-09T14:29:11
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Report-Generator
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    io.cpp \
    initials.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui

RESOURCES += \
    Resources.qrc
