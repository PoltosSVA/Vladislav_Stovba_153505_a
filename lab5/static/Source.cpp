#include <iostream>
#include "Header.h"
using namespace std;
int vich(double n_A, double n_B) {
	double z = n_B / n_A;
	return -z;
}
int k_A()
{
	while (true)
	{

		int num;

		cout << "������ ������� A[1; 7]: "; cin >> num;


		if (!cin.fail() && cin.peek() == '\n' && num >= 1 && num <= 7)
		{
			return num;
		}
		else {
			cin.clear();
			cin.ignore(32767, '\n');
			cout << "����������� ����.\n";
		}

	}
}

int k_B()
{
	while (true)
	{

		int num;

		cout << "������ ������� B[1; 7]: "; cin >> num;


		if (!cin.fail() && cin.peek() == '\n' && num >= 1 && num <= 7)
		{
			return num;
		}
		else {
			cin.clear();
			cin.ignore(32767, '\n');
			cout << "����������� ����.\n";
		}

	}
}

int cin_A(int& i) {
	int x;
	while (true) {

		cout << "array_A[" << i << "]= "; cin >> x;





		if (cin.fail() || cin.peek() != '\n') {
			cin.clear();
			cin.ignore(10000, '\n');
			cout << "��������� ����: ";
		}
		else {
			return x;
		}
	}

}

int cin_B(int& i) {
	int x;
	while (true) {

		cout << "array_B[" << i << "]= "; cin >> x;





		if (cin.fail() || cin.peek() != '\n') {
			cin.clear();
			cin.ignore(10000, '\n');
			cout << "��������� ����: ";
		}
		else {
			return x;
		}
	}

}

int k_o()
{
	while (true)
	{

		int num;

		cout << "������� ����� ����� ��� ������� A: "; cin >> num;


		if (!cin.fail() && num >= 0 && cin.peek() == '\n')
		{
			return num;
		}
		else {
			cin.clear();
			cin.ignore(32767, '\n');
			cout << "����������� ����.\n";
		}

	}
}

int k_k()
{
	while (true)
	{

		int num;

		cout << "������� ����� ����� ��� ������� B: "; cin >> num;


		if (!cin.fail() && num >= 0 && cin.peek() == '\n')
		{
			return num;
		}
		else {
			cin.clear();
			cin.ignore(32767, '\n');
			cout << "����������� ����.\n";
		}

	}
}