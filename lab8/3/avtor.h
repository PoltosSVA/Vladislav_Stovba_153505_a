#pragma once

extern int N;

class  Library {
private:
    int id = 0; // идентификационный номер
    char avtor[30]; //автор
    char name[30]; // название
    int year = 0; //год издания
    char fabric[30]; //издательство
    int pages = 0; //кол-во страниц

public:
    void set(int i = N - 1);
    void get(int i);
    //***********************************//
    void Id(int newId) {
        id = newId;
    }
    void Avtor(char new_author[]) {
        for (int i = 0; i < 30; i++) {
            avtor[i] = new_author[i];
        }
    }
    void Title(char new_title[]) {
        for (int i = 0; i < 30; i++) {
            name[i] = new_title[i];
        }
    }
    void Year(int newYear) {
        year = newYear;
    }
    void Fabric(char new_fabric[]) {
        for (int i = 0; i < 30; i++) {
            fabric[i] = new_fabric[i];
        }
    }
    void Pages(int newPages) {
        pages = newPages;
    }
    
    int Id() {
        return id;
    }

    char* Avtor() {
        return avtor;
    }

    char* Title() {
        return name;
    }

    int Year() {
        return year;
    }

    char* Fabric() {
        return fabric;
    }

    int Pages() {
        return pages;
    }

    
};

