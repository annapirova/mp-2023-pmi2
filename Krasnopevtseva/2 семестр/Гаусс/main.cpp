using namespace std;
#include "gauss.h"
#include "matrix&vector.h"
#include <locale.h>
#include <math.h>
#include <iostream>

int main()
{
    setlocale(LC_ALL, "Russian");
    matrix A(3, 3);
    vector x(3), b, res(3);
    double err;
    //A.generate(-3.0, 3.0);
    //x.generate(-3.0, 3.0);
    cin >> A >> x;
    cout << "матрица A:\n" << A;
    cout << "вектор х:\n" << x;
    b = A * x;
    cout << "вектор b:\n" << b;
    Gauss g(&A, &b, &res);
    g.Solve();
    cout << "вектор res:" << endl;
    cout << res << endl;
    err = g.Check();
    cout<<"проверка: " <<err << endl;
    return 0;
}