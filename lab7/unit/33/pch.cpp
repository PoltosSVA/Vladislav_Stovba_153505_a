//
// pch.cpp
//

#include "pch.h"
int raz(int a, int i)
{
	int v= ((a % (int)pow(10, i))) / pow(10, i - 1);
	return v;
}