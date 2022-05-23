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

template<class T>
string tran(weak<T>& lhs) {
    ostringstream oss;
    oss << lhs.getweak();
    string str = oss.str();
    return str;
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    table1 = new QStandardItemModel(10,3,this);

    table1->setHeaderData(0,Qt::Horizontal,"Указатель");
    table1->setHeaderData(1,Qt::Horizontal,"Значение");
    table1->setHeaderData(2,Qt::Horizontal,"Кол-во Weak");

    table = new QStandardItemModel(10,2,this);

    table->setHeaderData(0,Qt::Horizontal,"Указатель");
    table->setHeaderData(1,Qt::Horizontal,"Значение");

    arr[0] = new int(1);
    for(int i = 0 ; i < 9 ; i++ ){
        arr[i + 1] = arr[i];
    }
    for(int i = 0;i <10;i++){
        woo[i] = arr[i];
    }


    for(int i = 0; i < 10;i++){

        table->setData( table->index(i,0), QString::fromStdString(tran(arr[i])));
        table->setData( table->index(i,1), QString::number(arr[i].use_count()));


        table1->setData( table1->index(i,0), QString::fromStdString(tran(woo[i])));
        table1->setData( table1->index(i,1), QString::number(woo[i].refcount()));
        table1->setData( table1->index(i,2), QString::number(woo[i].count()));

    }


    ui->spinBox->setRange(1,10);
    ui->spinBox_2->setRange(1,10);
    ui->spinBox_4->setRange(1,10);
    ui->spinBox_5->setRange(1,10);
    ui->spinBox_8->setRange(1,10);
    ui->spinBox_9->setRange(1,10);
    ui->spinBox_3->setRange(1,10);
    ui->spinBox_6->setRange(1,10);
    ui->spinBox_7->setRange(1,10);


     ui->tableView->setModel(table);

     ui->tableWeak->setModel(table1);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_weak_to_weak_clicked()
{

    int choose = ui->spinBox->value()-1;
    int choose1 = ui->spinBox_2->value()-1;
     woo[choose1] = woo[choose];


     for(int i = 0; i < 10;i++){
         table->setData( table->index(i,0), QString::fromStdString(tran(arr[i])));
         if(arr[i].get()==nullptr){
            table->setData(table->index(i,1) , "empty");
         }
         else{
             table->setData( table->index(i,1), QString::number(arr[i].use_count()));
             table1->setData( table1->index(i,0), QString::fromStdString(tran(woo[i])));
             table1->setData( table1->index(i,2), QString::number(woo[i].count()));
               table1->setData( table1->index(i,1), QString::number(woo[i].refcount()));
         }
     }
}


void MainWindow::on_shared_to_weak_clicked()
{
    int choose = ui->spinBox_4->value()-1;
    int choose1 = ui->spinBox_5->value()-1;
    woo[choose]=arr[choose1];

    for(int i = 0; i < 10;i++){
        table->setData( table->index(i,0), QString::fromStdString(tran(arr[i])));
        if(arr[i].get()==nullptr){
           table->setData(table->index(i,1) , "empty");
        }
        else{
            table->setData( table->index(i,1), QString::number(arr[i].use_count()));
            table1->setData( table1->index(i,0), QString::fromStdString(tran(woo[i])));
            table1->setData( table1->index(i,2), QString::number(woo[i].count()));
              table1->setData( table1->index(i,1), QString::number(woo[i].refcount()));
        }
    }
}


void MainWindow::on_weak_to_shared_clicked()
{

    int choose = ui->spinBox_8->value()-1;
    int choose1 = ui->spinBox_9->value()-1;

    arr[choose1] = woo[choose].Lock();

    for(int i = 0; i < 10;i++){
        table->setData( table->index(i,0), QString::fromStdString(tran(arr[i])));
        if(arr[i].get()==nullptr){
           table->setData(table->index(i,1) , "empty");
        }
        else{
            table->setData( table->index(i,1), QString::number(arr[i].use_count()));
            table1->setData( table1->index(i,0), QString::fromStdString(tran(woo[i])));
            table1->setData( table1->index(i,2), QString::number(woo[i].count()));
              table1->setData( table1->index(i,1), QString::number(woo[i].refcount()));
        }
    }
}


void MainWindow::on_pushButton_2_clicked()
{

    int choose = ui->spinBox_3->value()-1;
    if(arr[choose].get()!=nullptr){
        arr[choose] = new int();
    }


    for(int i = 0; i < 10;i++){
        table->setData( table->index(i,0), QString::fromStdString(tran(arr[i])));
        if(arr[i].get()==nullptr){
           table->setData(table->index(i,1) , "empty");
        }
        else{
            table->setData( table->index(i,1), QString::number(arr[i].use_count()));
            table1->setData( table1->index(i,0), QString::fromStdString(tran(woo[i])));
            table1->setData( table1->index(i,2), QString::number(woo[i].count()));
              table1->setData( table1->index(i,1), QString::number(woo[i].refcount()));
        }
    }
}


void MainWindow::on_pushButton_4_clicked()
{

    int choose = ui->spinBox_6->value()-1;
    int choose1=ui->spinBox_7->value()-1;

    arr[choose] = arr[choose1];

    for(int i = 0; i < 10;i++){
        table->setData( table->index(i,0), QString::fromStdString(tran(arr[i])));
        if(arr[i].get()==nullptr){
           table->setData(table->index(i,1) , "empty");
        }
        else{
            table->setData( table->index(i,1), QString::number(arr[i].use_count()));
            table1->setData( table1->index(i,0), QString::fromStdString(tran(woo[i])));
            table1->setData( table1->index(i,2), QString::number(woo[i].count()));
              table1->setData( table1->index(i,1), QString::number(woo[i].refcount()));
        }
    }
}

