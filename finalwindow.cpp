#include <QApplication>
#include <QVBoxLayout>
#include "finalwindow.h"

FinalWindow::FinalWindow(QWidget *parent) : QMainWindow(parent)
{
    this->setCentralWidget(new QWidget());
    layout = new QVBoxLayout;
    this->centralWidget()->setLayout(layout);

    endMessage = new QLabel("You have finished the game!");
    quitButton = new QPushButton("Quit");
    quitButton->setMinimumSize(200,200);

    endMessage->show();
    quitButton->show();

    layout->addWidget(endMessage);
    layout->addWidget(quitButton);

    connect(quitButton, SIGNAL (clicked()), this, SLOT (quitHandler()));

}

void FinalWindow::quitHandler(){
    QApplication::quit();
}

FinalWindow::~FinalWindow(){
    delete endMessage;
    delete quitButton;
    delete layout;
}
