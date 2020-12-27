#include "aboutwindow.h"
#include "ui_aboutwindow.h"

AboutWindow::AboutWindow(QWidget *parent) :
    QDialog(parent),
    m_ui(new Ui::AboutWindow)
{
    m_ui->setupUi(this);
    m_ui->aboutText->setPlainText(tr("This software is written for educational purposes. It can be used free of any charge and without any obligation. Please check the website where this came from for all licensing and copyright information."));
    m_ui->aboutText->setReadOnly(true);
    setWindowTitle(tr("About"));
}

AboutWindow::~AboutWindow()
{
    delete m_ui;
}
