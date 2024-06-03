#define _USE_MATH_DEFINES
using namespace std;
#include <iostream>
#include <cmath>
#include <vector>
#include "Shapes.h"


int main() {
	setlocale(LC_ALL, "ru");
	double len_edge, w_edge, h, x, y, z, radius;
	double angle_base, angle_height, first_side_angle, second_side_angle;
	vector <double> coord_center;
	cout << "Введите длину ребра куба: ";
	cin >> len_edge;
	cout << "\nВведите координату центра (x, y, z): ";
	cin >> x >> y >> z;
	coord_center = { 0, 0, 0 };
	Cube C(coord_center, len_edge);
	cout << "\nВведите длину параллелепипеда (x): ";
	cin >> len_edge;
	cout << "\nВведите ширину параллелепипеда (y): ";
	cin >> w_edge;
	cout << "\nВведите высоту параллелепипеда (z): ";
	cin >> h;
	cout << "\nВведите угол между шириной и длиной: ";
	cin >> angle_base;
	cout << "\nВведите угол наклона бокового ребра: ";
	cin >> angle_height;
	cout << "\nВведите угол между боковым ребром и длиной: ";
	cin >> first_side_angle;
	cout << "\nВведите угол между боковым ребром и шириной: ";
	cin >> second_side_angle;
	cout << "\nВведите координату центра (x, y, z): ";
	cin >> x >> y >> z;
	coord_center = { 0, 0, 0 };
	Parallelepiped P(coord_center, len_edge, w_edge, h, angle_height, angle_base, first_side_angle, second_side_angle);
	cout << "Введите радиус цилиндра: ";
	cin >> radius;
	cout << "Введите высоту цилиндра: ";
	cin >> h;
	cout << "\nВведите координату центра (x, y, z): ";
	cin >> x >> y >> z;
	coord_center = { 0, 0, 0 };
	Cylinder Cyl(coord_center, radius, h);
	cout << "Cube: " << endl;
	cout << C.Square() << endl;
	cout << C.Volume() << endl;
	cout << "\nВведите координату точки (x, y, z): ";
	cin >> x >> y >> z;
	cout << C.Point_Inside_Shape(x, y, z) << endl;

	cout << "Parallelepiped: " << endl;
	cout << P.Square() << endl;
	cout << P.Volume() << endl;
	cout << "\nВведите координату точки (x, y, z): ";
	cin >> x >> y >> z;
	cout << P.Point_Inside_Shape(x, y, z) << endl;

	cout << "Cylinder: " << endl;
	cout << Cyl.Square() << endl;
	cout << Cyl.Volume() << endl;
	cout << "\nВведите координату точки (x, y, z): ";
	cin >> x >> y >> z;
	cout << Cyl.Point_Inside_Shape(x, y, z) << endl;
}
