#-------------------------------------------------
#
# Project created by QtCreator 2022-08-24T08:59:05
#
#-------------------------------------------------

QT       += core gui \
         multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Game
TEMPLATE = app

CONFIG += resources_big

SOURCES += main.cpp \
    portrait.cpp \
    game.cpp \
    infobox.cpp \
    text.cpp \
    data.cpp \
    ui.cpp \
    tile.cpp \
    partyarrow.cpp \
    characterpic.cpp \
    monsterpic.cpp \
    effect.cpp \
    itempic.cpp \
    battlebackground.cpp \
    healthbar.cpp

HEADERS  += \
    portrait.h \
    game.h \
    infobox.h \
    text.h \
    data.h \
    ui.h \
    tile.h \
    partyarrow.h \
    characterpic.h \
    monsterpic.h \
    effect.h \
    itempic.h \
    battlebackground.h \
    healthbar.h

FORMS    += mainwindow.ui

RESOURCES += \
    res.qrc
