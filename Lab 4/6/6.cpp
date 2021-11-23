//Лаболаторная 4,задача 6.Выполнено: Стовба В.А.
/*Для заданной матрицы A размерности N*M построить матрицу B такого же размера
* элементы которой обладают следующии свойствомЖ элемент B[i,j] равен максимальному
* из элементов матрицы A, расположенных левее и выше позиции (i,j),включая позицию(i,j)
* При этом считается,что позиция (1,1)- верхняя левая позиция матрицы.
*/

#include <iostream>
#include<iomanip>
#include <cmath>

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
}
int k_M()
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

	int  i, j, y, z, v, p,  max;
	double  sum = 0;

	int n = kul();
	int m = k_M();

	z = n + 2;
	y = m + 2;

	int** array = new int* [z];

	for (i = 0; i < z; i++)
		array[i] = new int[y];
	

	for (i = 0; i < z; i++) {
		for (j = 0; j < y; j++) {

			array[i][j] = rand() % 50;
			array[i][0] = -32768;
			array[0][j] = -32768;
			array[i][y - 1] = -32768;
			array[z - 1][j] = -32768;

			
		}
		

	}

	cout << "\n";
	for (int i = 1; i < z - 1; i++) {
		for (int j = 1; j < y - 1; j++) {
			cout << setw(6) << array[i][j];
		}
		cout << "\n";
	}

	int** now = new int* [z];

	for (i = 0; i < z; i++)
		now[i] = new int[y];
	
	for (i = 1; i < z - 1; i++) {
		for (j = 1; j < y - 1; j++) {
			max = array[i][j];
			
			for (v= 0 ; v <= i;v++) {
				for (p =0  ; p <=j;p++) {
					
					if (array[v][p] >=max ) {
						max = array[v][p];
					}
					else if (array[v][j] >= max) {
						max = array[v][j];
					}
					else if (array[i][p] >=max) {
						max = array[i][p]; 
					}
					
					
				}	
				
			}
			
			now[i][j] = max;
			
		}
		
	}

	cout << "---------------" << endl;
	for (i = 1; i < z - 1; i++) {
		for (j = 1; j < y - 1; j++) {




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