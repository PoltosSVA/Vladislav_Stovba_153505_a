#include <iostream>
#include <windows.h>
#include "abonent.h"
#include "func.h"
#include "sort.h"
#include <fstream>
#include <string>

using namespace std;

int N = 0;

Abonent* Abon = nullptr;
void commands();
void vib();
int main() {

	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	cout << "Введите кол-во городов: \n";
	cin >> N;
	
	Abon = (Abonent*)realloc(Abon, N * sizeof(Abonent));
	
	fstream per;

	per.open("Input.txt", ios::in);



	per.seekg(0, ios::beg);
	per>>Abon[0].day;

	per.seekg(3, ios::beg);
	per >> Abon[0].mon;

	per.seekg(6, ios::beg);
	per >> Abon[0].year;

	per.seekg(11, ios::beg);
	per >> Abon[0].hour;

	per.seekg(13, ios::beg);
	per >> Abon[0].min;

	per.seekg(15, ios::beg);
	per >> Abon[0].tarif;

	per.seekg(23, ios::beg);
	per >> Abon[0].number;

	per.seekg(36, ios::beg);
	per >> Abon[0].number_ab;

	per.seekg(49, ios::beg);
	per >> Abon[0].cod;

	

	Abon[0].time_sp = (Abon[0].hour * 60 + Abon[0].min) * 10;

	commands();
	vib();
	
}
void commands() {
	cout<<" *********Команды **********\n\nxcmd - Просмотреть команды\nadd - Добавить клиента\nlist - Просмотреть список\ndel - Удалить клиента\nedit - Редактировать клиента\ncls - Очистить консоль\nexit - Завершить программу\n\n";
}
void vib() {
	string mas;

	do {
		cin >> mas;
		if (mas == "xcmd")
			commands();
		else if (mas == "add")
			Add();
		else if (mas == "list")
			Print();
		else if (mas == "del")
			Del();
		else if (mas == "edit")
			Edit();
		else if (mas == "cls")
			system("cls");
		else if (mas != "exit")
			cout << "\nНеверная команда\n\n";
	} while (mas != "exit");
}
