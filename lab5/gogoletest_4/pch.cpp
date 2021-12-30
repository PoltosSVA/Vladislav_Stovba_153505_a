
#include "pch.h"
int F(int n, int i, int s, int z) {

	if (i == z - 1) {
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