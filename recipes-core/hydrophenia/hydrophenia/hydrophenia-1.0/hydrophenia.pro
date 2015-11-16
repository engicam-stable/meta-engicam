# -------------------------------------------------
# Project created by QtCreator 2013-06-05T21:40:12
# -------------------------------------------------
QT       += core gui widgets

LIBS += -lqwt

CONFIG += qwt



TARGET = hydrophenia
TEMPLATE = app
SOURCES += main.cpp \
    mainwindow.cpp \
    fbaseform.cpp \
    cserra.cpp \
    fmainmenu.cpp \
    cvasca.cpp \
    fpiante.cpp \
    fpianta.cpp \
    fserra.cpp \
    fvalues.cpp
HEADERS += mainwindow.h \
    fbaseform.h \
    cserra.h \
    fmainmenu.h \
    keycode.h \
    cvasca.h \
    fpiante.h \
    fpianta.h \
    fserra.h \
    fvalues.h
FORMS += mainwindow.ui \
    fbaseform.ui \
    fmainmenu.ui \
    fpiante.ui \
    fpianta.ui \
    fserra.ui \
    fvalues.ui
RESOURCES += images.qrc
