#include "kassa.h"
#include <iostream>
#include<string>
#include <cstdlib>
using namespace std;

void Sklad::assortiment()
{
	setlocale(LC_ALL, "Russian");
	cout << "В нашем магазине есть:" << endl;
	for (int i = 0; i < size; i++)
	{
		cout << title[i] << endl;
	}
}

Tovar::Tovar(string nazvanie_, Sklad s, int kolvo)  
{
	for (int i = 0; i < s.size; i++)
	{
		if (nazvanie_ == s.title[i])
		{
			index = i;
		}
	}
	barcode = s.shtrichcode[index];
	name = s.title[index];
	price = s.cost[index];
	kolvo = kolvo;
	discount = s.skidka[index];
}

Tovar Tovar::operator+(const Tovar& t)
{

	if (barcode == t.barcode)
	{
		Tovar nov_tovar = t;
		nov_tovar.kolvo = kolvo + nov_tovar.kolvo;
		return nov_tovar;
	}
	else
	{
		throw 1; //исключение
	}
}
Tovar Tovar::operator-(const Tovar& t)
{
	if (barcode == t.barcode)
	{
		Tovar nov_tovar = t;
		nov_tovar.kolvo = kolvo - nov_tovar.kolvo;
		if (nov_tovar.kolvo < 0) {
			throw "Недопустимая операция: количество товара не может быть отрицательным.";
		}
		return nov_tovar;
	}
	else
	{
		throw 1; //исключение
	}
}
ostream& operator<<(ostream& ostr, Tovar& t)
{
	t.operator_stoimost();
	ostr << "Товар: " << t.name << ", Штрихкод: " << t.barcode << ", Стоимость: " << t.stoimost << ", Количество: " << t.kolvo << endl;
	return ostr;
}
bool Tovar::operator<(const Tovar& t)
{
	// Сравнение товаров по общей стоимости
	// Считается общая стоимость текущего товара (price * (1 - discount)) и товара t, учитывая количество
	// Сравниваются общие стоимости
	return ((price * (100 - discount)) / 100 * kolvo) < (t.price * (100 - t.discount)) / 100 * t.kolvo;
}
void Tovar::operator_stoimost()
{
	stoimost = (price * (100 - discount)) / 100 * kolvo;
}
bool Tovar::operator==(const Tovar& t)
{
	return name == t.name;
}

