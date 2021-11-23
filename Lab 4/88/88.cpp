//Лаболаторная 4,задача 8.Выполнено: Стовба В.А.
/*Заменить нулями все элементы, которые находятся в ячейках
между минимальным и максимальным элементами (не включая их).
Изначально все элементы в массиве различные. Если после данного действия
большая часть массива будет содержать нули, то удалить все нулевые
элементы из массива (c сохранением порядка следования остальных
элементов).

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
		cout << "Размер массива: "; cin >> num;

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
int cin_N(int&i) {


	int x;
	

	// Пока не будет введено корректное значение
	while (true) {

		cout << "array["<<i<<"]= "; cin >> x;
		
		// Пропуск пробелов после элемента
		while (cin.peek() == ' ')
			cin.ignore(1, ' ');

		// Проверка предыдущего извлечения данных из буфера
		// Извлечение неудачное / удачное, но остались неизвлеченные символы / число отрицательное/число меньшее либо равное 2
		if (cin.fail() || cin.peek() != '\n' ) {
			cin.clear(); // Возвращение в обычный режим работы
			cin.ignore(10000, '\n'); // Игнор 'n' символов до Enter
			cout << "Повторите ввод: ";
		}
		else {
			return x;
		}
	}

}

int main() {

	setlocale(LC_ALL, "Rus");

	int n, imin, imax, max, min, i, q = 0;

	n = kul();

	int* array = new int[n];
	int* array_new = new int[n];
	for (int i = 0; i < n; i++) {

		array[i] = cin_N(i);

	}

	for (int i = 0; i < n; i++) {

		cout << array[i] << "  ";


	}
	cout << endl;
	min = max = array[0];
	imin = imax = 0;
	for (i = 0; i < n; i++) {

		if (array[i] < min) {
			min = array[i];
			imin = i;

		}
		if (array[i] > max) {
			max = array[i];
			imax = i;
		}

	}
	cout << "index max: " << imax << endl;
	cout << "index min: " << imin << endl;

	if (imin < imax) {
		for (i = (imin + 1); i < (imax); i++) {
			array[i] = 0;

		}
	}

	else {
		for (i = (imax + 1); i < (imin); i++) {
			array[i] = 0;

		}
	}


	cout << endl;

	int col = 0;
	for (int i = 0; i < n; i++) {
		if (array[i] == 0) {
			col++;
		}
	}
	
	for (i = 0; i < n; i++) {
		cout << array[i] << " ";
	}
	cout << endl;
	if (col > n / 2) {






		for (i = 0; i < n; i++) {
			if (array[i] != 0)
				array_new[q++] = array[i];
		}
		n -= col;
		for (int i = 0; i < n; i++) {
			cout << array_new[i] << " ";
		}
	}



	delete[]array;
	
	delete[]array_new;
	return 0;
}
