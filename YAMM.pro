#-------------------------------------------------
#
# Project created by QtCreator 2012-04-02T23:49:21
#
#-------------------------------------------------

QT       += core network

TARGET = YAMM
TEMPLATE = app


SOURCES += main.cpp \
    connection.adapter.irc.cpp \
    connection.manger.cpp

HEADERS += \
    connection.adapter.abstract.h \
    connection.adapter.irc.h \
    connection.manager.h
