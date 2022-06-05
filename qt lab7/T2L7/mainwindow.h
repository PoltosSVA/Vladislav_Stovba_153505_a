#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "unordered.h"
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

    void UpdateTable();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::MainWindow *ui;

    QStandardItemModel *table;

    Unordered_map<int, int, HashFunctor> *uomap;

    vector<int> values;
};
#endif // MAINWINDOW_H
