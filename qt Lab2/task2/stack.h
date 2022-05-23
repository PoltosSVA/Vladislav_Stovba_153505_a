#ifndef STACK_H
#define STACK_H
#include <QMessageBox>
#include <QDebug>
template <typename T>
class Stack
{
private:

    struct Node{
      T data;//поле данных
      Node *next;//указатель на следующий

    };
    Node* root;//указатель на ввершину стека

public:



    Stack(): root(nullptr){}//по умолчанию стек пустой
    //+
    void push(const T& x){//для типа стринг 1 в икс потом в стек

        Node* newNode= new Node;
        newNode->data = x;
        newNode->next=root;
        root=newNode;
    }


    //+
    bool empty() const{
        return root == nullptr;
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
    ~Stack(){
            while(!empty())
            {
                 pop();

            }
    }
};





//bool balanced(const QString&s) {

//    int stolb=1;
//    int strok=0;

//    Stack<QChar> stack;
//    int size = s.length();
//    for (int i = 0; i <size; i++){

//        strok++;

//        QChar c;
//        c = s[i];

//        if(c=='\n'){
//            stolb++;
//            strok = 1;
//        }

//        if(c=='('){
//            stack.push(')');


//        }
//        else if(c=='['){
//            stack.push(']');

//        }
//        else if(c=='{'){
//            stack.push('}');

//        }


//        if(c==')'||c==']'||c=='}'){
//            if (stack.empty() || stack.top() != c) {
//                ShowError(stolb,strok);
//                            return false;
//            }
//            stack.pop();

//        }


//    }
//    return stack.empty();
//}



//void test(const QString& s) {

//     QMessageBox::critical(0,"Error",(balanced(s) ? "yes\n" : "no\n"));
//}

#endif // STACK_H







