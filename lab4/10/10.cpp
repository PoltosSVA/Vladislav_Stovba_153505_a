//Лаболаторная 4,задача 10.Выполнено: Стовба В.А.
/* Построить магический квадрат любого порядка, используя любой
алгоритм. Выделение памяти через функции языка С

*/

#include <iostream>
#include <iomanip>

using namespace std;

int cin_N();
void change(int* a, int* b);

//квадраты
int** nechet_magic(int** magic, int per);
int** chet_chet_magic(int** magic, int per);
int** chet_nechet_magic(int** magic, int per);

int main() {

	setlocale(LC_ALL, "Rus");

	int N=cin_N();

	//маг квадрат

	int** magic = (int**)malloc(N * sizeof(int*));
	for (int i = 0; i < N; i++) {
		magic[i] = (int*) malloc(N * sizeof(int));
	}

	//строим квадрат в зависимости от четности
	if (N % 2 == 1) {
		magic = nechet_magic(magic, N);
	}
	else if (N % 4 == 0) {
		magic = chet_chet_magic(magic, N);
	}
	else if (N % 2 == 0 && N % 2 != 4) {
		magic = chet_nechet_magic(magic, N);
	}
	else {
		cout << "Неверный квадрат";
	}
	
	int max = N * N;//max улемент в квадрате
	int z = 0;
	while (max >= 1) {
		z++;
		max /= 10;
	}
	z += 2;//ширина вывода

	cout << "\n";
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << setw(z) << magic[i][j];
		}
		cout << "\n";
	}

	cout << "\nCуммы в строках: \n";
	int sum = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			sum += magic[i][j];
		}
		cout << sum << endl;
		sum = 0;
	}

	cout << "\nCуммы в столбцах: \n";
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			sum += magic[i][j];
		}
		cout << sum << endl;
		sum = 0;
	}

	cout << "\nCумма в главной диагонали: \n";
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (i == j) {
				sum += magic[i][j];
			}
		}
		
	}
	cout << sum << endl;
	sum = 0;

	cout << "\nCумма в побочной диагонали: \n";

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (i + j == N - 1) {
				sum += magic[i][j];
			}
		}
		
	}
	cout << sum << endl;

	for (int i = 0; i < N; i++) {
		free(magic[i]);
	} free(magic);

	return 0;
}

int cin_N() {


	int x;

	// Пока не будет введено корректное значение
	while (true) {

		cout << "Введите сторону квадрата: "; cin >> x;

		// Пропуск пробелов после элемента
		while (cin.peek() == ' ')
			cin.ignore(1, ' ');

		// Проверка предыдущего извлечения данных из буфера
		// Извлечение неудачное / удачное, но остались неизвлеченные символы / число отрицательное/число меньшее либо равное 2
		if (cin.fail() || cin.peek() != '\n' || x <= 0|| x <= 2) {
			cin.clear(); // Возвращение в обычный режим работы
			cin.ignore(10000, '\n'); // Игнор 'n' символов до Enter
			cout << "Повторите ввод: ";
		}
		else {
			return x;
		}
	}

}

int** nechet_magic(int** magic, int per) {
	//метод террас
	int N = per;

	int N_full = N + (N / 2) * 2;//сторона полного квадрата
	//полный квадрат - квадрат включающий основной + квадрат находящийся под углом 45
	int** full = (int**)malloc(N_full * sizeof(int*));
	for (int i = 0; i < N_full; i++) {
		full[i] = (int*)malloc(N_full * sizeof(int));
	}

	//заполняем 0-ми

	for (int i = 0; i < N_full; i++) {
		for (int j = 0; j < N_full; j++) {
			full[i][j] = 0;
		}
	}

	//m,n координаты для заполнения слева направо под углом 45
	int m = N_full / 2, m_con;
	int n = 0, n_con;

	int start = 1;// от какого числа идут елементы в строке
	int end = N;

	for (int i = 0; i < N; i++) {
		m_con = m; n_con = n;
		for (int j = start; j <= end; j++) {
			full[m--][n++] = j;
		}
		start += N; end += N;
		m = m_con + 1; n = n_con + 1;
	}

	//h террасы
	int h_terr = N / 2;

	//левая терраса
	for (int i = h_terr + 1; i <= h_terr + N - 2; i++) {
		for (int j = 0; j < h_terr; j++) {
			if (full[i][j] != 0) {
				full[i][j + N] = full[i][j];
			}
		}
	}
	//правая терраса
	for (int i = h_terr + 1; i <= h_terr + N - 2; i++) {
		for (int j = N_full-1; j >N+ h_terr-1; j--) {
			if (full[i][j] != 0) {
				full[i][j - N] = full[i][j];
			}
		}
	}
	//верхняя терраса
	for (int i = 0; i < h_terr ; i++) {
		for (int j = h_terr+1; j < h_terr+N-1; j++) {
			if (full[i][j] != 0) {
				full[i+N][j] = full[i][j];
			}
		}
	}
	//нижняя терраса
	for (int i = h_terr + N; i <= N_full-1; i++) {
		for (int j = h_terr+1; j < h_terr+N-1; j++) {
			if (full[i][j] != 0) {
				full[i-N][j] = full[i][j];
			}
		}
	}

	m = 0; n = 0;
	for (int i = h_terr; i < N_full - h_terr; i++) {
		for (int j = h_terr; j < N_full - h_terr; j++) {
			magic[m][n++] = full[i][j];
		}
		m++; n = 0;
	}

	for (int i = 0; i < N_full; i++) {
		free(full[i]);
	} free(full);

	return magic;
}

int** chet_chet_magic(int** magic, int per) {
	//Метод Рауз-Болла
	int N = per;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			magic[i][j] = (j + 1) + i * N;
		}
	}

	int** obr = (int**)malloc(N * sizeof(int*));
	for (int i = 0; i < N; i++) {
		obr[i] = (int*)malloc(N * sizeof(int));
	}
	//заполняем квадрат с N^2 до 1
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			obr[i][j] = N * N - (j + i * N);
		}
	}
	
	int n = 0, m = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			n = i;
			m = j;

			while (n > 3) {
				n -= 4;
			}
			while (m > 3) {
				m -= 4;
			}

			if (n == m || n + m == 3)
				magic[i][j] = obr[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		free(obr[i]);
	} free(obr);

	return magic;

}

int** chet_nechet_magic(int** magic, int per) {

	int N = per;

	int N_min = N / 2;//размерность 4-х мал квадратов

	int** min = (int**)malloc(N_min * sizeof(int*));
	for (int i = 0; i < N; i++) {
		min[i] = (int*)malloc(N_min * sizeof(int));
	}

	//делаем min квадрат магическим

	min = nechet_magic(min, N_min);

	for (int i = 0; i < N_min; i++) {
		for (int j = 0; j < N_min; j++) {
			magic[i][j] = min[i][j];
		}
	}

	//Остальные квадраты

	int add = N_min * N_min;//добавим к элементам 3-х квадратов
	int m = 0, n = 0;
	//справа
	for (int i = 0; i < N_min; i++) {
		for (int j = N_min; j < N; j++) {
			magic[i][j] = min[m][n++] + add * 2;
		}
		m++; n = 0;
	}
	//под
	m = 0, n = 0;
	for (int i = N_min; i < N; i++) {
		for (int j = 0; j < N_min; j++) {
			magic[i][j] = min[m][n++] + add * 3;
		}
		m++; n = 0;
	}
	//право-низ
	m = 0, n = 0;
	for (int i = N_min; i < N; i++) {
		for (int j = N_min; j < N; j++) {
			magic[i][j] = min[m][n++] + add * 1;
		}
		m++; n = 0;
	}
	for (int i = 0; i < N_min; i++) {
		free(min[i]);
	}free(min);


	//меняем некоторые элементы местами
	change(&magic[0][0], &magic[N_min][0]);
	change(&magic[N_min-1][0], &magic[N-1][0]);

	for (int i = 1; i < N_min - 1; i++) {
		change(&magic[i][1], &magic[i+N_min][1]);
	}

	int x = (N - 2) / 4 - 1;
	for (int i = 0; i < N_min; i++) {
		for (int j = N_min - x; j < N_min + x; j++) {
			change(&magic[i][j], &magic[i+N_min][j]);
		}
	}
	
	return magic;

}

void change(int*a,int*b){
	int temp = *a;
	*a = *b;
	*b = temp;
}
