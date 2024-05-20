bool func(string& s)
{
	if (s[0] == 'v')
		return true;
	else return false;
}

void main()
{
    vector<string> v;
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
