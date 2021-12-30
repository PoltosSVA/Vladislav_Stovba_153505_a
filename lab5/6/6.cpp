#include <iostream>

using namespace std;

int k_o()
{
	while (true)
	{

		int num;

		cin >> num;


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

int rec(int n)

{

	int z = (n + 1) / 2;

	if (n == 0) 
		return 0;


	return z * z + rec(n / 2);

}

int main() {

	setlocale(LC_ALL, "Rus");

	int n;
	int  S;
	




	int x = 1;
	int* A = (int*)malloc(x * sizeof(int));

	n = k_o();
	while (n!=-1) {


		S = rec(n);


		A[x - 1] = S;
		A = (int*)realloc(A, ++x * sizeof(int));
		cin >> n;
	}




	cout << endl;
	for (int i = 0; i < x - 1; i++) {
		cout << A[i] << endl;
	}

	free(A);


}