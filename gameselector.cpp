#include "gameselector.h"
#include "ui_gameselector.h"
#include "mainwindow.h"
GameSelector::GameSelector(QWidget *parent) :
    QWidget(parent),
    m_ui(new Ui::GameSelector)
{
    m_mainWindow = NULL;
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
    hide();
    if(m_mainWindow != NULL)
        delete m_mainWindow;
    m_mainWindow = new MainWindow(true);
    connect(m_mainWindow, SIGNAL(restart()), this,SLOT(show()));
    m_mainWindow->show();
}

void GameSelector::openNumberGame() {
    hide();
    if(m_mainWindow != NULL)
        delete m_mainWindow;
    m_mainWindow= new MainWindow(false);
    connect(m_mainWindow, SIGNAL(restart()), this,SLOT(show()));
    m_mainWindow->show();
}
