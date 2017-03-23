#include <QCoreApplication>
#include <iostream>
#include <QLabel>
#include <QLineEdit>
#include <QComboBox>
#include <QVBoxLayout>
#include <QStackedWidget>
#include <QRadioButton>
#include <QButtonGroup>
#include <QVBoxLayout>
#include <QComboBox>
#include <QString>
#include <string.h>
#include <QCheckBox>
#include "Command.h"
#include "playwindow.h"
#include "charinfowindow.h"
#include "ZorkUL.h"
#include "battle.h"
#include "Room.h"

PlayWindow::PlayWindow(QWidget *parent)
    : QMainWindow(parent)
{
    this->setCentralWidget(new QWidget());
    m_layout = new QHBoxLayout();
    this->centralWidget()->setLayout(m_layout);

    itemBox = new QComboBox;
    m_layout->addWidget(itemBox);

    map = new QLabel(this);
    map->setPixmap(QPixmap("map.png").scaled(350,300));
    map->setGeometry(QRect(QPoint(0,250),QSize(350,300)));
    map->hide();

    inventoryButton = new QComboBox;
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

    attackButton = new QPushButton("Attack Monster!", this);
    attackButton->setGeometry(QRect(QPoint(300, 200),QSize(100, 100)));
    attackButton->hide();

    takeButton = new QPushButton("Take Item", this);
    takeButton->setGeometry(QRect(QPoint(500, 100),QSize(100, 100)));
    takeButton->hide();


    QGroupBox *weaponsBox = new QGroupBox("Pick a weapon!", this);
    weaponsBox->hide();

    buttonGroup = new QButtonGroup();



    name = new QLabel(this);
    name->setGeometry(QRect(QPoint(0, 55),QSize(200, 20)));

    health = new QLabel(this);
    health->setGeometry(QRect(QPoint(200, 55),QSize(200, 20)));

    currRoom = new QLabel(this);
    currRoom->setGeometry(QRect(QPoint(400, 55),QSize(200, 20)));

    roomDesc = new QLabel(this);
    roomDesc->setGeometry(QRect(QPoint(600, 75),QSize(200, 100)));


    //Top buttons signals/slots
    //connect(inventoryButton, SIGNAL (clicked()), this, SLOT (inventoryHandler()));
    connect(mapButton, SIGNAL (clicked()), this, SLOT (mapHandler()));
    connect(infoButton, SIGNAL (clicked()), this, SLOT (infoHandler()));
    connect(quitButton, SIGNAL (clicked()), this, SLOT (quitHandler()));

    //Button signals/slots
    connect(leftButton, SIGNAL (clicked()), this, SLOT (leftHandler()));
    connect(rightButton, SIGNAL (clicked()), this, SLOT (rightHandler()));
    connect(upButton, SIGNAL (clicked()), this, SLOT (upHandler()));
    connect(downButton, SIGNAL (clicked()), this, SLOT (downHandler()));

    connect(attackButton, SIGNAL (clicked()), this, SLOT (attackHandler()));
    connect(takeButton, SIGNAL (clicked()), this, SLOT (takeHandler()));

}

void PlayWindow::startGame() {
    playGame->play();
}

void PlayWindow::inventoryHandler() {
    std::cout << "Inventory button" << std::endl;
}

void PlayWindow::mapHandler() {
    if(0 == showMap) {
        map->show();
        showMap = 1;
    }
    else {
        map->hide();
        showMap = 0;
    }
}

void PlayWindow::infoHandler() {

}

void PlayWindow::quitHandler() {
    close();
}

void PlayWindow::leftHandler() {
    Command* command;
    command = parser.getCommand("go left");
    playGame->processCommand(*command);
    setRoom();
    delete command;
}

void PlayWindow::upHandler() {
    Command* command;
    command = parser.getCommand("go up");
    playGame->processCommand(*command);
    setRoom();
    delete command;
}

void PlayWindow::rightHandler() {
    Command* command;
    command = parser.getCommand("go right");
    playGame->processCommand(*command);
    setRoom();
    delete command;
}

void PlayWindow::downHandler() {
    Command* command;
    command = parser.getCommand("go down");
    playGame->processCommand(*command);
    setRoom();
    delete command;
}

void PlayWindow::takeHandler() {
    if (playGame->currentRoom->numberOfItems() > 0)
    {
        string item = (itemBox->currentText()).toStdString(); //string name of item being taken
        Item *temp = (playGame->getCurrentRoom())->getItemByName(item);//getcorresponding object
        cout << "line 154" << endl;
        (playGame->getPlayer())->addItem(temp);
        cout << "line 156" << endl;
        (playGame->getCurrentRoom())->removeItem(temp);
        cout << "line 158" << endl;
    }
    setRoom();
}

void PlayWindow::attackHandler() {
    Battle *battle = 0;
    battle->engageBattle(playGame);
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
    delete attackButton;
}

void PlayWindow::setName(std::string userName) {
    std::string nameText = "Name: " + userName;
    name->setText(QString::fromStdString(nameText));
}

void PlayWindow::setRoom() {
    std::string roomText = "Room: " + playGame->currentRoom->shortDescription();
    currRoom->setText(QString::fromStdString(roomText));
    roomDesc->setText(QString::fromStdString(playGame->currentRoom->longDescription()));
    displayRoomItems();
    //checking if monster is in room
    if((playGame->getCurrentRoom())->getMonsterInRoom() != NULL){
        setRadioButtons();
        attackButton->show(); //when attack is pressed, you attack and the monster attacks back
    }
}

void PlayWindow::setHealth(int newHealth) {
    QString healthText = QString::fromStdString("Health: ") + QString::number(newHealth);
    health->setText(healthText);
}

void PlayWindow::setup(std::string userName, std::string favFood) {
    playGame = new ZorkUL(userName, favFood);
    setName(userName);
    setHealth(playGame->me->getHealth());
    attackButton->hide();
    setRoom();
}


void PlayWindow::setRadioButtons(){
    /*vector <Item*> items = (playGame->getPlayer())->getItemsInCharacter();
    for(vector<Item*>::iterator it = items.begin(); it != items.end(); ++it){
        if((*it)->getWeaponCheck() != false){
          buttonGroup->addButton(new QRadioButton(QString::fromStdString((*it)->getName()), this));
        }
    }*/
}

void PlayWindow::displayRoomItems(){
    itemBox->clear(); //clears items from previous room
    vector <Item*> itemList = (playGame->getCurrentRoom())->getItemsInRoom();
    for(vector<Item*>::iterator it = itemList.begin(); it != itemList.end(); ++it){
        string name = (*it)->getName();
        itemBox->addItem(QString::fromStdString(name));
    }
    takeButton->show();
}
