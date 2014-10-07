#-------------------------------------------------
#
# Project created by QtCreator 2014-07-09T14:29:11
#
#-------------------------------------------------

QMAKE_LFLAGS += -static -static-libgcc
CONFIG += static

QT       += core gui
QT	 += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Report-Generator
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    io.cpp \
    initials.cpp \
    checkboxes.cpp \
    textbox.cpp \
    malwarewindow.cpp \
    menues.cpp \
    sqlite.cpp \
    saveReport.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui

RESOURCES += \
    Resources.qrc
