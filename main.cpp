#include <QApplication>
#include <QCommandLineParser>
#include <QDebug>
#include "gameselector.h"
#include <QTranslator>
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
    GameSelector gameSelector;
    gameSelector.show();
    return a.exec();
}
