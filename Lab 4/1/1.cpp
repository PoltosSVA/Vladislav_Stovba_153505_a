//Лаболаторная 4,задача 1.Выполнено: Стовба В.А.
/* Преобразовать массив следующим образом:все отрицательные элементы
 массива перенести в начало,сохранив исходное взаимное расположени,как среди
 отрицательных так и среди остальных элементов массива*/
#include <iostream>
#include <cstdlib>
using namespace std;
int main()
{
	setlocale(LC_ALL, "Rus");
	int nums[10]{1, -5, 4 ,5, 3, 7, -2, 8, 9, 10};
	int a, b, t,temp;
	int size;
	size = 10; 
	
	//for (t = 0; t < size; t++) nums[t] = rand()%100-50;
	
	cout << "Исходный массив: ";
	for (t = 0; t < size; t++) cout << nums[t] << ' ';
	cout << '\n';
	
	for (a = 0; a < size; a++)
		for (b = size - 1; b > a; b--) {
			if ((nums[b - 1] > nums[b])&&nums[b-1]>0&&nums[b]<0) { 
			
				temp = nums[b - 1];
				nums[b - 1] = nums[b];
				nums[b] = temp;
			}
			
		}


cout << "Отсортированный массив: ";
for (t = 0; t < size; t++)
	cout << nums[t] << ' ';
return 0;
}