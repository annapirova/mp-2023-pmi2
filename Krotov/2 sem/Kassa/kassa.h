#include <iostream>
#include<vector>
#include <algorithm>
using namespace std;
class Sklad
{
public:
	const int size = 5;
	int shtrichcode[5] = { 1111,2222,3333,4444,5555 };
	int cost[5] = { 50,60,100,30,25 };
	string title[5] = { "tomato", "protein", "beer", "water", "watermelon" };
	int skidka[5] = { 0,20,10,0,0 };
	void assortiment();
	friend class Tovar;
};
class Tovar
{
	int kolvo;
	double stoimost;
	double price;
	int discount;
	int barcode;
	int index;
	string name;
public:
	Tovar(string nasvanie_, Sklad s, int kolvo = 1);
	Tovar operator+(const Tovar& t);
	Tovar operator-(const Tovar& t);
	bool operator<(const Tovar& t);
	friend ostream& operator<<(ostream& ostr, Tovar& t);
	void operator_stoimost();
	bool operator==(const Tovar& t);
	friend class Check;
	friend class Sklad;
};
class Check
{
	std::vector<Tovar> tovari;
	vector <Tovar>::iterator it;
public:
	void AddTovar(string name, const Sklad& s, int kollichestvo);
	friend ostream& operator<<(ostream& ostr, Check& ch);
	void Delete_tovar(string name, Sklad s, int kollichestvo);
	int summ_sh();
	void sort_ch();
	void vuvod(Check& ch);
	void parser(const Sklad& s);
	pair<string, int> delenie_str(string str, const Sklad& s);
	friend class Tovar;
};
