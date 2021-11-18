#include <iostream>
#include<iomanip>
#include <cmath>

using namespace std;

int main() {
	int n, imin, imax, max, min, i, q = 0;

	cin >> n;

	int* array = new int[n];
	int* array_new = new int[n];
	for (int i = 0; i < n; i++) {

		cin >> array[i];

	}

	for (int i = 0; i < n; i++) {

		cout << array[i] << "  ";


	}
	cout << endl;
	min = max = array[0];
	imin = imax = 0;
	for (i = 0; i < n; i++) {

		if (array[i] < min) {
			min = array[i];
			imin = i;

		}
		if (array[i] > max) {
			max = array[i];
			imax = i;
		}

	}
	cout << "index max: " << imax << endl;
	cout << "index min: " << imin << endl;
	//cout << imax << endl;
	//cout << imin ;
	if (imin < imax) {
		for (i = (imin + 1); i < (imax); i++) {
			array[i] = 0;

		}
	}

	else {
		for (i = (imax + 1); i < (imin); i++) {
			array[i] = 0;

		}
	}
	for (i = 0; i < n; i++) {
		cout << array[i] << " ";
	}


	int col = 0;
	for (int i = 0; i < n; i++) {
		if (array[i] == 0) {
			col++;
		}
	}
	cout << "amount:  " << col << endl;
	for (i = 0; i < n; i++) {
		cout << array[i] << " ";
	}
	cout << endl;
	if (col > n / 2) {






		for (i = 0; i < n; i++) {
			if (array[i] != 0)
				array_new[q++] = array[i];
		}
		n -= col;
		for (int i = 0; i < n; i++) {
			cout << array_new[i] << " ";
		}
	}



	delete[]array;
	return 0;
}
