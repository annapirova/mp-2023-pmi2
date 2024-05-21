#include <iostream>

class Field {
private:
	char** field;
	int n, m;
public:
	//Field();
	Field(int n_ = 1, int m_ = 1);
	~Field();

	void FieldZeroFill();	
	void FieldCompFill(char** field);
	void FieldPlayerFill();
	void fieldOut();
};

// доделать расположение кораблей игроком
// сделать автоввод копутером
// сделать обработку неверных вводов
// сделать ходы с уничтожением кораблей и заменой их на -
// доделать условия выигрыша
// сделать ходы компьютера
// как нормально организовать вывод?
// 
//