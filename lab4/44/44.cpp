//Лаболаторная 4,задача 4.Выполнено: Стовба В.А.
/* Посчитать кол-во локальных минимумов заданной матрицы*/
#include <iostream>
#include<iomanip>

using namespace std;

int kul()
{
	while (true)
	{

		int num;
		cout << "Кол-во строк: "; cin >> num;

		if (!cin.fail() && num > 0 &&cin.peek() == '\n')
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

		if (!cin.fail() && num >0 && cin.peek() == '\n')
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
	int i, j, k, g, cst = 0,z,y;
	int n = kul();
	int m = k_M();
	z = n + 2;
	y = m + 2;
	int** array = new int* [z];

	for (i = 0; i < z; i++)
		array[i] = new int[y];
	srand(time(NULL));
	for (i = 0; i < z; i++) {
		for (j = 0; j < y; j++) {
			
			array[i][j] = rand() % 50 -50;
			array[i][0] = 32767;
			array[0][j] = 32767;
			array[i][y-1] = 32767;
			array[z-1][j] = 32767;
			
			
		}
		
	}
	cout << "\n";
	for (int i = 1; i < z-1; i++) {
		for (int j = 1; j < y-1; j++) {
			cout << setw(6) <<array[i][j];
		}
		cout << "\n";
	}

	
	for (i = 0; i < z-1; i++) {
		for (j = 0; j < y-1; j++) {
			k = i+1; g = j+1;

			if(k>0&& k<z-1&&g>0&&g<y-1)
				if (array[k][g] < array[i][j] && array[k][g] < array[i][j + 1] && array[k][g] < array[i][j + 2] && array[k][g] < array[i + 1][j + 2] && array[k][g] < array[i + 2][j + 2] && array[k][g] < array[i + 2][j + 1] && array[k][g] < array[i + 2][j] && array[k][g] < array[i + 1][j]) {
					cst++;
			}

		}
	}

	cout << endl<<"Кол-во локальных минимумов: " << cst;
	for (int i = 0; i < z; i++) {
		delete[]array[i];
	}
	delete[]array;
}