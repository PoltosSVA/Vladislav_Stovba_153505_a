//Лаболаторная 4,задача 3.Выполнено: Стовба В.А.
/* В вещественной матрицы размеров N*N найти максимальный и минимальный
* элементы.Переставить строки,в которых они находятс.
* Если они находятся в 1-ой строк,выдать об этом сообщение.
*/
#include <iostream>
#include <cstdlib>
#include <iomanip>
using namespace std;
int kul()
{
	while (true)
	{

		int num;
		cout << "Размер массива: "; cin >> num;

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
	int n=kul(), max, min, i, j, z, v;
	
	
	int** array = new int* [n];

	for (i = 0; i < n; i++)
		array[i] = new int[n];

	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			array[i][j] = rand() % 50 - 40;
			cout << setw(6) << array[i][j];
		}
		cout << endl;
	}
	


	max = min = array[0][0];
	z = 0; v = 0;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {

			if (array[i][j] > max) {
				max = array[i][j];
				z = i;
			}



			if (array[i][j] < min) {
				min = array[i][j];
				v = i;
			}
			
		}
		
	}
	cout << "\nmin = " << min << endl;
	cout << "\nmax = " << max << endl;
	cout << endl;
	int temp;
	
	for (i = 0; i < n; i++) {
		if (array[v][i] != array[z][i]) {
		temp = array[v][i];

		array[v][i] = array[z][i];
		array[z][i] = temp;
		}
		else if (z==v)
		{ cout << "Переменные в 1 строке"; }
	}

	cout << endl;
	
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			cout << setw(6) << array[i][j];
		}
		cout << endl;
	}
	for (int i = 0; i < n; i++) {
		delete[]array[i];
	}
	delete[]array;
	
	return 0;
}




