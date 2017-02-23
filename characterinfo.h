#ifndef CHARACTERINFO_H
#define CHARACTERINFO_H

#include <QMainWindow>
#include <QPushButton>
#include <QTextEdit>

using namespace std;

namespace Ui {
    class CharacterInfo;
}

class CharacterInfo : public QMainWindow
{
    Q_OBJECT
public:
    explicit CharacterInfo(QWidget *parent = 0);
private slots:
    bool validateText(string);
private:
    QPushButton *confirmButton;
    QTextEdit *askName;
};

#endif
