#include "abonent.h"
#include <iostream>
#include "func.h"
#include <fstream>
#include "sort.h"
using namespace std;

extern int N;

void Abonent::set(int i) {
	
	std::cout << "\n�����_" << i + 1 << endl;
	
	std::cout << "\n���� ���������: ";
	std::cout << "\n\t����: ";day = get_address_d();
	std::cout << "\n\t�����: ";mon = get_address_mo();
	std::cout << "\n\t���: "; year = get_address_y();

	std::cout << "\n����� ���������: ";
	std::cout << "\n\t����: "; hour= get_address_h();
	std::cout << "\n\t������: "; min= get_address_m();

	std::cout << "\n�����: ";
	
	
	string_chek(tarif);
	
	
	std::cout << "\n��������� �������: ";
	
	number=get_address_n();

	std::cout << "\n������ �������: ";
	number_ab= get_address_nab();

	std::cout << "\n���: ";
	cod = get_address();

	time_sp = (hour * 60 + min) * 10;
}
void Abonent::get(int i) {
	
	std::cout << "\n�����_" << i+1 << endl;


	std::cout << "\n����: " << day<<"."<<mon<<"."<<year << endl;
	

	std::cout << "\n����� ���������: " << hour << " : " << min<<endl;
	std::cout << "\n\t����: " << time_sp<<endl;


	std::cout << "\n�����: " << tarif << endl;
	

	std::cout << "\n��������� �������: "<<number<<endl;
	

	std::cout << "\n������ �������: " << number_ab << endl;
	

	std::cout << "\n���: " << cod << endl;
	

}