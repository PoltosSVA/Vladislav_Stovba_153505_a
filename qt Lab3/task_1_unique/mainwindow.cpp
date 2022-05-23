#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <sstream>
#include <string>
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


    ui->spinBox->setRange(1,10);
    ui->spinBox_3->setRange(1,10);
    ui->spinBox_5->setRange(1,10);
    ui->spinBox_6->setRange(1,10);
    ui->spinBox_8->setRange(1,10);
    ui->spinBox_9->setRange(1,10);
    ui->spinBox_2->setRange(1,99);
    ui->spinBox_4->setRange(1,99);
    ui->spinBox_7->setRange(1,99);

    table->setHeaderData(0,Qt::Horizontal,"Указатель");
    table->setHeaderData(1,Qt::Horizontal,"Значение");


    for(int i = 0; i<10;i++){

        a[i] = new int();
        arr[i].set(a[i]);
        table->setData( table->index(i,0), QString::fromStdString(tran(arr[i])));
        table->setData( table->index(i,1), QString::number(*arr[i]));


    }

    for (int i = 0; i < table->rowCount(); i++)//блокировка полей
        for (int j = 0; j < table->columnCount(); j++)
            table->item(i, j)->setEditable(false);

     ui->tableView->setModel(table);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::refresh_table()
{





    for(int i=0;i<10;i++){
        table->setData( table->index(i,0), QString::fromStdString(tran(arr[i])));
        table->setData( table->index(i,1), QString::number(*arr[i]));
    }



    qDebug()<<"table";

}

void MainWindow::on_pushButton_clicked()//move
{



    ch_box = ui->spinBox->value()-1;
    ch_box_1 = ui->spinBox_2->value()-1;
    if (arr[ch_box].get() == 0) return;



    if(ch_box != ch_box_1){
        arr[ch_box_1].move(arr[ch_box]);

        table->setData(table->index(ch_box,0) , QString::fromStdString(tran(arr[ch_box])));


        if(arr[ch_box].get()==nullptr){
            table->setData(table->index(ch_box,1) , "empty");

        }
        else{
            table->setData( table->index(ch_box,1), QString::number(*arr[ch_box]));

        }
    }


    table->setData(table->index(ch_box_1,0) , QString::fromStdString(tran(arr[ch_box_1])));
    table->setData(table->index(ch_box_1,1) , "empty");
    table->setData( table->index(ch_box_1,1), QString::number(*arr[ch_box_1]));




}




void MainWindow::on_pushButton_2_clicked()//присвоить
{
    int choose=ui->spinBox_3->value()-1;
    int num=ui->spinBox_4->value();

    if(arr[choose].get()!=nullptr){
        *arr[choose] = num;
    }
    table->setData( table->index(choose,1), QString::number(*arr[choose]));
}


void MainWindow::on_pushButton_3_clicked()
{

    int choose  = ui->spinBox_5->value()-1;
     arr[choose].release();
     table->setData(table->index(choose,0) , QString::fromStdString(tran(arr[choose])));
     table->setData(table->index(choose,1) , "empty");
}


void MainWindow::on_pushButton_4_clicked()
{

    int choose = ui->spinBox_6->value()-1;
    int num = ui->spinBox_7->value();
    arr[choose].reset(num);
    table->setData(table->index(choose,0) , QString::fromStdString(tran(arr[choose])));
    table->setData( table->index(choose,1), QString::number(*arr[choose]));
}


void MainWindow::on_pushButton_5_clicked()
{



    int choose = ui->spinBox_8->value()-1;
    int choose1 = ui->spinBox_9->value()-1;

    if (arr[choose].get() == 0) return;

\
    arr[choose].swap(arr[choose1]);

    table->setData(table->index(choose,0) , QString::fromStdString(tran(arr[choose])));


    if(arr[choose].get()==nullptr){
        table->setData(table->index(choose1,1) , "empty");

    }

    else{
        table->setData( table->index(choose,1), QString::number(*arr[choose]));

    }
    table->setData(table->index(choose1,0) , QString::fromStdString(tran(arr[choose1])));

    table->setData( table->index(choose1,1), QString::number(*arr[choose1]));


}

