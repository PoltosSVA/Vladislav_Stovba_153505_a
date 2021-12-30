#include <iostream>
#include <string>
#include "abonent.h"
#include "func.h"
#include "sort.h"
char* string_chek(char arr[]) {
	bool check = true;
	while (check) {
		bool flag = true;
		std::cin.getline(arr, 30);

		for (int i = 0; arr[i] != '\0'; i++) {
			if ((arr[i] < 65 || arr[i] > 90) && (arr[i] < 97 || arr[i] > 122) || (i > 29)) {
				//std::cin.ignore(32768, '\n');
				flag = false;
			}
		}

		if (flag)
			return arr;
		else
			
			std::cout << "Повторите ввод" << std::endl;
			
	}
}
int get_address() {
	while (true) {
		int element;
		std::cin >> element;

		if (std::cin.fail() || std::cin.peek() != '\n' || element < 0 || element > 5000) { 
			std::cin.clear();
			std::cin.ignore(32768, '\n'); 
			std::cout << "Повторите ввод" << std::endl;
		}
		else {
			std::cin.ignore(32768, '\n');
			return element;
		}
	}
}


int get_address_h() {
	while (true) {
		int element;
		std::cin >> element;

		if (std::cin.fail() || std::cin.peek() != '\n' || element < 0 || element > 23) { 
			std::cin.clear(); 
			std::cin.ignore(32768, '\n'); 
			std::cout << "Повторите ввод" << std::endl;
		}
		else {
			std::cin.ignore(32768, '\n');
			return element;
		}
	}
}
int get_address_m() {
	while (true) {
		int element;
		std::cin >> element;

		if (std::cin.fail() || std::cin.peek() != '\n' || element < 0 || element > 59) { 
			std::cin.clear(); 
			std::cin.ignore(32768, '\n'); 
			std::cout << "Повторите ввод" << std::endl;
		}
		else {
			std::cin.ignore(32768, '\n');
			return element;
		}
	}
}
long long get_address_nab() {
	while (true) {
		long long element;
		std::cin >> element;

		if (std::cin.fail() || std::cin.peek() != '\n' || element < 100000000000 || element >999999999999) { 
			std::cin.clear(); // "heal" cin
			std::cin.ignore(32768, '\n'); 
			std::cout << "Повторите ввод" << std::endl;
		}
		else {
			std::cin.ignore(32768, '\n');
			return element;
		}
	}
}long long get_address_n() {
	while (true) {
		long long element;
		std::cin >> element;

		if (std::cin.fail() || std::cin.peek() != '\n' || element < 100000000000 || element >999999999999) { 
			std::cin.clear(); 
			std::cin.ignore(32768, '\n'); 
			std::cout << "Повторите ввод" << std::endl;
		}
		else {
			std::cin.ignore(32768, '\n');
			return element;
		}
	}
}
int get_address_d() {
	while (true) {
		int element;
		std::cin >> element;

		if (std::cin.fail() || std::cin.peek() != '\n' || element < 1 || element > 28) { 
			std::cin.clear(); 
			std::cin.ignore(32768, '\n'); 
			std::cout << "Повторите ввод" << std::endl;
		}
		else {
			std::cin.ignore(32768, '\n');
			return element;
		}
	}
}
int get_address_mo() {
	while (true) {
		int element;
		std::cin >> element;

		if (std::cin.fail() || std::cin.peek() != '\n' || element < 1 || element > 12) { 
			std::cin.clear(); 
			std::cin.ignore(32768, '\n'); 
			std::cout << "Повторите ввод" << std::endl;
		}
		else {
			std::cin.ignore(32768, '\n');
			return element;
		}
	}
}
int get_address_y() {
	while (true) {
		int element;
		std::cin >> element;

		if (std::cin.fail() || std::cin.peek() != '\n' || element < 0 || element > 9999) { 
			std::cin.clear(); 
			std::cin.ignore(32768, '\n'); 
			std::cout << "Повторите ввод" << std::endl;
		}
		else {
			std::cin.ignore(32768, '\n');
			return element;
		}
	}
}
