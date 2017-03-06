#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include "characterinfo.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);
private slots:
    void startHandler();
    void exitHandler();
private:
    QPushButton *startButton;
    QPushButton *exitButton;
    CharacterInfo *charInfo;
};

#endif
