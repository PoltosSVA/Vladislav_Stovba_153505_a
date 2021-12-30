//
// pch.cpp
//

#include "pch.h"
int lens(std::string a) {
	int ln = 0;
	while (a[ln])
		ln++;
	return ln;
}