#include "matrix.h"
using namespace std;

#include <iostream>
#include "matrix.h"

int main() {

    Matrix A(2, 2);
    A.Generate(1.0, 10.0);
cout << "Matrix A:\n" << A << endl;


    Matrix B(2, 2);
    B.Generate(1.0, 10.0);
    cout << "Matrix B:\n" << B << endl;

    Matrix C = A + B;
  cout << "Matrix C = A + B:\n" << C << endl;

 
    Matrix D = A - B;
    cout << "Matrix D = A - B:\n" << D << endl;

    Matrix E = A * B;
cout << "Matrix E = A * B:\n" << E << endl;

    Vector v(2);
    v.Generate(1.0, 10.0);
cout << "Vector v:\n" << v << endl;

    Vector result = A.multiplyVector(v);
  cout << "Result of A * v:\n" << result << endl;

    return 0;
}
