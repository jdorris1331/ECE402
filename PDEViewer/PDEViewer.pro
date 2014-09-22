#-------------------------------------------------
#
# Project created by QtCreator 2014-09-04T14:49:47
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = PDEViewer
TEMPLATE = app


SOURCES += main.cpp\
        \ #uiview.cpp \
        model.cpp \
        guiview.cpp \
        sliderbox.cpp \
        ctrlgui.cpp \
        ctrlsliders.cpp \
    ctrlmenubar.cpp \
    ctrlcmd.cpp \
    initview.cpp

HEADERS  += \#uiview.h \
        model.h \
        guiview.h \
        sliderbox.h \
        ctrlgui.h \
        ctrlsliders.h \
    ctrlmenubar.h \
    ctrlcmd.h \
    initview.h

#FORMS    += uiview.ui

OTHER_FILES += \
        netlogogui.txt \
        temp.txt
