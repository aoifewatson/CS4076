#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include "playwindow.h"
#include "charinfowindow.h"

class MainWindow : public QMainWindow //template is QMainWindow
{
    Q_OBJECT //macro - just leave it as is
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
private slots:
    void startHandler();
    void exitHandler();
private:
    QPushButton *startButton;
    QPushButton *exitButton;
    CharInfoWindow *ciWin;
};

#endif
