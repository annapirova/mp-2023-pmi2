#pragma once
#include <iostream>
#include "matr_class.h"


class Field : public Matrix{
//private:
//	int** field;
//	int rw;
//	int cl;
public:
	//Field();
	Field(int n_ = 1, int m_ = 1);
	//~Field();

	bool shipToField(int row, int column, int index, char dr, Field& field);
	void FieldZeroFill();
	void FieldCompFill(Field& field);
	bool Attack(Field& field, char who);
	char Win();
	void fieldOut();
	bool operator==(Field& matr);
	//friend Field shipToField(int row, int column, int index, char dr, Field& field);
	friend bool Game(Field& f1, Field& f2);
	friend bool Prov(int x, int y, Field& field);
	friend void GetShipField(Field& field);
};