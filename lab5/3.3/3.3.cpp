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

int fre(int**A,int n,int m,int l) {
	int** f_A = new int* [n];
	for (int i = 0; i < n; i++) {
		f_A[i] = new int[m];
	}
	int* f_B = new int[m];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {

			f_A[i][j] = cin_A1(i, j);

		}
	}

	int col = 0, w = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (j % 2 == 1) {
				if (f_A[i][j] % 2 == 1) {
					f_B[w++] = f_A[i][j];
					col++;

				}
			}
		}

	}
	return col;
}

int main() {
	setlocale(LC_ALL, "Rus");
	int z = k_n();
	int x = k_k();

	int** f_A = new int* [z];
	for (int i = 0; i < z; i++) {
		f_A[i] = new int[x];
	}

	int* f_B = new int[x];

	
	int col = fre(f_A, z, x, 0);

	cout << endl;
	cout << "col = " << col << endl;
	if (f_B[0] > 0) {

		double sum = 0;
		for (int i = 0; i < col; i++) {
			sum += f_B[i];
		}
		sum /= col;
		return sum;
	}
	else
		return 0;

	for (int i = 0; i < x; i++) {
		delete[]f_A[i];
	}delete[]f_A;
	delete[]f_B;





}