#include <iostream>
#include "Gauss.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

int main()
{
 
    Matrix matrix(3, 3);
    matrix.Generate(1.00, 52.00);

    Vector b(3);
    b.Generate(1.00, 52.00);

    Vector result(3);

    Gauss gauss(0, &matrix, &b, &result);

    // Решение системы уравнений методом Гаусса
    gauss.Solve();

    std::cout << gauss << std::endl;

    // Вычисление погрешности решения системы уравнений
    double error = gauss.Result();

    // Вывод погрешности
    std::cout << "Error in solution: " << error << std::endl;

    return 0;
}
