#include <iostream>
#include<iomanip>

using namespace std;

int main() {
	int n = 0, m = 0, i, j,k,g,cst=0;
	cin >> n;
	cin >> m;
	int** array = new int* [n];

	for (i = 0; i < n; i++)
		array[i] = new int[m];

	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			array[i][j] = rand() % 10 + 1;
			cout << setw(6) << array[i][j];
		}
		cout << endl;
	}

	for (i = 0; i < n+1; i++) {
		for (j = 0; j < m+1; j++) {
			k = i;
			g = j;
			
		}
	}
	/*for (k = 0, i = 1; k < n && i<n; k++, i++) {
		for (g =0,j=1; g < m&&j<m; g++,j++) {
			if (array[k] >= array[i - 1] && array[k] <= array[i + 1] && array[g] >= array[j - 1] && array[g] >= array[j + 1]) {
				cst++;
			}
		}
	}*/
	cout << endl << cst;
}