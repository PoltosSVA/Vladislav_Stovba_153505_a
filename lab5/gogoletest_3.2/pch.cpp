
#include "pch.h"
int Foo(int** A, int col, int z, int x) {

	for (int i = 0; i < z; i++) {
		for (int j = 0; j < x; j++) {
			if (A[i][j] == 0) {

				col++;
			}
		}

	}
	return col;
}