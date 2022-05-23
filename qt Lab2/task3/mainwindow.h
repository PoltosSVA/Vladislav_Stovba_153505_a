#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QDebug>
#include <QStandardItemModel>
#include <QRegularExpressionValidator>
#include "Mass.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow;
             }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    void refresh_table();
    void KAVO();
    QString check(QString str);
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    double Res(QString str);
    bool isCorrect();

private slots:


    void on_pushButton_2_clicked();

public:
    Ui::MainWindow *ui;
    double mas[300];
    QStandardItemModel* table;
    int rSize = 15;
    int MaxSize = 10000;
    Mass* mass;
    int error=0;
    QRegularExpressionValidator name__;
    QRegularExpressionValidator sername__;
    QRegularExpressionValidator secondname__;
    QRegularExpressionValidator publishing__;
    QRegularExpressionValidator booktitle__;

public:

    QString return_name();
    QString return_a();
    QString return_b();
    QString return_c();
    QString return_d();
    QString return_e();
    QString return_result();
    void Translate();



};


template <typename T>
class Stack:public MainWindow
{
public:

    struct Node{
      T data;//поле данных
      Node *next;//указатель на следующий

    };
    Node* root;//указатель на ввершину стека

public:



    Stack(): root(NULL){}//по умолчанию стек пустой
    //+
    void push(const T& x){//для типа стринг 1 в икс потом в стек

        Node* newNode= new Node;
        newNode->data = x;
        newNode->next=root;
        root=newNode;
    }



    //+
    bool empty() const{
        return root == NULL;
    }


   //+
   const T& top()const{

        if(empty()){
            QMessageBox::critical(0,"Error","Заполните форму");


        }
        return root->data;
    }



   //+
    T pop(){//
        if(empty()){
            QMessageBox::critical(0,"Error","Заполните форму");

        }
        Node* delNode=root;//запоминаем узел который удаляем
        T x = delNode->data;
        root = delNode->next;//рут теперь следующий за удаляемым
        delete delNode;
        return x;
    }








};



#endif // MAINWINDOW_H
