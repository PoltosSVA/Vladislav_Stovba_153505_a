#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
#include <cmath>


template<typename T>
class HashTable {
private:
    const int stackSize = 10;

    std::stack<T> *mas;
    int size;
    int MaxSize;

public:
    int HashFunc(int k, int N)
    {

        if(k<0){
            k = -k;
        }
        else{
            k=k*1;
        }

        double A=0.618033;

        int h= N*fmod(k*A, 1);

        return h;
    }

    HashTable() {

        MaxSize = stackSize;

        size = 0;

        mas = new std::stack<T>[MaxSize];
    }

    ~HashTable() {
        delete[] mas;
    }

    void Resize() {

        int oldMax = MaxSize;

        MaxSize *= 2;

        size = 0;

        auto mas2 = new std::stack<T>[MaxSize];

        std::swap(mas, mas2);

        for(int i = 0; i < oldMax; ++i) {

            while(!mas2[i].empty()) {


                this->insert(mas2[i].top());

                mas2[i].pop();
            }
        }

        delete[] mas2;
    }

    bool Find(const T& value) {

        int h = HashFunc(value, MaxSize);

        std::stack<T> temp = mas[h];

        while(!temp.empty()) {

            if(temp.top() == value) {

                return true;
            }

            temp.pop();
        }

        return false;
    }

    bool Remove(const T& value) {

        int h = HashFunc(value, MaxSize);

        std::stack<T> temp = mas[h];

        std::vector<T> vec;

        int i = 0;

        while(!temp.empty()) {

            if(temp.top() == value) {

                temp.pop();

                std::reverse(vec.begin(), vec.end());

                for(auto o : vec) {

                    temp.push(o);
                }

                std::swap(temp, mas[h]);

                size--;

                return true;
            }

            vec.push_back(temp.top());

            temp.pop();

            i++;
        }

        return false;
    }

    bool insert(const T& value) {

        if (this->Find(value)){
            return false;
        }


        if(size + 1 > int(0.8 * MaxSize)) {

            Resize();

        }

        int h = HashFunc(value, MaxSize);



        mas[h].push(value);//в стек

        size++;

        return true;
    }

    auto Getmas() {
        return mas;
    }

    size_t GetCapacity() {
        return MaxSize;
    }

    size_t GetSize() {
        return size;
    }

};

#endif // HASHTABLE_H
