#include <iostream>
#include "vecmat.h"
#include "Gauss.h"
#include <ctime>
using namespace std;
int main() {
    // Создание матрицы и вектора, объекта класса Gauss
    Matrix A(3, 3); 
    A(0, 0) = 1; A(0, 1) = 2; A(0, 2) = 3;
    A(1, 0) = 2; A(1, 1) = -1; A(1, 2) = 2;
    A(2, 0) = 1; A(2, 1) = 1; A(2, 2) = 5;

    Vector x(A.GetN()); // Создаём вектор размера, соответствующего числу строк матрицы A
    // Вектор x заполняется нулями по умолчанию

    Vector b(3); // Создаём вектор размера 3
    b(0) = 1; b(1) = 6; b(2) = -1;

    // Создание объекта класса Gauss
    Gauss gauss(&A, &x, &b);

    // Решение системы методом Гаусса
    gauss.solve();

    // Вывод решения
    cout << "ZNAHENIE x:" << endl;
    cout << x << endl;

    // Проверка решения
    double err = gauss.Check();
    cout << " error: " << err << endl;
    return 0;
}