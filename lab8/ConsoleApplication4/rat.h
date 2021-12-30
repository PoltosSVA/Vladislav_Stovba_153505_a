#pragma once

using namespace std;
extern int N;

struct client {
	char Last_name[30]; // Фамилия
	char First_name[30]; // Имя
	char Second_name[30]; // Отчество

	char City[30]; // Город
	char Street[30]; // Улица
	int house=0; // Дом
	int flat=0; // Квартира

	int Sale=0; // Скидка
	
	void set(int i= N-1);
	void get(int i);
};
