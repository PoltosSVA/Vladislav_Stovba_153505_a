//
// pch.cpp
//

#include "pch.h"
int Foo(int i, int* A, int N, int z) {
	if (i == N)
		return z;
	else
		if (sin(A[i]) > 0) {

			return Foo(i + 1, A, N, z + 1);
		}
		else
			return Foo(i + 1, A, N, z);
}
