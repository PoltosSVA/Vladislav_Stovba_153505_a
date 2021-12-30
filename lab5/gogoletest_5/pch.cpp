
#include "pch.h"
int rec(int k, int n, int r) {

	if (n == 0 && r == 0) {
		return 1;
	}
	if (n > 0 && r >= 0 && r < (n * (k - 1) + 1)) {
		int S = 0;
		for (int i = 0; i <= k - 1; i++) {
			S += rec(k, n - 1, r - i);
		}
		return S;
	}
	else {
		return 0;
	}



}