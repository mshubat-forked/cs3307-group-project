TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    data_entry.cpp \
    grants_entry.cpp \
    HashTable.cpp \
    LinkedList.cpp \
    teaching_entry.cpp

HEADERS += \
    data_entry.h \
    grants_entry.h \
    HashTable.h \
    LinkedList.h \
    teaching_entry.h

