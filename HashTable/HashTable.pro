#-------------------------------------------------
#
# Project created by QtCreator 2015-10-25T21:50:58
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = HashTable
TEMPLATE = app
CONFIG += c++11


SOURCES += main.cpp\
        mainwindow.cpp \
    teaching_entry.cpp \
    data_entry.cpp \
    linkedlist.cpp

HEADERS  += mainwindow.h \
    teaching_entry.h \
    data_entry.h \
    linkedlist.h \
    node.h

FORMS    += mainwindow.ui
