#include <iostream>
#include <iomanip>
#include <string>
#include <Windows.h>


using namespace std;

/*
		Данные о издателе:
		ФИО
		Название книги
		Год выпуска
		Данные о магазине:
		Название магазина
		Пометка о наличие
		Количестов проданных книг
*/

struct Name {
	string surname, fisrtName, middleName;
};

struct Book {
	int id; // Уникальное поле. Ключ. 
	string nameBook, yearIssue;

};

struct Shop {
	string nameShop;
	char presence;
	int number;
};

class Data {
private:
	Name name;
	Book book;
	Shop shop;
public:
	Data();
	Data(Name name_, Book book_, Shop shop_);
	~Data();

	void Show();
	void EnterDataForMassive(Name name_, Book book_, Shop shop_);

	Name getName() { return name; }
	Book getBook() { return book; }
	Shop getShop() { return shop; }
	void setShop(char presense_) {
		 shop.presence = presense_;
	}
};