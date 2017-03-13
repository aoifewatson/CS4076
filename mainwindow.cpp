#include <QInputDialog>
#include <QLineEdit>
#include <QDir>
#include <QCoreApplication>
#include <QWidget>
#include <QMainWindow>

#include "charinfowindow.h"
#include "mainwindow.h"
#include "playwindow.h"
#include "ZorkUL.h"

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
    ciWin = new CharInfoWindow();
    ciWin->setFixedSize(400,400);
    ciWin->show();
    close();
}

void MainWindow::exitHandler()
{
    close();
}

