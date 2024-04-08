#include <iostream>
#include "vecmat.h"
#include "Gauss.h"
#include <ctime>
#include "gauss.h"

// Реализация методов класса Gauss...

using namespace std;
Gauss::Gauss(Matrix* A, Vector* x, Vector* b) : A(A), x(x), b(b), status(0) {}

void Gauss::solve() {
    // Прямой ход метода Гаусса
    for (int i = 0; i < A->GetN(); ++i) {
        double pivot = (*A)(i, i);
        if (pivot == 0) {
            // Обработка случая, когда главный элемент равен нулю
            status = -1; // Устанавливаем статус ошибки
            return;
        }
        for (int j = i + 1; j < A->GetN(); ++j) {
            double ratio = (*A)(j, i) / pivot;
            for (int k = 0; k < A->GetM(); ++k) {
                (*A)(j, k) -= ratio * (*A)(i, k);
            }
            (*b)(j) -= ratio * (*b)(i);
        }
    }

    // Обратный ход метода Гаусса
    for (int i = A->GetN() - 1; i >= 0; --i) {
        double sum = 0;
        for (int j = i + 1; j < A->GetN(); ++j) {
            sum += (*A)(i, j) * (*x)(j);
        }
        (*x)(i) = ((*b)(i) - sum) / (*A)(i, i);
    }
}

double Gauss::Check() {
    Vector e = (*A) * (*x) - (*b);
    double a, y;
    a = e.Norm();
    y = b->Norm();
    return a / y;
}