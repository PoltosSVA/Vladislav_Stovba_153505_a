#include <iostream>

using namespace std;

int main() {
	int z = 1;
	int x = 1;
	int w = 1;
	int const a = (z << 1) + 1;
	int const b = (x << 2)+ (x << 5) + 1;
	int const c = (w << 3) + (w << 4) + (w << 6) + 1;
	
	int num;
	cin >> num;

	int y = 0;
	int u = 0;
	int p = 0;

	for (int i = 0; y <= num; i++) {
		y += a;
		if (y == num) {
			cout << "Da_1" << endl;
			break;

		}
		else (y>num){
			cout << "net_1"<<endl;
			break;
		}
		

	}

	for (int i = 0; u <= num; i++) {
		u += b;
		if (u == num) {
			cout << "Da_2" << endl;
			break;

		}
		else(u>num) {
			cout << "net_2" << endl;
			break;
		}

	}

	for (int i = 0; p <= num; i++) {
		p += c;
		if (p == num) {
			cout << "Da_3" << endl;
			break;
		}
		else(p>num) {
			cout << "net_3" << endl;
			break;
		}

	}

	cout << a<<endl;
	cout << b << endl;
	cout << c << endl;
}
