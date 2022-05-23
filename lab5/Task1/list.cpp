#include "list.h"



Node::Node(Library* t) : item(t) {

}


Library* Node::getItem(){
    return item;
}

List_class::List_class() : Head(nullptr), Tail(nullptr), List_size(0) {

}


bool List_class::is_empty() {
    return Head == nullptr;
}


void List_class::push_begin(Library item) {
    Node* new_node = new Node(&item);

    new_node->prev = nullptr;
    new_node->next = Head;

    if (is_empty()) {
        Head = new_node;
        Tail = new_node;
        List_size++;
        return;
    }

    Head->prev = new_node;
    Head = new_node;

    List_size++;
}


void List_class::push_back(Library *item) {
    Node* new_node = new Node(item);

    new_node->next = nullptr;
    new_node->prev = Tail;

    if (is_empty()) {
        Head = new_node;
        Tail = new_node;
        List_size++;
        return;
    }

    Tail->next = new_node;
    Tail = new_node;

    List_size++;
}


void List_class::print() {
    if (is_empty()) {
        return;
    }

    Node* p = Head;
    while (p) {
        //std::cout << p->item << " ";
        p = p->next;
    }
}


void List_class::print(int pos) {
    if (is_empty()) {
        return;
    }

    if (pos < 1 || pos > List_size) {
        return;
    }

    Node* temp;

    if (pos <= List_size / 2) {
        temp = Head;

        int i = 1;
        while (i < pos)
        {
            temp = temp->next;
            i++;
        }
    }
    else {
        temp = Tail;

        int i = List_size;
        while (i > pos)
        {
            temp = temp->prev;
            i--;
        }
    }
}


void List_class::insert(int pos, Library item) {


    if (pos == List_size - 1) {
        push_back(&item);
        return;
    }
    else if (pos == 0) {
        push_begin(item);
        return;
    }


    Node* Ins = Head;
    for (int i = 0; i < pos; i++) {
        Ins = Ins->next;
    }

    Node* PrevIns = Ins->prev;
    Node* NewIns = new Node(&item);

    if (PrevIns != 0 && List_size != 1)
        PrevIns->next = NewIns;

    NewIns->next = Ins;
    NewIns->prev = PrevIns;
    Ins->prev = NewIns;

    List_size++;
}

void List_class::del(int del_pos) {
    if (del_pos < 1 || del_pos > List_size) {
        return;
    }

    Node* Del = Head;

    int i = 1;
    for (i; i < del_pos; i++) {
        Del = Del->next;
    }

    Node* AfterDel = Del->next;
    Node* BeforeDel = Del->prev;

    if (BeforeDel != nullptr && List_size != 1) {
        BeforeDel->next = AfterDel;
    }
    if (AfterDel != nullptr && List_size != i) {
        AfterDel->prev = BeforeDel;
    }

    if (del_pos == 1)
        Head = AfterDel;
    if (del_pos == List_size)
        Tail = BeforeDel;

    delete Del;

    List_size--;
}


void List_class::delall() {
    while (List_size != 0)
        del(1);
}


Node* List_class::getfront() {
    return Head;
}


Node* List_class::getback() {
    return Tail;
}


Node* List_class::getitem(int pos) {
    if (is_empty())
        return nullptr;



    Node* temp = Head;
    for (int i = 0; i < pos; i++) {
        temp = temp->next;
    }

    return temp;
}


int List_class::size() {
    return List_size;
}


void List_class::delete_Head_node() {
    if (is_empty())
        return;

    Node* p = Head;
    Head = p->next;

    List_size--;

    delete p;
}


void List_class::delete_Tail_node() {
    if (is_empty())
        return;

    Node* p = Head;
    if (Head == Tail) {
        delete_Head_node();
        return;
    }

    while (p->next != Tail)
        p = p->next;

    p->next = nullptr;

    List_size--;

    delete Tail;
    Tail = p;
}




//Node* partition(Node* left, Node* right)
//{
//    Node* pivot = right;
//    Node* i = left->prev;
//    for (Node* ptr = left; ptr != right; ptr = ptr->next)
//    {
//        if (ptr->item->name <= pivot->item->name)
//        {
//            i = (i == nullptr ? left : i->next);
//            QString temp = i->item->name;
//            i->item->name = ptr->item->name;
//            ptr->item->name = temp;
//        }
//    }
//    i = (i == nullptr ? left : i->next);
//    QString temp = i->item->name;
//    i->item->name = pivot->item->name;
//    pivot->item->name = temp;
//    return i;
//}

//void QuickSort(Node* left, Node* right){
//    if (right != nullptr && left != right && left != right->next)
//    {
//          Node* p = partition(left, right);
//       QuickSort(left, p->prev);
//       QuickSort(p->next, right);
//    }
//}



