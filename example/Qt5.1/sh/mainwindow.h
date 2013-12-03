#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSystemHotkey/qsystemhotkey.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void halt(void);

public slots:
    void hotkeyPressed(int position);  //Handle hotkey SIGNAL

private:
    Ui::MainWindow *ui;
    QSystemHotkey *hotkeys;
};

#endif // MAINWINDOW_H
