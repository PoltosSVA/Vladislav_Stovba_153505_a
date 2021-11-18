#include <iostream>
#include<malloc.h>

using namespace std;

int main() {
	int n, m,i,j,Z,X,C;
	cin >> n;
	cin >> m;

	int* array;
	array = (int*)malloc(n * m * sizeof(int));
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			cin >> array[i][j];
		}
	}
	
	/*for (i = 0; i < n; i++)  // цикл по строкам
	{
		for (j = 0; j < m; j++)  // цикл по столбцам
		{
			printf("%5d ", *(array + i * m + j)); // 5 знакомест под элемент массива
		}
		printf("\n");
	}*/
	/*for (int i = 0; i < n; i++) {
		for (int j = 0; j <m; j++) {
			cin >> array[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << array[i][j] << "  ";
		}
		cout << endl;
	}*/

	free(array);
	return 0;
}