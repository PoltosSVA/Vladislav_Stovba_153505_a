#include <iostream>
#include <cmath>
#include <Windows.h>

using namespace std;

int Foo(int i, double* A, int N,int z) {
	if (i == N)
		return z;
	else
		if (sin(A[i]) > 0) {
			
			return Foo(i+1, A, N,z+1);
		}
		else
			return Foo(i+1, A, N,z);
}

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

double* sozdanie(int N) {
	double* A;
	 A = new double[N];

	for (int x = 0; x < N; x++) {
		A[x] = cin_A(x);
	}
	return A;
}

int main() {
	setlocale(LC_ALL, "Rus");

	HINSTANCE load;
	load = LoadLibrary(L"Dinamiclib.dll");
	typedef int (*set)();
	set K_A; 
	K_A = (set)GetProcAddress(load, "wewe");
	
	int N = K_A();
	
	

	double f_part,s_part;

	
	double* A = sozdanie(N);
	
	 
	f_part = Foo(0, A, N/2,0);
	s_part = Foo(N / 2, A, N, 0);

	cout <<"Кол-во элементов в 1-ой части:" << f_part << endl;
	cout <<"Кол-во элементов в 2-ой части:" << s_part << endl;

	return 0;
	FreeLibrary(load);
}