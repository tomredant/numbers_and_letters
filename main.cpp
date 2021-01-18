#include <QApplication>
#include <QCommandLineParser>
#include <QDebug>
#include "gameselector.h"
#include <QTranslator>
#include "showlicense.h"
int main(int argc, char *argv[])
{

    QCommandLineParser parser;
    parser.setApplicationDescription("Number and letter quiz.");
    parser.addHelpOption();
    parser.addVersionOption();
    QString language = "nl";

    QApplication a(argc, argv);
    parser.process(a);
    QTranslator *translator = new QTranslator();
    QString translatorFile =(":/numbersandletters_" + language + ".qm");
    translator->load(translatorFile);
    a.installTranslator(translator);

    std::vector<std::string> libs;
    libs.push_back("Numbers and letters-1.0#The software is written by Tom Redant. Source files can be obtained from https://github.com/tomredant/numbers_and_letters#gpl-3.0");
    libs.push_back("Qt5.15.3#Source files can be obtained from http://www.qt.io.#lgpl-3.0");
    libs.push_back("MinGW-W64-builds-4.3.5##MinGW-w64");
    libs.push_back("libstdc++-6##gpl-3.0_runtime_exception");
    libs.push_back(R"MYSTRING(PortAudio V19.6.0-devel##/*
                  * PortAudio Portable Real-Time Audio Library
                  * Latest Version at: http://www.portaudio.com
                  *
                  * Copyright (c) 1999-2008 Phil Burk and Ross Bencina
                  *
                  * Permission is hereby granted, free of charge, to any person obtaining
                  * a copy of this software and associated documentation files
                  * (the "Software"), to deal in the Software without restriction,
                  * including without limitation the rights to use, copy, modify, merge,
                  * publish, distribute, sublicense, and/or sell copies of the Software,
                  * and to permit persons to whom the Software is furnished to do so,
                  * subject to the following conditions:
                  *
                  * The above copyright notice and this permission notice shall be
                  * included in all copies or substantial portions of the Software.
                  *
                  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
                  * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
                  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
                  * IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR
                  * ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF
                  * CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
                  * WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
                  */

                 /*
                  * The text above constitutes the entire PortAudio license; however,
                  * the PortAudio community also makes the following non-binding requests:
                  *
                  * Any person wishing to distribute modifications to the Software is
                  * requested to send the modifications to the original developer so that
                  * they can be incorporated into the canonical version. It is also
                  * requested that these non-binding requests be included along with the
                  * license above.
                  */


                 PortAudio is a portable audio I/O library designed for cross-platform
                 support of audio. It uses either a callback mechanism to request audio
                 processing, or blocking read/write calls to buffer data between the
                 native audio subsystem and the client. Audio can be processed in various
                 formats, including 32 bit floating point, and will be converted to the
                 native format internally.
)MYSTRING");
    showLicenseDialog(libs);
    if(!waitLicenseDialogAccepted())
        return 0;


    GameSelector gameSelector;
    gameSelector.show();
    return a.exec();
}
