#include "pch.h"
#include <iostream>
using namespace std;

int cin_A(int& i) {
	int x;
	while (true) {

		cout << "array_A[" << i << "]= "; cin >> x;




		if (cin.fail() || cin.peek() != '\n') {
			cin.clear();
			cin.ignore(10000, '\n');
			cout << "Повторите ввод: ";
		}
		else {
			return x;
		}
	}

}

double Foo(int i, double* A, int N, int z) {
	if (i == N)
		return z;
	else
		if (sin(A[i]) > 0) {

			return Foo(i + 1, A, N, z + 1);
		}
		else
			return Foo(i + 1, A, N, z);
}

double* sozdanie(int N) {
	double* A;
	A = new double[N];

	for (int x = 0; x < N; x++) {
		A[x] = cin_A(x);
	}
	return A;
}

TEST(Case1, Task2) {
	double n = 1.79e+308;
	int w = 2147483647;
	double* A = new double[5]{n,n,n,n,n};

	EXPECT_EQ(Foo(0, A, 5, 0), 5);

}