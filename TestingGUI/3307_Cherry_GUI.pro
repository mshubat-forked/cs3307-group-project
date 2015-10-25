#-------------------------------------------------
#
# Project created by QtCreator 2015-10-24T16:36:57
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

TARGET = Test_Pull
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    graphwindow.cpp \
    qcustomplot.cpp \
    summarywindow.cpp \
    graphwindowpie.cpp

HEADERS  += mainwindow.h \
    graphwindow.h \
    qcustomplot.h \
    summarywindow.h \
    graphwindowpie.h

FORMS += \
    graphwindow.ui \
    mainwindow.ui \
    summarywindow.ui \
    graphwindowpie.ui
