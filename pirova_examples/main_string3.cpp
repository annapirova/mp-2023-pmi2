#include <string>
#include <iostream>
#include <locale>
#include <vector>
#include <algorithm>
#include <fstream>


using namespace std;

bool func(string& s)
{
	if (s[0] == 'v')
		return true;
	else return false;
}

void main()
{
	string s1 = "hello";
	string letters = "aeoiu";
	std::size_t pos = s1.find_first_of(letters);
	cout << pos << "\n";
	cout << "all vowels\n";
	while (pos != std::string::npos)
	{
		pos = s1.find_first_of(letters, pos + 1);
		cout << pos << "\n";
	}

	// replase all vowels to Uppercase
	locale loc;
	pos = s1.find_first_of(letters);
	s1[pos] = toupper(s1[pos], loc);
	while (pos != std::string::npos)
	{
		pos = s1.find_first_of(letters, pos + 1);
		if (pos != std::string::npos)
			s1[pos] = toupper(s1[pos], loc);
	}
	cout << s1 << endl;

	std::getline(std::cin, s1);
	cout << "line: " << s1 << endl;

	// format string
	s1.insert(s1.begin(), 3, ' ');
	cout << s1 << endl;
	int k = s1.find('.');
	vector<string> v;
	v.push_back(s1.substr(0, k));
	v.push_back(s1.substr(k + 1, s1.length() - (k + 1)));
	cout << v[0] << endl << v[1] << endl;
	s1.replace(2, 2, "vasya");
	cout << s1 << endl;
	s1.replace(s1.begin() + 1, s1.begin() + 3, "valya");
	cout << s1 << endl;
	string::iterator it2;
	pos = s1.find("valya");
	it2 = s1.begin() + pos;
	s1.erase(it2, it2 + 5);
	cout << s1 << endl;

	v.clear();
	v.push_back("vasya");
	v.push_back("vanya");
	v.push_back("kolya");
	cout << count(v.begin(), v.end(), "vasya") << "\n";
	cout << count_if(v.begin(), v.end(), func) << "\n";
	vector<string>::iterator it = v.begin();
	while (it != v.end())
	{
		it = find_if(it, v.end(), func);
		if (it != v.end())
		{
			cout << *it << "\n";
			it++;
		}
	}

	ofstream of("select.txt");
	if (of)
	{
		for (it = v.begin(); it != v.end(); it++)
			of << *it << "\n";
	}
	of.close();


	vector<string> newV;
	string tmp;
	ifstream myfile("select.txt");
	if (myfile.is_open())
	{
		while (getline(myfile, tmp))
		{
			newV.push_back(tmp);
		}
	}
	myfile.close();

	for (it = newV.begin(); it != newV.end(); it++)
		cout << *it << "\n";

	vector<string> newV2;
	string tmp2;
	ifstream myfile2("select.txt");
	if (myfile2.is_open())
	{
		while (myfile2 >> tmp2)
		{
			newV2.push_back(tmp2);
		}
	}
	myfile2.close();

	for (it = newV2.begin(); it != newV2.end(); it++)
		cout << *it << "\n";

	newV2.clear();
	myfile2.open("select.txt");
	if (myfile2.is_open())
	{
		while (!myfile2.eof())
		{
			myfile2 >> tmp2;
			newV2.push_back(tmp2);
		}
	}
	myfile2.close();

	for (it = newV2.begin(); it != newV2.end(); it++)
		cout << *it << "\n";

}
