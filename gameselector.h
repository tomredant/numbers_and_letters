#ifndef GAMESELECTOR_H
#define GAMESELECTOR_H

#include <QWidget>

namespace Ui {
class GameSelector;
}

class GameSelector : public QWidget
{
    Q_OBJECT

public:
    explicit GameSelector(QWidget *parent = nullptr);
    ~GameSelector();
private slots:
    void openLetterGame();
    void openNumberGame();
private:
    Ui::GameSelector *m_ui;
};

#endif // GAMESELECTOR_H
