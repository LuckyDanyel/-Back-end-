#include "Functions.h"

void EnterData(Data*& massiveObjects, int& number) { // ���� ��������� ������

	//��������� ��� ������
	Name name;
	Book book;
	Shop shop;
	
	massiveObjects = new Data[number];

	for (int i = 0; i < number; i++) {
		cout << "������� �������: ";
		cin >> name.fisrtName;
		cout << "������� ���: ";
		cin >> name.surname;
		cout << "������� ��������: ";
		cin >> name.middleName;
		cout << "������� id ����� - ";
		cin >> book.id;
		cout << "������� �������� �����: ";
		cin.ignore();
		getline(cin, book.nameBook);
		cout << "������� ��� ������� �����: ";
		cin >> book.yearIssue;
		cout << "������� �������� ��������: ";
		cin.ignore();
		getline(cin, shop.nameShop);
		cout << "������� ���������� � ������� �����: ";
		cin >> shop.presence;
		cout << "������� ���������� ��������� ����: ";
		cin >> shop.number; 
		// ��������� ������ ��� ������ ����������� ��������� ������ Data � ������ ��������
		massiveObjects[i].EnterDataForMassive(name, book, shop);

		cout << "--------------------------------------------------" << endl;
	}
	
} // ���� ������
void Print(Data* massiveObjects, int number) { // ����� ������
	for (int i = 0; i < number; i++) {
		cout << "������ �" << i + 1 << endl;
		massiveObjects[i].Show();
		cout << "--------------------------------------------" << endl;
	}
} // ����� ������
void AddData(Data*& massiveObjects, int& number) { // ��������� ������
	cout << "������� ���������� �������, ������� ��������� ��������: ";
	int newNumberMassive = 0; // ������ ������ �������
	cin >> newNumberMassive;
	int oldNumberMassive = number;// ������ ������� �������
	number = number + newNumberMassive;
	Data* massiveObjectsTime = new Data[oldNumberMassive];// �������� ���������� �������
	for (int i = 0; i < oldNumberMassive; i++) { // ��������� ������ �� ��������� ������
		massiveObjectsTime[i] = massiveObjects[i];
	}
	massiveObjects = new Data[number]; // ������� ������ ������ � ����������� ��������
	for (int i = 0; i < oldNumberMassive; i++) {
		massiveObjects[i] = massiveObjectsTime[i]; // ������������ ������ �� ���������� ������ � �������� ������
	}
	//��������� ��� ������
	Name name;
	Book book;
	Shop shop;
	for (int i = oldNumberMassive; i < number; i++) {
		cout << "������� �������: ";
		cin >> name.fisrtName;
		cout << "������� ���: ";
		cin >> name.surname;
		cout << "������� ��������: ";
		cin >> name.middleName;
		cout << "������� id �����: ";
		cin >> book.id;
		cout << "������� �������� �����: ";
		cin.ignore();
		getline(cin, book.nameBook);
		cout << "������� ��� ������� �����: ";
		cin >> book.yearIssue;
		cout << "������� �������� ��������: ";
		cin.ignore();
		getline(cin, shop.nameShop);
		cout << "������� ���������� � ������� �����: ";
		cin >> shop.presence;
		cout << "������� ���������� ��������� ����: ";
		cin >> shop.number;
		// ��������� ������ ��� ������ ����������� ��������� ������ Data � ������ ��������
		massiveObjects[i].EnterDataForMassive(name, book, shop);
		cout << "--------------------------------------------------" << endl;

	}
	
} 
void DeleteData(Data*& massiveObjects, int& number) { // ������� ������ �� ���� �� id
	int id; // ����������, ������� �������� ������� ������
	Data Object; // ������ ������, ���� ����� ���������� ������ �� ������� ������� ��� ������������
	cout << "������ id ����� ��� ����, ����� ������� ��� ������ � ��� �� ���� " << endl;
	cin >> id; // ������ ������� ������				������: M[1,2,3,4,5] - ��� ���� ������� ������� 3
		for (int i = 0; i < number; i++) { // ������������ ������� ������� ��������	
			if (massiveObjects[i].getBook().id == id) { // ���� ��������� ������� ����������	
				massiveObjects[i] = massiveObjects[number - 1]; // M[1,2,5,4,5] // �� ����� ���������� ������� ������ ��������� ������� �������
				massiveObjects[number--]; // M[1,2,5,4] ������� ��������� �������
				Object = massiveObjects[i]; // Object = 5;
				massiveObjects[i] = massiveObjects[number - 1]; // M[1, 2, 4, 4]
				massiveObjects[number - 1] = Object; // M[1, 2, 4, 5] // ��� ��� ����� ��� ����, ����� ���� ���������� �������
			}
		}
			if (number == 0) {
				cout << "�� ������� ��� ������ " << endl;
			}
} 
void SortingData(Data *&massiveObjects, int& number) { // ���������� ������� "������ �����"
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
void ShopList(Data*& massiveObjects, int &number) { // ������� ������������� ��� ����, ����� ���������� � ����� ��������� ���� ����� ������ ������(�� �������) � � ����� ����������.
	string autor;
	int count = 0; // ���������� ��� ������� ���������� ���� ������ ������ ��� ������� ��������
	string* dataShop = new string[number]; // ������, ���� ���������� �������� "�������� ��������" ������������� ������
	string* dataNumberForShop = new string[number]; // ������ ���� ���������� �������� "���������� ����" ��� ������������� ������ ������� ��������
	int index = 0; // ���������� ������������ ���������. ������������� ��� �����, ������� ���������� ������ �������

	cout << "������� ������� ������, ����� ������ � ����� ��������� ���� ��� �����" << endl;
	cin >> autor;
	for (int i = 0; i < number; i++) { // ��� ������ ����� ���� for ��������� � ��������� �� ��������, � �������� ������� ���������� ������� ��������.
		if (autor == massiveObjects[i].getName().fisrtName && massiveObjects[i].getShop().presence == '+') { // ���� ������� �� ������� ��������� � �������� � ���� ������ � ����� ���� � �������, �� ��������� � ������ ����� �������� ���������, � ������ ���� ����� ������
			dataShop[index] = massiveObjects[i].getShop().nameShop;
			index++;
		}
	}
	for (int i = 0; i < index; i++) { // ����� ������ �� ������������� ��������� ��������� �� ���� ������ � ��������� �� ����� �������������� �������� ������ ������ - " "; 
		for (int m = i + 1; m < index; m++) {
			if (dataShop[i] == dataShop[m]) {
				dataShop[i] = " "; 	// ���������� ������� �������� �� ����� �������������� ��������.
			}
		}
	}
	if (dataShop->empty()) {
		cout << "�� � ����� �������� ��� ����� ������ - " << autor << endl;
	}
	else {
		cout << "����� ������ - " << autor << " ��������� � ����� ��������� ���: " << endl; // ������, �������� ������ �������� " ", ������� ���������� ��������.
		for (int i = 0; i < index; i++) {
			if (dataShop[i] != " ") {
				cout << "| ������� - " << dataShop[i] << " |";
				for (int j = 0; j < number; j++) {
					if (dataShop[i] == massiveObjects[j].getShop().nameShop && massiveObjects[j].getName().fisrtName == autor) {
						count++;
						dataNumberForShop[i] = to_string(count);
					}
				}
				count = 0;
				cout << " | � ���������� - " << setw(5) << dataNumberForShop[i] << " |"<< endl;
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
	cout << "������� ������� ������, �������� ����� � ������� � ����� ���������� �� ������� ���������� ����� " << endl;
	cout << "������� �������: ";
	cin >> nameAutor;
	cout << "������� �������� �����: ";
	cin.ignore();
	getline(cin, nameBook1);
	cout << "������� ����������: ";
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
		
	cout << "����� ������� " << endl;

}
