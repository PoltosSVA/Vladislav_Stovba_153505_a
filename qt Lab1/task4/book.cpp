#include "book.h"

Book::Book()
{

}

Book::Book(QString strin):all_str(strin)
{

}

Book::~Book()
{

}

Book::Book(int pages, int y_publish, QString name, QString ser_name, QString second_name, QString publishing, QString book_title) :
    pages(pages),y_publish(y_publish),name(name),ser_name(ser_name),second_name(second_name),publishing(publishing),book_title(book_title)
{

}
QString Book::toStr_name()
{
    QString str;

    str=this->name +"."+this->ser_name+"."+this->second_name;

    return str;
}

QString Book::toStr_publishing()
{
    QString str;

    str= this->publishing;
    return str;
}

QString Book::toStr_book_title()
{
    QString str;

    str= this->book_title;
    return str;
}

QString Book::toStr_pages()
{
    QString str;
    str=QString::number(this->pages);
    return str;
}

QString Book::toStr_y_publish()
{
    QString str;
    str=QString::number(this->y_publish);
    return str;
}
