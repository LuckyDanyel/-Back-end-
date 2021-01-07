#include "Functions.h"
int menu;

void Menu() {
    cout << "���� ����������: " << endl;
    cout << "(0) ����� �� ��������� " << endl;
    cout << "(1) ���� ������ " << endl;
    cout << "(2) ����� ������ " << endl;
    cout << "(3) ���������� ������ " << endl;
    cout << "(4) �������� ������ " << endl;
    cout << "(5) ���������� ������ " << endl;
    cout << "(6) ������ � ����� ��������� ���� ����� ������������� ������ " << endl;
    cout << "(7) ������ ����� " << endl;

    cin >> menu;
}
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    
    int sizeGlobal = 0;
    Data* d = new Data[sizeGlobal];
    if (sizeGlobal == 0) {
        cout << "������� ������ ���� ������(������ ������) ";
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
                cout << "������ �����!" << endl;
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
                cout << "������ �����!";
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
                cout << "������ �����!";
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
                cout << "������ �����!";
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
                cout << "������ �����!";
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
                cout << "������ �����!";
            }
            system("pause");
            system("cls");
            Menu();
            break;
        }
     }

}
