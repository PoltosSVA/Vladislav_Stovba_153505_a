#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    Ojb.push_back(ui->spinBox->value());

    rSize++;


    for(int i=0;i<rSize;i++){
        text += QString::number(Ojb[i]);
    }

    ui->textEdit->setPlainText(text);
    text="";
}


void MainWindow::on_pushButton_2_clicked()
{
    Ojb.push_front(ui->spinBox->value());
    rSize++;

    for(int i=0;i<rSize;i++){
        text += QString::number(Ojb[i]);
    }

    ui->textEdit->setPlainText(text);
    text="";
}


void MainWindow::on_pushButton_3_clicked()
{

    Ojb.pop_back();
    rSize--;

    for(int i=0;i<rSize;i++){
        text += QString::number(Ojb[i]);
    }

    ui->textEdit->setPlainText(text);
    text="";
    if(text==""){
        return;
    }

    vs9 = ui->textEdit->toPlainText();
    if(vs9==""){
        return;
    }
}


void MainWindow::on_pushButton_4_clicked()
{
    Ojb.pop_front();
    rSize--;

    for(int i=0;i<rSize;i++){
        text += QString::number(Ojb[i]);
    }

    ui->textEdit->setPlainText(text);
    text="";

    if(text==""){
        return;
    }
    vs9 = ui->textEdit->toPlainText();
    if(vs9==""){
        return;
    }
}

