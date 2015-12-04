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
    Charts/Nightcharts/nightcharts.cpp \
    Charts/Nightcharts/nightchartswidget.cpp \
    Charts/qcustomplot.cpp \
    DataEntry/data_entry.cpp \
    DataEntry/data_process.cpp \
    DataEntry/grants_entry.cpp \
    DataEntry/presentation_entry.cpp \
    DataEntry/publication_entry.cpp \
    DataEntry/teaching_entry.cpp \
    Windows/graphcolors.cpp \
    Windows/graphwindow.cpp \
    Windows/graphwindowbar.cpp \
    Windows/graphwindowpie.cpp \
    Windows/mainwindow.cpp \
    Windows/piechartwidget.cpp \
    Windows/summary_window.cpp

HEADERS  += mainwindow.h \
    Charts/Nightcharts/nightcharts.h \
    Charts/Nightcharts/nightchartswidget.h \
    Charts/qcustomplot.h \
    DataEntry/data_entry.h \
    DataEntry/grants_entry.h \
    DataEntry/presentation_entry.h \
    DataEntry/publication_entry.h \
    DataEntry/teaching_entry.h \
    Windows/graphcolors.h \
    Windows/graphwindow.h \
    Windows/graphwindowbar.h \
    Windows/graphwindowpie.h \
    Windows/mainwindow.h \
    Windows/piechartwidget.h \
    Windows/summary_window.h

FORMS += \
    Windows/graphwindow.ui \
    Windows/summary_window.ui \
    Windows/graphwindowbar.ui \
    Windows/graphwindowpie.ui \
    Windows/mainwindow.ui
