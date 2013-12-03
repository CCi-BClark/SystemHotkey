#-------------------------------------------------
#
# Project created by QtCreator 2013-12-02T10:43:51
#
#-------------------------------------------------

QT       -= gui
TARGET = QSystemHotkey
TEMPLATE = lib
CONFIG+= static

DEFINES += QSYSTEMHOTKEY_LIBRARY

SOURCES += qsystemhotkey.cpp \
    windows/stdafx.cpp

HEADERS += qsystemhotkey.h\
    windows/targetver.h \
    windows/stdafx.h

unix:!symbian {
    maemo5 {
        target.path = /opt/usr/lib
    } else {
        target.path = /usr/lib
    }
    INSTALLS += target
}
