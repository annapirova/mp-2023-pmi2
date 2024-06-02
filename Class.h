#pragma once
#include "Class.cpp"
//Field::Field() {
//
//}
Field::Field(int n_, int m_){
	n = n_; m = m_;
	field = new char* [n];
	for (int i = 0; i < n; i++)	{
		field[i] = new char[m];
	}
}
void Field::FieldZeroFill() {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			field[i][j] = 'O';
		}
}
Field::~Field() {
	for (int i = 0; i < n; i++)
		delete field[i];
	delete field;
}

void Field::FieldCompFill(char** field_) {

	// сделать заполнение матрицы кораблями
}
void Field::FieldPlayerFill() {
	int maxships = 0;
	while (maxships <= 20) {
		int row, column;
		std::cout << "Row: "; std::cin >> row;
		std::cout << "Column: "; std::cin >> column;

		char ch;
		std::cout << "Enter '+' to place the ship in the cell (" << row << ", " << column << ") or 'e' for exit.\nEnter: ";
		std::cin >> ch;
		field[row][column] = ch;
		if(ch=='e')
			return;
		maxships++;
	}
}
void Field::fieldOut() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			std::cout << field[i][j]<<" ";
		}
		std::cout << std::endl;
	}
}