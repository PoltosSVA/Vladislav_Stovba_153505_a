#include "avtor.h"
#include <iostream>
#include "func.h"
#include <fstream>;
#include "filesystem"
#include "sort.h"
#include "file.h"



extern int N;
extern Library* books;

void Library::set(int i) {
	//Заполнение структуры

	std::cout << "\nКнига_" << i + 1;

	std::cout << "\nРегистрационный номер: ";
	id = get_av();

	std::cout << "\nАвтор: \n";
	string_chek(avtor);

	std::cout << "\nНазвание: \n";
	string_chek(name);

	std::cout << "\nГод издания: ";
	year =get_address_y();

	std::cout << "\nИздательство: \n";
	string_chek(fabric);

	std::cout << "\nКоличество страниц: ";
	pages = get_av();

	


}
void Library::get(int i) {
	//Вывод полей структуры

	std::cout << "\n\n\nКнига_" << i + 1;


	std::cout << "\n\nРегистрационный номер: ";
	std::cout << id;

	std::cout << "\nАвтор: ";
	std::cout << avtor;

	std::cout << "\nНазвание: ";
	std::cout << name;

	std::cout << "\nГод издания: ";
	std::cout << year;

	std::cout << "\nИздательство: ";
	std::cout << fabric;

	std::cout << "\nКоличество страниц: ";
	std::cout << pages;
}
