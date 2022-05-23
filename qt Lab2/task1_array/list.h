#ifndef LIST_H
#define LIST_H
#include <QString>
#include <QDebug>
//class List
//{
//public:
//    List();
//};
#define compare_function bool (*compare)(const Work* left, const Work* right)

enum Sortir{
    NAME,
    SER_NAME,
    SECOND_NAME,
    COUNTRY,
    TEAM,
    AGE,
    ROST,
    VES,
    REG_NUM
};





class Work {
public:
    QString name;
    QString ser_name;
    QString second_name;
    QString country;
    QString team;

    QString age;
    QString Rost;
    QString ves;
    QString reg_num;

    Work(QString name,QString ser_name,QString second_name,QString country,QString team,QString reg_num,QString Rost,QString ves,QString age) :name(name),ser_name(ser_name),
    second_name(second_name),country(country),team(team),age(age),Rost(Rost),ves(ves),reg_num(reg_num){

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
    void set_country(QString country){
        this->country = country;
    }
    void set_team(QString team){
        this->team = team;
    }
    void set_age(QString age){
        this->age = age;
    }
    void set_Rost(QString Rost){
        this->Rost = Rost;
    }
    void set_ves(QString ves){
        this->ves=ves;
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
    QString get_country(){

        return country;
    }
    QString get_team(){

        return team;
    }
    QString get_age(){

        return age;
    }
    QString get_Rost(){

        return Rost;
    }

    QString get_ves(){

        return ves;
    }
    QString get_reg_num(){

        return reg_num;
    }


};


class Node {
public:
    Work* item;
    int next;
    int prev;
    Node(Work* item);
};




class ArrayList {

public:
    int head;
    int tail;
    int real_size;
    int capacity;

    Node* array;
//    class SortList
//           { friend ArrayList;

//            public:


//            static bool less(const Work* left, const Work* right) {
//                return left->name < right->name;
//            }

//            static void swap(Node left, Node right) {
//                Node temp = left;
//                left = right;
//                right = temp;
//            }

//            static void qsort(Node* array, int left, int right, compare_function) {

//                int l = left;
//                int r = right;
//                Node mid = array[(l + r) / 2];

//                while (l <= r) {
//                    while (compare(array[l].item, mid.item))
//                        l++;

//                    while (compare(mid.item, array[r].item))
//                        r--;

//                    if (l <= r) {
//                        swap(array[l], array[r]);
//                        l++; r--;
//                    }
//                }

//                if (left < r)
//                    qsort(array, left, r, compare);

//                if (l < right)
//                    qsort(array, l, right, compare);

//            }
//        };


public:
    ArrayList();

    void push_back(Work* item);
    void push_front(Work* item);
    void pop_front();
    void pop_back();
    void eraseall();
    void print();
    void erase(int pos);
    void insert(int pos, Work* item);
    Work *operator [](const int index);
    //void sort(compare_function = [](const T& left, const T& right){return left < right;}) {

//    void sort(compare_function){
//                Node* sorted = (Node*)malloc(real_size * sizeof(Node));
//                qDebug()<<"xui";
//                int index = head;
//                for (int i = 0; i < real_size; i++) {
//                    sorted[i] = array[index];
//                    index = array[index].next;
//                }

//                SortList::qsort(sorted, 0, real_size - 1, compare);

//                for (int i = 0; i < real_size; i++) {
//                    sorted[i].prev = i - 1;
//                    sorted[i].next = i + 1;
//                }
//                sorted[real_size - 1].next = -1;

//                free(array);
//                head = 0;
//                tail = real_size - 1;
//                capacity = real_size;
//                array = sorted;

//            }

    bool is_empty();

    int size();

    //void QuickSort(Node* left, Node* right);
    Node* partition(Node* left, Node* right);


    Node* back();
    Node* front();

};






#endif // LIST_H
