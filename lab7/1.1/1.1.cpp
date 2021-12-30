#include <iostream>
#include <string>
#include <cmath>
using namespace std;
int lens(char* a) {
	int ln = 0;
	while (a[ln])
		ln++;
	return ln;
}
int ten_tw(int dec);
void rev(char* str, int i) {
	int j = i - 1;

	for (int i = 0; i < (j + 1) / 2; i++) {
		char temp = str[i];
		str[i] = str[j - i];
		str[j - i] = temp;
	}
}
char* no_point(char* a) {
	int len = lens(a);
	int v = len - 1;
	int ten = 0;
	for (int i = 0; i < len; i++) {
		ten += (a[i] - '0') * pow(7, v);

		v--;
	}

	char* gh = new char[200];

	int save_ten = ten;

	for (int i = 0; i < len; i++) {
		save_ten = ten;
		save_ten %= 12;
		gh[i] = save_ten + '0';
		if (save_ten == 10) {
			gh[i] = 'a';
		}
		if (save_ten == 11) {
			gh[i] = 'b';
		}
		trunc(ten /= 12);

	}
	gh[len-1] = '\0';
	int p = lens(gh);
	rev(gh,p);
	return gh;
}

int main() {

	char num[200];
	cin >> num;

	

	int ten = 0;

	int len = lens(num);
	int point;
	int q = 0;
	int orpoint=0;
	for (int i = 0; i < len; i++) {
		if (num[i] == '.') {
			orpoint++;
		}
	}
	if (orpoint > 0) {
		for (int i = 0; i < len; i++) {
			if (num[i] == '.') {
				point = i;
			}

		}
		double drob = 0;
		int col = 1;

		for (int i = point + 1; i < len; i++) {
			drob += (num[i] - '0') * pow(7, -col);
			col++;
		}

		int v = point - 1;

		for (int i = 0; i < point; i++) {
			ten += (num[i] - '0') * pow(7, v);

			v--;
		}
		double num_ = drob + ten;
		//int h = lens(num);
		int tw;

		char* gh = new char[200];

		int save_ten = ten;

		for (int i = 0; i < point - 1; i++) {
			save_ten = ten;
			save_ten %= 12;
			gh[i] = save_ten + '0';
			if (save_ten == 10) {
				gh[i] = 'a';
			}
			if (save_ten == 11) {
				gh[i] = 'b';
			}
			trunc(ten /= 12);

		}

		
		rev(gh, point - 1);

		
		gh[point - 1] = '.';
		double drob_save = drob;

		for (int i = point; i < 8; i++) {

			double a = drob;
			drob_save = a;
			drob_save *= 12;
			a = drob_save - trunc(drob_save);



			

			if (trunc(drob_save) == 10) {
				gh[i] = 'a';
			}
			else if (trunc(drob_save) == 11) {
				gh[i] = 'b';
			}
			else {
				gh[i] = trunc(drob_save) + '0';
			}

			drob = a;
		}
		gh[8] = '\0';
		cout << gh;
	}
	else {
		cout<<no_point(num);
	}
	

	
}
int ten_tw(int dec) {
	int tw = 0;
	for (int j = 0; dec > 0; j++) {
		tw += (dec % 12) * pow(10.0, j);

		dec /= 12;
	}
	return tw;
}

