#include "kassa.h"
#include<iostream>
#include<vector>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;
void Check::AddTovar(string name, const Sklad& s, int kollichestvo)
{
	int flag = 0;
	Tovar t(name, s, kollichestvo);
	for (it = tovari.begin(); it != tovari.end(); it++)
	{
		if (t == *it)
		{
			flag = 1;
			it->kolvo += kollichestvo;
			break;
		}
	}
	if (flag == 0)
	{
		tovari.push_back(t);
	}
}
ostream& operator<<(ostream& ostr, Check& ch)
{
	for (ch.it = ch.tovari.begin(); ch.it != ch.tovari.end(); ch.it++)
	{

		cout << *ch.it;
	}
	return ostr;
}
void Check::Delete_tovar(string name, Sklad s, int kollichestvo)
{

	int flag = -1;
	Tovar t(name, s, kollichestvo);
	for (it = tovari.begin(); it != tovari.end(); it++)
	{
		if (t == *it)
		{
			flag = 0;
			if (it->kolvo > 1)
			{
				flag = 1;
				it->kolvo -= kollichestvo;
			}
			break;
		}
	}

	if (flag == 0)
	{
		tovari.erase(it);
	}
}
int Check::summ_sh()
{
	int summa = 0;
	for (it = tovari.begin(); it != tovari.end(); it++)
	{
		summa += it->stoimost;
	}
	return summa;
}
void Check::sort_ch()
{
	sort(tovari.begin(), tovari.end());
}

void Check::vuvod(Check& ch)
{
	ofstream ofs("tovaru_vuvod.txt"); // окрываем файл для записи
	if (ofs.is_open())
	{
		for (ch.it = ch.tovari.begin(); ch.it != ch.tovari.end(); ch.it++)
		{

			ofs << *ch.it;
		}
		//ofs << ch1;
		ofs << "Сумма Вашей покупки: " << ch.summ_sh() << endl;
	}
	ofs.close();
	cout << "Ваш чек готов" << endl;
}

void Check::parser(const Sklad& s)
{
	int kollich;
	string name;
	ifstream ifs("tovaru.txt"); // окрываем файл для чтения
	if (ifs.is_open())
	{
		string currstr;
		while (!ifs.eof())
		{
			getline(ifs, currstr, '\n');
			pair<string, int> res = delenie_str(currstr, s);
			AddTovar(res.first, s, res.second);
		}
	}
	ifs.close();
	//cout << "File has been written" << endl;
}
pair<string, int> Check::delenie_str(string str, const Sklad& s)
{
	pair<string, int> res;
	int i = 0, flag;
	for (i = 0; i < s.size; i++)
	{
		flag = str.find(s.title[i]);
		if (flag >= 0)
		{
			res.first = s.title[i];
			break;
		}
	}
	if (flag == string::npos)
	{
		throw 1;// в строке нет ни одного названия товара
	}

	for (int i = 0; i < str.size(); i++)
	{
		if (isdigit(str[i]))
		{
			res.second = atoi(&str[i]);
			break;
		}
	}
	return res;

}