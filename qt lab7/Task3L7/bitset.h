#ifndef BITSET_H
#define BITSET_H

#include <iostream>
#include <QString>
#include <cmath>

using namespace std;

template <size_t N>
class bitset {
private:

    size_t bytes_arr[N / ((sizeof(size_t) * 8)) + 1];


    void setBit(size_t po, bool value){//Устанавливает val как значение бита в позиции pos(n)
        if (po > N)
            return;

        if (value)
            bytes_arr[po / (sizeof(size_t) * 8)] |= ((size_t)1 << (po % (sizeof(size_t) * 8)));//если вставляем 1
        else
            bytes_arr[po / (sizeof(size_t) * 8)] &= ~((size_t)1 << (po % (sizeof(size_t) * 8)));//если вставляем 0
    }

    bool getBit(size_t po){
        if (po >= N)
            return false;

        return ((bytes_arr[po / (sizeof(size_t) * 8)] & ((size_t)1 << (po % (sizeof(size_t) * 8)))));
    }


    struct BitReference {
        size_t* ptr;
        size_t pos;

        BitReference& operator=(bool v) {
            if (!v)
                *ptr &= ~((size_t)1 << pos);
            else
                *ptr |= ((size_t)1 << pos);

            return *this;
        }
    };



public:

    bitset(){
        for (int i = 0; i < N; i++) {
            setBit(i, false);
        }
    }

    void reset(){
        for (size_t i = 0; i < N; i++)
            setBit(i, false);
    }
    void reset(size_t po){
        setBit(po, false);
    }

    void set(){// все биты = 1
        for (size_t i = 0; i < N; ++i)
            setBit(i, true);
    }
    void set(size_t po){
        setBit(po, true);
    }

    void flip(){//0 = 1 1 =0
        for (size_t i = 0; i < N; i++) {
            flip(i);
        }
    }
    void flip(size_t po){
        if (getBit(po))
            setBit(po, false);
        else
            setBit(po, true);
    }

    bool all(){// смотрим все ли биты 1
        for (size_t i = 0; i < N; i++) {
            if (!getBit(i))
                return false;
        }
        return true;
    }
    bool any(){//смотрим есть ли хотя бы 1 тру
        for (size_t i = 0; i < N; i++) {
            if (getBit(i))
                return true;
        }
        return false;
    }

    size_t count(){// сколько 1
        size_t count = 0;

        for (size_t i = 0; i < N; i++) {
            if (getBit(i))
                count++;
        }
        return count;
    }
    size_t size(){//кол-во битов
        return N;
    }

    bool test(size_t po){//проверка на равенство
        return getBit(po);
    }
    bool none(){//все ли 0
        return !any();
    }


    unsigned long to_ulong(){
        if (N > sizeof(unsigned long) * 8)
            throw std::overflow_error("");

        unsigned long number = 0;

        for (size_t i = 0; i < N; ++i)
            number += getBit(i) * pow(2, i);

        return number;
    }
    unsigned long long to_ullong(){
        if (N > sizeof(unsigned long long) * 8)
            throw std::overflow_error("");

        unsigned long long number = 0;

        for (size_t i = 0; i < N; ++i)
            number += getBit(i) * pow(2, i);

        return number;
    }

    BitReference operator[] (size_t po) {
        size_t pos = po % (sizeof(size_t) * 8);
        size_t* ptr = bytes_arr + po / (sizeof(size_t) * 8);

        return BitReference{ ptr, pos };
    }

    QString to_string() {

        QString str;

        for (size_t i = 0; i < N; i++) {
            str.push_back(QString::number(getBit(N - 1 - i)));
        }

        return str;
    }
};


#endif // BITSET_H
