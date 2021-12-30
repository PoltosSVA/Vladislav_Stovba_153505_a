#include <iostream>
#include <cstring>

using namespace std;
int rec(int a);


int main() {

	setlocale(LC_ALL, "Rus");
	char str[200];
	cout << "Введите предложение:" << endl;
	cin >> str;
	int x = strlen(str);
	




	char* mas = new char[200];
	int p = 0;
	for (int i = 0; i < 200; i++) {
		mas[i] = str[p++];

	}
	int w = strlen(mas);
	
	for (int i = 0; i < x; i++) {
		for (int j = i + 1; j < x; j++) {
			if (str[i] == str[j]) {
				for (int k = j; k < x; k++) {
					str[k] = str[k + 1];



				}
				x--;
				if (str[i] == str[j]) {
					j--;
				}

			}
		}
	}

	
	int v = strlen(str);
	

	int num = rec(w);
	int col = 0;
	for (int i = 0; i < v; i++) {
		col = 0;
		for (int j = 0; j < w; j++) {
			if (mas[j] == str[i]) {
				col++;
			}
		}
		cout << col << endl;
		num /= rec(col);

	}

	cout << num;
}
int rec(int a) {

	if (a < 0)
		return 0;
	if (a == 0)
		return 1;
	else
		return a * rec(a - 1);
}