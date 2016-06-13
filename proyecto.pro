#-------------------------------------------------
#
# Project created by QtCreator 2016-05-30T17:24:03
#
#-------------------------------------------------

QT       += widgets svg

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = proyecto
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui

DISTFILES += \
    pelot.svg \
    pelot0.svg \
    cube.svg \
    reloj.svg \
    file/reloj.svg

RESOURCES += \
    files.qrc
