
#include "pch.h"
int res(int**A,int n,int m,int pr) {
	int* B = new int[m];
	int col = 0, w = 0;
	for (int i = 0; i < n; i++) {

		for (int j = 0; j < m; j++) {
			if (i == j) {
				if (A[i][j] % 2 == 0) {
					B[w++] = A[i][j];
					col++;

				}
			}
		}

	}
	
	for (int i = 0; i < col; i++) {
		pr *= B[i];
	}
	if (pr == 1) {
		return 0;
	}
	else
		return pr;
}