QT += core
QT -= gui

CONFIG += c++11

TARGET = Proyecto-consola
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    matrizdispersa.cpp

HEADERS += \
    matrizdispersa.h
