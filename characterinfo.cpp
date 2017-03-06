#include "characterinfo.h"
#include <QApplication>
#include <QFormLayout>
#include <QLineEdit>

CharacterInfo::CharacterInfo(QWidget *parent)
    : QMainWindow(parent)
{   
    name = new QLineEdit;
    name->setGeometry(QRect(QPoint(100, 100),QSize(200, 50)));

    submit = new QPushButton("Submit", this);
    submit->setGeometry(QRect(QPoint(100, 200),QSize(200, 50)));


    connect(submit, SIGNAL (clicked()), this, SLOT (submitHandler()));
}

void CharacterInfo::submitHandler() {

}



