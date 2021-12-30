#include <iostream>
using namespace std;

int raz(int a, int i);


void rd(int numb, int* array);


int main()
{
	setlocale(LC_ALL, "Rus");
	bool min_a = 0;
	bool min_b = 0;



	int numb_a;
	cout << "Первое: ";
	cin >> numb_a;
	if (numb_a < 0)
	{
		numb_a = -numb_a;
		min_a = 1;
	}

	int numb_b;
	cout << "Второе: ";

	cin >> numb_b;


	if (numb_b < 0)
	{
		numb_b = -numb_b;
		min_b = 1;
	}

	int numb_a_10 = 0;
	int numb_b_10 = 0;

	int* arr1 = new int[32];

	int* arr2 = new int[32];

	int* arr3 = new int[32];

	for (int i = 1; 1; i++)
	{
		int n = 0;

		n = raz(numb_a, i);//возвращаем разряд

		numb_a_10 += n * pow(2, i - 1);

		if (numb_a == numb_a % (int)pow(10, i))
			break;
	}

	if (min_a)
		numb_a_10 = -numb_a_10;



	for (int i = 1; 1; i++)
	{
		int n = 0;

		n = raz(numb_b, i);

		numb_b_10 += n * pow(2, i - 1);

		if (numb_b == numb_b % (int)pow(10, i))
			break;
	}

	if (min_b)
		numb_b_10 = -numb_b_10;

	rd(numb_a_10, arr1);
	rd(numb_b_10, arr2);

	for (int i = 0; i < 32; i++)
	{
		cout << arr1[i];
	}


	cout << " +" << endl;


	for (int i = 0; i < 32; i++)
	{
		cout << arr2[i];
	}


	//плюс разряд
	int  r = 0;

	for (int i = 31; i >= 0; i--)
	{
		int n = arr1[i] + arr2[i] + r;

		if (n < 2)
		{
			r = 0;
			arr3[i] = n;
		}
		else if (n == 2)
		{
			r = 1;
			n = 0;
			arr3[i] = n;
		}
		else
		{
			r = 1;
			n = 1;
			arr3[i] = n;
		}
	}



	if (arr3[0] == 1)
	{

		for (int i = 31; i > 0; i--)
		{
			if (arr3[i] == 0)
			{
				arr3[i] = 1;
			}
			else
			{
				arr3[i] = 0;
			}
		}
	}

	cout << " =" << endl;
	cout << "   ";

	for (int i = 0; i < 32; i++)
	{
		cout << arr3[i];
	}



	delete[] arr1;
	delete[] arr2;
	delete[] arr3;

	return 0;
}
void rd(int numb, int* array)
{
	for (int i = 31, j = 0; i >= 0; i--, j++)//запись двоичной записи в массив
	{
		bool y = (bool((1 << i) & numb));
		array[j] = y;
	}
}
int raz(int a, int i)
{
	return ((a % (int)pow(10, i))) / pow(10, i - 1);
}
