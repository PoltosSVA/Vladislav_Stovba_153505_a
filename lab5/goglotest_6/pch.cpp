
#include "pch.h"
int rec(int n)

{

	int z = (n + 1) / 2;

	if (n == 0)
		return 0;


	return z * z + rec(n / 2);

}