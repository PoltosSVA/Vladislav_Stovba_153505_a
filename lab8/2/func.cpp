#include "func.h"
#include "abonent.h"
#include <iostream>
#include "sort.h"
#include <fstream>
extern int N;
extern Abonent* Abon;




void Add() {

	Abon = (Abonent*)realloc(Abon, ++N * sizeof(Abonent));
	Abon[N - 1].set();
	
	
}
void Del() {
	if (!N) {
		std::cout << "Список пуст...\n\n" << std::endl;
		return;
	}

	int DelNumb;
	std::cout << "\nВведите номер города: ";
	std::cin >> DelNumb;

	if (DelNumb < 1 || DelNumb > N) {

		std::cout<<"Нет такого \n";
		return;
	}

	for (int i = DelNumb; i < N; i++) {
		Abon[i - 1] = Abon[i];
	}

	Abon = (Abonent*)realloc(Abon, --N * sizeof(Abonent));
	
	std::cout<<"Успешно удален!\n";
	out();
}
void Edit() {
	if (!N) {
		std::cout<<"Список пуст\n";
		return;
	}

	int EditNumb;
	std::cout << "\nВведите номер изменяемого: ";
	std::cin >> EditNumb;

	if (EditNumb < 1 || EditNumb > N) {
		std::cout<<"Нет такого \n";
		return;
	}

	Abon[EditNumb - 1].set(EditNumb);

	std::cout<<"Успешно изменен.\n";
	out();
}
void Print() {
	if (!N) {
		std::cout<<"Список пуст\n";
		return;
	}

	for (int i = 0; i < N; i++) {
		Abon[i].get(i);
	}
	std::cout << std::endl;
	out();
}
void out(){
	std::ofstream  Z;
	if (!N) {
		Z.open("doc.txt");
		Z << " ";
		Z.close();
		return;
	}

	Z.open("doc.txt");

	for (int i = 0; i < N; i++) {
		Z << "\n\nДата: " << Abon[i].day << "." << Abon[i].mon << "." << Abon[i].year
			<< "\nВремя разговора: " << Abon[i].hour << ":" << Abon[i].min
			<< "\nТариф: " << Abon[i].tarif
			<< "\nГородской телефон: " << Abon[i].number
			<< "\nЛичный телефон: " << Abon[i].number_ab
			<< "\nКод: " << Abon[i].cod
			<< "\nЦена: " << Abon[i].time_sp;
	}

	Z.close();

}