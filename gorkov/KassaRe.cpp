#include <iostream>
#include <vector>
#include <string>
//#include <locale>
#include <algorithm>
#include <sstream>
//#include <fstream>


using namespace std;

class Tovar
{
	int sh, price, dis, kol;
	string name;
public:
	Tovar(int a, int b, int c, int d, string s) :sh(a), price(b), dis(c), kol(d), name(s) {};
	Tovar(const Tovar& A) {
		sh = A.sh;
		price = A.price;
		dis = A.dis;
		kol = A.kol;
		name = A.name;
	};
	Tovar& operator= (const Tovar& A) {
		sh = A.sh;
		price = A.price;
		dis = A.dis;
		kol = A.kol;
		name = A.name;
		return *this;
	};
	Tovar(string asd, int a = 0, int b = 0, int c = 0, int d = 0) : sh(a), price(b), dis(c), name(asd), kol(d) {};
	Tovar& operator+= (const Tovar& A) {
		if (name == A.name) {
			kol += A.kol;
		}
		return *this;
	}
	bool operator < (const Tovar& A) const {
		return((price * kol) > (A.price * A.kol));
	}

	int get_stoim() {
		int a = (price * kol * (1 - dis / 100));
		return a;
	}
	int get_sh() const
	{
		return sh;
	}
	int get_dis() const
	{
		return dis;
	}
	int get_price() const
	{
		return price;
	}
	int get_kol() const
	{
		return kol;
	}
	string get_name() const
	{
		return name;
	}
	friend ostream& operator<<(ostream& os, const Tovar& A)
	{
		os << "sh: " << A.get_sh() << "price= " << A.get_price() << endl << "dis= " << A.get_dis() << endl << "kol " << A.get_kol() << endl << "name: " << A.get_name() << endl;
		return os;
	}

	friend bool operator ==(const Tovar& A, const Tovar& B);
	friend bool compare(const Tovar& A, const Tovar& B)
	{
		return B.name == A.name;
	}
	friend bool mensh(const Tovar& A, const Tovar& B);
};

bool operator ==(const Tovar& A, const Tovar& B) {
	return (B.name == A.name);
};
bool mensh(const Tovar& A, const Tovar& B)
{
	return((A.get_price() *(1- A.get_dis()) * A.get_kol()) < (B.get_price() * (1 - B.get_dis()) * B.get_kol()));
}


class Sklad
{
	
public:
	static vector <Tovar> sklvec;
	static void add()
	{
		sklvec.push_back(Tovar(1111, 100, 5, 3, "bread"));
		sklvec.push_back(Tovar(2222, 200, 8, 3, "milk"));
		sklvec.push_back(Tovar(3333, 300, 10, 3, "coffee"));
		sklvec.push_back(Tovar(4444, 400, 15, 3, "qwerty"));
		sklvec.push_back(Tovar(5555, 500, 3, 3, "abcd"));
	}
	
	static void incTovar(int a, int b, int c, int d, string s)
	{
		Tovar New(a, b, c, d, s);
		sklvec.push_back(New);
	}
	static void find_tovar(string st)
	{
		Tovar A(st);
		if (find(sklvec.begin(), sklvec.end(), A) != sklvec.end())
			// if все хорошо
		{
			
			cout << (*(find(sklvec.begin(), sklvec.end(), A))) << endl;
		}
		// else
		else cout << "product doesn't exist" << endl;
		
	}

	static void Print()
	{
		for (auto it = sklvec.begin(); it != sklvec.end(); it++)
		{	
			cout << *it << endl;
		}
	}
	friend class Check;
};


class Check
{	//without static don't know how to call sclvec from Sklad
	static vector<Tovar> check;
	static int all_cost;
public:
	//static void add(const Tovar& str, const int& lok)
	static void add(const string& str)
	{
		/*if (find(Sklad::sklvec.begin(), Sklad::sklvec.end(), str) != Sklad::sklvec.end())
		 {
			 all_cost = str.get_price() * (1 - str.get_dis() / 100) * lok; 
			 check.push_back(Tovar())

		 }*/

		 stringstream fin(str);
		 string mm;
		 vector<string> input;
		 while (getline(fin, mm, ' '))
		 {
			 input.push_back(mm);
		 }
		 vector<string>::iterator it;
		 vector<string>::iterator it1;
		 int k = 0;
		 for (it = input.begin(); it != input.end(); it++)
		 {
			 Tovar Tov(*it);
			 if (find((Sklad::sklvec).begin(), Sklad::sklvec.end(), Tov) != Sklad::sklvec.end())
			 {
				 it1 = it;
				 k++;
			 }
		 }
		 if (k != 1) cout << "error" << endl;
		 else
		 {
			 Tovar Pc(*it1);
			 vector<Tovar>::iterator wish = find(check.begin(), check.end(), Pc);
			 vector<Tovar>::iterator real = find(Sklad::sklvec.begin(), Sklad::sklvec.end(), Pc);
			 if (wish != check.end())
			 {
				 if (((*wish).get_kol() + Pc.get_kol()) <= (*(real)).get_kol())
				 {
					 *(wish) += Pc;
				 }
				 else cout<<"too much";
			 }
			 else
			 {
				 Tovar B(*(real));
				 if (B.get_kol() >= Pc.get_kol())
				 {
					 //B.get_kol() = Pc.get_kol();
					 check.push_back(Pc); //was B, but was wrong, because pushed choosen tovar entirely 
				 }
				 else cout<<"not enought on sklad";
			 }
		 }

	}
	static void print_check()
	{
		for (vector<Tovar>::iterator iter = check.begin(); iter != check.end(); ++iter)
			cout << *iter;
	}
	static void sort_check()
	{
		sort(check.begin(), check.end(), mensh);
		reverse(check.begin(), check.end());
		print_check();
	}
};
vector<Tovar> Sklad::sklvec;
vector<Tovar> Check::check;

int main()
{
	cout << "1-print sklad"<<endl<<"  2-enter name of searching tovar"<<endl<<"  3-print check  4-print sort check  5-add tovar in check" << endl;
	Sklad::add();
	string vvod;
	int k;
	do
	{
		cout << "Enter number" << endl;
		cin >> k;
		switch (k)
		{
		case 1:
		{
			Sklad::Print();
			break;
		}
		case 2:
		{
			cout << "name of tovar for search: ";
			string enter;
			cin >> enter;
			Sklad::find_tovar(enter);
			break;
		}
		case 3:
		{

			Check::print_check();

			break;
		}
		case 4:
		{
			Check::sort_check();

			break;
		}
		case 5:
		{
			string vvod;
			cin >> vvod;
			Check::add(vvod);
			break;
		}
		default:
		{
			if (k != 0)
			{
				cout<<"wrong operation"<<endl;
			}
			break;
		}
		}
		} while (k != 0);
	return 0;
}