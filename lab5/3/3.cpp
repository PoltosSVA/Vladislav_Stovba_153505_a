#include <iostream>
#include <iomanip>

using namespace std;

double cin_A(double& i,double& j) {
	double x;
	while (true) {

		cout << "array_A[" << i << "][" << j << "]="; cin >> x;


		


		if (cin.fail() || cin.peek() != '\n') {
			cin.clear();
			cin.ignore(10000, '\n');
			cout << "Повторите ввод: ";
		}
		else {
			return x;
		}
	}

}


int cin_A1(int& i, int& j) {
	int x;
	while (true) {

		cout << "array_A[" << i << "][" << j << "]="; cin >> x;





		if (cin.fail() || cin.peek() != '\n'&&x>0) {
			cin.clear();
			cin.ignore(10000, '\n');
			cout << "Повторите ввод: ";
		}
		else {
			return x;
		}
	}

}






int task_1(int** A, int n, int k, int* B)
{
	int z = n;
	int x = k;

	int** f_A = new int* [z];
	for (int i = 0; i < z; i++) {
		f_A[i] = new int[x];
	}

	int* f_B = new int[x];


	for (int i = 0; i < z; i++) {
		for (int j = 0; j < x; j++) {

			f_A[i][j] = cin_A1(i, j);

		}
	}

	for (int i = 0; i < z; i++) {
		for (int j = 0; j < x; j++) {


			cout << setw(4) << f_A[i][j];
		}
		cout << "\n";
	}


	int col = 0, w = 0;
	for (int i = 0; i < z; i++) {

		for (int j = 0; j < x; j++) {
			if (i == j) {
				if (f_A[i][j] % 2 == 0) {
					f_B[w++] = f_A[i][j];
					col++;
					
				}
			}
		}

	}

	cout << endl;

	int pr = 1;


	for (int j = 0; j < col; j++) {
		pr *= f_B[j];
	}

	for (int i = 0; i < x; i++) {
		delete[]f_A[i];
	}delete[]f_A;
	delete[]f_B;
	return pr;
}

double task_2(double** Ar, int n, int k) {

	int z = n;
	int x = k;

	double** f_A = new double* [z];
	for (int i = 0; i < z; i++) {
		f_A[i] = new double[x];
	}
	int w = 0; int l = 0;
	for (double i = 0; i < z; i++) {
		for (double j = 0; j < x; j++) {

			f_A[w][l++] = cin_A(i, j);

		}
		w++; l = 0;
	}
	int col = 0;
	for (int i = 0; i < z; i++) {
		for (int j = 0; j < x; j++) {
			if (f_A[i][j] == 0) {
				cout << i << " " << j << "|";
				col++;
			}
		}

	}
	cout << endl;
	cout << "col = " << col << endl;

	int m = z-1; 
	for (int i = 0 ; i <z; i++) {
		int n = x - 1;
		for (int j =0 ; j<x/2; j++) {
			
				int temp;
				temp = f_A[m][n];
				f_A[m][n] = f_A[i][j];
				f_A[i][j] = temp;
				n--;
		}
		m--; 
		
	}
	if (x % 2 != 0) {
		m = z - 1;
		int n = x / 2;
		int j = x / 2;
		for (int i = 0; i < z / 2; i++) {
			int temp = f_A[m][n];
			f_A[m][n] = f_A[i][j];
			f_A[i][j] = temp;
			m--;
		}
	}

	for (int i = 0; i < z; i++) {
		for (int j = 0; j < x; j++) {
			cout <<setw(7)<< f_A[i][j];
		}
		cout << endl;
	}


	for (int i = 0; i < z; i++) {
		delete[]f_A[i];
	}delete[]f_A;
	return 0;

}

int task_3(int** A, int n, int k, int* B) {

	int z = n;
	int x = k;

	int** f_A = new int* [z];
	for (int i = 0; i < z; i++) {
		f_A[i] = new int[x];
	}

	int* f_B = new int[x];

	for (int i = 0; i < z; i++) {
		for (int j = 0; j < x; j++) {

			f_A[i][j] = cin_A1(i, j);

		}
	}
	int col = 0, w = 0;
	for (int i = 0; i < z; i++) {
		for (int j = 0; j < x; j++) {
			if (j % 2 == 1) {
				if (f_A[i][j] % 2 == 1 && f_A[i][j] > 0) {
					f_B[w++] = f_A[i][j];
					col++;

				}
			}
		}

	}
	
	cout << endl;
	cout << "col = " << col << endl;
	if (f_B[0] > 0) {

		double sum = 0;
		for (int i = 0; i < col; i++) {
			sum += f_B[i];
		}
		sum /= col;
		return sum;
	}
	else
		return 0;

	for (int i = 0; i < x; i++) {
		delete[]f_A[i];
	}delete[]f_A;
	delete[]f_B;

	
	

}

int k_n()
{
	while (true)
	{

		int num;

		cout << "Кол-во строк: "; cin >> num;


		if (!cin.fail() && num > 0 && cin.peek() == '\n')
		{
			return num;
		}
		else {
			cin.clear();
			cin.ignore(32767, '\n');
			cout << "Некоректный ввод.\n";
		}

	}
}

int k_k()
{
	while (true)
	{

		int num;

		cout << "Кол-во столбцов: "; cin >> num;


		if (!cin.fail() && num > 0 && cin.peek() == '\n')
		{
			return num;
		}
		else {
			cin.clear();
			cin.ignore(32767, '\n');
			cout << "Некоректный ввод.\n";
		}

	}
}

int k_p()
{
	while (true)
	{

		int num;

		cout << "Номер задачи: "; cin >> num;


		if (!cin.fail() &&num>0&&num<=3 && cin.peek() == '\n')
		{
			return num;
		}
		else {
			cin.clear();
			cin.ignore(32767, '\n');
			cout << "Некоректный ввод.\n";
		}

	}
}


int main() {

	setlocale(LC_ALL, "Rus");

	int n=k_n(), k=k_k(), p=k_p();

	int** A = new int* [n];
	for (int i = 0; i < n; i++) {
		A[i] = new int[k];
	}

	int* B = new int[k];

	double** Ar = new double* [n];
	for (int i = 0; i < n; i++) {
		Ar[i] = new double[k];
	}

	if (p == 1) {
	int sum = task_1(A, n, k, B);
	if(sum!=1)
		cout <<"sum = "<< sum;
	}
	if(p==2){
		task_2(Ar, n, k);
	}
	if (p == 3) {
		int sum =task_3(A, n, k, B);
		cout <<"sum = "<< sum;
	}
	return 0;
}