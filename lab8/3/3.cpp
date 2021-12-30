#include <iostream>
#include <windows.h>
#include "avtor.h"
#include "func.h"
#include "sort.h"
#include <fstream>
#include <string>
#include "file.h"

using namespace std;

int N = 0;
int a = 0;
Library* books = nullptr;
void commands();
void vib();
int main() {

	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	cout << "Введите  год: \n";

	a = get_address_y();
	
	books = LoadFile(books);

	

	commands();
	vib();

}
void commands() {
	cout << " *********Команды **********\n\nxcmd - Просмотреть команды\nadd - Добавить клиента\nlist - Просмотреть список\ndel - Удалить клиента\nedit - Редактировать клиента\ncls - Очистить консоль\nexit - Завершить программу\n\n";
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
