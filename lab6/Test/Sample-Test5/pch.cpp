
#include "pch.h"
int s_s1(char* str_1, char* str_2, int len, int dl_1, int dl_2, int m,int col) {
	
	int S1 = 0; int v;
	if (((dl_1 + dl_2) == len) && col == 0) {
		S1 = 2;

		return 0;
	}
	else if (((dl_1 + dl_2 - col) == len)) {

		S1 = 1;

	}
	else if (((dl_1 + dl_2 - col) > len)) {

		S1 = 0;
	}

	else if ((v = len - dl_1 - dl_2 + col) >= 0) {
		col = v;
		S1 = (int)pow(26, col) % m;

	}
	return S1;
}