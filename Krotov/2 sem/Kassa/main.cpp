#include<iostream>
#include"kassa.h"
#include<string>
#include <cstdlib>
#include <vector>
using namespace std;
int main()
{
	setlocale(LC_ALL, "Russian");
	Check ch1;
	Sklad s;
	string name;
	int kollichestvo;
	int size;
	s.assortiment();
	cout << "------------------------------" << endl;
	ch1.parser(s);
	cout << ch1;
	int yes_no1;
	cout << "Вы хотите удалить товар? Да - 1, нет - 0" << endl; cin >> yes_no1;
	if (yes_no1 == 1)
	{
		cout << "Введите название и сколько штук товара, который хотите убрать" << endl;
		cin >> name >> kollichestvo;
		ch1.Delete_tovar(name, s, kollichestvo);
		cout << ch1;
	}
	int yes_no2;
	cout << "Отсортировать товары по цене?" << endl; cin >> yes_no2;
	if (yes_no2 == 1)
	{
		ch1.sort_ch();
		cout << ch1;
	}
	cout << "Ваш чек:" << endl;
	ch1.vuvod(ch1);
	
}
