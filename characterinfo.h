#ifndef CHARACTERINFO_H
#define CHARACTERINFO_H

#include <QMainWindow>
#include <QPushButton>
#include <QInputDialog>
#include <Character.h>
#include <QGridLayout>
#include <QGroupBox>
#include <QLineEdit>
#include <QDialogButtonBox>
#include <QLabel>


namespace Ui {
    class CharacterInfo;
}

class CharacterInfo : public QMainWindow {
    Q_OBJECT
    public:
        explicit CharacterInfo(QWidget *parent = 0);

    private slots:
    void submitHandler();

    private:
        QLineEdit *name;
        QPushButton *submit;

};

#endif
