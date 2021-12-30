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
		std::cout << "������ ����...\n\n" << std::endl;
		return;
	}

	int DelNumb;
	std::cout << "\n������� ����� ������: ";
	std::cin >> DelNumb;

	if (DelNumb < 1 || DelNumb > N) {

		std::cout<<"��� ������ \n";
		return;
	}

	for (int i = DelNumb; i < N; i++) {
		Abon[i - 1] = Abon[i];
	}

	Abon = (Abonent*)realloc(Abon, --N * sizeof(Abonent));
	
	std::cout<<"������� ������!\n";
	out();
}
void Edit() {
	if (!N) {
		std::cout<<"������ ����\n";
		return;
	}

	int EditNumb;
	std::cout << "\n������� ����� �����������: ";
	std::cin >> EditNumb;

	if (EditNumb < 1 || EditNumb > N) {
		std::cout<<"��� ������ \n";
		return;
	}

	Abon[EditNumb - 1].set(EditNumb);

	std::cout<<"������� �������.\n";
	out();
}
void Print() {
	if (!N) {
		std::cout<<"������ ����\n";
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
		Z << "\n\n����: " << Abon[i].day << "." << Abon[i].mon << "." << Abon[i].year
			<< "\n����� ���������: " << Abon[i].hour << ":" << Abon[i].min
			<< "\n�����: " << Abon[i].tarif
			<< "\n��������� �������: " << Abon[i].number
			<< "\n������ �������: " << Abon[i].number_ab
			<< "\n���: " << Abon[i].cod
			<< "\n����: " << Abon[i].time_sp;
	}

	Z.close();

}