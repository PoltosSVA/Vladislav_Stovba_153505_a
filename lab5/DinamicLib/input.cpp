#include <iostream>
using namespace std;
extern "C" __declspec(dllexport) int wewe() {
	while (true)
	{

		int num;

		cout << "Размер массива A: "; cin >> num;


		if (!cin.fail() && cin.peek() == '\n' && num >= 1)
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