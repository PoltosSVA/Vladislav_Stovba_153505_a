#include <iostream>
#include <iomanip>

using namespace std;

double cin_A(int& i, int& j) {
	double x;
	while (true) {

		cout << "array_A[" << i << "][" << j << "]="; cin >> x;





		if (cin.fail() || cin.peek() != '\n') {
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

int Foo(int** A, int col,int z,int x) {
	
	for (int i = 0; i < z; i++) {
		for (int j = 0; j < x; j++) {
			if (A[i][j] == 0) {
				
				col++;
			}
		}

	}
	return col;
}

int main() {

	setlocale(LC_ALL, "Rus");

	int z = k_n();
	int x = k_k();

	double** f_A = new double* [z];
	for (int i = 0; i < z; i++) {
		f_A[i] = new double[x];
	}

	for (int i = 0; i < z; i++) {
		for (int j = 0; j < x; j++) {
			f_A[i][j] = cin_A(i, j);
			
		}
	}
	for (int i = 0; i < z; i++) {
		for (int j = 0; j < x; j++) {
			
			if (f_A[i][j] == 0) {
				cout << i << " " << j << "|";
			}
		}
	}
	int col = (f_A,0,z,x);

	cout << endl;
	cout << "col = " << col << endl;

	int m = z - 1;
	for (int i = 0; i < z; i++) {
		int n = x - 1;
		for (int j = 0; j < x / 2; j++) {

			int temp;
			temp = f_A[m][n];
			f_A[m][n] = f_A[i][j];
			f_A[i][j] = temp;
			n--;
		}
		m--;

	}
	if (x % 2 != 0) {
		m = z - 1;
		int n = x / 2;
		int j = x / 2;
		for (int i = 0; i < z / 2; i++) {
			int temp = f_A[m][n];
			f_A[m][n] = f_A[i][j];
			f_A[i][j] = temp;
			m--;
		}
	}

	for (int i = 0; i < z; i++) {
		for (int j = 0; j < x; j++) {
			cout << setw(10) << f_A[i][j];
		}
		cout << endl;
	}


	for (int i = 0; i < z; i++) {
		delete[]f_A[i];
	}delete[]f_A;
	return 0;

}