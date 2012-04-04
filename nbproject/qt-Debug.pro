# This file is generated automatically. Do not edit.
# Use project properties -> Build -> Qt -> Expert -> Custom Definitions.
TEMPLATE = app
DESTDIR = dist/Debug/GNU-Linux-x86
TARGET = YAMM
VERSION = 1.0.0
CONFIG -= debug_and_release app_bundle lib_bundle
CONFIG += debug 
QT = core gui
SOURCES += src/main.cpp src/bindings/skype/protocol/CommunicationLayerAdaptor.cpp src/bindings/common/Contact.cpp src/bindings/skype/skypeConnection.cpp src/bindings/skype/protocol/ProtocolLayer.cpp src/bindings/skype/skypeCall.cpp src/bindings/skype/protocol/CommunicationLayer.cpp
HEADERS += src/bindings/skype/protocol/ProtocolLayer.h src/bindings/common/Connection.h src/bindings/common/Call.h src/bindings/common/Callable.h src/bindings/skype/protocol/CommunicationLayer.h src/bindings/skype/skypeConnection.h src/bindings/skype/protocol/CommunicationLayerAdaptor.h src/bindings/common/Contact.h src/bindings/skype/skypeCall.h src/bindings/common/IMConnection.h src/bindings/common/VideoCallable.h
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
LIBS += -lQtDBus  
