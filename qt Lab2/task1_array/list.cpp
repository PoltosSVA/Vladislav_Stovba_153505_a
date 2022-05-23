#include "list.h"


ArrayList::ArrayList() {
    array = nullptr;

    head = -1;
    tail = -1;
    real_size = 0;
    capacity = 0;
}


void ArrayList::push_back(Work* item) {
    array = (Node*)realloc(array, ++capacity * sizeof(Node));
    array[capacity - 1].item = item;
    array[capacity - 1].next = -1;

    if(tail != -1) {
        array[tail].next = capacity - 1;
        array[capacity - 1].prev = tail;
        tail = capacity - 1;
    }
    else {
        tail = 0;
        array[tail].next = -1;
        array[tail].prev = -1;
        head = 0;
        array[head].prev = -1;
        array[head].next = -1;
    }

    real_size++;
}


void ArrayList::push_front(Work* item) {
    array = (Node*)realloc(array, ++capacity * sizeof(Node));
    array[capacity - 1].item = item;

    if (head != -1) {
        array[capacity - 1].prev = -1;
        array[capacity - 1].next = head;
        array[head].prev = capacity - 1;
        head = capacity - 1;

    }
    else {
        tail = 0;
        array[tail].next = -1;
        array[tail].prev = -1;
        head = 0;
        array[head].prev = -1;
        array[head].next = -1;
    }

    real_size++;
}


void ArrayList::pop_front() {
    if (real_size == 0)
        return;
    else if (real_size == 1) {
        tail = -1;
        head = -1;
        real_size = 0;
        free(array);
        array = nullptr;
        capacity = 0;
        return;
    }

    int head_next = array[head].next;
    array[head_next].prev = -1;
    head = head_next;

    real_size--;
}


void ArrayList::pop_back() {
    if (real_size == 0)
        return;
    else if (real_size == 1) {
        tail = -1;
        head = -1;
        real_size = 0;
        free(array);
        array = nullptr;
        capacity = 0;
        return;
    }

    int tail_prev = array[tail].prev;
    array[tail_prev].next = -1;
    tail = tail_prev;

    real_size--;
}


void ArrayList::eraseall() {
    head = -1;
    tail = -1;
    real_size = 0;
    free(array);
    array = nullptr;
    capacity = 0;
}


void ArrayList::print() {

    int index = head;

   // std::cout << "\n";
    while (index != -1) {
     //   std::cout << array[index].data << " ";
        index = array[index].next;
    }
}


void ArrayList::erase(int pos) {
    pos--;
    if (pos > real_size - 1 || pos < 0) {
     //   std::cout << "Incorrect input" << std::endl;
        return;
    }

    if (pos == 0) {
        pop_front();
        return;
    }
    else if (pos == real_size - 1) {
        pop_back();
        return;
    }

    int del = head;

    for (int i = 0; i < pos; i++) {
        del = array[del].next;
    }

    int prev_del = array[del].prev;
    int next_del = array[del].next;

    array[prev_del].next = next_del;
    array[next_del].prev = prev_del;

    real_size--;
}


void ArrayList::insert(int pos, Work* item) {
    pos--;

    if (pos < 0 || pos > real_size + 1)
        return;

    if (pos == 0) {
        push_front(item);
        return;
    }
    if (pos == real_size) {
        push_back(item);
        return;
    }

    array = (Node*)realloc(array, ++capacity * sizeof(Node));

    int ins = head;
    for (int i = 0; i < pos; i++) {
        ins = array[ins].next;
    }

    int ins_prev = array[ins].prev;

    array[ins_prev].next = capacity - 1;
    array[ins].prev = capacity - 1;

    array[capacity - 1].item = item;
    array[capacity - 1].prev = ins_prev;
    array[capacity - 1].next = ins;

    real_size++;
}



bool ArrayList::is_empty() {
    return real_size == 0;
}

int ArrayList::size() {
    return real_size;
}

Node* ArrayList::back() {

    return &array[tail];
}

Node* ArrayList::front() {

    return &array[head];
}

Work* ArrayList::operator[](const int index) {
   // if (is_empty())
       // return nullptr;

    int p = head;
    for (int i = 0; i < index; i++) {
        p = array[p].next;

        //if (!p)
            //return nullptr;
    }

    return array[p].item;
}

Node::Node(Work *item):item(item)
{

}
