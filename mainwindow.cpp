#include "mainwindow.h"
#include "ZorkUL.h"
#include "characterinfo.h"
#include <QInputDialog>
#include <QLineEdit>
#include <QDir>

#include <QCoreApplication>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    startButton = new QPushButton("Start", this);
    startButton->setGeometry(QRect(QPoint(100, 100),QSize(200, 50)));

    exitButton = new QPushButton("Exit", this);
    exitButton->setGeometry(QRect(QPoint(100, 200),QSize(200, 50)));

    connect(startButton, SIGNAL (clicked()), this, SLOT (startHandler()));
    connect(exitButton, SIGNAL (clicked()), this, SLOT (exitHandler()));
}

void MainWindow::startHandler()
{
    charInfo = new CharacterInfo();
    charInfo->setFixedSize(400,400);
    charInfo->show();
    close();

    //return app.exec();
    //ZorkUL temp;
    //close();
    //temp.play();
}

void MainWindow::exitHandler()
{
    close();
}
