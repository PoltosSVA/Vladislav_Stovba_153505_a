#include <iostream>
#include <iomanip>
#include <stdlib.h>
using namespace std;

int cin_B() {
	int x;
	while (true) {

		cin >> x;


		


		if (cin.fail() && cin.peek() != '\n'&&x>=-1) {
			cin.clear();
			cin.ignore(10000, '\n');
			cout << "Повторите ввод: ";
		}
		else {
			return x;
		}
	}

}






int F(int n, int i, int s, int z) {

	if (i == z-1) {
		return s;
	}
	else {
		if (n % 10 > 0) {
			n %= 10;
			return s + n + F(n + 1, i + 1, s, z);
		}
		if (n == 0) {
			return 0;
		}
		else {
			n = n / 10;
			return s + n + F(n + 1, i + 1, s, z);
		}
	}

}



int main() {

	setlocale(LC_ALL, "Rus");

	int p, q, S;
	

	

	int x = 1;
	int* A = (int*)malloc(x*sizeof(int));
	 	
	p = cin_B(); q = cin_B();
	 while (q > -1 && p > -1) {
		 
		
			 S = F(p, p, 0, q);
			
		 
		 A[x - 1] = S;
		 A = (int*)realloc(A, ++x * sizeof(int));
		 p = cin_B(); q = cin_B();
	 }
	
	 
		 
	 
	cout << endl;
	for (int i = 0; i < x - 1; i++) {
		cout << A[i]<<endl;
	}
	
	free(A);

}