//
// pch.cpp
//

#include "pch.h"
int func(char* A,int prise) {
	int am = 0;
	for (int i = 0; i < strlen(A) + 1; i++) {
		if (A[i] == ' ' || A[i] == '\0')
			am++;
	}
	return am*prise;
}