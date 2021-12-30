#include "func.h"
#include <iostream>
#include "rat.h"
using namespace std;

extern int N;
extern client* rat;
extern client* mas = nullptr;

void SortNum(int a) {
	//сортировка вставкой
	int i = 0;
	int j = 0;

	std::string x = mas[j].Last_name;

	std::string y = mas[j - 1].Last_name;

	for (i = 1; i < a; i++) {
		for (j = i; j > 0 && (y > x); j--) {

			client tmp = mas[j - 1];
			mas[j - 1] = mas[j];
			mas[j] = tmp;
		}
	}

}
client* func(client* a) {

	client* new_a = new client[N+1];
	for (int n = 0; n < N; n++) {
		new_a[n] = a[n];
		
	}
	delete[] a; 
	return new_a;
}
client* cnuf(client* a,int num) {

	client* new_a = new client[N-1];
	int j = 0;
	for (int n = 0; n < N; n++) {
		if(n !=num - 1)
		new_a[j++] = a[n];
	}
	delete[] a;  
	
	return new_a;
}

void AddClient() {

	
	
	rat=func(rat);
	
	N++;
	rat[N - 1].set(N);
}
void DellClient() {
	if (!N) {
		printf("Список пуст...\n");
		return;
	}

	int DelNumb; cin >> DelNumb;

	if (DelNumb < 1 || DelNumb > N) {
		
		printf("Нет такого \n");
		return;
	}

	for (int i = DelNumb; i < N; i++) {
		rat[i - 1] = rat[i];
	}

	//rat = (client*)realloc(rat, --N * sizeof(client));
	rat = cnuf(rat,DelNumb);

	N--;
	
	printf("Успешно удален!\n");
	
}
void EditClient() {
	if (!N) {
		printf("Список пуст\n");
		return;
	}

	int EditNumb; cin >> EditNumb;

	if (EditNumb < 1 || EditNumb > N) {
		printf("Нет такого \n");
		return;
	}
	
	rat[EditNumb - 1].set(EditNumb);

	printf("Успешно изменен!\n");
}
void PrintAll() {
	if (!N) {
		printf("Список пуст\n");
		return;
	}
	
	for (int i = 0; i < N; i++) {
		rat[i].get(i + 1);
	}
	
}
void Sort() {
	if (!N) {
		printf("Список пуст\n");
		return;
	}
	int am = 0;

	for (int i = 0; i < N; i++) {
		if ((rat[i].Sale) == 5)
			am++;
	}

	if (!am) {
		printf("Нет таких\n");
		return;
	}


	mas = (client*)calloc(am, sizeof(client));

	int j = 0;
	for (int i = 0; i < N; i++) {
		if (rat[i].Sale == 5)
			mas[j++] = rat[i];
	}
	SortNum(am);
	for (int i = 0; i < am; i++)
		mas[i].get(i+1); 
	
	printf("\n");

}
