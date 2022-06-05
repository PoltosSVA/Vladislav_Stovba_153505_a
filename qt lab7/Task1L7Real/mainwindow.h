#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "ft.h"
#include <QTreeWidgetItem>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    using Node = Node<int, int>;
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void UpdateTable();

    void PreOrderUpdateTable(Node* node, QTreeWidgetItem *parent);

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::MainWindow *ui;
    Tree<int, int> tree;
};
#endif // MAINWINDOW_H
