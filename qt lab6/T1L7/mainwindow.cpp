#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMessageBox>
using namespace std;


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    table = new QStandardItemModel(count,2,this);
    table->setHeaderData(0,Qt::Horizontal,"Ключ");
    table->setHeaderData(1,Qt::Horizontal,"Число");

    ui->tableView->setModel(table);

}



MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_pushButton_8_clicked()
{

    int a  = ui->spinBox->value();
    int b  = ui->spinBox_2->value();

    tree.insert(make_pair(a,b));

     std::cout<<"\n\n\n\n\n";
    tree.disp();


}


void MainWindow::on_pushButton_clicked()
{

    tree.preorder(tree.root);

    std::cout<<"\n\n\n\n\n";
}


void MainWindow::on_pushButton_2_clicked()
{
    tree.postorder(tree.root);

    std::cout<<"\n\n\n\n\n";
}


void MainWindow::on_pushButton_3_clicked()
{
    tree.inorder(tree.root);

    std::cout<<"\n\n\n\n\n";
}


void MainWindow::on_pushButton_5_clicked()
{

        tree.Remove(ui->spinBox_3->value());

     std::cout<<"\n\n\n\n\n";

    tree.disp();

}





void MainWindow::on_pushButton_7_clicked()
{

    QString strok = QString::number(tree.Count_Nodes());
    ui->textEdit->setPlainText(strok);
}

