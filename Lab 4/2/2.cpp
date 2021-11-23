//Лаболаторная 4,задача 2.Выполнено: Стовба В.А.
/* Определить количество положительных элементовбрасположенных ниже
* побочной диагонали матрицы

*/
#include <iostream>
#include <cstdlib>
#include<iomanip>
using namespace std;
const int N = 7, M = 8;
int main() {

	setlocale(LC_ALL, "Rus");

	int mas[N][M];
	int i ;
	int j ;
	int c = 0;
	
	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			mas[i][j] = rand() % 50 - 40;
			cout << mas[i][j] << '\t';
		}
		cout << endl;
	}

	for (i =0; i <N; i++) {

		for (j = 0; j < M; j++) {
			
			int n = N ;
			if (((i+j)>(n-1))&&(mas[i][j] < 0))
					
					c++;
			
			
		}

	}cout << c << endl;

	return 0;
}