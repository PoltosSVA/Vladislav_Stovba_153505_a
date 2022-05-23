#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <sstream>
using namespace std;
template<class T>
string tran(T& lhs) {
    ostringstream oss;
    oss << lhs.get();
    string str = oss.str();
    return str;
}
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    table = new QStandardItemModel(10,2,this);

    table->setHeaderData(0,Qt::Horizontal,"Указатель");
    table->setHeaderData(1,Qt::Horizontal,"Значение");

    arr[0] = new int(1);
    for(int i = 0 ; i < 9 ; i++ ){
        arr[i + 1] = arr[i];
    }
    for(int i = 0; i < 10;i++){
        table->setData( table->index(i,0), QString::fromStdString(tran(arr[i])));
        table->setData( table->index(i,1), QString::number(arr[i].use_count()));

    }

    for (int i = 0; i < table->rowCount(); i++)//блокировка полей
        for (int j = 0; j < table->columnCount(); j++)
            table->item(i, j)->setEditable(false);
    ui->spinBox_3->setRange(1,10);
    ui->spinBox_6->setRange(1,10);
    ui->spinBox_7->setRange(1,10);
    ui->spinBox_8->setRange(1,10);
    ui->spinBox_9->setRange(1,10);
     ui->tableView->setModel(table);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_2_clicked()
{
        int choose = ui->spinBox_3->value()-1;

        if(arr[choose].get()!=nullptr){
            arr[choose] = new int();
        }


    for(int i = 0; i < 10;i++){
        table->setData(table->index(i,0) , QString::fromStdString(tran(arr[i])));


        if(arr[i].get()==nullptr){
            table->setData(table->index(i,1) , "empty");

        }
        else{
            table->setData( table->index(i,1), QString::number(arr[i].use_count()));

        }
    }
}


void MainWindow::on_pushButton_4_clicked()
{
    int choose= ui->spinBox_6->value()-1;
    int choose1= ui->spinBox_7->value()-1;

        arr[choose] = arr[choose1];


        for(int i = 0; i < 10;i++){
            table->setData(table->index(i,0) , QString::fromStdString(tran(arr[i])));


            if(arr[i].get()==nullptr){
                table->setData(table->index(i,1) , "empty");

            }
            else{
                table->setData( table->index(i,1), QString::number(arr[i].use_count()));

            }
        }
}


void MainWindow::on_pushButton_5_clicked()
{
    int choose= ui->spinBox_8->value()-1;
    int choose1= ui->spinBox_9->value()-1;

    arr[choose].swap(arr[choose1]);

    for(int i = 0; i < 10;i++){
        table->setData(table->index(i,0) , QString::fromStdString(tran(arr[i])));


        if(arr[i].get()==nullptr){
            table->setData(table->index(i,1) , "empty");

        }
        else{
            table->setData( table->index(i,1), QString::number(arr[i].use_count()));

        }
    }

}

