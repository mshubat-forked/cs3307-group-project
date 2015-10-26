#-------------------------------------------------
#
# Project created by QtCreator 2015-10-23T01:08:19
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ReadingFiles
TEMPLATE = app
CONFIG += c++11

SOURCES += main.cpp\
        mainwindow.cpp \
    data_entry.cpp \
    grants_entry.cpp \
    HashTable.cpp \
    LinkedList.cpp \
    teaching_entry.cpp

HEADERS  += mainwindow.h \
    data_entry.h \
    grants_entry.h \
    HashTable.h \
    LinkedList.h \
    teaching_entry.h

FORMS    += mainwindow.ui

INCLUDEPATH += C:/boost/boost_1_59_0/
LIBS += "-LC:/boost/boost_1_59_0/libs/"

INCLUDEPATH += C:/libcfu-0.03/libcfu-0.03/
LIBS += "-LC:/libcfu-0.03/libcfu-0.03/src/libcu-config"

unix|win32: LIBS += -lcomdlg32
