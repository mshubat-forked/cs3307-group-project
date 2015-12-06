#-------------------------------------------------
#
# Project created by QtCreator 2015-12-04T11:06:09
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Reading_Files
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    data_entry.cpp \
    datastruct.cpp \
    grants_entry.cpp \
    teaching_entry.cpp \
    testpubs.cpp \
    db.cpp

HEADERS  += mainwindow.h \
    data_entry.h \
    datastruct.h \
    grants_entry.h \
    teaching_entry.h \
    testpubs.h \
    db.h

FORMS    += mainwindow.ui

INCLUDEPATH += C:\boost_1_59_0
LIBS += "-LC:\boost_1_59_0\libs"


unix|win32: LIBS += -lcomdlg32


CONFIG += C++11
