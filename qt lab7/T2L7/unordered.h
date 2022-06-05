#ifndef UNORDERED_H
#define UNORDERED_H


#include <iostream>
#include <forward_list>
#include <algorithm>
#include <cmath>
using namespace std;

class HashFunctor {
public:

    int operator()(int key, int N)const {
        key = key < 0 ? -key : key;

        double A = 0.618033;

        int h = N * fmod(key * A, 1);

        return h;
    }

};

template <typename Key, typename Value, typename HashF>
class Unordered_map {
private:

    static const size_t def_size_l = 16;

    constexpr static const double reh_s = 0.7;

    forward_list<pair<const Key, Value>>* array;

    size_t size;//кол-во элем вообщем

    size_t rSize_Hash;

    HashF hash;

public:

    Unordered_map() {
        rSize_Hash = def_size_l;
        size = 0;
        array = new forward_list<pair<const Key, Value>>[rSize_Hash];
    }

    Unordered_map(const Unordered_map& other) {

        size = other.size;



        rSize_Hash = other.rSize_Hash;
        hash = other.hash;

        array = new  forward_list<pair<const Key, Value>>[rSize_Hash];

        for (int i = 0; i < rSize_Hash; i++) {
            array[i] = other.array[i];
        }

    }

    ~Unordered_map() {
        delete[] array;
    }

    void Resize() {

        size_t oldHashSize = rSize_Hash;

        rSize_Hash *= 2;//после срабатывания лоад фактора

        auto tempArr = new forward_list<pair<const Key, Value>>[rSize_Hash];

        swap(array, tempArr);

        for (int i = 0; i < oldHashSize; i++) {
            for (auto v : tempArr[i]) {
                this->insert(v);
            }
        }

        delete[] tempArr;


    }

    bool find(const Key& key) {
        int fkey = hash(key, rSize_Hash);

        for (auto i : array[fkey]) {
            if (i.first == key) {
                return true;
            }
        }
        return false;
    }

    bool insert(const pair<const Key, Value>& par) {

        if (this->find(par.first)) {//чтобы не было одинаковых ключей
            return false;
        }

        if (size + 1 > int(reh_s * rSize_Hash)) {//load_faactor
            Resize();
        }

        int key = hash(par.first,rSize_Hash);

        array[key].push_front(par);//конец 1 бакета привязан к началу другого
        size++;//инсерт в пустой список то чтобы добавить в лист просто делаем началом

        return true;

    }

    bool remove(const Key& key) {

        int h = hash(key, rSize_Hash);

        if (array[h].empty()) {
            return false;
        }



        auto takeBegin = array[h].begin();

        if((*takeBegin).first  == key) {
            array[h].pop_front();
            size--;
            return true;
        }

        auto takeEnd = array[h].end();

        while ((*takeBegin).first != key || (takeBegin != takeEnd)) {
            takeBegin++;
            if((*takeBegin).first == key){
                break;
            }
        }

        if (takeBegin == takeEnd) {
            return false;
        }
        array[h].erase_after(takeBegin);
        size--;
        return true;

    }

    Value& operator[](const Key& key) {

        int h = hash(key, rSize_Hash);

        auto takeBegin = array[h].begin();

        auto takeEnd = array[h].end();

        for (takeBegin; takeBegin != takeEnd; takeBegin++) {
            if ((*takeBegin).first == key) {
                return (*takeBegin).second;
            }
        }

        this->insert(make_pair(key, Value()));

        return (*takeBegin).second;



    }

    void clear() {

        delete[] array;

        array = new forward_list<pair<const Key, Value>>[rSize_Hash];

    }

    size_t capacity() {
        return rSize_Hash;
    }

    auto getArr() {

        return array;

    }

};

#endif // UNORDERED_H
