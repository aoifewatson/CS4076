#include <QCoreApplication>
#include <QApplication>
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
#include "playwindow.h"
#include "charinfowindow.h"
#include "ZorkUL.h"
#include "battle.h"
#include "Room.h"

PlayWindow::PlayWindow(QWidget *parent)
    : QMainWindow(parent)
{
    this->setCentralWidget(new QWidget());
    m_layout = new QVBoxLayout();
    (this->centralWidget())->setLayout(m_layout);
    m_layout->setSpacing(0);

    toolBar = new QToolBar();

    showMap = 0;
    map = new QLabel(this);
    map->setPixmap(QPixmap("map.png").scaled(350,300));
    map->setGeometry(QRect(QPoint(0,250),QSize(350,300)));

    inventory = new QComboBox;
    inventory->addItem("Inventory");
    inventory->setMinimumWidth(180);
    mapButton = new QPushButton("Map", this);
    mapButton->setMinimumWidth(180);
    quitButton = new QPushButton("Quit", this);
    quitButton->setMinimumWidth(180);

    toolBar->addWidget(inventory);
    toolBar->addWidget(mapButton);
    toolBar->addWidget(quitButton);

    itemBox = new QComboBox;
    toolBar->addWidget(itemBox);
    itemBox->setMinimumWidth(180);

    toolBar ->setFloatable(false);
    toolBar ->setMovable(false);
    toolBar -> show();

    m_layout->setMenuBar(toolBar);

    rButtons = new QGroupBox("Pick a weapon!");
    rLayout = new QVBoxLayout();

    knife = new QRadioButton(tr("Knife"));
    knife->setChecked(false);
    sword = new QRadioButton(tr("Sword"));
    sword->setChecked(false);

    rLayout -> addWidget(sword);
    rLayout -> addWidget(knife);

    rButtons->setLayout(rLayout);
    m_layout->addWidget(rButtons);

    upButton = new QPushButton("Up", this);
    upButton->setGeometry(QRect(QPoint(400, 500),QSize(50, 50)));
    leftButton = new QPushButton("Left", this);
    leftButton->setGeometry(QRect(QPoint(350, 525),QSize(50, 50)));
    downButton = new QPushButton("Down", this);
    downButton->setGeometry(QRect(QPoint(400, 550),QSize(50, 50)));
    rightButton = new QPushButton("Right", this);
    rightButton->setGeometry(QRect(QPoint(450, 525),QSize(50, 50)));

    attackButton = new QPushButton("Attack Monster!", this);
    takeButton = new QPushButton("Take Item", this);
    weaponButton = new QPushButton("Use this weapon", this);
    takeButton->setMaximumWidth(100);
    attackButton->setMaximumWidth(100);
    weaponButton->setMaximumWidth(100);

    name = new QLabel(this);
    health = new QLabel(this);
    currRoom = new QLabel(this);
    roomDesc = new QLabel(this);
    monsterDead = new QLabel(this);
    monHealth = new QLabel(this);
    QString monText = QString::fromStdString("You have killed the monster!");
    monsterDead->setText(monText);

    name->setContentsMargins(0,0,0,0);

    m_layout->addWidget(weaponButton);
    m_layout->addWidget(name);
    m_layout->addWidget(currRoom);
    m_layout->addWidget(roomDesc);
    m_layout->addWidget(health);
    m_layout->addWidget(monsterDead);
    m_layout->addWidget(monHealth);
    m_layout->addWidget(attackButton);
    m_layout->addWidget(takeButton);


    connect(mapButton, SIGNAL (clicked()), this, SLOT (mapHandler()));
    connect(quitButton, SIGNAL (clicked()), this, SLOT (quitHandler()));
    connect(leftButton, SIGNAL (clicked()), this, SLOT (leftHandler()));
    connect(rightButton, SIGNAL (clicked()), this, SLOT (rightHandler()));
    connect(upButton, SIGNAL (clicked()), this, SLOT (upHandler()));
    connect(downButton, SIGNAL (clicked()), this, SLOT (downHandler()));
    connect(attackButton, SIGNAL (clicked()), this, SLOT (attackHandler()));
    connect(takeButton, SIGNAL (clicked()), this, SLOT (takeHandler()));
    connect(weaponButton, SIGNAL (clicked()), this, SLOT (weaponHandler()));
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

void PlayWindow::quitHandler() {
    close();
}

void PlayWindow::leftHandler() {
    playGame->goRoom("left");
    setRoom();
}

void PlayWindow::upHandler() {
    playGame->goRoom("up");
    setRoom();
}

void PlayWindow::rightHandler() {
    playGame->goRoom("right");
    setRoom();
}

void PlayWindow::downHandler() {
    playGame->goRoom("down");
    setRoom();
}

void PlayWindow::takeHandler() {
    if (playGame->currentRoom->numberOfItems() > 0){
        string itemName = (itemBox->currentText()).toStdString();
        Item *temp = (playGame->getCurrentRoom())->getItemByName(itemName);
        (playGame->getPlayer())->addItem(temp);
        (playGame->getCurrentRoom())->removeItem(temp);
        setRoom();
        playGame->getPlayer()->addItem(temp);
        inventory->addItem(QString::fromStdString(itemName));
    }
}

void PlayWindow::attackHandler() {
    Battle *battle = 0;

    if(playGame->me->getHealth() != 0 && playGame->currentRoom->getMonsterInRoom()->getHealth() != 0){
        battle->engageBattle(playGame);
        monHealth->show();
    }

    monHealth->setText("Monster Health: " + QString::number(playGame->currentRoom->getMonsterInRoom()->getHealth()));
    setHealth(playGame->me->getHealth());

    if(playGame->currentRoom->getMonsterInRoom()->getHealth() == 0){
        playGame->currentRoom->deleteMonsterInRoom();
        playGame->currentRoom->setNullMonster();
        attackButton->hide();
        monHealth->hide();
        monsterDead->show();
        showDirectionalButtons();
    }
    else if(playGame->me->getHealth() == 0){
        QApplication::quit();
    }
}

void PlayWindow::weaponHandler(){
    rButtons->hide();
    weaponButton->hide();
    monHealth->setText("Monster Health: " + QString::number(playGame->currentRoom->getMonsterInRoom()->getHealth()));
    monHealth->show();
    attackButton->show();
}

PlayWindow::~PlayWindow() {
    delete m_layout;
    delete inventory;
    delete mapButton;
    delete leftButton;
    delete upButton;
    delete rightButton;
    delete downButton;
    delete quitButton;
    delete attackButton;
    delete takeButton;
    delete playGame;
    delete name;
    delete health;
    delete currRoom;
    delete roomDesc;
    delete monsterDead;
    delete weaponButton;
    delete knife;
    delete sword;
    delete itemBox;
    delete map;
    delete rButtons;
    delete toolBar;

}

void PlayWindow::setName(std::string userName) {
    std::string nameText = "Name: " + userName;
    name->setText(QString::fromStdString(nameText));
}

void PlayWindow::setRoom() {
    std::string roomText = "Room: " + playGame->currentRoom->getName();
    currRoom->setText(QString::fromStdString(roomText));
    roomDesc->setText(QString::fromStdString(playGame->currentRoom->longDescription()));
    displayRoomItems();
    showDirectionalButtons();
    monsterDead->hide();
    if((playGame->getCurrentRoom())->getMonsterInRoom() != NULL){
        hideDirectionalButtons();
        setRadioButtons();
    }
    else if(playGame->currentRoom->getLast() == true){
        fw = new FinalWindow;
        fw->setMinimumSize(400, 400);
        fw->show();
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
    showDirectionalButtons();
    setRoom();
    hideButtons();
}

void PlayWindow::setRadioButtons(){
    vector <Item*> items = (playGame->getPlayer())->getItemsInCharacter();
    for(vector<Item*>::iterator it = items.begin(); it != items.end(); ++it){
        if((*it)->getWeaponCheck() != false){
            if((*it)->getName() == "Knife"){
              knife->show();
            }
            else if((*it)->getName() == "Sword"){
               sword->show();
            }
        }
    }
   rButtons->show();
   weaponButton->show();
}

void PlayWindow::displayRoomItems(){
    itemBox->clear();
    vector <Item*> itemList = (playGame->getCurrentRoom())->getItemsInRoom();
    if(itemList.size() > 0){
        takeButton->show();
            for(vector<Item*>::iterator it = itemList.begin(); it != itemList.end(); ++it){
            string name = (*it)->getName();
            itemBox->addItem(QString::fromStdString(name));
        }
    }
    else{
        takeButton->hide();
        itemBox->addItem("No items in Room");
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
    monsterDead->hide();
}
