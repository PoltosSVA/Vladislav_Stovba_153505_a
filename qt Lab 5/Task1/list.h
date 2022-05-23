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


    Library(QString name) :name(name){

    }

    void set_Name(QString name){
        this->name = name;
    }



    QString get_Name(){

        return name;
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
