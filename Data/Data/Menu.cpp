#include "Functions.h"
int menu;

void Menu() {
    cout << "Меню управления: " << endl;
    cout << "(0) Выход из программы " << endl;
    cout << "(1) Ввод данных " << endl;
    cout << "(2) Вывод данных " << endl;
    cout << "(3) Добавление данных " << endl;
    cout << "(4) Удаление данных " << endl;
    cout << "(5) Сортировка данных " << endl;
    cout << "(6) Узнать в каких магазинах есть книга определенного Автора " << endl;
    cout << "(7) Купить книгу " << endl;

    cin >> menu;
}
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    
    int sizeGlobal = 0;
    Data* d = new Data[sizeGlobal];
    if (sizeGlobal == 0) {
        cout << "Введите размер базы данных(Массив данных) ";
        cin >> sizeGlobal;
       
        system("cls");
        }
    Menu();
    while (menu != 0) {
        switch (menu) {
        case 1:
            system("cls");
            EnterData(d, sizeGlobal);
            system("cls");
            Menu();
            break;

        case 2:
            system("cls");
            if (sizeGlobal != 0) {
                Print(d, sizeGlobal);
            }
            else {
                cout << "Данные пусты!" << endl;
            }
            system("pause");
            system("cls");
            Menu();
            break;

        case 3:
            system("cls");

            if (sizeGlobal != 0) {
                AddData(d, sizeGlobal);
            }
            else {
                cout << "Данные пусты!";
            }
            system("pause");
            system("cls");
            Menu();
            break;

        case 4:
            system("cls");

            if (sizeGlobal != 0) {
                DeleteData(d, sizeGlobal);
            }
            else {
                cout << "Данные пусты!";
            }
            system("pause");
            system("cls");
            Menu();
            break;
            
        case 5:
            system("cls");

            if (sizeGlobal != 0) {
                SortingData(d, sizeGlobal);
            }
            else {
                cout << "Данные пусты!";
            }
            system("pause");
            system("cls");
            Menu();
            break; 

        case 6:
            system("cls");

            if (sizeGlobal != 0) {
                ShopList(d, sizeGlobal);
            }
            else {
                cout << "Данные пусты!";
            }
            system("pause");
            system("cls");
            Menu();
            break;
        case 7:
            system("cls");

            if (sizeGlobal != 0) {
                Buy(d, sizeGlobal);
            }
            else {
                cout << "Данные пусты!";
            }
            system("pause");
            system("cls");
            Menu();
            break;
        }
     }

}
