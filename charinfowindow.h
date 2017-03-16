#ifndef CHARINFOWINDOW_H
#define CHARINFOWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QHBoxLayout>
#include <QFormLayout>
#include <QLineEdit>
#include <QLabel>
#include <string>
#include "playwindow.h"
#include "ZorkUL.h"

namespace Ui {
    class CharInfoWindow;
}

class CharInfoWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit CharInfoWindow(QWidget *parent = 0);
    string getName();
    string getFood();
    ~CharInfoWindow();

private slots:
    void submitHandler();
    bool validateText(QString toValidate);


private:
    //ZorkUL *playGame;
    PlayWindow *playWin;
    QGridLayout *textLayout;
    QLineEdit *nameBox;
    QLineEdit *foodBox;
    QPushButton *submitButton;
    QLabel *askName;
    QLabel *askFood;
    QLabel *err;
    std::string name;
    std::string food;

};

#endif
