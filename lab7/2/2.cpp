#include <iostream>
#include <cmath>
#include <string>
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
int main() {
	
	string mas;
	cin >> mas;

	int len_mas = lens(mas);

	string sign;
	int col_min_pl=-1;
	int point=0;
	for (int i = 0; i < len_mas; i++) {
		

			if (mas[i] == '-') {
				sign[0] = '1';
				col_min_pl = i;

			}
			else if (mas[i] == '+') {
				sign[0] = '0';
				col_min_pl = i;

			}
			
			
		
		if(mas[i] == '.') {
			point = i;
		}
		
	}
	int i = point;
	if (point == 0) {
		point = len_mas;
	}
	//найдем числа находящиеся в строке
	int num_len=0;
	for (int i = col_min_pl + 1; i < point; i++) {
		num_len++;
	}

	int step = num_len - 1;
	int main = 0;

	for (int i = col_min_pl+1 ; i < point; i++) {
		main += (mas[i] - '0') * pow(10, step);
		step--;
	}

	int z = 1;
	double drob = 0;
	for (int i = point + 1; i < len_mas; i++) {
		drob += (mas[i] - '0') * pow(10, -z);
		z++;
	}

	char new_mas[200];
	int save_main = main; int w = 0;
	for (int i = 0;main>0; i++) {
		
		save_main = main;
		save_main %= 2;
		new_mas[i] = save_main + '0';

		trunc(main /= 2);
		w++;
	}
	rev(new_mas, w);
	double drob_save = drob;
	new_mas[w ] = '.';

	if (drob > 0) {
		for (int i = w + 1; i < 100; i++) {

			double a = drob;
			drob_save = a;
			drob_save *= 2;
			a = drob_save - trunc(drob_save);
			new_mas[i] = trunc(drob_save) + '0';
			drob = a;
		}
	}
	if (i > 0)
		new_mas[w + 5] = '\0';
	else new_mas[w] = '\0';
	
	int ne_len = lens(new_mas);
	char sec_mas[200];
	if (sign[0] == '1') {
		
		for (int i = 0; i < ne_len; i++) {
			
			if (new_mas[i] == '1') {
				sec_mas[i] = '0';
			}
			if (new_mas[i] == '0') {
				sec_mas[i] = '1';
			}
			if (new_mas[i] == '.') {
				sec_mas[i] = '.';
			}
		}
		sec_mas[ne_len] = '\0';
		
		cout <<sign[0]<<"," << sec_mas;
	}else  {
		
		for (int i = 0; i < ne_len; i++) {

			sec_mas[i] = new_mas[i];
		}
		sec_mas[ne_len] = 0;
		cout << "0," << sec_mas;


	}
}
	
