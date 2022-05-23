#ifndef DEQUE_H
#define DEQUE_H
#include <iostream>

template<class T>
class deque {
private:

    T** ptr;
    const int mas_len = 10; // Стандартная длина внутреннего массива содержаищего непосредственно данные
    int ptr_num; // Число указателей T*(указатели во внешнем массиве)
    int rSize; // Элементов в очереди текущее кол-вод(rSize для внутреннего массива)

    int k = 3; // Во сколько раз новый ptr_num будет больше arr_amount(тоесть просто новый массив с указателями больше предыдущего)

    int up_arr; // Индекс верхнего массива(на который указывает указатель внешнего массива)
    int begin_ = mas_len - 1; // Индекс свободного первого элемента(в частности для пуша в конец)

    int down_arr; // Индекс нижнего массива(на который указывает указатель внешнего массива)
    int end_ = 0; // Индекс свободного последнего элемента(в частности для пуша в начало


    void increase_memory() {//расширение массива
        int arr_amount = down_arr - up_arr + 1;//кол-во массивов в массиве(ну кол-во указателей в массиве указатлей как то так)

        T** new_ptr = new T * [arr_amount * k];//расширение массива указателей

        int new_up_arr = (arr_amount * k - (down_arr - up_arr)) / 2;
        int new_down_arr = new_up_arr + (down_arr - up_arr);

        for (int i = 0; i < arr_amount * k; i++) {

            new_ptr[i] = nullptr;
        }//зануляем новый масс

        for (int i = up_arr, j = new_up_arr; i <= down_arr; i++, j++)
            new_ptr[j] = ptr[i];

        delete ptr;

        ptr = new_ptr;
        ptr_num = arr_amount * k;
        up_arr = new_up_arr;
        down_arr = new_down_arr;
    }

public:

    deque() {
        ptr_num = 6;//стандарт указ во внеш мас
        rSize = 0;//текущий размер

        ptr = new T * [ptr_num];

        for (int i = 0; i < ptr_num; i++) {

            ptr[i] = nullptr;
        }

        up_arr = ptr_num / 2;
        down_arr = up_arr + 1;

        ptr[up_arr] = new T[mas_len];//иниц верхнего а ниже нижнего
        ptr[down_arr] = new T[mas_len];
    }

    ~deque() {//отсюда выходим
        for (int i = 0; i < ptr_num; i++)
            delete[] ptr[i];
        delete[] ptr;
    }

    void clear() {
        up_arr = ptr_num / 2;
        down_arr = up_arr + 1;

        begin_ = mas_len - 1;
        end_ = 0;
        rSize = 0;
    }

    void push_back(T data) {

        if (end_ < mas_len) {
            ptr[down_arr][end_] = data;
            ++end_;
            ++rSize;

        }
        else {



            if (down_arr == ptr_num - 1)
                increase_memory();

            ++down_arr;

            if (!ptr[down_arr])
                ptr[down_arr] = new T[mas_len];

            ptr[down_arr][0] = data;
            end_ = 1;
            ++rSize;

        }


    }

    void push_front(T data) {

        if (begin_ >= 0) {
            ptr[up_arr][begin_] = data;
            --begin_;
            ++rSize;
        }
        else {

            if (up_arr == 0)
                increase_memory();

            --up_arr;
            if (!ptr[up_arr])
                ptr[up_arr] = new T[mas_len];

            ptr[up_arr][mas_len - 1] = data;
            begin_ = mas_len - 2;
            ++rSize;
        }
    }

    void pop_back() {

        if (rSize) {
            if (end_ == 0) {
                --down_arr;
                end_ = mas_len - 1;
            }
            else {
                --end_;
            }
            --rSize;
        }
        else {
            //    throw(std::exception());
        }
    }

    void pop_front() {
        if (rSize) {
            if (begin_ == mas_len - 1) {
                ++up_arr;
                begin_ = 0;
            }
            else {
                ++begin_;
            }
            --rSize;
        }
        else {
            //    throw(std::exception());
        }
    }

    T& operator[](int i) {


        int index = begin_ + i+1;//push_back
        int row = index / mas_len;//
        int column = index - row * mas_len;//

        return ptr[up_arr + row][column];
    }

    int size() {
        return rSize;
    }

    T& back() {
        if (rSize)
            return operator[](rSize - 1);
        else
            throw (std::exception());
    }

    T& front() {
        if (rSize)
            return operator[](0);
        else
            throw (std::exception());
    }

    bool empty() {
        return !rSize;
    }







    class iterator {
    private:
        T** ptr;
        int mas_len;

        int row;
        int column;


            int ptr_num;

        iterator(T** ptr, int ptr_num, int mas_len, int row, int column):ptr(ptr), ptr_num(ptr_num), mas_len(mas_len),row(row),column(column){


            this->ptr = new T * [ptr_num];
            for (int i = 0; i < ptr_num; i++)
                this->ptr[i] = ptr[i];

        }

    public:

        iterator():ptr(nullptr),mas_len(0),row(0),column(0),ptr_num(0) {}

        iterator(const iterator& other) {

            mas_len = other.mas_len;
            row = other.row;
            column = other.column;
            ptr_num = other.ptr_num;

            this->ptr = new T * *[ptr_num];
            for (int i = 0; i < ptr_num; i++)
                this->ptr[i] = other.ptr[i];
        }

        friend deque;

        virtual ~iterator() {
            delete ptr;
        }

        T& operator*() {
            return ptr[row][column];
        }

        iterator& operator+(int n) {
            int index = column + n;
            int new_row = index / mas_len;
            int new_column = index - new_row * mas_len;

            row += new_row;
            column = new_column;

            return *this;
        }

        iterator& operator-(int n) {
            int index = column - n;
            int new_row = index / mas_len;



            int new_column = index - new_row * mas_len;
            if (new_column < 0) {
                new_row--;
                new_column = index - new_row * mas_len;
            }
            row += new_row;

            column = new_column;

            return *this;
        }

        iterator& operator++() {
            return operator+(1);
        }

        iterator& operator--() {
            return operator-(1);
        }

        iterator& operator=(const iterator& other) {

            mas_len = other.mas_len;
            row = other.row;
            column = other.column;
            ptr_num = other.ptr_num;

            T** new_ptr = new T * [ptr_num];

            for (int i = 0; i < ptr_num; i++)
                new_ptr[i] = other.ptr[i];

            T** del = ptr;

            ptr = new_ptr;

            delete del;

            return *this;
        }

        iterator& operator+=(int n) {
            *this = *this + n;
            return *this;
        }

        iterator& operator-=(int n) {
            *this = *this - n;
            return *this;
        }

        bool operator==(const iterator& other) {
            return &ptr[row][column] == &(other.ptr[other.row][other.column]);
        }

        bool operator!=(const iterator& other) {
            return !operator==(other);
        }
    };

    iterator begin() {
        int index = begin_ + 0 + 1;
        int row = index / mas_len;
        int column = index - row * mas_len;

        return iterator(ptr, ptr_num, mas_len, up_arr + row, column);
    }

    iterator end() {
        int index = begin_ + rSize + 1;
        int row = index / mas_len;
        int column = index - row * mas_len;

        return iterator(ptr, ptr_num, mas_len, up_arr + row, column);
    }



};
#endif // DEQUE_H
