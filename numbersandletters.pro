#-------------------------------------------------
#
# Project created by QtCreator 2020-12-12T15:57:03
#
#-------------------------------------------------

QT       += core gui
#CONFIG += static
#QMAKE_LFLAGS += -static-libgcc -static-libstdc++

CONFIG+=static
QMAKE_LFLAGS+=-static -static-libgcc -static-libstdc++ -lstdc++
DEFINES+=STATIC

VERSION = 1.0.0
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = numbers_and_letters
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0
CONFIG += c++11
SOURCES += \
        main.cpp \
        mainwindow.cpp \
    soundplayer.cpp

HEADERS += \
        mainwindow.h \
    soundplayer.h

FORMS += \
        mainwindow.ui
 D:\lib\portaudio

INCLUDEPATH +=$$(PORT_AUDIO_ROOT)\include
LIBS += $$PWD\audio\audio.raw.o
LIBS += -L$$(PORT_AUDIO_ROOT)\lib\.libs\ -lportaudio
# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
