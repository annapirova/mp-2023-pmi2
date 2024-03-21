#include <iostream>
#include "Matrix.h"
#include <iomanip>
#include <ctime>
using namespace std;
int main()
{
    srand(time(NULL));

    matrix mat1(2, 2);
    matrix mat2(2, 2);

    mat1.set_random(1.0, 10.0);
    mat2.set_random(1.0, 10.0);

    cout << "Matrix 1:" << endl;
    mat1.Print();

    cout << "Matrix 2:" << endl;
    mat2.Print();

    return 0;
}