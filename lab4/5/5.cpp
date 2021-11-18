//Лаболаторная 4,задача 5.Выполнено: Стовба В.А.
/*Построить результат сглаживания заданной вещественной матрицы
*/
#include <iostream>
#include<iomanip>

using namespace std;

int kul()
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
}int k_M()
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

int main() {
	setlocale(LC_ALL, "Rus");

	int  i, j,  y,z;
	double del, sum = 0;

	int n = kul();
	int m = k_M();
	
	z = n + 2;
	y = m + 2;

	double** array = new double* [z];

	for (i = 0; i < z; i++)
		array[i] = new double[y];
	
	for (i = 0; i < z; i++) {
		for (j = 0; j < y; j++) {
			
			array[i][j] = rand() % 50;
			array[i][0] = 0;
			array[0][j] = 0;
			array[i][y - 1] = 0;
			array[z - 1][j] = 0;

			
		}
		
	}

	cout << "\n";
	for (int i = 1; i < z - 1; i++) {
		for (int j = 1; j < y - 1; j++) {
			cout << setw(6) << array[i][j];
		}
		cout << "\n";
	}

	double** now = new double* [z];

	for (i = 0; i < z; i++)
		now[i] = new double[y];

	


	for (i = 1; i < z-1; i++) {
		for (j = 1; j < y - 1; j++) {
			
			if ((i - 1 == 0 && j - 1 == 0) || (i - 1 == 0 && j + 1 == y - 1) || (i + 1 == z - 1 && j + 1 == y - 1) || (j - 1 == 0 && i + 1 == z - 1)) {
				del = 3;
			}
			else if ((i - 1 == 0 && j + 1 != 0 && j - 1 != 0) || (i - 1 != 0 && i + 1 != 0 && j + 1 == y - 1) || (i + 1 == z - 1 && j + 1 != 0 && j - 1 != 0) || (i - 1 != 0 && i + 1 != 0 && j - 1 == 0)) {
				del = 5;
			}
			else { del = 8; }

			sum = (array[i-1][j] + array[i-1][j+1] + array[i][j+1] + array[i+1][j+1] + array[i+1][j] + array[i+1][j-1] + array[i][j-1] + array[i-1][j-1]) / del;
			now[i][j] = sum;
		}
	}
	cout << "---------------"<<endl;
	for (i = 1; i < z-1; i++) {
		for (j = 1; j < y-1; j++) {

			


			cout << now[i][j] << "\t\t";
		}
		cout << endl;
	}
	for (int i = 0; i < z; i++) {
		delete[]array[i];
	}
	delete[]array;
	for (int i = 0; i < z; i++) {
		delete[]now[i];
	}
	delete[]now;
	return 0;
}