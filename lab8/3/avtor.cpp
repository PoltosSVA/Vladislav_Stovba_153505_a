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
	//���������� ���������

	std::cout << "\n�����_" << i + 1;

	std::cout << "\n��������������� �����: ";
	id = get_av();

	std::cout << "\n�����: \n";
	string_chek(avtor);

	std::cout << "\n��������: \n";
	string_chek(name);

	std::cout << "\n��� �������: ";
	year =get_address_y();

	std::cout << "\n������������: \n";
	string_chek(fabric);

	std::cout << "\n���������� �������: ";
	pages = get_av();

	


}
void Library::get(int i) {
	//����� ����� ���������

	std::cout << "\n\n\n�����_" << i + 1;


	std::cout << "\n\n��������������� �����: ";
	std::cout << id;

	std::cout << "\n�����: ";
	std::cout << avtor;

	std::cout << "\n��������: ";
	std::cout << name;

	std::cout << "\n��� �������: ";
	std::cout << year;

	std::cout << "\n������������: ";
	std::cout << fabric;

	std::cout << "\n���������� �������: ";
	std::cout << pages;
}
