#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QBoxLayout>
#include <QPushButton>
#include <QDebug>
#include "soundplayer.h"
#include "aboutwindow.h"
#include "gameselector.h"
MainWindow::MainWindow(bool letters) :
    m_ui(new Ui::MainWindow),
    m_letters(letters)
{
    m_aboutWindow = NULL;
    m_ui->setupUi(this);
    setWindowTitle("Free number and Letter Trainer 1.0.0");
    QBoxLayout* layout = new QBoxLayout(QBoxLayout::TopToBottom);
    m_ui->centralWidget->setLayout(layout);
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
    connect(m_ui->actionAbout,SIGNAL(triggered()),this,SLOT(showAbout()));
    connect(m_ui->actionQuit,SIGNAL(triggered()),this,SLOT(clickQuit()));
    connect(m_ui->actionRestart,SIGNAL(triggered()),this,SLOT(clickRestart()));


}


void MainWindow::clickRestart() {
    GameSelector* gameSelector = new GameSelector();
    gameSelector->show();
    close();
}
void MainWindow::clickQuit() {
    QApplication::quit();
}

void MainWindow::showAbout() {
    if(m_aboutWindow == NULL)
        m_aboutWindow = new AboutWindow();
    m_aboutWindow->show();
}

void MainWindow::playback() {
    QPushButton* but = qobject_cast<QPushButton*>(sender());
    QString text = but->text();
    int fileNumber;
    if(m_letters)
        fileNumber = text.toUtf8().at(0)-0x41+100; //0x41 is the hex code for the char A.
    else
        fileNumber = text.toInt();
    SoundPlayer player;
    player.playSoundFile(fileNumber);
}

MainWindow::~MainWindow()
{
    delete m_ui;
}
