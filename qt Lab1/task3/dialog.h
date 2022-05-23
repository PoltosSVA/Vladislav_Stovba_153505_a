#ifndef DIALOG_H
#define DIALOG_H

#include <QMainWindow>
#include "mainwindow.h"
namespace Ui {
class Dialog;
}

class Dialog : public QMainWindow
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();
signals:
    void dial();

private:
    Ui::Dialog *ui;
};

#endif // DIALOG_H
