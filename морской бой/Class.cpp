#include "Class.h"
#include <vector>
//#include "Game.cpp"

Field::Field(int n_, int m_) {
	n = n_; m = m_;
	matrix = new int* [n];
	for (int i = 0; i < n; i++) {
		matrix[i] = new int[m];
	}
}
void Field::FieldZeroFill() {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			matrix[i][j] = 0;
		}
}
void Field::fieldOut() { // переделать с учётом того, что поле - матрица интов
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (matrix[i][j] == 0) std::cout << "0 ";
			else if (matrix[i][j] == 2)	std::cout << "+ ";
			else if (matrix[i][j] == -2) std::cout << "- ";
			else if (matrix[i][j] == -1) std::cout << "# ";
		}
		std::cout << std::endl;
	}
}
bool Field::shipToField(int row, int column, int index, char dr, Field& field) {
	int flag = -1;
	int zn = 1;
	int value;
	if (dr == 'W' || dr == 'N') zn = -1;
	if (dr == 'E' || dr == 'W') value = column;
	else value = row;
	for (int i = 0; i < index; i++) { // proverka ne visli li za pole
		flag = value + zn * i;
	}
	if (flag >= 0 && flag < 10) {
		Field f2(field); // sozdaem matrisu i razmeshaem korabl v nei
		for (int l = 0; l < index; l++) {
			if (dr == 'E' || dr == 'W')
				f2.matrix[row][column + zn * l] += 2;
			if (dr == 'S' || dr == 'N')
				f2.matrix[row + zn * l][column] += 2;
		}
		for (int i = 0; i < f2.n; i++)
			for (int j = 0; j < f2.m; j++) // esli korabli pereseklis, to vozvrasaem nol
				if (f2.matrix[i][j] == 4)
					return 0;
		field.operator=(f2); // esli ne peresekautsa, to stavim korabl i vozvrosaem odin		
		return 1;
	}
	return 0;
}
void Field::FieldCompFill(Field& field) {
	int j = 1;
	srand(time(NULL));
	for (int i = 4; i > 0; i--) {
		for (int k = 0; k < j; k++) {
			bool flag = 0;
			do {
				int rw = rand() % (9) + 1;
				int cln = rand() % (9) + 1;
				int dr = rand() % (4) + 1;
				char direction;
				if (dr == 1) direction = 'W';
				else if (dr == 2) direction = 'E';
				else if (dr == 3) direction = 'S';
				else if (dr == 4) direction = 'N';
				flag = shipToField(rw, cln, i, direction, field); // generiruem raspolozenie corabla
			} while (!flag);
		}
		j++;
	}
}
int getCoord(std::string str) {
	bool flag = 0;
	int num;
	do {
		std::cout << str << ": ";
		if ((std::cin >> num).good() != 1)
			std::cout << "Invalid character! Try again!\n";
		else {
			if (num >= 0 && num < 10)
				flag = 1;
			else
				std::cout << "Invalid range! Try again!\n";
		}
	} while (!flag);
	return num;
}
bool Prov(int x, int y, Field& field) {
	if (field.matrix[x][y] == 2) return 1;
	if (field.matrix[x][y] == 0) return 1;
	else return 0;
}
bool Field::Attack(Field& field, char who) {
	int x, y;
	if (who == 'p') {
		std::cout << "Enter an attack coordinates\n";
		x = getCoord("X"); y = getCoord("Y");		
	}
	else {
		bool flag = 0;
		do {
			x = rand() % (9) + 1;
			y = rand() % (9) + 1;
			flag = Prov(x, y, field);
		} while (!flag);		
	}
	if (matrix[x][y] == 2) {
		std::cout << "Strike!\n";
		matrix[x][y] = -2;
		return 1;
	}
	else {
		std::cout << "Miss!\n";
		field.matrix[x][y] = -1;
		return 0;
	}
}
char Field::Win() {
	int value = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (matrix[i][j] == -2) value += matrix[i][j];
	if (value == -40) return 'w';
	else return 'n';
}
bool Field::operator==(Field& f) {
	if (this == &f) return 1;
	if (n != f.n || m != f.m) return 0;
	bool flag = 1;
	for (int i = 0; i < f.n; i++)
		for (int j = 0; j < f.m; j++)
			if (f.matrix[i][j] != matrix[i][j])
				flag = 0;
	return flag;
}