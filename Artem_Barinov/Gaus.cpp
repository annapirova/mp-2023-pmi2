#include "MVecClass.h"
#include <math.h>


Matrix Gaus(Matrix& matr, Vector& mvect) { // прямой ход
	double diagEl;
	double* str;
	for (int i = 0; i < matr.m - 1; i++) { // идем по диагонали и выбираем диагональный элемент (ведущий)
		diagEl = matr.matrix[i][i];
		if (abs(diagEl) < 1e-15) {
			str = matr.matrix[i];
			matr.matrix[i] = matr.matrix[matr.n - 1];
			matr.matrix[matr.n - 1] = str;
			continue;
		}
		for (int k = 0; k < matr.m; k++) // делим все элементы строки на ведущий
			matr.matrix[i][k] /= diagEl;
		mvect.vect[i] /= diagEl;
		for (int j = i + 1; j < matr.n; j++) {
			double fInStr = matr.matrix[j][i]; // первый элемент в строке, с которой работаем
			for (int q = i; q < matr.m; q++)
				matr.matrix[j][q] -= matr.matrix[i][q] * fInStr; // вычитаем из выбранной строки элемент ведущей строки (соотв.столбец), домн. на первый элем выбр. строки
			mvect.vect[j] -= mvect.vect[i] * fInStr;
		}
	}
	return matr;
}
void ReGaus(Matrix& matr, Vector& mvect) {
	Vector solv(mvect.len);
	for (int i = matr.n - 1; i >= 0; i--) {
		solv.vect[i] = mvect.vect[i];
		for (int j = i + 1; j < matr.m; j++)
			solv.vect[i] -= (matr.matrix[i][j] * solv.vect[j]);
		solv.vect[i] /= matr.matrix[i][i];
	}
	for (int i = 0; i < solv.len; i++)
		std::cout << "X" << matr.n - i << " = " << solv.vect[i] << std::endl;
	mvect = solv;
}
void GSolCheck(Matrix& matr, Vector& solvect, Vector& mvect) {
	int flag = 1;
	for (int i = 0; i < matr.n; i++) {
		double value = 0;
		for (int j = 0; j < matr.m; j++)
			value += matr.matrix[i][j] * solvect.vect[j];
		if (abs(value - mvect.vect[i]) > 1e-12)
			flag = 0;
	}
	if (flag == 0)
		std::cout << "Gdeta oshibka, ishi sam" << std::endl;
}
// проверка со старой матрицей
