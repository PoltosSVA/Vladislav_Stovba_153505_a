//Лаболаторная 4,задача 11.Выполнено: Стовба В.А.
/*Дан трёхмерный динамический массив размером n^3 целых
неотрицательных чисел. Необходимо определить диагональ с наибольшей
суммой чисел. Для обхода диагоналей нельзя использовать вложенные
циклы.


*/

#include <iostream>
#include<iomanip>
using namespace std;

int k_A()
{
	while (true)
	{

		int num;
		cout << "Сторона куба : "; cin >> num;

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
	int x, y, z, n, sum_diag_1 = 0, sum_diag_2 = 0, sum_diag_3 = 0, sum_diag_4 = 0, max = 0;

	n = k_A();



	int* diag_1 = new int[n];
	int* diag_2 = new int[n];
	int* diag_3 = new int[n];
	int* diag_4 = new int[n];


	int*** array = new int** [n];
	for (int i = 0; i < n; i++) {
		array[i] = new int* [n];

		for (int j = 0; j < n; j++) {
			array[i][j] = new int[n];
		}
	}
	srand(1);
	for (z = 0; z < n; z++)
		for (y = 0; y < n; y++)
			for (x = 0; x < n; x++)
				array[z][y][x] = rand() % 14 + 1;

	cout << "diag_1: ";
	x = n - 1; y = 0; z = n - 1;
	for (int i = 0; i < n; i++) {

		diag_1[i] = array[z--][y++][x--];
		cout << diag_1[i] << "\t";


		sum_diag_1 += diag_1[i];

	}

	cout << "sum_diag_1: " << sum_diag_1 << endl;
	cout << "diag_2: ";
	x = 0; y = 0; z = n - 1;
	for (int i = 0; i < n; i++) {

		diag_2[i] = array[z--][y++][x++];
		cout << diag_2[i] << "\t";

		sum_diag_2 += diag_2[i];


	}
	cout << "sum_diag_2: " << sum_diag_2 << endl;
	cout << "diag_3: ";
	x = 0; y = 0; z = 0;
	for (int i = 0; i < n; i++) {

		diag_3[i] = array[z++][y++][x++];
		cout << diag_3[i] << "\t";

		sum_diag_3 += diag_3[i];

	}
	cout << "sum_diag_3: " << sum_diag_3 << endl;
	cout << "diag_4: ";
	x = n - 1; y = 0; z = 0;
	for (int i = 0; i < n; i++) {

		diag_4[i] = array[z++][y++][x--];
		cout << diag_4[i] << "\t";

		sum_diag_4 += diag_4[i];

	}
	cout << "sum_diag_4: " << sum_diag_4 << endl;

	if (sum_diag_4 > sum_diag_1 && sum_diag_4 > sum_diag_2 && sum_diag_4 > sum_diag_3) {

		max = sum_diag_4;
		cout << "Максимальная даигональ 4: " << max;
	}
	else if (sum_diag_1 > sum_diag_4 && sum_diag_1 > sum_diag_2 && sum_diag_1 > sum_diag_3) {

		max = sum_diag_1;
		cout << "Максимальная даигональ 1: " << max;
	}
	else if (sum_diag_3 > sum_diag_4 && sum_diag_3 > sum_diag_2 && sum_diag_3 > sum_diag_1) {

		max = sum_diag_3;
		cout << "Максимальная даигональ 3: " << max;
	}
	else if (sum_diag_2 > sum_diag_4 && sum_diag_2 > sum_diag_3 && sum_diag_1 > sum_diag_3) {

		max = sum_diag_2;
		cout << "Максимальная даигональ 2: " << max;
	}

	delete[]diag_1;
	delete[]diag_2;
	delete[]diag_3;
	delete[]diag_4;

	delete[]array;

	return 0;
}