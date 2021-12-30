#include <iostream>
#include "windows.h"
//#include "Крыса.h"
#include <string>
//#include "Функции.h"

using namespace std;
struct client {
    char Last_name[30]; // Фамилия
    char First_name[30]; // Имя
    char Second_name[30]; // Отчество

    char City[30]; // Город
    char Street[30]; // Улица
    int house; // Дом
    int flat; // Квартира

    float Sale; // Скидка

    void set(int i);
    void get(int i);
};
int N = 0;
client* rat = nullptr; // массив структур

void ViewCommands() {
    printf("*********Команды**********\n\nx - Просмотреть команды\nadd - Добавить клиента\nlist - Просмотреть список\ndel - Удалить клиента\nswap - Редактировать клиента\nprint - Просмотреть остортированный список\ncls - Очистить консоль\nexit - Завершить программу\n\n");
}

void client::set(int i) {
    printf("\nКлиент#_%d\n", i);

    printf("\nФамилия: ");
    scanf_s("%s", Last_name, 30);

    printf("\nИмя: ");
    scanf_s("%s", First_name, 30);

    printf("\nГород: ");
    scanf_s("%s", City, 30);

    printf("\nУлица: ");
    scanf_s("%s", Street, 30);

    printf("\nДом: ");
    scanf_s("%d", &house);

    printf("\nКвартира: ");
    scanf_s("%d", &flat);

    printf("\nСкидка: ");
    scanf_s("%f", &Sale);
}
void client::get(int i) {
    printf("\nКлиент#_%d\n", i);

    printf("\nФамилия: %s", Last_name);

    printf("\nИмя: %s", First_name);

    printf("\nГород: %s", City);

    printf("\nУлица: %s", Street);

    printf("\nДом: %d", house);

    printf("\nКвартира: %d", flat);

    printf("\nСкидка: %f\n\n", Sale);

}
void AddClient() {
    rat = (client*)realloc(rat, ++N * sizeof(client));
    rat[N - 1].set(N);
}
void DellClient() {
    if (!N) {
        cout << "Список пуст...\n";
        return;
    }

    int DelNumb; cin >> DelNumb;

    if (DelNumb < 1 || DelNumb > N) {
        cout << "Нет такого \n";
        return;
    }

    for (int i = DelNumb; i < N; i++) {
        rat[i - 1] = rat[i];
    }
    rat = (client*)realloc(rat, --N * sizeof(client));

    cout << "Успешно удален!\n";
}
void EditClient() {
    if (!N) {
        cout << "Список пуст...\n";
        return;
    }

    int EditNumb; cin >> EditNumb;

    if (EditNumb < 1 || EditNumb > N) {
        cout << "Нет такого \n";
        return;
    }

    rat[EditNumb - 1].set(EditNumb);

    cout << "Успешно изменен!\n";
}
void PrintAll() {
    if (!N) {
        cout << "Список пуст...\n";
        return;
    }

    for (int i = 0; i < N; i++) {
        rat[i].get(i + 1);
    }
}
//void Sort() {
//	
//	
//
//	int buff = 0; // для хранения перемещаемого значения
//	int i, j; // для циклов 
//	string a = rat[i].Last_name(N);
//	/************* Начало сортировки *******************/
//	for (i = 1; i < N; i++)
//	{
//		buff = a[i]; // запомним обрабатываемый элемент
//		// и начнем перемещение элементов слева от него
//		// пока запомненный не окажется меньше чем перемещаемый
//		for (j = i - 1; j >= 0 && a[j] > buff; j--)
//			a[j + 1] = a[j];
//
//		a[j + 1] = buff; // и поставим запомненный на его новое место 
//	}
//	/************* Конец сортировки *******************/
//
//	for (int i = 0; i < N; i++) // вывод отсортированного массива
//		cout << a[i] << '\t';
//	cout << endl;
//}
void Cyclecmd() {

    char line;

    do {
        cin >> line;

        if (!strchr("x", tolower(line)))
            ViewCommands();
        else if (!strchr("a", tolower(line)))
            AddClient();
        else if (!strchr("l", tolower(line)))
            PrintAll();
        else if (!strchr("d", tolower(line)))
            DellClient();
        else if (!strchr("s", tolower(line)))
            EditClient();
        /*else if (line == "print")
             Sort();*/
        else if (!strchr("c", tolower(line)))
            system("cls");
        else {
            cout << "Неизвестная команда...\n";
            
        }
    } while (!strchr("e", tolower(line)));

}
void init_list()
{
    int t;
    // Имя нулевой длины означает пустое имя.
    for (t = 0; t < N; t++) *rat[t].Last_name = '\0';
    for (t = 0; t < N; t++) *rat[t].Second_name = '\0';
    for (t = 0; t < N; t++) *rat[t].First_name = '\0';
    for (t = 0; t < N; t++) *rat[t].City = '\0';
    for (t = 0; t < N; t++) *rat[t].Street = '\0';
}

int main()
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    ViewCommands();
   
    init_list();
   

    Cyclecmd();
    return 0;
}