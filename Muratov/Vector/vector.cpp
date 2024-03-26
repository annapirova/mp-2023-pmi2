using namespace std;
#include <iostream>
#include "vector.h"
#include <locale.h>
#include <ctime>
#include <random>

Vector::Vector(int size_): size(size_) {
	Memory = new double [size_];
}


Vector::~Vector() {
	delete[] Memory;
}


Vector::Vector(const Vector& B) : size(B.size) {
	Memory = new double [size];
	for (int i = 0; i < size; i++) {
		Memory[i] = B.Memory[i];
	}
}


istream& operator>>(istream& in, Vector& vec) {
	cout << "Введите размер вектора:  ";
	in >> vec.size;
	vec.Memory = new double[vec.size];
	for (int i = 0; i < vec.size; i++) {
		cout << "Введите элемент: ";
		in >> vec.Memory[i];
	}
	return in;
}


ostream& operator<<(ostream& os, const Vector& vec) {
	os << "Ваш вектор" << endl;
	for (int i = 0; i < vec.size; i++) {
		os << vec.Memory[i] << "\n";
	}
	return os;
}


Vector Vector::operator=(const Vector& B){
	if (this == &B) {
		return* this;
	}

	if (size != B.size) {
		delete[] Memory;
		Memory = new double [B.size];
		size = B.size;
	}

	for (int i = 0; i < size; i++) {
		Memory[i] = B.Memory[i];
	}
	return *this;
}


Vector Vector::operator+(const Vector& B){
	Vector New_Vector(size);
	for (int i = 0; i < size; i++) {
		New_Vector.Memory[i] = Memory[i] + B.Memory[i];
	}
	return New_Vector;
}


Vector Vector::operator-(const Vector& B){
	Vector New_Vector(size);
	for (int i = 0; i < size; i++) {
		New_Vector.Memory[i] = Memory[i] - B.Memory[i];
	}
	return New_Vector;
}


void Vector::Generate() {
	double random_int;
	for (int i = 0; i < size; i++) {
		random_int = rand();
		Memory[i] = rand() + (random_int / RAND_MAX);
	}
}


double& Vector::operator[](const int i) {
	return Memory[i];
}


const double& Vector::operator[](const int i) const {
	return Memory[i];
}


Vector& Vector::operator+=(const Vector& B) {
	if (size < B.size) {
		Vector New_Vector(B.size);
		//Выделяем память под новый вектор
		New_Vector.Memory = new double [B.size];
		//Заполняем нулями
		for (int i = 0; i < B.size; i++) {
			New_Vector.Memory[i] = 0;
		}
		//Переносим данные из меньшего вектора
		for (int i = 0; i < size; i++) {
			New_Vector.Memory[i] = Memory[i];
		}
		//Складываем и возвращаем итоговую матрицу
		for (int i = 0; i < B.size; i++) {
			New_Vector.Memory[i] += B.Memory[i];
		}
		Vector::operator=(New_Vector);
	}
	else {
		for (int i = 0; i < B.size; i++) {
			Memory[i] += B.Memory[i];
		}
		return *this;
	}

}


Vector& Vector::operator-=(const Vector& B) {
	if (size < B.size) {
		Vector New_Vector(B.size);
		//Выделяем память под новый вектор
		New_Vector.Memory = new double[B.size];
		//Заполняем нулями
		for (int i = 0; i < B.size; i++) {
			New_Vector.Memory[i] = 0;
		}
		//Переносим данные из меньшего вектора
		for (int i = 0; i < size; i++) {
			New_Vector.Memory[i] = Memory[i];
		}
		//Вычитаем и возвращаем итоговую матрицу
		for (int i = 0; i < B.size; i++) {
			New_Vector.Memory[i] -= B.Memory[i];
		}
		Vector::operator=(New_Vector);
	}
	else {
		for (int i = 0; i < B.size; i++) {
			Memory[i] -= B.Memory[i];
		}
		return *this;
	}

}

Vector Vector::operator*(const Vector& B) {
	if (size < B.size) {
		int i = 0;
		Vector New_Vector(B.size);
		New_Vector.Memory = new double[B.size];
		for (i; i < size; i++) {
			New_Vector.Memory[i] = Memory[i] * B.Memory[i];
		}
		for (int j = B.size - i; j < B.size; j++) {
			New_Vector.Memory[j] = B.Memory[i];
		}
		return New_Vector;
	}
	else {
		Vector New_Vector(B.size);
		int i = 0;
		New_Vector.Memory = new double[B.size];
		for (i; i < B.size; i++) {
			New_Vector.Memory[i] = Memory[i] * B.Memory[i];
		}
		for (int j = size - i; j < size; j++) {
			New_Vector.Memory[j] = Memory[j];
		}
		return New_Vector;
	}
}


Vector Vector::operator++(int k) {
	Vector tmp(*this);
	for (int i = 0; i < size; i++) {
		tmp.Memory[i] = tmp.Memory[i] + 1.0;
	}
	return tmp;
}

Vector &Vector::operator++() {
	for (int i = 0; i < size; i++) {
		Memory[i] = Memory[i] + 1.0;
	}
	return *this;
}

