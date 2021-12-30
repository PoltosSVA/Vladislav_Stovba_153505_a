#include "abonent.h"
#include <iostream>
#include "func.h"
#include <fstream>
#include "sort.h"
using namespace std;

extern int N;

void Abonent::set(int i) {
	
	std::cout << "\nГород_" << i + 1 << endl;
	
	std::cout << "\nДата разговора: ";
	std::cout << "\n\tДень: ";day = get_address_d();
	std::cout << "\n\tМесяц: ";mon = get_address_mo();
	std::cout << "\n\tГод: "; year = get_address_y();

	std::cout << "\nВремя разговора: ";
	std::cout << "\n\tЧасы: "; hour= get_address_h();
	std::cout << "\n\tМинуты: "; min= get_address_m();

	std::cout << "\nТариф: ";
	
	
	string_chek(tarif);
	
	
	std::cout << "\nГородской телефон: ";
	
	number=get_address_n();

	std::cout << "\nЛичный телефон: ";
	number_ab= get_address_nab();

	std::cout << "\nКод: ";
	cod = get_address();

	time_sp = (hour * 60 + min) * 10;
}
void Abonent::get(int i) {
	
	std::cout << "\nГород_" << i+1 << endl;


	std::cout << "\nДата: " << day<<"."<<mon<<"."<<year << endl;
	

	std::cout << "\nВремя разговора: " << hour << " : " << min<<endl;
	std::cout << "\n\tЦена: " << time_sp<<endl;


	std::cout << "\nТариф: " << tarif << endl;
	

	std::cout << "\nГородской телефон: "<<number<<endl;
	

	std::cout << "\nЛичный телефон: " << number_ab << endl;
	

	std::cout << "\nКод: " << cod << endl;
	

}