#include <QCoreApplication>
#include <iostream>
#include <QLabel>
#include <QLineEdit>
#include <QComboBox>
#include <QVBoxLayout>
#include <QStackedWidget>
#include <QRadioButton>
#include <QGroupBox>
#include <QGridLayout>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QComboBox>
#include <QString>
#include <string.h>
#include <QCheckBox>
#include <QToolBar>
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
    m_layout = new QVBoxLayout(); //overall layout for the screen
    (this->centralWidget())->setLayout(m_layout);

    toolBar = new QToolBar();

    showMap = 0;
    map = new QLabel(this);
    map->setPixmap(QPixmap("map.png").scaled(350,300));
    map->setGeometry(QRect(QPoint(0,250),QSize(350,300)));

    inventory = new QComboBox;
    inventory->addItem("Inventory");
    mapButton = new QPushButton("Map", this);
    infoButton = new QPushButton("Info", this);
    quitButton = new QPushButton("Quit", this);

    //inventoryButton->setGeometry(QRect(QPoint(0, 0),QSize(200, 50)));
    //mapButton->setGeometry(QRect(QPoint(200, 0),QSize(200, 50)));
    //infoButton->setGeometry(QRect(QPoint(400, 0),QSize(200, 50)));
    //quitButton->setGeometry(QRect(QPoint(600, 0),QSize(200, 50)));

    //adding buttons to toolbar
    toolBar->addWidget(inventory);
    toolBar->addWidget(mapButton);
    toolBar->addWidget(infoButton);
    toolBar->addWidget(quitButton);

    itemBox = new QComboBox;
    //m_layout->addWidget(itemBox);
    toolBar->addWidget(itemBox);

    toolBar ->setFloatable(false);
    toolBar ->setMovable(false);
    toolBar -> show();

    m_layout->setMenuBar(toolBar); //correct place but too small, needs to be wider

    rButtons = new QGroupBox("Pick a weapon!");
    rLayout = new QVBoxLayout();

    knife = new QRadioButton(tr("Knife"));
    knife->setChecked(false);
    sword = new QRadioButton(tr("Sword"));
    sword->setChecked(false);



    rLayout -> addWidget(sword);
    rLayout -> addWidget(knife);
    //rButtons->addWidget(weaponButton);

    rButtons->setLayout(rLayout);
    m_layout->addWidget(rButtons);

    arrowLayout = new QVBoxLayout();


    upButton = new QPushButton("Up", this);
    upButton->setGeometry(QRect(QPoint(400, 400),QSize(50, 50)));
    leftButton = new QPushButton("Left", this);
    leftButton->setGeometry(QRect(QPoint(350, 425),QSize(50, 50)));
    downButton = new QPushButton("Down", this);
    downButton->setGeometry(QRect(QPoint(400, 450),QSize(50, 50)));
    rightButton = new QPushButton("Right", this);
    rightButton->setGeometry(QRect(QPoint(450, 425),QSize(50, 50)));


    attackButton = new QPushButton("Attack Monster!", this);
    takeButton = new QPushButton("Take Item", this);
    weaponButton = new QPushButton("Use this weapon", this);

    //arrowLayout->addWidget(upButton);
    //arrowLayout->addWidget(downButton);
    //arrowLayout->addWidget(leftButton);
    //arrowLayout->addWidget(rightButton);

    name = new QLabel(this);
    //name->setGeometry(QRect(QPoint(0, 55),QSize(200, 20)));
    health = new QLabel(this);
   // health->setGeometry(QRect(QPoint(200, 55),QSize(200, 20)));
    currRoom = new QLabel(this);
   // currRoom->setGeometry(QRect(QPoint(400, 55),QSize(200, 20)));
    roomDesc = new QLabel(this);
   // roomDesc->setGeometry(QRect(QPoint(600, 75),QSize(200, 100)));
    monsterDead = new QLabel(this);
    QString monText = QString::fromStdString("You have killed the monster!");
    monsterDead->setText(monText);
    monsterDead->hide();

    m_layout->addWidget(weaponButton);
    m_layout->addWidget(name);
    m_layout->addWidget(currRoom);
    m_layout->addWidget(roomDesc);
    m_layout->addWidget(health);
    m_layout->addWidget(monsterDead);
    m_layout->addWidget(attackButton);
    m_layout->addWidget(takeButton);
    m_layout->addLayout(arrowLayout);

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
    connect(weaponButton, SIGNAL (clicked()), this, SLOT (weaponHandler()));
}

void PlayWindow::startGame() {
    //playGame->play();
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
    if (playGame->currentRoom->numberOfItems() > 0){
        string item = (itemBox->currentText()).toStdString();           //string name of item being taken
        Item *temp = (playGame->getCurrentRoom())->getItemByName(item); //get corresponding object
        (playGame->getPlayer())->addItem(temp);
        (playGame->getCurrentRoom())->removeItem(temp);
        setRoom();
    }
}

void PlayWindow::attackHandler() {
    Battle *battle = 0;
    if(playGame->getPlayer()->getHealth() > 0 && playGame->getCurrentRoom()->getMonsterInRoom()->getHealth() > 0){
        battle->engageBattle(playGame);
    }
    else{
        attackButton->hide();
        monsterDead->show();
    }
}

void PlayWindow::weaponHandler(){
    rButtons->hide();
    weaponButton->hide();
    attackButton->show(); //after weapon is shown, attack button appears
}

std::string PlayWindow::getCommand() {
    return commandString;
}


PlayWindow::~PlayWindow() {
    delete m_layout;
    delete inventory;
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
    showDirectionalButtons();
    if((playGame->getCurrentRoom())->getMonsterInRoom() != NULL){
        hideDirectionalButtons();
        setRadioButtons();
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
    setRoom();
    hideButtons();
}

//setting radio buttons for picking weapon to attack
void PlayWindow::setRadioButtons(){
    vector <Item*> items = (playGame->getPlayer())->getItemsInCharacter();
    for(vector<Item*>::iterator it = items.begin(); it != items.end(); ++it){
        if((*it)->getWeaponCheck() != false){
            if((*it)->getName() == "Knife"){
              knife->show();
            }
            else{
               sword->show();
            }
        }
    }
   rButtons->show();
   weaponButton->show();
}

//combo box got displaying items in room
void PlayWindow::displayRoomItems(){
    itemBox->clear(); //clears items from previous room
    vector <Item*> itemList = (playGame->getCurrentRoom())->getItemsInRoom();
    if(itemList.size() > 0){
        takeButton->show();
            for(vector<Item*>::iterator it = itemList.begin(); it != itemList.end(); ++it){
            string name = (*it)->getName();
            itemBox->addItem(QString::fromStdString(name));
        }
    }
    else{
        takeButton->hide();//hide button if there are no items in room
    }
}

void PlayWindow::hideDirectionalButtons() {
    upButton->hide();
    downButton->hide();
    leftButton->hide();
    rightButton->hide();
}

void PlayWindow::showDirectionalButtons() {
    upButton->show();
    downButton->show();
    leftButton->show();
    rightButton->show();
}

void PlayWindow::hideButtons(){
    attackButton->hide();
    weaponButton->hide();
    takeButton->hide();
    rButtons->hide();
    map->hide();
    knife->hide();
    sword->hide();
}
