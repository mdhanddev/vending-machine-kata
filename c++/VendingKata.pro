#-------------------------------------------------
#
# Project created by QtCreator 2016-06-11T21:26:11
#
#-------------------------------------------------

QT       += core
QT       -= gui

TARGET = VendingKata
CONFIG   += console c++11
CONFIG   -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    vendingmachine.cpp \
    test/vendingmachinetest.cpp

HEADERS += \
    vendingmachine.h \
    vendingmachinetest.h
