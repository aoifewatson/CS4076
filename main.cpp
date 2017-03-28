#include <iostream>
#include <QApplication>
#include "Character.h"
#include "item.h"
#include "mainwindow.h"
#include "ZorkUL.h"

using namespace std;

int main(int argc, char **argv) {
    QApplication app(argc, argv);

    MainWindow mainWin;
    mainWin.setFixedSize(400,400);
    mainWin.show();

    app.exec();

    return 0;
}
