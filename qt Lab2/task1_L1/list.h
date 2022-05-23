#ifndef LIST_H
#define LIST_H

#include <QString>
#include <QMessageBox>
#include <QDebug>


class Library;


class Node {
public:
    Library* item;

    Node* next;
    Node* prev;

    Node(Library* item);

    Library *getItem();
};

class Library {
public:
    QString name;
    QString ser_name;
    QString second_name;
    QString publishing;
    QString book_title;

    QString pages;
    QString y_publish;
    QString reg_num;

    Library(QString name,QString ser_name,QString second_name,QString publishing,QString book_title,QString pages,QString y_publish,QString reg_num) :name(name),ser_name(ser_name),
    second_name(second_name),publishing(publishing),book_title(book_title),pages(pages),y_publish(y_publish),reg_num(reg_num){

    }

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


};


class List_class {
private:
    Node* Head;
    Node* Tail;

    int List_size;

public:
    List_class();
    int List_size_public = List_size;
    bool is_empty();

    void push_begin(Library item);
    void push_back(Library *item);
    void print();
    void print(int pos);
    void insert(int pos, Library item);
    void del(int del_pos);
    void delall();
    void delete_Head_node();
    void delete_Tail_node();
    void Add();
    //void QuickSort(Node* left, Node* right);

    int size();

    //Node* partition(Node* left, Node* right);

    Node* getfront();
    Node* getback();
    Node* getitem(int pos);
    Node* search(QString item_search);
    Node& operator[](const int index);
};





#endif // LIST_H
