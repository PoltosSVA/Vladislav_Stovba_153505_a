// test.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <cstring>
#include <iomanip>
#include <cmath>
using namespace std;
int s_s1(char* str_1, char* str_2, int len, int dl_1, int dl_2, int m);



int main() {
	setlocale(LC_ALL, "Rus");

	int time;
	int len, m;

	cin >> time;
	while (time >= 1) {
		cin >> len >> m;

		cin.ignore(10000, '\n');

		char str1[300];
		char str2[300];

		cin.getline(str1, 200);
		cin.getline(str2, 200);

		int dl_1 = strlen(str1);
		int dl_2 = strlen(str2);

		int n = len - dl_2;

		char* str_1 = new char[len];


		char* str_2 = new char[len];

		int k = 0;

		for (int j = 0; j < dl_1; j++) {
			str_1[j] = str1[k++];
			cout << str_1[j] << "\t";
		}
		cout << endl;

		k = 0;
		for (int j = n; j < len; j++) {
			str_2[j] = str2[k++];
			cout << str_2[j] << "\t";
		}
		cout << endl;
		int col = 0;

		for (int i = 0; i < dl_1; i++) {
			for (int j = n; j < len; j++) {
				if ((i == j) && (str_1[i] == str_2[j])) {
					col++;
				}
			}
		}
		int S1; int S2;
		if (((dl_1 + dl_2 - col) == len)) {
			S1 = s_s1(str_1, str_2, len, dl_1, dl_2, m);
			cout << S1 << endl;
		}
		else {
			S1 = s_s1(str_1, str_2, len, dl_1, dl_2, m);
			S2 = s_s1(str_2, str_1, len, dl_1, dl_2, m);

			cout << S1 + S2 << endl;
		}
		S1 = 0;
		S2 = 0;
		col = 0;
		time--;
	}
	return 0;
}

int s_s1(char* str_1, char* str_2, int len, int dl_1, int dl_2, int m) {
	int col = 0;
	int n = len - dl_2;
	for (int i = 0; i < dl_1; i++) {
		for (int j = n; j < len; j++) {
			if ((i == j) && (str_1[i] == str_2[j])) {
				col++;
			}
		}
	}

	int S1 = 0; int v;
	if (((dl_1 + dl_2) == len) && col == 0) {
		S1 = 2;

		return 0;
	}
	else if (((dl_1 + dl_2 - col) == len)) {

		S1 = 1;

	}
	else if (((dl_1 + dl_2 - col) > len)) {

		S1 = 0;
	}

	else if ((v = len - dl_1 - dl_2 + col) >= 0) {
		col = v;
		S1 = (int)pow(26, col) % m;

	}
	return S1;
}

