#include <iostream>
#include "Header.h"

using namespace std;



int main() {
	setlocale(LC_ALL, "Rus");
	int i = k_A(), j = k_B(),  o, k, n_A, n_B;
	double x;

	

	int* A = new int[i];
	int* B = new int[j];

	for (int a = 0; a < i; a++) {
		A[a] = cin_A(a);
	}
	cout << endl;

	for (int b = 0; b < j; b++) {
		B[b] = cin_B(b);
	}

	o = k_o();
	k = k_k();

	n_A = A[o];
	n_B = B[k];

	if (n_A == 0) {
		x = 0;
		cout << "x = " << x;

	}
	else {
		x = vich(n_A, n_B);
		cout <<"x = "<< x;
		
	}


	return 0;
}