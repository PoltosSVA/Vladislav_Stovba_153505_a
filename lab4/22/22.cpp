
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Rus");

	const int N = 7, M = 8;
	int mas[N][M];

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			mas[i][j] = rand() % 50 - 10;
			cout << setw(6) << mas[i][j];
		}
		cout << endl;
	}

	cout << endl;
	int stop = 0;
	int count = 0;
	for (int i = N - 1; i >= 0; i--) {
		for (int j = M - 1; j > stop; j--) {
			if (mas[i][j] < 0) {
				cout << mas[i][j] << endl;
				count++;
			}
			
		}
		stop++;
	}

	cout << endl << count;
}

