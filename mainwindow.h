#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}
class QThread;
class AboutWindow;
class SoundPlayer;
class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(bool letters);
    ~MainWindow();
signals:
    void restart();
private slots:
    void playback();
    void showAbout();
    void clickQuit();
    void clickRestart();
private:
    Ui::MainWindow *ui;
    bool m_letters;
    AboutWindow* m_aboutWindow;
private:
    SoundPlayer* m_player;

    QThread* m_playerThread;
};

#endif // MAINWINDOW_H
