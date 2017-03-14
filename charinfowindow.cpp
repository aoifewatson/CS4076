#include <QCoreApplication>
#include <iostream>
#include <QLabel>
#include <string>
#include <QLineEdit>
#include <QRegExpValidator>
#include <QValidator>
#include "charinfowindow.h"
#include "playwindow.h"

using namespace std;

CharInfoWindow::CharInfoWindow(QWidget *parent)
    : QMainWindow(parent)
{
    this->setCentralWidget(new QWidget());
    textLayout = new QGridLayout();
    this->centralWidget()->setLayout(textLayout);

    err = new QLabel("");
    askName = new QLabel("What is your name?");
    askFood = new QLabel("What is your favourite food?");
    nameBox = new QLineEdit();
    foodBox = new QLineEdit();
    submitButton = new QPushButton("Submit");

    textLayout->addWidget(err,0,0,0,0);
    textLayout->addWidget(askName,0,0,1,1);
    textLayout->addWidget(nameBox,0,1,1,1);
    textLayout->addWidget(askFood,1,0,1,1);
    textLayout->addWidget(foodBox,1,1,1,1);
    textLayout->addWidget(submitButton,3,0,1,4);

    QString name = nameBox->text();
    QString food = foodBox->text();

    connect(submitButton, SIGNAL (clicked()), this, SLOT (submitHandler()));
}

void CharInfoWindow::submitHandler() {
    if(validateText(nameBox->text()) && validateText(foodBox->text())) {
        name = nameBox->text().toStdString();
        food = foodBox->text().toStdString();
        close();
        playGame = new ZorkUL(name, food);
        playGame->play();
    }
    else if (!validateText(nameBox->text()) || !validateText(foodBox->text())) {
        err->setText("Input must be 3 to 15 characters long and must be alphanumeric.");

    }
    else {
        err->setText("Invalid input.");
    }

    cout << nameBox->text().toStdString() << " " << foodBox->text().toStdString() << endl;
}

bool CharInfoWindow::validateText(QString toValidate) {
    bool valid = false;

    QRegExp rx("[A-Za-z\\s]*");
    QRegExpValidator validator(rx, 0);
    int pos = 0;
    string validText;

    if(validator.validate(toValidate, pos) && 0 != toValidate.compare("")) {
        valid = true;
    }
    return valid;

}

CharInfoWindow::~CharInfoWindow() {
    delete textLayout;
    delete nameBox;
    delete foodBox;
    delete submitButton;
    delete askName;
    delete askFood;
    delete err;
}
