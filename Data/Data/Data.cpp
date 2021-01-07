// Project.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.

#include "Data.h"

Data::Data() {
    name.surname = " ";
    name.fisrtName = " ";
    name.middleName = " ";
    book.id = 0;
    book.nameBook = " ";
    book.yearIssue = " ";

    shop.nameShop = " ";
    shop.presence = ' ';
    shop.number = 0;
} // Конструктор без параметром
 
Data::Data(Name name_, Book book_, Shop shop_) {
    name.surname = name_.surname;
    name.fisrtName = name_.fisrtName;
    name.middleName = name_.middleName;
    book.id = book_.id;
    book.nameBook = book_.nameBook;
    book.yearIssue = book_.yearIssue;

    shop.nameShop = shop_.nameShop;
    shop.presence = shop_.presence;
    shop.number = shop_.number;
}// Коснруктор с параметрами

Data::~Data() {} // Деструктор

void Data::Show() {
    cout << "| Издатель: " << name.fisrtName << " " << name.surname[0] <<"." << " " << name.middleName[0] <<"." << endl;
    cout << "| id книги - " << book.id << " | Название книги: " << book.nameBook << " | Год выпуска: " << book.yearIssue << endl;
    cout << "| Название магазина: " << shop.nameShop << " | Информация о наличии: " << shop.presence << " | Количество проданных книг: " << shop.number << endl;
} //Вывод данных

void Data::EnterDataForMassive(Name name_, Book book_, Shop shop_) { // Ввод данных в массив объектов
    name.fisrtName = name_.fisrtName;
    name.surname = name_.surname;
    name.middleName = name_.middleName;

    book.id = book_.id;
    book.nameBook = book_.nameBook;
    book.yearIssue = book_.yearIssue;

    shop.nameShop = shop_.nameShop;
    shop.presence = shop_.presence;
    shop.number = shop_.number;
}



