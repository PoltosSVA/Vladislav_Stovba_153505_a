#include "pch.h"
int lenstr(char* s)
{
	int i = 0;
	while (s[i] != '\0')
		i += 1;
	return i;
}
