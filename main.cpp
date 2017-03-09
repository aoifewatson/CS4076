#include <iostream>
#include <QApplication>
#include "Character.h"
#include "item.h"
#include "mainwindow.h"
#include "characterinfo.h"
#include "ZorkUL.h"

//Initializer list??
//Friends

using namespace std;

int main(int argc, char **argv) {
   QApplication app(argc, argv);

    MainWindow mainWin;
    mainWin.setFixedSize(400,400);
    mainWin.show();

    return app.exec();
    return 0;
}
