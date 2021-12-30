
#include "pch.h"
int rec(int a) {

	if (a < 0)
		return 0;
	if (a == 0)
		return 1;
	else
		return a * rec(a - 1);
}