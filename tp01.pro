#-------------------------------------------------
#
# Project created by QtCreator 2019-01-12T12:27:11
#
#-------------------------------------------------

QT       += core gui

CONFIG += c++14

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = tp01
TEMPLATE = app

win32{
    LIBS += -lGLU32\
        -lOpengl32
}


SOURCES += main.cpp\
        princ.cpp \
        glarea.cpp \
    puff.cpp \
    smoke.cpp

HEADERS  += princ.h \
        glarea.h \
    puff.h \
    smoke.h

FORMS    += princ.ui

RESOURCES += \
    tp01.qrc
