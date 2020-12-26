#include "mainwindow.h"
#include <QApplication>
#include <QCommandLineParser>
#include <QDebug>
int main(int argc, char *argv[])
{

    QCommandLineParser parser;
    parser.setApplicationDescription("Number and letter quiz.");
    parser.addHelpOption();
    parser.addVersionOption();
    QCommandLineOption useLetters(QStringList() << "l" << "letters",
        "Play with letters instead of numbers.");
    parser.addOption(useLetters);
    QApplication a(argc, argv);
    parser.process(a);
    bool useLettersBool = false;
    if (parser.isSet(useLetters)) {
        useLettersBool = true;
        qDebug() << "using letters";
    }

    MainWindow w(useLettersBool);
    w.show();

    return a.exec();
}
