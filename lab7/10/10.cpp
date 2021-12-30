#include <iostream>
#include <cmath>

using namespace std;

string num_3(int number);
int num_10 (string number);
int lens(string a);
	

int main() {
	int p_boch;
	cin>> p_boch;

	string poison = num_3(p_boch);
	string slaves = "00000";

	string* bochka = new string[240];
	for (int i = 0; i < 240; i++) {
		bochka[i] = num_3(i);//перегон бочек в другую систему счис(3)
	}

	for (int i = 0; i < 240; i++) {
		for (int j = 0; j < 5; j++) {
			if (bochka[i][j] == '0' || bochka[i][j] == '2') {
				continue;
			}
			if (bochka[i] == poison) {
				slaves[j] = '1';
			}
		}
	}

	for (int i = 0; i < 240; i++) {
		for (int j = 0; j < 5; j++) {
			if (bochka[i][j] == '0' || bochka[i][j] == '1') {
				continue;
			}
			if (bochka[i] == poison) {
				slaves[j] = '2';
			}
		}
	}

	cout << num_10(slaves);
}
int lens(string a) {
	int ln = 0;
	while (a[ln])
		ln++;
	return ln;
}
string num_3(int number) {
	string ans;
	while (number != 0) {
		ans = char(48 + number % 3) + ans;
		number /= 3;
	}
	
	while (lens(ans) < 5) {
		ans = '0' + ans;
	}
	return ans;
}

int num_10(string number) {
	int ans = 0;
	for (int i = 0; i < 5; i++) {
		ans += (number[i] - '0') * pow(3, 4 - i);
	}
	return ans;
}