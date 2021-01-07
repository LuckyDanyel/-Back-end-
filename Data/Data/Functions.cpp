#include "Functions.h"

void EnterData(Data*& massiveObjects, int& number) { // Ввод начальных данных

	//Переменые для записи
	Name name;
	Book book;
	Shop shop;
	
	massiveObjects = new Data[number];

	for (int i = 0; i < number; i++) {
		cout << "Введите Фамилию: ";
		cin >> name.fisrtName;
		cout << "Введите имя: ";
		cin >> name.surname;
		cout << "Введите отчество: ";
		cin >> name.middleName;
		cout << "Введите id книги - ";
		cin >> book.id;
		cout << "Введите название книги: ";
		cin.ignore();
		getline(cin, book.nameBook);
		cout << "Введите год выпуска книги: ";
		cin >> book.yearIssue;
		cout << "Введите название магазина: ";
		cin.ignore();
		getline(cin, shop.nameShop);
		cout << "Введите информацию о наличие книги: ";
		cin >> shop.presence;
		cout << "Введити количество проданных книг: ";
		cin >> shop.number; 
		// Добавляем данные для каждой структурной пременной класса Data в массив объектов
		massiveObjects[i].EnterDataForMassive(name, book, shop);

		cout << "--------------------------------------------------" << endl;
	}
	
} // Ввод данных
void Print(Data* massiveObjects, int number) { // Вывод данных
	for (int i = 0; i < number; i++) {
		cout << "Данные №" << i + 1 << endl;
		massiveObjects[i].Show();
		cout << "--------------------------------------------" << endl;
	}
} // Вывод данных
void AddData(Data*& massiveObjects, int& number) { // Добавляет запись
	cout << "Введите количество записей, которые требуется добавить: ";
	int newNumberMassive = 0; // Размер нового массива
	cin >> newNumberMassive;
	int oldNumberMassive = number;// Размер старого массива
	number = number + newNumberMassive;
	Data* massiveObjectsTime = new Data[oldNumberMassive];// создание временного массива
	for (int i = 0; i < oldNumberMassive; i++) { // Переносим данные во временный массив
		massiveObjectsTime[i] = massiveObjects[i];
	}
	massiveObjects = new Data[number]; // Создаем пустой массив с обновленным размером
	for (int i = 0; i < oldNumberMassive; i++) {
		massiveObjects[i] = massiveObjectsTime[i]; // Переписываем данные из временного масива в основной массив
	}
	//Переменые для записи
	Name name;
	Book book;
	Shop shop;
	for (int i = oldNumberMassive; i < number; i++) {
		cout << "Введите Фамилию: ";
		cin >> name.fisrtName;
		cout << "Введите имя: ";
		cin >> name.surname;
		cout << "Введите отчество: ";
		cin >> name.middleName;
		cout << "Введите id книги: ";
		cin >> book.id;
		cout << "Введите название книги: ";
		cin.ignore();
		getline(cin, book.nameBook);
		cout << "Введите год выпуска книги: ";
		cin >> book.yearIssue;
		cout << "Введите название магазина: ";
		cin.ignore();
		getline(cin, shop.nameShop);
		cout << "Введите информацию о наличие книги: ";
		cin >> shop.presence;
		cout << "Введити количество проданных книг: ";
		cin >> shop.number;
		// Добавляем данные для каждой структурной пременной класса Data в массив объектов
		massiveObjects[i].EnterDataForMassive(name, book, shop);
		cout << "--------------------------------------------------" << endl;

	}
	
} 
void DeleteData(Data*& massiveObjects, int& number) { // Удаляет данные из базы по id
	int id; // Переменная, которая содержит фамилию автора
	Data Object; // Объект класса, куда будем записывать даныне из массива объктов для перестановки
	cout << "Ведите id книги для того, чтобы удалить все данные о ней из базы " << endl;
	cin >> id; // Вводим фамилию автора				Пример: M[1,2,3,4,5] - Нам надо удалить элемент 3
		for (int i = 0; i < number; i++) { // Осуществляем перебор массива объектов	
			if (massiveObjects[i].getBook().id == id) { // Если введенная фамилия существует	
				massiveObjects[i] = massiveObjects[number - 1]; // M[1,2,5,4,5] // На место найденного объекта ставим послдений элемент массива
				massiveObjects[number--]; // M[1,2,5,4] Удаляем последний элемент
				Object = massiveObjects[i]; // Object = 5;
				massiveObjects[i] = massiveObjects[number - 1]; // M[1, 2, 4, 4]
				massiveObjects[number - 1] = Object; // M[1, 2, 4, 5] // Все это нужно для того, чтобы было соблюление порядка
			}
		}
			if (number == 0) {
				cout << "Вы удалили все записи " << endl;
			}
} 
void SortingData(Data *&massiveObjects, int& number) { // Сортировка методом "Прямой выбор"
	Data object;
	for (int i = 1; i < number; i++) {
		for (int j = 0; j < number; j++) {
			if (massiveObjects[j].getShop().number > massiveObjects[i].getShop().number) {
				object = massiveObjects[j];
				massiveObjects[j] = massiveObjects[i];
				massiveObjects[i] = object;
			}
		}
	}
}
void ShopList(Data*& massiveObjects, int &number) { // Функция предназначена для того, чтобы посмотреть в каких магазигах есть книга одного Автора(по фамилии) и в каком количестве.
	string autor;
	int count = 0; // Переменная для посчета количества книг одного автора для каждого магазина
	string* dataShop = new string[number]; // Массив, куда передаются значения "Название магазина" определенного автора
	string* dataNumberForShop = new string[number]; // Массив куда передаются значения "количество книг" для определенного автора каждого магазина
	int index = 0; // количество добавившихся элементов. Использовался как число, которое определяет размер массива

	cout << "Введите фамилию Автора, чтобы узнать в каких магазинах есть его книга" << endl;
	cin >> autor;
	for (int i = 0; i < number; i++) { // Для начала через цикл for прогоняем и добавляем те элементы, в условиях которых содержится фамилия издателя.
		if (autor == massiveObjects[i].getName().fisrtName && massiveObjects[i].getShop().presence == '+') { // Если Фамилия по выборке совпадает с фамилией в базе данных и книга есть в наличие, то добавляем в массив строк название магазинов, в котром есть книга автора
			dataShop[index] = massiveObjects[i].getShop().nameShop;
			index++;
		}
	}
	for (int i = 0; i < index; i++) { // После массив из повторяющихся элементов прогоняем по двум циклам и добовляем на место повторяющегося элемента пустой символ - " "; 
		for (int m = i + 1; m < index; m++) {
			if (dataShop[i] == dataShop[m]) {
				dataShop[i] = " "; 	// Добавление пустого элемента на место повторяюшегося элемента.
			}
		}
	}
	if (dataShop->empty()) {
		cout << "Ни в одном магазине нет книги Автора - " << autor << endl;
	}
	else {
		cout << "Книга автора - " << autor << " находится в таких магазинах как: " << endl; // Дальше, исключая пустое значение " ", выводим уникальные значения.
		for (int i = 0; i < index; i++) {
			if (dataShop[i] != " ") {
				cout << "| Магазин - " << dataShop[i] << " |";
				for (int j = 0; j < number; j++) {
					if (dataShop[i] == massiveObjects[j].getShop().nameShop && massiveObjects[j].getName().fisrtName == autor) {
						count++;
						dataNumberForShop[i] = to_string(count);
					}
				}
				count = 0;
				cout << " | В количестве - " << setw(5) << dataNumberForShop[i] << " |"<< endl;
			}
		}
	}
}
void Buy(Data*& massiveObjects, int& number)
{
	string nameAutor;
	string nameBook1;
	int numberBook;
	int count = 0;
	cout << "Введите фамилию Автора, название книги и укажите в каком количестве вы желаете приобрести книги " << endl;
	cout << "Введите фамилию: ";
	cin >> nameAutor;
	cout << "Введите название книги: ";
	cin.ignore();
	getline(cin, nameBook1);
	cout << "Введите количество: ";
	cin >> numberBook;
	Shop shop;

			for (int j = 0; j < number; j++) {
				if (massiveObjects[j].getName().fisrtName == nameAutor && massiveObjects[j].getBook().nameBook == nameBook1) {
					massiveObjects[j].setShop('-');
					count++;
					cout << "Count " << endl;
				}
				if (count == numberBook) {
					j = number;
				}
			}
		
	cout << "Книга куплена " << endl;

}
