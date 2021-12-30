#include <iostream>
#include <string>
#include "avtor.h"
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
char* string_chek_numbers(char arr[]) {
	bool check = true;
	while (check) {
		bool flag = true;
		std::cin.getline(arr, 30);

		for (int i = 0; (arr[i] != '\0'); i++) {
			if (((arr[i] < 65 || arr[i] > 90) && (arr[i] < 97 || arr[i] > 122) && (arr[i] < 48 || arr[i] > 57)) || i > 29)
				flag = false;
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

		if (std::cin.fail() || std::cin.peek() != '\n' || element < 0 || element > 5000) { // if we entered erundu
			std::cin.clear(); // "heal" cin
			std::cin.ignore(32768, '\n'); // delete all erundu out of cin
			std::cout << "Повторите ввод" << std::endl;
		}
		else {
			std::cin.ignore(32768, '\n');
			return element;
		}
	}
}



int get_av() {
	while (true) {
		int element;
		std::cin >> element;

		if (std::cin.fail() || std::cin.peek() != '\n' || element < 0) { // if we entered erundu
			std::cin.clear(); // "heal" cin
			std::cin.ignore(32768, '\n'); // delete all erundu out of cin
			std::cout << "Incorrect input..." << std::endl;
		}
		else {
			std::cin.ignore(32768, '\n');
			return element;
		}
	}
}

long long get_address_n() {
	while (true) {
		long long element;
		std::cin >> element;

		if (std::cin.fail() || std::cin.peek() != '\n' || element < 100000000000 || element >999999999999) { // if we entered erundu
			std::cin.clear(); // "heal" cin
			std::cin.ignore(32768, '\n'); // delete all erundu out of cin
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

		if (std::cin.fail() || std::cin.peek() != '\n' || element < 0 || element > 9999) { // if we entered erundu
			std::cin.clear(); // "heal" cin
			std::cin.ignore(32768, '\n'); // delete all erundu out of cin
			std::cout << "Повторите ввод" << std::endl;
		}
		else {
			std::cin.ignore(32768, '\n');
			return element;
		}
	}
}
