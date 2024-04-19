class Date
{
	int day;
	int month;
	int year;
public:
	void Reset();
	void Set(int d, int m, int y);
	void Print();
	void AddToDate(int d, int m, int y);
	void SumDate(const Date& D);
};