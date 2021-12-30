#include <iostream>
#include "windows.h"
#include "rat.h"
#include <string>
#include "func.h"

using namespace std;

int N = 0;
client* rat = nullptr; // массив структур

void ViewCommands() {
    
    printf("*********Команды**********\n\ncmd - Просмотреть команды\nadd - Добавить клиента\nlist - Просмотреть список\ndel - Удалить клиента\nedit - Редактировать клиента\nprint - Просмотреть остортированный список\ncls - Очистить консоль\nexit - Завершить программу\n\n");
}


void Cyclecmd() {

    char line[80];
    
    do {
        scanf_s("%s", line,30);

        if (!strcmp(line, "cmd"))
            ViewCommands();
        else if (!strcmp(line, "add"))
            AddClient();
        else if (!strcmp(line, "list"))
            PrintAll();
        else if (!strcmp(line, "del"))
            DellClient();
        else if (!strcmp(line, "edit"))
            EditClient();
        else if (!strcmp(line, "print"))
             Sort();
        else if (!strcmp(line, "cls"))
            system("cls");
        else if (strcmp(line, "exit"))
            printf("Неизвестная команда...\n");
    } while (strcmp(line, "exit"));

}


int main()
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    ViewCommands();

    Cyclecmd();
    return 0;
}
