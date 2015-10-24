#-------------------------------------------------
#
# Project created by QtCreator 2015-10-19T12:23:42
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

TARGET = TestingGUI
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    summarywindow.cpp \
    graphwindow.cpp \
    qcustomplot.cpp

HEADERS  += mainwindow.h \
    summarywindow.h \
    graphwindow.h \
    qcustomplot.h

FORMS    += mainwindow.ui \
    summarywindow.ui \
    graphwindow.ui
