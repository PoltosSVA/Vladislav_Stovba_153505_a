#pragma once

using namespace std;
extern int N;

struct client {
	char Last_name[30]; // �������
	char First_name[30]; // ���
	char Second_name[30]; // ��������

	char City[30]; // �����
	char Street[30]; // �����
	int house=0; // ���
	int flat=0; // ��������

	int Sale=0; // ������
	
	void set(int i= N-1);
	void get(int i);
};
