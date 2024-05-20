#include <iostream>
#include "vecmat.h"
#include "gauss.h"
#include <ctime>

// Реализация методов класса Gauss

Gauss::Gauss(Matrix* A, Vector* x, Vector* b) : A(A), x(x), b(b), status(0) { M = *A; bold = *b; }

void Gauss::Solve() {
    for (int i = 0; i < A->Rows(); i++) {
        double p = (*A)(i, i);
        if (p == 0) {
            status = -1;
            return;
        }
        for (int j = i + 1; j < A->Rows(); j++) {
            double r = (*A)(j, i) / p;
            for (int k = 0; k < A->Cols(); k++) {
                (*A)(j, k) -= r * (*A)(i, k);
            }
            (*b)(j) -= r * (*b)(i);
        }
    }

    for (int i = A->Rows() - 1; i >= 0; i--) {
        double sum = 0;
        for (int j = i + 1; j < A->Rows(); j++) {
            sum += (*A)(i, j) * (*x)(j);
        }
        (*x)(i) = ((*b)(i) - sum) / (*A)(i, i);
    }
}

double Gauss::Check() {
    if (status != 0) {
        return -1;
    }

    //Matrix M = *A;
    Vector e = M * (*x) - bold; 
    double a = e.Norm(); 
    double y = bold.Norm();

    return a / y; 
}
