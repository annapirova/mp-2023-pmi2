#include "vector.h"
using namespace std;
#include "locale.h"
#include <iostream>
#include <cstdlib>

int main()
{
    setlocale(LC_ALL, "Russian");
    vector x,z, w, q;
    cin >> x;
    vector y(x);
    cout << "Координаты вектора y (копир. x):" << endl;
    cout << y;
    x += y;
    cout << "Координаты вектора x (x+=y):" << endl;
    cout << x;
    y = x * 4;
    cout << "Координаты вектора y (y = x * 4):" << endl;
    cout << y;
    z = x - y;
    cout << "Координаты вектора z (z = x - y):" << endl;
    cout << z;
    z -= x * 2;
    cout << "Координаты вектора z (z -= x * 2):" << endl;
    cout << z;
    w = z + x;
    cout << "Координаты вектора w (w = z + x;):" << endl;
    cout <<w;
    w = z++;
    cout << "Координаты вектора w (w=z++):" << endl;
    cout << w;
    ++w;
    cout << "Координаты вектора w (++w):" << endl;
    cout << w;
    cout << "w[2]:" << endl;
    cout << w[2]<<endl;
    q.generate(-10, 100);
    cout << "Координаты вектора q (генерация):" << endl;
    cout << q;
}