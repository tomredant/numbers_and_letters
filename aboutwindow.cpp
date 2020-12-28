#include "aboutwindow.h"
#include "ui_aboutwindow.h"

AboutWindow::AboutWindow(QWidget *parent) :
    QDialog(parent),
    m_ui(new Ui::AboutWindow)
{
    m_ui->setupUi(this);
    m_ui->aboutText->setPlainText(tr("This software is written for educational purposes. It can be used free of any charge. Thanks for mentioning the original author Tom Redant and if you are planning to improve this software, to be compilant with the GPLv3-license. The license text is available through the following link: https://www.gnu.org/licenses/gpl-3.0.en.html"));
    m_ui->aboutText->setReadOnly(true);
    setWindowTitle(tr("About"));
}

AboutWindow::~AboutWindow()
{
    delete m_ui;
}
//Deze software is gemaakt voor educatieve doeleinden. Het kan zonder enig kost gebruikt worden. Bedankt om de originele auteur Tom Redant te vermelden en indien je de software verbetert ook in regel te zijn met de GPLv3-licentie. De licentietekst is beschikbaar op volgende link: https://www.gnu.org/licenses/gpl-3.0.en.html
