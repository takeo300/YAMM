# This file is generated automatically. Do not edit.
# Use project properties -> Build -> Qt -> Expert -> Custom Definitions.
TEMPLATE = app
DESTDIR = dist/Debug/GNU-Linux-x86
TARGET = YAMM
VERSION = 1.0.0
CONFIG -= debug_and_release app_bundle lib_bundle
CONFIG += debug 
QT = core gui network
SOURCES += main.cpp Skype/CommunicationLayer/DBusAdaptor.cpp Skype/CommunicationLayer/DBus.cpp
HEADERS += Skype/CommunicationLayer/DBusAdaptor.h Skype/CommunicationLayer/DBus.h
FORMS +=
RESOURCES +=
TRANSLATIONS +=
OBJECTS_DIR = build/Debug/GNU-Linux-x86
MOC_DIR = 
RCC_DIR = 
UI_DIR = 
QMAKE_CC = gcc
QMAKE_CXX = g++
DEFINES += 
INCLUDEPATH += 
LIBS += -Wl,-rpath /usr/lib64 /usr/lib64/libQtDBus.so  
