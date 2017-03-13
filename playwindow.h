#ifndef PLAYWINDOW_H
#define PLAYWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QHBoxLayout>

namespace Ui {
    class PlayWindow;
}

class PlayWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit PlayWindow(QWidget *parent = 0);
private slots:
    void inventoryHandler();
    void mapHandler();
    void infoHandler();
    void quitHandler();
    //void leftHandler();
    //void upHandler();
    //void rightHandler();
    //void downHandler();

private:
    QHBoxLayout * m_layout;
    QPushButton *inventoryButton;
    QPushButton *mapButton;
    QPushButton *leftButton;
    QPushButton *upButton;
    QPushButton *rightButton;
    QPushButton *downButton;
    QPushButton *infoButton;
    QPushButton *quitButton;


};

#endif