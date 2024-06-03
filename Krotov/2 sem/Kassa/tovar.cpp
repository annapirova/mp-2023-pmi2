#include "kassa.h"
#include <iostream>
#include<string>
#include <cstdlib>
using namespace std;
/*int shtrich[3] = {1111,2222,3333};
int cena[3] = { 50,60,100 };
string nazvanie[3] = { "milk", "sok", "ice"};
int skidka[3] = { 0,20,10 };*/
void Sklad::assortiment()
{
	setlocale(LC_ALL, "Russian");
	cout << "В нашем магазине есть:" << endl;
	for (int i = 0; i < size; i++)
	{
		cout << title[i] << endl;
	}
}

Tovar::Tovar(string nazvanie_, Sklad s, int kolvo)  //конструктор, узнали все характеристики товара, по названию нашли номер товара 
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
//в контрускторе ничего не выделяли поэтому диструктор пустой
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
		return nov_tovar;
	}
	else
	{
		throw 1; //исключение
	}
}
ostream& operator<<(ostream& ostr, Tovar& t) //убрала const
{
	//t.stoimost = t.price * t.discount * t.kollichestvo;
	t.operator_stoimost();
	ostr << "Tovar: " << "name-" << t.name << ", " << "shtrichkod-" << t.barcode << ", " << "stoimost-" << t.stoimost << ", " << "kollichestvo-" << t.kolvo << endl;
	return ostr;
}
bool Tovar::operator<(const Tovar& t)
{
	bool res = true;
	if (((price * (100 - discount)) / 100 * kolvo) > (t.price * (100 - t.discount)) / 100 * t.kolvo) //поставила обратное услувие, почему неправильно если пишешь !<
	{
		res = false;
	}
	return res;
}
void Tovar::operator_stoimost()
{
	stoimost = (price * (100 - discount)) / 100 * kolvo;
}
bool Tovar::operator==(const Tovar& t)
{
	if (name == t.name)
	{
		return true;
	}
	else
	{
		return false;
	}
}

