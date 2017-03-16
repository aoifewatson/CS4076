#include <QCoreApplication>
#include <iostream>
#include <QLabel>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QStackedWidget>
#include "playwindow.h"
#include "charinfowindow.h"
#include "ZorkUL.h"

PlayWindow::PlayWindow(QWidget *parent)
    : QMainWindow(parent)
{
    this->setCentralWidget(new QWidget());
    m_layout = new QHBoxLayout();
    this->centralWidget()->setLayout(m_layout);

    inventoryButton = new QPushButton("Inventory", this);
    inventoryButton->setGeometry(QRect(QPoint(0, 0),QSize(200, 50)));

    mapButton = new QPushButton("Map", this);
    mapButton->setGeometry(QRect(QPoint(200, 0),QSize(200, 50)));

    infoButton = new QPushButton("Info", this);
    infoButton->setGeometry(QRect(QPoint(400, 0),QSize(200, 50)));

    quitButton = new QPushButton("Quit", this);
    quitButton->setGeometry(QRect(QPoint(600, 0),QSize(200, 50)));

    upButton = new QPushButton("Up", this);
    upButton->setGeometry(QRect(QPoint(400, 400),QSize(50, 50)));

    leftButton = new QPushButton("Left", this);
    leftButton->setGeometry(QRect(QPoint(350, 425),QSize(50, 50)));

    downButton = new QPushButton("Down", this);
    downButton->setGeometry(QRect(QPoint(400, 450),QSize(50, 50)));

    rightButton = new QPushButton("Right", this);
    rightButton->setGeometry(QRect(QPoint(450, 425),QSize(50, 50)));

    name = new QLabel(this);
    name->setGeometry(QRect(QPoint(0, 55),QSize(200, 20)));

    health = new QLabel(this);
    health->setGeometry(QRect(QPoint(200, 55),QSize(200, 20)));

    currRoom = new QLabel(this);
    currRoom->setGeometry(QRect(QPoint(400, 55),QSize(200, 20)));

    connect(inventoryButton, SIGNAL (clicked()), this, SLOT (inventoryHandler()));
    connect(mapButton, SIGNAL (clicked()), this, SLOT (mapHandler()));
    connect(infoButton, SIGNAL (clicked()), this, SLOT (infoHandler()));
    connect(quitButton, SIGNAL (clicked()), this, SLOT (quitHandler()));

    //Button signals/slots
    connect(leftButton, SIGNAL (clicked()), this, SLOT (leftHandler()));
    connect(rightButton, SIGNAL (clicked()), this, SLOT (rightHandler()));
    connect(upButton, SIGNAL (clicked()), this, SLOT (upHandler()));
    connect(downButton, SIGNAL (clicked()), this, SLOT (downHandler()));
}

void PlayWindow::startGame() {
    playGame->play();
}

void PlayWindow::inventoryHandler() {
    std::cout << "Inventory button" << std::endl;
}

void PlayWindow::mapHandler() {
    std::cout << "map button" << std::endl;

}

void PlayWindow::infoHandler() {

}

void PlayWindow::quitHandler() {
    close();
}

void PlayWindow::leftHandler() {
    command = parser.getCommand("go left");
    playGame->processCommand(*command);
    setRoom();
}

void PlayWindow::upHandler() {
    command = parser.getCommand("go up");
    playGame->processCommand(*command);
    setRoom();
}

void PlayWindow::rightHandler() {
    command = parser.getCommand("go right");
    playGame->processCommand(*command);
    setRoom();
}

void PlayWindow::downHandler() {
    command = parser.getCommand("go down");
    playGame->processCommand(*command);
    setRoom();
}

std::string PlayWindow::getCommand() {
    return commandString;
}

PlayWindow::~PlayWindow() {
    delete m_layout;
    delete inventoryButton;
    delete mapButton;
    delete leftButton;
    delete upButton;
    delete rightButton;
    delete downButton;
    delete infoButton;
    delete quitButton;
}

void PlayWindow::setName(std::string userName) {
    std::string nameText = "Name: " + userName;
    name->setText(QString::fromStdString(nameText));
}

void PlayWindow::setRoom() {
    std::string roomText = "Room: " + playGame->currentRoom->shortDescription();
    currRoom->setText(QString::fromStdString(roomText));
}

void PlayWindow::setHealth(int newHealth) {
    QString healthText = QString::fromStdString("Health: ") + QString::number(newHealth);
    health->setText(healthText);
}

void PlayWindow::setup(std::string userName, std::string favFood) {
    playGame = new ZorkUL(userName, favFood);
    setName(userName);
    setHealth(playGame->me->getHealth());
    setRoom();
}
