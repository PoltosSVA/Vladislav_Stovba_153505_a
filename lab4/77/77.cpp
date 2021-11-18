#include <iostream>
#include<iomanip>
#include <cmath>

using namespace std;

int kul()
{
	while (true)
	{

		int num;
		cout << "Число: "; cin >> num;

		if (!cin.fail() && num > 0 && cin.peek() == '\n')
		{
			return num;
		}
		else {
			cin.clear();
			cin.ignore(32767, '\n');
			cout << "Некоректный ввод.\n";
		}

	}
}

int main() {

	setlocale(LC_ALL, "Rus");

	int  x, c = -1, sum = 0, i, z,del=0;

	int n = kul();
	z = n;
	while (n) {
		del++;
		n /= 10;
	}
	
	x = del;
	int* array = new int[x];
	
	while (n >= 1) {

		n /= 10;
		c++;
	}
	cout << c;

	while (z >= 1) {
		z %= 10;
		sum += pow(z % 10, 10 * c);
		z = trunc(z / 10);

	}
	cout << sum;
	/*for (i = 0; i <= c; i++) {



		array[i] = sum % 10;


	}
	delete[]array;
	*/


	return 0;
}