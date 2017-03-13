#ifndef CHARINFOWINDOW_H
#define CHARINFOWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QHBoxLayout>
#include <QFormLayout>
#include <QLineEdit>
#include <QLabel>
#include "playwindow.h"

namespace Ui {
    class CharInfoWindow;
}

class CharInfoWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit CharInfoWindow(QWidget *parent = 0);
private slots:
    void submitHandler();
    bool validateText(QString toValidate);


private:
    PlayWindow *playWin;
    QGridLayout *textLayout;
    QLineEdit *nameBox;
    QLineEdit *foodBox;
    QPushButton *submitButton;
    QLabel *askName;
    QLabel *askFood;
    QLabel *err;

};

#endif
