#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

void split(const std::string &s, char delim, std::vector<std::string> &elems) {
  std::stringstream ss(s);
  std::string item;
  while (std::getline(ss, item, delim)) {
	  elems.push_back(item);
  }
}

void main1()
{
  string str0;
  string str1 = "34+55*a";
  string str2(str1);
  string str3(str1, 2);
  string str4("25*(3-7.2)");
  string str5("25*(3-7.2)", 3);
  string str6(10, 'a');

  cout << str0 << " " << str0.size() << " " << str0.length() << " " << str0.capacity() << endl;
  cout << str1 << " " << str1.size() << " " << str1.max_size() << " " << str1.capacity() << endl;
  cout << str2 << " " << str2.size() << " " << " " << str2.capacity() << endl;
  cout << str3 << " " << str3.size() << " " << " " << str3.capacity() << endl;
  cout << str4 << " " << str4.size() << " " << " " << str4.capacity() << endl;
  cout << str5 << " " << str5.size() << " " << " " << str5.capacity() << endl;
  cout << str6 << " " << str6.size() << " " << " " << str6.capacity() << endl;

  cout << str1[5] << endl;
  str6 = str5 + str4;
  cout << str6 << str6.size() << str6.capacity() << endl;
  str3 += "37";
  cout << str3 << " "<< str3.size() << endl;

  int p1 = str1.find(str3);
  int p2 = str4.find("(3", 2); // искать со 2й
  int p3 = str4.find("(4", 2, 1); // искать со 2й 1 символ
  int p4 = str4.find('/', 3);

  cout << p1 << " " << p2 << " " << p3 << " " << p4 << " " << endl;

  //string str100;
  //cin >> str100; // до пробела
  //cout << str100 << endl;
  //str100.clear();
  //getline(cin, str100);
  //cout << str100 << endl; // до \n
  //str100.clear();
  //getline(cin, str100, '.'); // до точки
  //cout << str100 << endl;

  
  //str0.clear();
  //getline(cin, str0);

  // подсчет числа слов
  string delim = ".,!? ";
  int n = 0;
  size_t pos = 0;
  size_t oldPos = 0;
  pos = str0.find_first_of(delim);
  while (pos != str0.npos)
  {
   if (pos - oldPos > 0)
     n++;
   oldPos = pos + 1;
   pos = str0.find_first_of(delim, oldPos);
  }
  if (oldPos < str0.size())
   n++;
  cout << "nwords = " << n << endl;

  //  сохранить cлова в массив
  string* words = new string[n];
  pos = 0;
  oldPos = 0;
  n = 0;
  pos = str0.find_first_of(delim);
  while (pos != str0.npos)
  {
   if (pos - oldPos > 0)
   {
     words[n] = str0.substr(oldPos, pos - oldPos);
     n++;
   }
   oldPos = pos + 1;
   pos = str0.find_first_of(delim, oldPos);
  }
  if (oldPos < str0.size())
  {
   words[n] = str0.substr(oldPos);
   n++;
  }

  for (int i = 0; i < n; i++)
    cout << words[i] << endl;


  str0.clear();
  double values[10];
  getline(cin, str0);

  // поиск чисел в строке
  pos = 0;
  oldPos = 0;
  int k = 0;
  oldPos = str0.find_first_of("0123456789");
  while (oldPos != string::npos)
  {
    values[k] = stod(str0.substr(oldPos), &pos);
    oldPos += pos;
    oldPos = str0.find_first_of("0123456789", oldPos);
    k++;
  }

  for (int i = 0; i < k; i++)
  {
    cout << values[i] << endl;
  }
}

void main()
{
	string s = "hello, world!";
	vector<string> words;
	split(s, ' ', words);
	vector<string>::iterator i;
	for (i = words.begin(); i != words.end(); i++)
		cout << *i << " * ";
}