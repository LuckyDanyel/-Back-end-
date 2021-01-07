#pragma once

#include "Data.h"
//Прототипы функций
void EnterData(Data*& massiveObjects, int& number); //Ввод начальных данных
void Print(Data* massiveObjects, int number); // Вывод записей
void AddData(Data*& massiveObjects, int& number);// Добавляет записи к уже существуюшим
void DeleteData(Data*& massiveObjects, int& number); // Удаляет все запси о книги согалсно id 
void SortingData(Data*& massiveObjects, int& number); //Сортировка по количеству проданных книг
void ShopList(Data*& massiveObjects, int& number); // Возвращает список магазинов, которые хранят хотя бы одну книгу издателя и также возвращает количество книг в каждом магазине определенного автора
void Buy(Data*& massiveObjects, int& number);//Функция покупки 