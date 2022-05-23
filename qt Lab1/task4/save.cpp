#include "save.h"
#include "ui_save.h"
#include "mainwindow.h"
#include <QMessageBox>
Save::Save(QWidget *parent, Book *booklist, int *countbooklist) :
    QMainWindow(parent),
    ui(new Ui::Save),
    book_list(booklist),
    count_book_list(countbooklist),
    name_(QRegularExpression("^[A-Z][a-z]{2,17}")),
    sername_(QRegularExpression("^[A-Z][a-z]{2,17}")),

    secondname_(QRegularExpression("^[A-Z][a-z]{2,17}")),

    publishing_(QRegularExpression("^[A-Z][a-z]{2,17}")),

    booktitle_(QRegularExpression("^[A-Z][a-z]{2,17}"))
{
    ui->setupUi(this);

    ui->Name->setValidator(&name_);
    ui->Second->setValidator(&secondname_);
    ui->sername->setValidator(&sername_);
    ui->IZD->setValidator(&publishing_);
    ui->NAZV->setValidator(&booktitle_);

    ui->Stran->setRange(1,10000);
    ui->Date->setRange(1564,2022);

}

Save::~Save()
{
    delete ui;
}


QString Save::return_name()
{
    QString str;
    str=ui->Name->text();
    return  str;
}

QString Save::return_ser_name()
{
    QString str;
    str=ui->sername->text();
    return  str;
}

QString Save::return_second_name()
{
    QString str;
    str=ui->Second->text();
    return  str;
}

QString Save::return_publishing()
{
    QString str;
    str=ui->IZD->text();
    return  str;
}

QString Save::return_book_title()
{
    QString str;
    str=ui->NAZV->text();
    return  str;
}

QString Save::return_pages()
{
    QString str;
    str=ui->Stran->text();
    return  str;
}

QString Save::return_y_publish()
{
    QString str;
    str=ui->Date->text();
    return  str;
}

void Save::saveslot()
{

}

void Save::on_pushButton_clicked()
{
    if(return_name()==""||return_second_name()==""||return_ser_name()==""||return_publishing()==""||return_book_title()==""){
            QMessageBox::critical(this,"Error","Присутствуют пустые поля");
            return;
        }

        book_list[*count_book_list-1].set_Name(return_name());
        book_list[*count_book_list-1].set_ser_name(return_ser_name());
        book_list[*count_book_list-1].set_second_name(return_second_name());
        book_list[*count_book_list-1].set_book_title(return_book_title());
        book_list[*count_book_list-1].set_publishing(return_publishing());
        book_list[*count_book_list-1].set_pages(return_pages());
        book_list[*count_book_list-1].set_y_publish(return_y_publish());



        emit Savetable();
        emit sign();

        close();


}

