#include <QApplication>
#include <QVBoxLayout>
#include <string.h>
#include "finalwindow.h"

FinalWindow::FinalWindow(QWidget *parent) : QMainWindow(parent)
{
    this->setCentralWidget(new QWidget());
    layout = new QVBoxLayout;
    this->centralWidget()->setLayout(layout);

    endMessage = new QLabel(QString::fromStdString(message));
    quitButton = new QPushButton("Quit");
    quitButton->setMinimumSize(200,200);

    endMessage->setMinimumSize(100, 100);
    quitButton->setMinimumSize(50, 50);

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

void FinalWindow::setMessage(string m){
    this->message = m;
}

string FinalWindow::getMessage()const{
    return this->message;
}
