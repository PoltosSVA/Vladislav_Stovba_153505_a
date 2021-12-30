#include <iostream>
using namespace std;

int main() {
	int step;
	cin >> step;

	double num;
	
	int col = 0;

	while (step) {

		cin >> num;
		col = 0;
		for (int i = 0; i <= num; i++) {
			if (i % 10 == 9) {
				col++;
			}
		}
		cout << "\t" << col << endl;;
		step--;
	}


	return 0;
}

