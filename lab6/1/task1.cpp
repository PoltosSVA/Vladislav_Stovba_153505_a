#include <iostream>
#include <cstring>
using namespace std;
int func(char* A, int x);
int main() {

	char str[80];
	gets_s(str);

	int l = strlen(str);

	int v = func(str, l);
	cout << v;

}
int func(char* A, int x) {

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