//Лаболаторная 4,задача 14.Выполнено: Стовба В.А.
/* На вход подаётся поле для игры в "сапёр" размером n*m
символов, где символ '.' означает пустое место, а символ '*' - бомбу. 
Требуется дополнить это поле числами , как в оригинальной игре. Выделение
памяти через функции языка С.


*/

#include <iostream>
#include <malloc.h>
#include<iomanip>

using namespace std;

int k_A()
{
	while (true)
	{

		int num;
		cout << "Размер строки : "; cin >> num;

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
		cout << "Размер столбца : "; cin >> num;

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

char k_C()
{
	while (true)
	{

		char num;
		cin >> num;

		if ( num=='.'||num=='*')
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
	int n = 0, m = 0,g, y, z, k, h;
	
	








	n = k_A();
	m = k_B();

	z = n + 2;
	y = m + 2;

	char** array = (char**)malloc(z * sizeof(char*));
	for (int i = 0; i < z; i++) {
		array[i] = (char*)malloc(y * sizeof(char));
	}


	for (int i = 0; i < z; i++) {
		for (int j = 0; j < y; j++) {
			array[i][j] = '.';
		}
	}

	for (int i = 1; i < z - 1; i++) {
		for (int j = 1; j < y - 1; j++) {
			array[i][j]=k_C();
		}
	}

	for (int i = 1; i < z-1; i++) {
		for (int j = 1; j < y-1; j++) {
			cout << array[i][j] << "  ";
		}
		cout << endl;
	}
	for (int i = 1; i < z - 1; i++) {
		for (int j = 1; j < y - 1; j++) {
			if (array[i][j] =='.') {
				array[i][j] = char('0');
			}
		}
	}
	for (int i = 1; i < z - 1; i++) {
		for (int j = 1; j < y - 1; j++) {
			if (array[i - 1][j] == '*'&& array[i][j]!='*') {
				array[i][j] += 1;
				
			}
			if (array[i - 1][j+1] == '*' && array[i][j] != '*') {
				array[i][j] += 1;
				
			}
			if (array[i][j+1] == '*' && array[i][j] != '*') {
				array[i][j] += 1;
				
			}
			if (array[i + 1][j+1] == '*' && array[i][j] != '*') {
				array[i][j] += 1;
				

			}
			if (array[i + 1][j] == '*' && array[i][j] != '*') {
				array[i][j] += 1;
				
			}
			if (array[i + 1][j-1] == '*' && array[i][j] != '*') {
				array[i][j] += 1;
				
			}
			if (array[i][j-1] == '*' && array[i][j] != '*') {
				array[i][j] += 1;
				
			}
			if (array[i - 1][j-1] == '*' && array[i][j] != '*') {
				array[i][j] += 1;
				
			}
		}
	}
	for (int i = 1; i < z - 1; i++) {
		for (int j = 1; j < y - 1; j++) {




			cout << array[i][j] << "\t\t";
		}
		cout << endl;
	}
	for (int i = 0; i < z; i++) {
		free(array[i]);
	}free(array);
	return 0;

}