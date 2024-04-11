#include <iostream>
#include <locale.h>
#include "vecmat.h"
#include "gauss.h"

using namespace std;

int main() {
    setlocale(LC_CTYPE, "Rus");
    double err;
    int n;
    cout << "Введите размерность: ";
    cin >> n;

    // Создаем матрицу, векторы и заполняем их вручную
    Matrix A(n, n);
    Vector X(n);
    Vector B(n);
    Vector Ans(n);

    cout << "Введите элементы матрицы A:" << endl;
    cin >> A;

    cout << "Введите элементы вектора X:" << endl;
    cin >> X;

    // Вычисляем вектор B
    B = A * X;

    // Выводим элементы матрицы и векторов
    cout << "Матрица A:" << endl << A << endl;
    cout << "Вектор X:" << endl << X << endl;
    cout << "Вектор B:" << endl << B << endl;

    // Решаем систему методом Гаусса
    Gauss G(&A, &X, &B);
    G.Solve();

    // Проверяем решение
    err = G.Check();
    cout << "Относительная ошибка: " << err << endl;

    return 0;
}
//A.RandomMatrix(-3, 3);
//X.Generate(-10, 10);
//B = A * X;
// G(&A, &X, &B);
//G.Solve();
//err = G.Check();
//cout << err;
//return 0;
//}




//5 1 2         1       13
//1 6 3    ///X=2     B=22
//5 2 6         3       27
