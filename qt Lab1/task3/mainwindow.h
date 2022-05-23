#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "date.h"

#include <QMainWindow>
#include <QFileDialog>
#include <QFile>
#include <QDebug>
#include <QTextStream>
#include <QList>
#include <QStandardItemModel>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    bool Fail_deff(QString sof);
    void show_Error();


private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    //void CheckFunc(QString mas);

    void EditFile(Date New_Date, int NumToChange);

    void Add_Date();

private:
     void LoadFromFile(QFile &File);
     Date* fCheck(Date *date,int,int&);
private:
    Ui::MainWindow *ui;

    QString str;

    int MasSize = 40;
    int rSize=0;


};
#endif // MAINWINDOW_H
