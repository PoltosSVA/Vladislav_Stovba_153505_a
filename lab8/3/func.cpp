#include "func.h"
#include "avtor.h"
#include <iostream>
#include "sort.h"
#include <fstream>
#include "file.h"
extern int N;
extern Library* books;
Library* mas = nullptr;
extern int a;

void SortNum(int a) {
	//сортировка вставкой
	int i = 0;
	int j = 0;

	std::string x = mas[j].Avtor();

	std::string y = mas[j - 1].Avtor();

	for (i = 1; i < a; i++) {
		for (j = i; j > 0 && (y > x); j--) {

			Library tmp = mas[j - 1];
			mas[j - 1] = mas[j];
			mas[j] = tmp;
		}
	}

}
Library* func(Library* a) {

	Library* new_a = new Library[N + 1];
	for (int n = 0; n < N; n++) {
		new_a[n] = a[n];

	}
	delete[] a;
	return new_a;
}
Library* cnuf(Library* a, int num) {

	Library* new_a = new Library[N - 1];
	int j = 0;
	for (int n = 0; n < N; n++) {
		if (n != num - 1)
			new_a[j++] = a[n];
	}
	delete[] a;

	return new_a;
}

void Add() {

	books = func(books);
	N++;
	books[N - 1].set();
	A_or_E(books, N);

}
void Del() {
	if (!N) {
		std::cout << "Список пуст...\n\n" << std::endl;
		return;
	}

	int DelNumb;
	std::cout << "\nВведите номер города: ";
	std::cin >> DelNumb;

	if (DelNumb < 1 || DelNumb > N) {

		std::cout << "Нет такого \n";
		return;
	}

	for (int i = DelNumb; i < N; i++) {
		books[i - 1] = books[i];
	}

	books = cnuf(books,DelNumb);
	N--;
	std::cout << "Успешно удален!\n";
	Del(books, DelNumb);
}
void Edit() {
	if (!N) {
		std::cout << "Список пуст\n";
		return;
	}

	int EditNumb;
	std::cout << "\nВведите номер изменяемого: ";
	std::cin >> EditNumb;

	if (EditNumb < 1 || EditNumb > N) {
		std::cout << "Нет такого \n";
		return;
	}

	books[EditNumb - 1].set(EditNumb);
	A_or_E(books, EditNumb);
	
	
}
void Print() {
	if (!N) {
		std::cout << "Список пуст\n";
		return;
	}

	for (int i = 0; i < N; i++) {
		books[i].get(i);
	}
	std::cout << std::endl;
	
}
void Sort() {
	if (!N) {
		printf("Список пуст\n");
		return;
	}
	int am = 0;

	for (int i = 0; i < N; i++) {
		if (books[i].Year() > a);
			am++;
	}

	if (!am) {
		printf("Нет таких\n");
		return;
	}


	mas = (Library*)calloc(am, sizeof(Library));

	int j = 0;
	for (int i = 0; i < N; i++) {
		if (books[i].Year() > a);
			mas[j++] = books[i];
	}
	SortNum(am);
	for (int i = 0; i < am; i++)
		mas[i].get(i);

	printf("\n");

}
