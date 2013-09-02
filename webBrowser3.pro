#-------------------------------------------------
#
# Project created by QtCreator 2013-07-19T18:48:32
#
#-------------------------------------------------

QT       += webkitwidgets core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = spark56
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    webview.cpp \
    networkaccessmanager.cpp \
    autosaver.cpp \
    cookiejar.cpp

HEADERS  += mainwindow.h \
    webview.h \
    networkaccessmanager.h \
    autosaver.h \
    cookiejar.h

RESOURCES += \
    res.qrc
