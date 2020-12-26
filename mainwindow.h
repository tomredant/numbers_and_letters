#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(bool letters);
    ~MainWindow();
public slots:
    void playback();
private:
    Ui::MainWindow *ui;
    bool m_letters;
};

#endif // MAINWINDOW_H
