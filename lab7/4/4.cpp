#include <iostream>
#include <string>
#include <cmath>

using namespace std;
int lens(string a);



int to_int(char a);


char to_char(int a);


int main()
{
	

	setlocale(LC_ALL, "Rus");

	string a;
	string b;

	cout << "Введите первое число: ";

	cin >> a;

	cout << "Введите второе число: ";

	cin >> b;

	int N1 = lens(a);

	int N2 = lens(b);

	char A[30];

	for (int i = 0; i < 30; i++)
	{
		A[i] = '+';
	}

	char B[30];
	for (int i = 0; i < 30; i++)
	{
		B[i] = '+';
	}

	char C[30];
	for (int i = 0; i < 30; i++)
	{
		C[i] = '+';
	}

	for (int i = 0; i <= N1; i++)
	{
		A[29 - i] = a[N1 - i];
	}

	for (int i = 0; i <= N2; i++)
	{
		B[29 - i] = b[N2 - i];
	}



	cout << "Введите знак: ";

	char H;
	cin >> H;

	if (H == '+')
	{
		int r = 0;

		for (int i = 28; i >= 0; i--)
		{
			int n = to_int(A[i]) + to_int(B[i]) + r;

			if (n < 12)
			{
				r = 0;
				C[i] = to_char(n);
			}
			else
			{
				r = 1;
				n = n - 12;
				C[i] = to_char(n);
			}
		}

		cout << endl;
		cout << "   ";

	}
	else
	{
		bool minus = false;

		for (int i = 0; i < 29; i++)
		{
			if (to_int(A[i]) > to_int(B[i]))
			{
				minus = false;
				break;
			}
			else if (to_int(A[i]) < to_int(B[i]))
			{
				minus = true;
				break;
			}
		}

		char p;

		if (minus)
		{
			for (int i = 0; i < 29; i++)
			{
				p = A[i];
				A[i] = B[i];
				B[i] = p;


			}
		}

		int r = 0;

		for (int i = 28; i >= 0; i--)
		{
			int n = to_int(A[i]) - to_int(B[i]) - r;

			if (n >= 0)
			{
				r = 0;
				C[i] = to_char(n);
			}
			else
			{
				r = 1;
				n = n + 12;
				C[i] = to_char(n);
			}
		}

		cout << endl;
		

		if (minus)
			cout << "-";
	}
	bool k = false;

	for (int i = 0; i < 28; i++)
	{
		if (C[i] != '0' || k)
		{
			cout << C[i];
			k = true;
		}
	}

	cout << C[28];

	
}
int lens(string a) {
	int ln = 0;
	while (a[ln])
		ln++;
	return ln;
}
int to_int(char a)
{
	if (a > 47 && a < 58)
	{
		return a - 48;
	}
	else if (a == 65)
	{
		return 10;
	}
	else if (a == 66)
	{
		return 11;
	}
	else
		return 0;
}
char to_char(int a)
{
	if (a >= 0 && a < 10)
		return a + 48;

	else if (a == 10)
		return 'A';

	else if (a == 11)
		return 'B';
}