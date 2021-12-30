
#include "pch.h"
int fre(int** A, int n, int m ) {

	

	int w = 0;
	int col = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (j % 2 == 1) {
				if (A[i][j] % 2 != 0 ) {
					
					col++;

				}
			}
		}

	}

	return col;
}