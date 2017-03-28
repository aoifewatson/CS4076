#ifndef FINALWINDOW_H
#define FINALWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>

class FinalWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit FinalWindow(QWidget *parent = 0);
    ~FinalWindow();

signals:

public slots:
    void quitHandler();

private:
    QVBoxLayout *layout;
    QLabel *endMessage;
    QPushButton *quitButton;
};

#endif // FINALWINDOW_H
