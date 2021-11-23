//Лаболаторная 4,задача 9.Выполнено: Стовба В.А.
/*В качестве входных данных поступают две целочисленные
матрицы A и B, которые имеют размер N и соответственно. Требуется найти
произведение матриц A*B. Выделение памяти через функции языка С.

*/

#include <iostream>
#include<malloc.h>

using namespace std;

int k_A()
{
	while (true)
	{

		int num;
		cout << "Кол - во строк A матрицы : "; cin >> num;

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
int k_B()
{
	while (true)
	{

		int num;
		cout << "Кол - во столбцов A матрицы и кол-во строк B : "; cin >> num;

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
int k_C()
{
	while (true)
	{

		int num;
		cout << "Кол - во столбцов B матрицы : "; cin >> num;

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

	int n, m, c;
	n = k_A();
	m = k_B();
	c = k_C();

	int** A = (int**)malloc(n * sizeof(int*));
	for (int i = 0; i < n; i++) {
		A[i] = (int*)malloc(m * sizeof(int));
	}

	int** B = (int**)malloc(m * sizeof(int*));
	for (int i = 0; i < m; i++) {
		B[i] = (int*)malloc(c * sizeof(int));
	}

	int** C = (int**)malloc(n * sizeof(int*));
	for (int i = 0; i < n; i++) {
		C[i] = (int*)malloc(c * sizeof(int));
	}


	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			A[i][j] = rand() % 10 + 1;
			cout << A[i][j] << "\t";
		}
		cout << endl;
	}
	cout << "\n";
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < c; j++) {
			B[i][j] = rand() % 10 + 1;
			cout << B[i][j] << "\t";

		}
		cout << endl;
	}
	cout << "\n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < c; j++) {
			C[i][j] = 0;

			for (int x = 0; x < m; x++) {
				C[i][j] += A[i][x] * B[x][j];

			}
			cout << C[i][j] << "\t";
		}
		cout << endl;
	}
	for (int i = 0; i < n; i++) {
		free(A[i]);
	} free(A);

	for (int i = 0; i < m; i++) {
		free(B[i]);
	} free(B);

	for (int i = 0; i < c; i++) {
		free(C[i]);
	} free(C);


	return 0;
}