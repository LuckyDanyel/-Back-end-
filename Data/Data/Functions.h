#pragma once

#include "Data.h"
//��������� �������
void EnterData(Data*& massiveObjects, int& number); //���� ��������� ������
void Print(Data* massiveObjects, int number); // ����� �������
void AddData(Data*& massiveObjects, int& number);// ��������� ������ � ��� ������������
void DeleteData(Data*& massiveObjects, int& number); // ������� ��� ����� � ����� �������� id 
void SortingData(Data*& massiveObjects, int& number); //���������� �� ���������� ��������� ����
void ShopList(Data*& massiveObjects, int& number); // ���������� ������ ���������, ������� ������ ���� �� ���� ����� �������� � ����� ���������� ���������� ���� � ������ �������� ������������� ������
void Buy(Data*& massiveObjects, int& number);//������� ������� 