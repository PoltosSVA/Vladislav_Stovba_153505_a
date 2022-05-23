#ifndef MYLIST_H
#define MYLIST_H

#include <QString>
struct Element
{
public:

//QString book;
//QString publishing;
//QString book_title;//сами данные

//int reg_number;
//int y_publishing;
//int num_pages;

//QString name;
//QString sername;
//QString secondname;

    QString data;



    Element *next; // указатели на следующий
    Element *pred; //и на предыдущий элементы списка
};
List::List()
{
    pHead = NULL;
    pPrev = NULL;
    countElem = 0;
}

List::~

class List
{
public:
    Element *pHead; // указатель на первый элемент списка
    Element *pPrev; // указатель на последний элемент списка
    int countElem; // количество элементов в списке

    List(); //конструктор
    ~List(); //деструктор

    void addToList(QString data); //функция добавки элемента (слова) в список
    void printList(); //функция вывода на экран всех элементов списка
    void delAllList(); //функция удаления всех элементов списка
    void delElem(int numb); //удаление одного элемента

};



#endif // MYLIST_H
