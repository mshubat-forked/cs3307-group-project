#-------------------------------------------------
#
# Project created by QtCreator 2015-10-24T16:36:57
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

TARGET = STAR Summary
TEMPLATE = app

CONFIG += c++11

SOURCES += main.cpp\
    Charts/Nightcharts/nightcharts.cpp \
    Charts/Nightcharts/nightchartswidget.cpp \
    Charts/qcustomplot.cpp \
    DataEntry/data_entry.cpp \
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
    Windows/summary_window.cpp \
    Reading_Files/datastruct.cpp \
    Reading_Files/db.cpp \
    Reading_Files/MyListBox.cpp \
    Reading_Files/testpubs.cpp \
    Reading_Files/read_database.cpp

HEADERS  += Windows/mainwindow.h \
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
    Windows/summary_window.h \
    Reading_Files/db.h \
    Reading_Files/main.h \
    Reading_Files/testpubs.h \
    Reading_Files/read_database.h \
    Reading_Files/datastruct.h

FORMS += \
    Windows/graphwindow.ui \
    Windows/summary_window.ui \
    Windows/graphwindowbar.ui \
    Windows/graphwindowpie.ui \
    Windows/mainwindow.ui

INCLUDEPATH += C:/Users/kungf/Documents/boost_1_59_0/
LIBS += "-LC:/Users/kungf/Documents/boost_1_59_0/libs/"

win32:RC_ICONS += Images/icon.ico

unix|win32: LIBS += -lcomdlg32
