#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}
class AboutWindow;
class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(bool letters);
    ~MainWindow();
private slots:
    void playback();
    void showAbout();
    void clickQuit();
private:
    Ui::MainWindow *m_ui;
    bool m_letters;
    AboutWindow* m_aboutWindow;
};

#endif // MAINWINDOW_H
