#include "characterinfo.h"
#include <QApplication>
#include <QTextEdit>
#include <string>

CharacterInfo::CharacterInfo(QWidget *parent)
    : QMainWindow(parent)
{
    askName = new QTextEdit();
    askName->setText("What is your name?");
}

bool CharacterInfo::validateText(string text)
{
    return true;
}
