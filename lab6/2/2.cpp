#include <iostream>
#include <cstring>

using namespace std;
int func(char* A);
int main() {

	char* str = new char[100];
	cin.getline(str, 100);

	int price = 0;
	cin >> price;
	

	int k = func(str);



	cout << k * price;

}
int func(char* A) {
	int am = 0;
	for (int i = 0; i < strlen(A) + 1; i++) {
		if (A[i] == ' ' || A[i] == '\0')
			am++;
	}
	return am;
}