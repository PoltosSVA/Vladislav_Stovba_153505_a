#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStandardItemModel>
#include "binary.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


public:
    Tree<int,int> tree;

private slots:
    void on_pushButton_8_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_5_clicked();



    void on_pushButton_7_clicked();

private:



    std::vector<int> valueMas;
    std::vector<int> KeyMas;



    QStandardItemModel* table;
    int count=0;

    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
