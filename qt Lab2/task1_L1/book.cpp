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

Book::Book(int pages, int y_publish,int reg_num, QString name, QString ser_name, QString second_name, QString publishing, QString book_title) :
    name(name),ser_name(ser_name),second_name(second_name),publishing(publishing),book_title(book_title),pages(pages),y_publish(y_publish),reg_num(reg_num)
{

}
