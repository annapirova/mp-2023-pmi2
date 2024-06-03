#pragma once
using namespace std;
#include <iostream>
#include <vector>

class Cube {
protected:
	vector <double> Coord_Center;
	double Edge_Length;
public:
	Cube(vector <double> center, double length);
	virtual double Square();
	virtual double Volume();
	virtual bool Point_Inside_Shape(double x, double y, double z);
};


class Parallelepiped : public Cube {
	double Height, Edge_Width;
	double angle_height, angle_base, first_side_angle, second_side_angle;
public:
	Parallelepiped(vector <double> center, double length, double width, double height, double angle_h, double angle_b, double first_side_angle, double second_side_angle);
	double Square();
	double Volume();
	bool Normal_Coordinate_Parallelepiped(double input_coord, int param);
	bool Point_Inside_Shape(double x, double y, double z);
};


class Cylinder: public Cube{
	double Height;
public:
	Cylinder(vector <double> center, double lenght, double height);
	bool Normal_Coordinate_Cylinder(double input_coord, int param);
	double Square();
	double Volume();
	bool Point_Inside_Shape(double x, double y, double z);
};