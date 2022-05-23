#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStandardItemModel>
#include <QFileDialog>
#include <QRegularExpressionValidator>
#include "book.h"
#include "list.h"
#include <regex>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow,public List_class
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


    QString return_name();


    QString return_ser_name();


    QString return_second_name();


    QString return_publishing();


    QString return_book_title();


    QString return_pages();


    QString return_y_publish();

    QString return_reg_num();


    void show_Error();

    bool File_deff();

    void From_table_to_Massiv();



    void metodStandart();

    QRegularExpressionValidator name__;
    QRegularExpressionValidator sername__;
    QRegularExpressionValidator secondname__;
    QRegularExpressionValidator publishing__;
    QRegularExpressionValidator booktitle__;
    QRegularExpressionValidator reg_num__;


    QRegularExpressionValidator reg_num___;
    QRegularExpressionValidator sername___;
    QRegularExpressionValidator booktitle___;
    QRegularExpressionValidator Year___;





    QString create_str();

    void set_Name(QString name){
        this->name = name;
    }
    void set_ser_name(QString ser_name){
        this->ser_name = ser_name;
    }
    void set_second_name(QString second_name){
        this->second_name = second_name;
    }
    void set_publishing(QString publishing){
        this->publishing = publishing;
    }
    void set_book_title(QString book_title){
        this->book_title = book_title;
    }
    void set_pages(QString pages){
        this->pages = pages;
    }
    void set_y_publish(QString y_publish){
        this->y_publish = y_publish;
    }
    void set_reg_num(QString reg_num){
        this->reg_num=reg_num;
    }

    void refresh_table();




    void CheckVoid();

    void Range();

    void File_Add();

    QString get_Name(){

        return name;
    }
    QString get_ser_name(){

        return ser_name;
    }
    QString get_second_name(){

         return second_name;
    }
    QString get_publishing(){

        return publishing;
    }
    QString get_book_title(){

        return book_title;
    }
    QString get_pages(){

        return pages;
    }
    QString get_y_publish(){

        return y_publish;
    }
    QString get_reg_num(){

        return reg_num;
    }

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_6_clicked();

private:
    Ui::MainWindow *ui;
    QStandardItemModel* table;
    int check_count=0;

    void FileDelete();
    List_class* BOOKS;

    int rSize=0;

    QString str;

    QString all_info;
    int MaxSize=10000;

    QString name;
    QString ser_name;
    QString second_name;
    QString publishing;
    QString book_title;
    bool vosh = false;
    QString pages;
    QString y_publish;
    QString reg_num;

};
#endif // MAINWINDOW_H
