#include <iostream>
#include <string>
#include "rat.h"
#include "func.h"
#include "prov.h"
using namespace std;
char* string_chek(char arr[]) {
	bool check = true;
	while (check) {
		bool flag = true;
		
		scanf_s("%s", arr, 30);
		for (int i = 0; arr[i] != '\0'; i++) {
			if ((arr[i] < 65 || arr[i] > 90) && (arr[i] < 97 || arr[i] > 122) || (i > 29)) {
				//std::cin.ignore(32768, '\n');
				flag = false;
			}
		}

		if (flag)
			return arr;
		else

			
			printf("Повторите ввод\n");
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