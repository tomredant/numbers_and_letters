#include "gameselector.h"
#include "ui_gameselector.h"
#include "mainwindow.h"
GameSelector::GameSelector(QWidget *parent) :
    QWidget(parent),
    m_ui(new Ui::GameSelector)
{
    m_ui->setupUi(this);
    setWindowTitle(tr("Select game"));
    connect(m_ui->pushButtonNumbers, SIGNAL(clicked()), this, SLOT(openNumberGame()));
    connect(m_ui->pushButtonLetters, SIGNAL(clicked()), this, SLOT(openLetterGame()));

}

GameSelector::~GameSelector()
{
    delete m_ui;
}

void GameSelector::openLetterGame() {
    close();
    MainWindow* w = new MainWindow(true);
    w->show();
}

void GameSelector::openNumberGame() {
    close();
    MainWindow* w = new MainWindow(false);
    w->show();
}
