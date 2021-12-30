#include <iostream>

using namespace std;
int lens(string a) {
	int ln = 0;
	while (a[ln])
		ln++;
	return ln;
}
void rev(char* str, int i) {
	int j = i - 1;

	for (int i = 0; i < (j + 1) / 2; i++) {
		char temp = str[i];
		str[i] = str[j - i];
		str[j - i] = temp;
	}
}
bool viser(string a) {
	int len = lens(a);
	for (int i = 0; i < len; i++)
		if (a[i] == '0')
			return true;
	return false;
	
}
int main() {

	string mas;
	cin >> mas;

	int len = lens(mas);
	int step = len - 1;
	int main = 0;
	for (int i = 0; i < len; i++) {
		main += (mas[i] - '0') * pow(10, step);
		step--;
	}

	char new_mas[200];
	int save_main = main; int w = 0;
	for (int i = 0; main > 0; i++) {

		save_main = main;
		save_main %= 3;
		new_mas[i] = save_main + '0';

		trunc(main /= 3);
		w++;
	}
	new_mas[w] = '\0';
	rev(new_mas, w);
	

	while (viser(new_mas)) {
		for (int i = 0; i < w; i++) {
			if (new_mas[i] == '0' && new_mas[i - 1] == '1') {
				new_mas[i] = '3';
				new_mas[i - 1] = '0';
			}
			if (new_mas[i] == '0' && new_mas[i - 1] == '2') {
				new_mas[i] = '3';
				new_mas[i - 1] = '1';
			}
			if (new_mas[i] == '0' && new_mas[i - 1] == '3') {
				new_mas[i] = '3';
				new_mas[i - 1] = '2';				
			}
			if (new_mas[i] == '0') {
				for (int i = 0; i < w; i++) {
					new_mas[i] = new_mas[i + 1];
				}
				new_mas[w - 1] = '\0';
			}
		}
	}

	cout << new_mas;
}