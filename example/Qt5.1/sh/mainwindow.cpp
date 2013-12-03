#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    hotkeys = new QSystemHotkey;

    connect(hotkeys, SIGNAL(runHotkey(int)),this,SLOT(hotkeyPressed(int)));
    hotkeys->addKey(200,MOD_ALT,'X');
    hotkeys->addKey(300,MOD_CONTROL,'X');
    hotkeys->addKey(400,MOD_CONTROL,'Q');
    QApplication::processEvents();
    hotkeys->beginHotkeys();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::halt()
{
    hotkeys->haltHotkeys();
}

void MainWindow::hotkeyPressed(int position)
{
    int val = hotkeys->getHotkey(position);
    switch (val) {
    case 200:
        qDebug() << "Case 200";
        break;
    case 300:
        qDebug() << "Case 300";
        break;
    case 400:
        qDebug() << "!!!Case 400: TURN OFF!!!";
        halt();
        close();
        break;
    default:
        break;
    }
}
