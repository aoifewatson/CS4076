#include "characterinfo.h"
#include <QApplication>
#include <QFormLayout>
#include <QLineEdit>
#include "ZorkUL.h"

CharacterInfo::CharacterInfo(QWidget *parent)
    : QMainWindow(parent)
{   

    QLineEdit *nameTextBox = new QLineEdit();
    nameTextBox->setGeometry(QRect(QPoint(100, 100),QSize(200, 50)));

    submit = new QPushButton("Submit", this);
    submit->setGeometry(QRect(QPoint(100, 200),QSize(200, 50)));

    connect(nameTextBox, SIGNAL (textChanged(const QString&)), this, SLOT (submitHandler()));
    connect(submit, SIGNAL (clicked()), this, SLOT (submitHandler()));
}

void CharacterInfo::submitHandler() {
    ZorkUL *game = new ZorkUL();
    close();
    game->play();

}



