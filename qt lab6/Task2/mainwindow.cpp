#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    table = new QStandardItemModel(0, 1, this);

    table->setHeaderData(0, Qt::Horizontal, "Строка стек");

    hashTable = new HashTable<int>();



    ui->tableView->setModel(table);

    Refresh();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    int value = ui->spinBox->value();

    hashTable->insert(value);

    values.push_back(value);



    Refresh();
}


void MainWindow::on_pushButton_2_clicked()
{

    int value = ui->spinBox_2->value();

    if(values.empty()){
        return;
    }
    hashTable->Remove(value);


    int ind=0;
    for(int i =0;i<values.size();i++){
        if(values[i]==value){
            ind = i;
            break;
        }
    }

    values.erase(values.begin()+ind);
    Refresh();
}


void MainWindow::on_pushButton_3_clicked()
{
    bool value = hashTable->Find(ui->spinBox_3->value());

    QString str;

    if(value){
        str ="true";
    }
    else{
        str = "false";
    }



    Refresh();

    ui->textEdit->setText(str);
}

void MainWindow::Refresh()
{
    QModelIndex index;

    int countRow = hashTable->GetCapacity();

    table->setRowCount(countRow);

    std::stack<int> * mas = hashTable->Getmas();

    for(int i = 0; i < countRow; ++i) {

        QString str;

        std::stack<int> temp = mas[i];

        while(!temp.empty()) {

            str += QString::number(temp.top()) + " ";

            temp.pop();
        }

        index = table->index(i, 0);

        table->setData(index, str);
    }
}


void MainWindow::on_pushButton_4_clicked()
{
    QString str;

    int min = values[0];



    for(int i =0;i<values.size();i++){

        if(values[i]<=min){
            min=values[i];
        }
    }
    str = QString::number(min);
    ui->textEdit->setText(str);
}

