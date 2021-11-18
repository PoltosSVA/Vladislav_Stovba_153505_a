//Лаболаторная 4,задача 12.Выполнено: Стовба В.А.
/*Написать функцию которая будет удалять дубликаты элементов
из массива. Входные параметры: массив, длинна массива. Выходные
параметры: новый массив, новый размер.

*/

#include <iostream>

using namespace std;

int k_A()
{
	while (true)
	{

		int num;
		cout << "Размер массива : "; cin >> num;

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

int cin_N(int& i) {


	int x;
	

	// Пока не будет введено корректное значение
	while (true) {

		cout << "array[" << i << "]= "; cin >> x;

		// Пропуск пробелов после элемента
		while (cin.peek() == ' ')
			cin.ignore(1, ' ');

		// Проверка предыдущего извлечения данных из буфера
		// Извлечение неудачное / удачное, но остались неизвлеченные символы / число отрицательное/число меньшее либо равное 2
		if (cin.fail() || cin.peek() != '\n') {
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

	int size,v,d = 0,i;
	
	size = k_A();

	int* array = new int[size];

	for (int i = 0; i < size; i++) {
		array[i] = cin_N(i);
		
	}

	for (int i = 0; i < size; i++) {
		
		cout << array[i] << "\t";
	}

	cout << endl;

	int* new_array = new int[size];

	for (int i = 0; i < size; i++) {
		for (int j = i+1; j < size; j++) {
			if (array[i] == array[j]) {
				for (int k = j; k < size; k++) {
					array[k] = array[k + 1];
					
					

				}
				size--;
				if (array[i] == array[j]) {
					j--;
				}
				
			}
		}
	}
	for (int i = 0; i < size; i++) {
		cout << array[i] << "\t";
	}

	

	delete[]array;
	delete[]new_array;
	
	return 0;
}