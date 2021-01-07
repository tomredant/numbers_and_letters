#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QBoxLayout>
#include <QPushButton>
#include <QDebug>
#include "soundplayer.h"
#include "gameselector.h"
#include <QThread>
#include "showlicense.h"

MainWindow::~MainWindow() {
    m_playerThread->quit();
    m_playerThread->wait();
    delete m_playerThread;
    delete m_player;
    delete ui;

}

MainWindow::MainWindow(bool letters) :
    ui(new Ui::MainWindow),
    m_letters(letters)
{
    m_aboutWindow = NULL;
    ui->setupUi(this);
    setWindowTitle(tr("Free number and Letter Trainer 1.0.0"));
    QBoxLayout* layout = new QBoxLayout(QBoxLayout::TopToBottom);
    ui->centralWidget->setLayout(layout);
    QFont font("Helvetica", 30, QFont::Bold);
    QBoxLayout* currentLayout = NULL;
    if(m_letters) {
        QString letters = "abcdefghijklmnopqrstuvwxyz";
        for (int i=0;i<letters.size();i++) {
            QPushButton *button = new QPushButton(letters.mid(i,1).toUpper());
            connect(button,SIGNAL(clicked()), this, SLOT(playback()));
            button->setFont(font);
            button->setMinimumHeight(50);
            button->setMaximumHeight(500);
            if((i % 10) == 0) {
                currentLayout = new QBoxLayout(QBoxLayout::LeftToRight);
                layout->addLayout(currentLayout);
            }
            currentLayout->addWidget(button);
        }
    } else {
        for (int i=0;i<100;i++) {
            QPushButton *button = new QPushButton(QString::number(i));
            connect(button,SIGNAL(clicked()), this, SLOT(playback()));
            button->setFont(font);
            button->setMinimumHeight(50);
            button->setMaximumHeight(500);
            if((i % 10) == 0) {
                currentLayout = new QBoxLayout(QBoxLayout::LeftToRight);
                layout->addLayout(currentLayout);
            }
            currentLayout->addWidget(button);
        }
    }
    connect(ui->actionAbout,SIGNAL(triggered()),this,SLOT(showAbout()));
    connect(ui->actionQuit,SIGNAL(triggered()),this,SLOT(clickQuit()));
    connect(ui->actionRestart,SIGNAL(triggered()),this,SLOT(clickRestart()));
    m_playerThread = new QThread();
    m_playerThread->setObjectName("Audio player thread");
    m_playerThread->start();
    m_player = new SoundPlayer();
    m_player->moveToThread(m_playerThread);

}


void MainWindow::clickRestart() {
    hide();
    emit restart();
}
void MainWindow::clickQuit() {
    QApplication::quit();
}

void MainWindow::showAbout() {
    std::vector<std::string> libsToShow;
    libsToShow.push_back("Qt5.15.3");
    showLicenseDialog(libsToShow);
}

void MainWindow::playback() {
    QPushButton* but = qobject_cast<QPushButton*>(sender());
    QString text = but->text();
    int fileNumber;
    if(m_letters)
        fileNumber = text.toUtf8().at(0)-0x41+100; //0x41 is the hex code for the char A.
    else
        fileNumber = text.toInt();
    QMetaObject::invokeMethod(m_player, "playSoundFile", Q_ARG(int, fileNumber));
}
