// test.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <cstring>
#include <iomanip>

using namespace std;




void rev(char* str);
int lenstr(char* s);



int main() {
	setlocale(LC_ALL, "Rus");
	int n;

	cout << "Введите элементы матрицы: "; cin >> n;
	char*** array = new char** [n];
	for (int i = 0; i < n; i++) {
		array[i] = new char* [n];

		for (int j = 0; j < n; j++) {
			array[i][j] = new char[80];
			cin >> array[i][j];

		}
	}
	for (int i = 0; i < n; i++) {


		for (int j = 0; j < n; j++) {

			cout << array[i][j] << "\t";

		}
		cout << endl;
	}
	
	int v = 0;
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int x = 0; x < lenstr(array[i][j]); x++) {
				v += (int)array[i][j][x];
				
			}
			if (v % 2 == 0) {
				rev(array[i][j]);
			}
			v = 0;
		}

	}


	cout << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << array[i][j] << " ";
		}
		cout << endl;
	}
}

int lenstr(char* s)
{
	int i = 0;
	while (s[i] != '\0')
		i += 1;
	return i;
}
void rev(char* str) {
	int j = lenstr(str) - 1;

	for (int i = 0; i < (j + 1) / 2; i++) {
		char temp = str[i];
		str[i] = str[j - i];
		str[j - i] = temp;
	}
}

