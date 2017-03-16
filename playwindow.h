#ifndef PLAYWINDOW_H
#define PLAYWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QHBoxLayout>
#include <QLabel>
#include <string>
#include "Command.h"
#include "ZorkUL.h"
#include "parser.h"


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
    std::string getCommand();
    void setup(std::string userName, std::string favFood);
    void startGame();

    ~PlayWindow();

private slots:
    void inventoryHandler();
    void mapHandler();
    void infoHandler();
    void quitHandler();
    void leftHandler();
    void upHandler();
    void rightHandler();
    void downHandler();

private:
    ZorkUL *playGame;
    Parser parser;
    QHBoxLayout *m_layout;
    QPushButton *inventoryButton;
    QPushButton *mapButton;
    QPushButton *leftButton;
    QPushButton *upButton;
    QPushButton *rightButton;
    QPushButton *downButton;
    QPushButton *infoButton;
    QPushButton *quitButton;
    QLabel *name;
    QLabel *health;
    QLabel *currRoom;
    std::string commandString;
};

#endif
