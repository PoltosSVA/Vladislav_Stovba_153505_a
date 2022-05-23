#ifndef BOOK_H
#define BOOK_H


#include <QString>
class Book
{
public:
    Book();
    Book (QString strin);
    ~Book();
    Book(int pages,int y_publish,int reg_num,QString name,QString ser_name,QString second_name,QString publishing,QString book_title);

public:
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
        this->pages = pages.toInt();
    }
    void set_y_publish(QString y_publish){
        this->y_publish = y_publish.toInt();
    }

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

        return QString::number(pages);
    }
    QString get_y_publish(){

        return QString::number(y_publish);
    }
public:


    QString all_str;

    QString name;
    QString ser_name;
    QString second_name;
    QString publishing;
    QString book_title;

    int pages;
    int y_publish;
    int reg_num;
};

#endif // BOOK_H
