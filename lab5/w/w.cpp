#include "MyFunctions.h"
#include <iostream>


using namespace std;



int main() {
	setlocale(LC_ALL, "Rus");
	int i, j, o, k, n_A, n_B;
	double x;

	cout << "Введите размер массива A[1; 8]"; cin >> i;
	cout << "Введите размер массива B[1; 8]"; cin >> j;

	int* A = new int[i];
	int* B = new int[j];

	for (int a = 0; a < i; a++) {
		cin >> A[a];
	}
	cout << endl;

	for (int b = 0; b < j; b++) {
		cin >> B[b];
	}

	cout << "Введите норме числа для массива A: "; cin >> o;
	cout << "Введите норме числа для массива B: "; cin >> k;

	n_A = A[o - 1];
	n_B = B[k - 1];

	if (n_A == 0) {
		x = 0;
		cout << "x = " << x;

	}
	else {
		int z=vich(n_A, n_B);
		
		cout << z;
	}


	return 0;
}