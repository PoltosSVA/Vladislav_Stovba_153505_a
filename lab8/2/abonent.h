#pragma once
#include <string>


extern int N;

struct Abonent {
	
	char tarif[30];

	int hour=0;
	int min=0;
	long long  number=0;//номер телефона v gorode
	long long number_ab=0;//номер абонента
	int cod=0;//код
	int day = 0;
	int mon = 0;
	int year = 0;
	int time_sp = 0;//Плата за разговор

	void set(int i = N - 1);
	void get(int i);
};