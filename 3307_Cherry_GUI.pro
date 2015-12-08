#-------------------------------------------------
#
# Project created by QtCreator 2015-10-24T16:36:57
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

TARGET = Test_Pull
TEMPLATE = app

CONFIG += c++11

SOURCES += main.cpp\
        mainwindow.cpp \
    graphwindow.cpp \
    qcustomplot.cpp \
    summary_window.cpp \
    graphwindowpie.cpp \
    graphwindowbar.cpp \
    data_entry.cpp \
    HashTable.cpp \
    LinkedList.cpp \
    graphcolors.cpp \
    piechartwidget.cpp

HEADERS  += mainwindow.h \
    graphwindow.h \
    qcustomplot.h \
    summary_window.h \
    graphwindowpie.h \
    graphwindowbar.h \
    data_entry.h \
    HashTable.h \
    LinkedList.h \
    piechartwidget.h \
    graphcolors.h

FORMS += \
    graphwindow.ui \
    mainwindow.ui \
    summary_window.ui \
    graphwindowpie.ui \
    graphwindowbar.ui
