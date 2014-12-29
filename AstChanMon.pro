# -------------------------------------------------
# Project created by QtCreator 2010-09-26T11:07:30
# -------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ACM
TEMPLATE = app


SOURCES += src/main.cpp\
    src/mainwindow.cpp \
    src/sessionmanagerdialog.cpp \
    src/asteriskmanager.cpp \
    src/sessionwindow.cpp \
    src/flowlayout.cpp \
    src/channelframe.cpp \
    src/peerframe.cpp

HEADERS  += src/mainwindow.h \
    src/sessionmanagerdialog.h \
    src/asteriskmanager.h \
    src/sessionwindow.h \
    src/flowlayout.h \
    src/channelframe.h \
    src/sessionmanagerdialog.h \
    src/peerframe.h

FORMS    += ui/mainwindow.ui \
    ui/sessionmanagerdialog.ui \
    ui/sessionwindow.ui \
    ui/channelframe.ui \
    ui/sessionmanagerdialog.ui \
    ui/peerframe.ui

RESOURCES += \
    icon/icon.qrc
