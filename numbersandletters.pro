QT       += core gui
#uncomment the following three lines for static linking
#CONFIG+=static
#QMAKE_LFLAGS+=-static -static-libgcc -static-libstdc++ -lstdc++
#DEFINES+=STATIC
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
    aboutwindow.cpp \
    gameselector.cpp

HEADERS += \
        mainwindow.h \
    soundplayer.h \
    aboutwindow.h \
    gameselector.h

FORMS += \
        mainwindow.ui \
    aboutwindow.ui \
    gameselector.ui
INCLUDEPATH +=$$(PORT_AUDIO_ROOT)/include
LIBS += $$PWD/audio/audio.raw.o
LIBS += -L$$(PORT_AUDIO_ROOT)/lib/.libs/ -lportaudio


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
