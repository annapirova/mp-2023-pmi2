#define _USE_MATH_DEFINES
using namespace std;
#include <iostream>
#include <cmath>
#include <vector>
#include "Shapes.h"


Cube::Cube(vector <double> center, double length) :Coord_Center(center), Edge_Length(length) {};


bool Normal_Noordinate_Cube(double center_coord, double input_coord, double length) {
	if (abs(center_coord - input_coord) < (length / 2.0)) {
		return true;
	}
	return false;
}

double Cube::Square() {
	return Edge_Length * Edge_Length * 6;
}

double Cube::Volume() {
	return Edge_Length * Edge_Length * Edge_Length;
}

bool Cube::Point_Inside_Shape(double x, double y, double z) {
	vector <double> input_coord = { x, y, z };
	for (int i = 0; i < 3; i++) {
		if (Normal_Noordinate_Cube(Coord_Center[i], input_coord[i], Edge_Length) == false) {
			return false;
		}
	}
	return true;
}


Parallelepiped::Parallelepiped(vector <double> center, double length, double width, double height, double angle_h, double angle_b, double first_side_angle, double second_side_angle) : Cube(center, length), Edge_Width(width), Height(height), angle_height(angle_h), angle_base(angle_b), first_side_angle(first_side_angle), second_side_angle(second_side_angle){};


bool Parallelepiped::Normal_Coordinate_Parallelepiped(double input_coord, int param) {
	if (param == 0) {
		if (abs(Coord_Center[0] - input_coord) < (Edge_Length / 2.0)) {
			return true;
		}
	}
	else if (param == 1) {
		if (abs(Coord_Center[1] - input_coord) < ((Edge_Width / sin(angle_base)) / 2.0)) {
			return true;
		}
	}
	else if (param == 2) {
		if (abs(Coord_Center[2] - input_coord) < (Height / 2.0)) {
			return true;
		}
	}
	return false;
}


double Parallelepiped::Square() {
	double sq = 0;
	double new_height;
	new_height = Height / std::sin(angle_height);
	sq += 2 * Edge_Length * Edge_Width * std::sin(angle_base);
	sq += 2 * Edge_Length * new_height * std::sin(first_side_angle);
	sq += 2 * new_height * Edge_Width * std::sin(second_side_angle);
	return sq;
}


double Parallelepiped::Volume() {
	return Height * Edge_Length * Edge_Width * sin(angle_base);
}


bool Parallelepiped::Point_Inside_Shape(double x, double y, double z) {
	vector <double> input_coord = { x, y, z };
	for (int i = 0; i < 3; i++) {
		if (Normal_Coordinate_Parallelepiped(input_coord[i], i) == false) {
			return false;
		}
	}
	return true;
}


Cylinder::Cylinder(vector <double> center, double length, double height) : Cube(center, length), Height(height) {};


bool Cylinder::Normal_Coordinate_Cylinder(double input_coord, int param) {
	if (param == 0) {
		if (abs(Coord_Center[0] - input_coord) < (Edge_Length / 2.0)) {
			return true;
		}
	}
	else if (param == 1) {
		if (abs(Coord_Center[1] - input_coord) < (Edge_Length / 2.0)) {
			return true;
		}
	}
	else if (param == 2) {
		if (abs(Coord_Center[2] - input_coord) < (Height / 2.0)) {
			return true;
		}
	}
	return false;
}


double Cylinder::Square() {
	return (2 * M_PI * Edge_Length * Edge_Length + 2 * M_PI * Edge_Length * Height);
}


double Cylinder::Volume() {
	return M_PI * Edge_Length * Edge_Length * Height;
}


bool Cylinder::Point_Inside_Shape(double x, double y, double z) {
	vector <double> input_coord = { x, y, z };
	for (int i = 0; i < 3; i++) {
		if (Normal_Coordinate_Cylinder(input_coord[i], i) == false) {
			return false;
		}
	}
	return true;
}