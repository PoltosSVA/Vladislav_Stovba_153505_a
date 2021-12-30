#include <iostream>
#include <iomanip>
using namespace std;

int cin_A1(int& i, int& j) {
	int x;
	while (true) {

		cout << "array_A[" << i << "][" << j << "]="; cin >> x;





		if (cin.fail() || cin.peek() != '\n' && x > 0) {
			cin.clear();
			cin.ignore(10000, '\n');
			cout << "Повторите ввод: ";
		}
		else {
			return x;
		}
	}

}
int k_n()
{
	while (true)
	{

		int num;

		cout << "Кол-во строк: "; cin >> num;


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

int k_k()
{
	while (true)
	{

		int num;

		cout << "Кол-во столбцов: "; cin >> num;


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
int res(int* B, int col, int pr) {
	for (int i = 0; i < col; i++) {
		pr *= B[i];
	}
	return pr;
}

int main()
{
	setlocale(LC_ALL, "Rus");

	int z = k_n();
	int x = k_k();

	int** f_A = new int* [z];
	for (int i = 0; i < z; i++) {
		f_A[i] = new int[x];
	}

	int* f_B = new int[x];


	for (int i = 0; i < z; i++) {
		for (int j = 0; j < x; j++) {

			f_A[i][j] = cin_A1(i, j);

		}
	}

	for (int i = 0; i < z; i++) {
		for (int j = 0; j < x; j++) {


			cout << setw(4) << f_A[i][j];
		}
		cout << "\n";
	}


	int col = 0, w = 0;
	for (int i = 0; i < z; i++) {

		for (int j = 0; j < x; j++) {
			if (i == j) {
				if (f_A[i][j] % 2 == 0) {
					f_B[w++] = f_A[i][j];
					col++;

				}
			}
		}

	}

	cout << endl;

	int pr = 1;


	pr = res(f_B, col, 1);

	if (pr == 1) {
		return 0;
	}
	else
		cout << pr;

	for (int i = 0; i < x; i++) {
		delete[]f_A[i];
	}delete[]f_A;
	delete[]f_B;
	return pr;
}