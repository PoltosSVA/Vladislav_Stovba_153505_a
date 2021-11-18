//Лаболаторная 4,задача 7.Выполнено: Стовба В.А.
/*Дано натуральное число n. Требуется подсчитать количество цифр
числа и определить, какая цифра стоит в разряде с номером i (разряды
нумеруются с конца, т.е. разряд единиц имеет номер 0).
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
		cout << "Число: "; cin >> num;

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
		cout << "Введите разряд i: "; cin >> num;

		if (!cin.fail() && num >= 0 && cin.peek() == '\n')
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
	
	int x ,c=0,sum=0,i,z,h,y;
	
	
	
	int n = kul();
	
	z = n;
	while (n >= 1) {

		n /= 10;
		c++;
	}
	cout << "Кол-во цифр числа: " << c << endl;
	h = c;
	int* array = new int[h];
	

	
	
	cout << "z = " << z << endl;
	
		i = 0;
		while (z >= 1) {
			y = z % 10;
			array[i++] = y;
			
			z = trunc(z / 10);
		}
	
		i = k_M();
		cout << array[i] << "  ";
	


	delete[]array;

	return 0;
}