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
    ~CharInfoWindow();
    string getName();
    string getFood();


private slots:
    void submitHandler();
    bool validateText(QString toValidate);


private:
    ZorkUL *playGame;
    QGridLayout *textLayout;
    QLineEdit *nameBox;
    QLineEdit *foodBox;
    QPushButton *submitButton;
    QLabel *askName;
    QLabel *askFood;
    QLabel *err;
    string name;
    string food;

};

#endif
