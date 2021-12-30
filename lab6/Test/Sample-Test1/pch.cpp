
#include "pch.h"
#include <iostream>
#include <cstring>


int func(char* A,int x) {

	
	

	

	A[x] = ' ';
	A[x + 1] = '\0';

	int am = 0, j = 0;
	for (int i = 0; i < x; i++) {

		if (A[i] == ' ' || A[i] == '\0') {
			if (i - j == 5)
				am++;

			j = i + 1;
		}

	}

	return am;

}
