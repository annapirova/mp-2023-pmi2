using namespace std;
#include "gauss.h"
#include "matrixvector.h"
#include <math.h>
#include <iostream>

int main()
{
    Matrix A(3, 3);
    Vector X(3), B, Z(3);
    double err;
    cin >> A;
    cin >> X;
    cout << "Matrix A:\n" << A;
    cout << "Vector X:\n" << X;
    B = A * X;
    cout << "Vector B:\n" << B;
    Gauss Gauss(&A, &B, &Z);
    Gauss.Solve();
    err = Gauss.Check();
    cout << "Proverka: " << err << endl;
    return 0;
}