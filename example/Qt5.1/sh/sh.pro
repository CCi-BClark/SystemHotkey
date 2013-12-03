#-------------------------------------------------
#
# Project created by QtCreator 2013-12-02T10:34:37
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = sh
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    QSystemHotkey/qsystemhotkey.cpp \
    QSystemHotkey/windows/stdafx.cpp

HEADERS  += mainwindow.h \
    QSystemHotkey/qsystemhotkey.h \
    QSystemHotkey/windows/targetver.h \
    QSystemHotkey/windows/stdafx.h

FORMS    += mainwindow.ui

OTHER_FILES +=


