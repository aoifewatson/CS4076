
#include "finalwindow.h"

FinalWindow::FinalWindow(QWidget *parent) : QMainWindow(parent)
{
    endMessage = new QLabel("You have finished the game!");
    quitButton = new QPushButton("Quit");

    connect(quitButton, SIGNAL (clicked()), this, SLOT (quitHandler()));

}

void FinalWindow::quitHandler(){
    close();
}

FinalWindow::~FinalWindow(){
    delete endMessage;
    delete quitButton;
}
