#ifndef PLAYWINDOW_H
#define PLAYWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QHBoxLayout>
#include <QLabel>
#include <QToolBar>
#include <QRadioButton>
#include <QVBoxLayout>
#include <QGroupBox>
#include <QComboBox>
#include <QString>
#include "ZorkUL.h"
#include "finalwindow.h"
#include "battle.h"

namespace Ui {
    class PlayWindow;
}

class PlayWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit PlayWindow(QWidget *parent = 0);
    void setName(std::string userName);
    void setRoom();
    void setHealth(int newHealth);
    string getCommand();
    void setup(string userName, string favFood);
    void setRadioButtons();
    void displayRoomItems();
    void hideButtons();
    void showFinalWindow(string message);

private:
    void hideDirectionalButtons();
    void showDirectionalButtons();
    void noWeapon();

    ~PlayWindow();

private slots:
    void mapHandler();
    void quitHandler();
    void attackHandler();
    void takeHandler();
    void weaponHandler();
    void weaponSelected(QString weapon);
    void directionSelected(QString direction);


private:
    ZorkUL *playGame;
    QVBoxLayout *m_layout;
    QComboBox *inventory;
    QPushButton *mapButton;
    QPushButton *leftButton;
    QPushButton *upButton;
    QPushButton *rightButton;
    QPushButton *downButton;
    QPushButton *quitButton;
    QLabel *name;
    QLabel *health;
    QLabel *currRoom;
    QLabel *roomDesc;
    QLabel *monsterDead;
    QLabel *monHealth;
    QPushButton *attackButton;
    QPushButton *weaponButton;
    QRadioButton *knife;
    QRadioButton *sword;
    QPushButton *takeButton;
    QComboBox *itemBox;
    QLabel *map;
    bool showMap;
    QGroupBox *rButtons;
    QVBoxLayout *rLayout;
    QToolBar *toolBar;
    FinalWindow * fw;
    Battle *battle;

};


#endif
