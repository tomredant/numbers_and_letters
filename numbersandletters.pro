QT       += core gui
#uncomment the following three lines for static linking
TRANSLATIONS = numbersandletters_nl.ts

CONFIG+=static
QMAKE_LFLAGS+=-static -static-libgcc -static-libstdc++ -lstdc++
DEFINES+=STATIC
VERSION = 1.0.0
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
TARGET = numbers_and_letters
TEMPLATE = app
DEFINES += QT_DEPRECATED_WARNINGS
CONFIG += c++11
SOURCES += \
        main.cpp \
        mainwindow.cpp \
    soundplayer.cpp \
    gameselector.cpp

HEADERS += \
        mainwindow.h \
    soundplayer.h \
    gameselector.h

FORMS += \
        mainwindow.ui \
    gameselector.ui
INCLUDEPATH +=$$(PORT_AUDIO_ROOT)/include
LIBS += $$PWD/audio/audio.raw.o
LIBS += -L$$(PORT_AUDIO_ROOT)/lib/ -lportaudio

INCLUDEPATH += $$(SHOWLICENSE_ROOT)
LIBS += -L$$(SHOWLICENSE_ROOT) -lshowlicense


RESOURCES += \
    numbersandletters.qrc
b
