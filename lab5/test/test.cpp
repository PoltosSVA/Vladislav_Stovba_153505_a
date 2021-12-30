#include <iostream>
#include <iomanip>
#include<cstdlib>

using namespace std;

int rec(int k, int n, int r) {

	if (n == 0 && r == 0) {
		return 1;
	}
	if (n > 0 && r >= 0 && r < (n * (k - 1) + 1)) {
		int S = 0;
		for(int i = 0;i<=k-1;i++){
			S += rec(k, n - 1, r - i);
		}
		return S;
	}
	else {
		return 0;
	}



}

int main() {

	setlocale(LC_ALL, "Rus");

	int k, n, t, S=0;




	int x = 1;
	int* A = (int*)malloc(x * sizeof(int));

	cin >> k >> n >> t;
	
	
	while (k != 0 && n != 0 && t != 0) {
		S = 0;
		for (int i = 0; i <= n * (k - 1); i++) {
			S += rec(k, n,i );
		}
		

		A[x - 1] = S%(int)pow(10,t);
		A = (int*)realloc(A, ++x * sizeof(int));
		cin >> k >> n >> t;

	}
		cout << endl;
		for (int i = 0; i < x - 1; i++) {
			cout <<"Case#"<<i+1<<":"<< A[i] << endl;
		}
		
		free(A);
}