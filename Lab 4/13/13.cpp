//Лаболаторная 4,задача 13.Выполнено: Стовба В.А.
/* У Миши в общежитии всего лишь 1 розетка. Дабы исправить это
недоразумение, Миша купил N удлинителей таких, что i-й удлинитель имеет
a[i] входов. Вычислите, сколько розеток получится у Миши, если он
оптимально соединит удлинители?

*/

#include <iostream>

using namespace std;

int k_A()
{
	while (true)
	{

		int num;
		cout << "Кол-во удлинителей : "; cin >> num;

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
	int N,raz,sum=0;
	N = k_A();
	int* array = new int[N];
	
		for (int i = 0; i < N; i++) {
		array[i] = cin_N(i);
		
	}

	for (int i = 0; i < N; i++) {
		
		cout << array[i] << "\t";
	}

	cout << endl;
	for (int i = 0; i < N; i++) {
		sum += array[i]-1;
	}
	sum += 1;
	cout << "Кол-во разеток: " << sum;
	delete[] array;
	return 0;
}