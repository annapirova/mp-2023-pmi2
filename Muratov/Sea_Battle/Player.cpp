using namespace std;
#include <iostream>
#include "Player.h"
#include <vector>
#include <locale.h>
#include <random>
#include <ctime>

vector <pair <int, int>>& Delete_Vector(vector <pair <int, int>> a) {
	for (int i = 0; i < a.size(); i++) {
		a.erase(a.begin() + i);
	}
	return a;
}

vector <pair <int, int>> App_Coord(int start_y, int start_x, int end_y, int end_x) {
	pair <int, int> tmp;
	vector <pair <int, int>> coordinate_ship;
	if (start_y == end_y) {
		for (int j = start_x; j < end_x + 1; j++) {
			tmp.first = start_y;
			tmp.second = j;
			coordinate_ship.push_back(tmp);
		}
	}
	else if (start_x == end_x) {
		for (int j = start_y; j < end_y + 1; j++) {
			tmp.first = j;
			tmp.second = start_x;
			coordinate_ship.push_back(tmp);
		}
	}
	return coordinate_ship;
}

vector <pair <int, int>> replace(vector <pair <int, int>> B) {
	int i, j;
	pair <int, int> tmp;
	for (i = 1; i < B.size(); ++i)
	{
		j = i;
		while ((j > 0) && (B[j - 1].first > B[j].first)) {
			tmp = B[j - 1];
			B[j - 1] = B[j];
			B[j] = tmp;
			j--;
		}
	}
	return B;
}

vector <pair <int, int>> replace_horizontal(vector <pair <int, int>> B) {
	int i, j;
	pair <int, int> tmp;
	for (i = 1; i < B.size(); ++i)
	{
		j = i;
		while ((j > 0) && (B[j - 1].second > B[j].second)) {
			tmp = B[j - 1];
			B[j - 1] = B[j];
			B[j] = tmp;
			j--;
		}
	}
	return B;
}

vector <vector <pair <int, int>>> Sort_Shots(vector <vector <pair <int, int>>> coord) {
	for (int i = 0; i < coord.size(); i++) {
		coord[i] = replace(coord[i]);
	}
	return coord;
}

int Random_Сoordinate(int min_value, int max_value) {
	return rand() % ((max_value - min_value + 1) + min_value);
}

int Random_Board(int min_value, int max_value) {
	return rand() % ((max_value - min_value + 1) + min_value);
}

Player::Player(vector <vector <int>> brd, vector <vector <int>> pl_brd, int counter_shots, vector <vector <pair <int, int>>> ships_shots) : Board(brd), Play_Board(pl_brd), counter_shots(counter_shots), Ships_Shots(ships_shots) {
	Ships_Shots = Sort_Shots(Ships_Shots);
};

Comp::Comp(vector <vector <int>> brd, vector <vector <int>> pl_brd, int counter_shots, vector <vector <pair <int, int>>> ships_shots): Player(brd, pl_brd, counter_shots, ships_shots) {
	pair <int, int> coord;
	for (int i = 1; i < 11; i++) {
		for (int j = 1; j < 11; j++) {
			coord.first = i;
			coord.second = j;
			allowed_coord.push_back(coord);
		}
	}
}

int Comp::Search_Coord(pair <int, int> coord) {
	pair <int, int> coordinate;
	for (int i = 0; i < allowed_coord.size(); i++) {
		if (coord == allowed_coord[i]) {
			return i;
		}
	}
	return -1;
}

bool Vertical_Ship(vector <pair <int, int>> coord_ship) {
	if (coord_ship[0].second == coord_ship[1].second) {
		return true;
	}
	return false;
}

bool Player::The_Ship_Has_Been_Destroyed() {
	for (int i = 0; i < ship.size(); i++) {
		ship[i].first -= 1;
		ship[i].second -= 1;
	}
	for (int i = 0; i < Ships_Shots.size(); i++) {
		if (ship == Ships_Shots[i]) {
			for (int i = 0; i < ship.size(); i++) {
				ship[i].first += 1;
				ship[i].second += 1;
			}
			return 1;
		}
	}
	for (int i = 0; i < ship.size(); i++) {
		ship[i].first += 1;
		ship[i].second += 1;
	}
	return 0;
}

void Comp::Forbidden_Area(int k) {
	if (k) {
		int index_coord, i, a, b;
		pair <int, int> new_coord;
		for (i = 0; i < ship.size(); i++) {
			a = ship[i].first;
			b = ship[i].second;
			b += 1;
			new_coord.first = a;
			new_coord.second = b;
			index_coord = Search_Coord(new_coord);
			if (index_coord != -1) {
				allowed_coord.erase(allowed_coord.begin() + index_coord);
			}
			b -= 2;
			new_coord.second = b;
			index_coord = Search_Coord(new_coord);
			if (index_coord != -1) {
				allowed_coord.erase(allowed_coord.begin() + index_coord);
			}
		}
		//delete up
		a = ship[0].first;
		b = ship[0].second;
		a -= 1;
		new_coord.first = a;
		new_coord.second = b;
		index_coord = Search_Coord(new_coord);
		if (index_coord != -1) {
			allowed_coord.erase(allowed_coord.begin() + index_coord);
		}
		b -= 1;
		new_coord.second = b;
		index_coord = Search_Coord(new_coord);
		if (index_coord != -1) {
			allowed_coord.erase(allowed_coord.begin() + index_coord);
		}
		b += 2;
		new_coord.second = b;
		index_coord = Search_Coord(new_coord);
		if (index_coord != -1) {
			allowed_coord.erase(allowed_coord.begin() + index_coord);
		}
		//delete low
		a = ship[i - 1].first;
		b = ship[i - 1].second;
		a += 1;
		new_coord.first = a;
		new_coord.second = b;
		index_coord = Search_Coord(new_coord);
		if (index_coord != -1) {
			allowed_coord.erase(allowed_coord.begin() + index_coord);
		}
		b -= 1;
		new_coord.second = b;
		index_coord = Search_Coord(new_coord);
		if (index_coord != -1) {
			allowed_coord.erase(allowed_coord.begin() + index_coord);
		}
		b += 2;
		new_coord.second = b;
		index_coord = Search_Coord(new_coord);
		if (index_coord != -1) {
			allowed_coord.erase(allowed_coord.begin() + index_coord);
		}
	}
	else {
		int index_coord, i, a, b;
		pair <int, int> new_coord;
		for (i = 0; i < ship.size(); i++) {
			a = ship[i].first;
			b = ship[i].second;
			a += 1;
			new_coord.first = a;
			new_coord.second = b;
			index_coord = Search_Coord(new_coord);
			if (index_coord != -1) {
				allowed_coord.erase(allowed_coord.begin() + index_coord);
			}
			a -= 2;
			new_coord.second = b;
			index_coord = Search_Coord(new_coord);
			if (index_coord != -1) {
				allowed_coord.erase(allowed_coord.begin() + index_coord);
			}
		}
		//delete right
		a = ship[0].first;
		b = ship[0].second;
		b -= 1;
		new_coord.first = a;
		new_coord.second = b;
		index_coord = Search_Coord(new_coord);
		if (index_coord != -1) {
			allowed_coord.erase(allowed_coord.begin() + index_coord);
		}
		a -= 1;
		new_coord.second = b;
		index_coord = Search_Coord(new_coord);
		if (index_coord != -1) {
			allowed_coord.erase(allowed_coord.begin() + index_coord);
		}
		a += 2;
		new_coord.second = b;
		index_coord = Search_Coord(new_coord);
		if (index_coord != -1) {
			allowed_coord.erase(allowed_coord.begin() + index_coord);
		}
		//delete left
		a = ship[i - 1].first;
		b = ship[i - 1].second;
		b += 1;
		new_coord.first = a;
		new_coord.second = b;
		index_coord = Search_Coord(new_coord);
		if (index_coord != -1) {
			allowed_coord.erase(allowed_coord.begin() + index_coord);
		}
		a -= 1;
		new_coord.second = b;
		index_coord = Search_Coord(new_coord);
		if (index_coord != -1) {
			allowed_coord.erase(allowed_coord.begin() + index_coord);
		}
		a += 2;
		new_coord.second = b;
		index_coord = Search_Coord(new_coord);
		if (index_coord != -1) {
			allowed_coord.erase(allowed_coord.begin() + index_coord);
		}
	}
}

bool Comp::Shot() {
	int a, b, index_coord;
	int k = 0;
	pair <int, int> coordinate, new_coordinate;
	if (ship.size() == 0) {
		index_coord = Random_Сoordinate(0, allowed_coord.size() - 1);
		coordinate = allowed_coord[index_coord];
		index_coord = Search_Coord(coordinate);
		allowed_coord.erase(allowed_coord.begin() + index_coord);
		if (Board[coordinate.first][coordinate.second] == 1) {
			counter_shots += 1;
			Play_Board[coordinate.first][coordinate.second] = 1;
			std::cout << "Попал" << endl;
			ship.push_back(coordinate);
			if (The_Ship_Has_Been_Destroyed()) {
				Forbidden_Area(1);
				ship = Delete_Vector(ship);
			}
			return true;
		}
		else {
			std::cout << "Мимо" << endl;
			Play_Board[coordinate.first][coordinate.second] = 2;
			return false;
		}
	}
	else {
		if (ship.size() == 1) {
			if (flag == 0) {
				new_coordinate.first = ship[0].first + 1;
				new_coordinate.second = ship[0].second;
				index_coord = Search_Coord(new_coordinate);
				if (index_coord != -1) {
					allowed_coord.erase(allowed_coord.begin() + index_coord);
					if (Board[new_coordinate.first][new_coordinate.second] == 1) {
						Board[new_coordinate.first][new_coordinate.second] = 2;
						counter_shots += 1;
						std::cout << "Попал" << endl;
						Play_Board[new_coordinate.first][new_coordinate.second] = 1;
						ship.push_back(new_coordinate);
						ship = replace(ship);
						if (The_Ship_Has_Been_Destroyed()) {
							Forbidden_Area(1);
							ship = Delete_Vector(ship);
						}
						return true;
					}
					else {
						std::cout << "Мимо" << endl;
						Play_Board[new_coordinate.first][new_coordinate.second] = 2;
						flag = 1;
						return false;
					}
				}
				else {
					flag = 1;
				}
			}
			if (flag == 1) {
				new_coordinate.first = ship[0].first;
				new_coordinate.second = ship[0].second + 1;
				index_coord = Search_Coord(new_coordinate);
				if (index_coord != -1) {
					allowed_coord.erase(allowed_coord.begin() + index_coord);
					if (Board[new_coordinate.first][new_coordinate.second] == 1) {
						Board[new_coordinate.first][new_coordinate.second] = 2;
						counter_shots += 1;
						std::cout << "Попал" << endl;
						Play_Board[new_coordinate.first][new_coordinate.second] = 1;
						ship.push_back(new_coordinate);
						ship = replace_horizontal(ship);
						flag = 0;
						if (The_Ship_Has_Been_Destroyed()) {
							Forbidden_Area(0);
							ship = Delete_Vector(ship);
						}
						return true;
					}
					else {
						std::cout << "Мимо" << endl;
						Play_Board[new_coordinate.first][new_coordinate.second] = 2;
						flag = 2;
						return false;
					}
				}
				else {
					flag = 2;
				}
			}
			if (flag == 2) {
				new_coordinate.first = ship[0].first - 1;
				new_coordinate.second = ship[0].second;
				index_coord = Search_Coord(new_coordinate);
				if (index_coord != -1) {
					allowed_coord.erase(allowed_coord.begin() + index_coord);
					if (Board[new_coordinate.first][new_coordinate.second] == 1) {
						Board[new_coordinate.first][new_coordinate.second] = 2;
						counter_shots += 1;
						std::cout << "Попал" << endl;
						Play_Board[new_coordinate.first][new_coordinate.second] = 1;
						ship.push_back(new_coordinate);
						ship = replace(ship);
						flag = 0;
						if (The_Ship_Has_Been_Destroyed()) {
							Forbidden_Area(1);
							ship = Delete_Vector(ship);
						}
						return true;
					}
					else {
						std::cout << "Мимо" << endl;
						Play_Board[new_coordinate.first][new_coordinate.second] = 2;
						flag = 3;
						return false;
					}
				}
				else {
					flag = 3;
				}
			}
			if (flag == 3) {
				new_coordinate.first = ship[0].first;
				new_coordinate.second = ship[0].second - 1;
				index_coord = Search_Coord(new_coordinate);
				if (index_coord != -1) {
					allowed_coord.erase(allowed_coord.begin() + index_coord);
					if (Board[new_coordinate.first][new_coordinate.second] == 1) {
						Board[new_coordinate.first][new_coordinate.second] = 2;
						counter_shots += 1;
						std::cout << "Попал" << endl;
						Play_Board[new_coordinate.first][new_coordinate.second] = 1;
						ship.push_back(new_coordinate);
						ship = replace_horizontal(ship);
						flag = 0;
						if (The_Ship_Has_Been_Destroyed()) {
							Forbidden_Area(0);
							ship = Delete_Vector(ship);
						}
						return true;
					}
				}
				flag = 0;
			}
		}
		else if (ship.size() >= 2) {
			if (Vertical_Ship(ship)) {
				if (flag == 0) {
					int a, b;
					a = ship[0].first;
					b = ship[0].second;
					a -= 1;
					new_coordinate.first = a;
					new_coordinate.second = b;
					index_coord = Search_Coord(new_coordinate);
					if (index_coord != -1) {
						allowed_coord.erase(allowed_coord.begin() + index_coord);
						if (Board[new_coordinate.first][new_coordinate.second] == 1) {
							Board[new_coordinate.first][new_coordinate.second] = 2;
							counter_shots += 1;
							std::cout << "Попал" << endl;
							Play_Board[new_coordinate.first][new_coordinate.second] = 1;
							ship.push_back(new_coordinate);
							ship = replace(ship);
							flag = 0;
							if (The_Ship_Has_Been_Destroyed()) {
								Forbidden_Area(1);
								ship = Delete_Vector(ship);
							}
							return true;
						}
						else {
							std::cout << "Мимо" << endl;
							Play_Board[new_coordinate.first][new_coordinate.second] = 2;
							flag = 1;
							return false;
						}
					}
					else {
						flag = 1;
					}
				}
				if (flag == 1) {
					int i;
					for (i = 0; i < ship.size(); i++);
					int a, b;
					a = ship[i - 1].first;
					b = ship[i - 1].second;
					a += 1;
					new_coordinate.first = a;
					new_coordinate.second = b;
					index_coord = Search_Coord(new_coordinate);
					if (index_coord != -1) {
						allowed_coord.erase(allowed_coord.begin() + index_coord);
						if (Board[new_coordinate.first][new_coordinate.second] == 1) {
							Board[new_coordinate.first][new_coordinate.second] = 2;
							counter_shots += 1;
							std::cout << "Попал" << endl;
							Play_Board[new_coordinate.first][new_coordinate.second] = 1;
							ship.push_back(new_coordinate);
							ship = replace(ship);
							flag = 0;
							if (The_Ship_Has_Been_Destroyed()) {
								Forbidden_Area(1);
								ship = Delete_Vector(ship);
							}
							return true;
						}
						else {
							std::cout << "Мимо" << endl;
							Play_Board[new_coordinate.first][new_coordinate.second] = 2;
							flag = 0;
							return false;
						}
					}
					else {
						flag = 0;
					}
				}
			}
			else {
				if (flag == 0) {
					int a, b;
					a = ship[0].first;
					b = ship[0].second;
					b -= 1;
					new_coordinate.first = a;
					new_coordinate.second = b;
					index_coord = Search_Coord(new_coordinate);
					if (index_coord != -1) {
						allowed_coord.erase(allowed_coord.begin() + index_coord);
						if (Board[new_coordinate.first][new_coordinate.second] == 1) {
							counter_shots += 1;
							std::cout << "Попал" << endl;
							Play_Board[new_coordinate.first][new_coordinate.second] = 1;
							ship.push_back(new_coordinate);
							ship = replace_horizontal(ship);
							flag = 0;
							if (The_Ship_Has_Been_Destroyed()) {
								Forbidden_Area(0);
								ship = Delete_Vector(ship);
							}
							return true;
						}
						else {
							std::cout << "Мимо" << endl;
							Play_Board[new_coordinate.first][new_coordinate.second] = 2;
							flag = 1;
							return false;
						}
					}
					else {
						flag = 1;
					}
				}
				if (flag == 1) {
					int i;
					for (i = 0; i < ship.size(); i++);
					int a, b;
					a = ship[i - 1].first;
					b = ship[i - 1].second;
					b += 1;
					new_coordinate.first = a;
					new_coordinate.second = b;
					index_coord = Search_Coord(new_coordinate);
					if (index_coord != -1) {
						allowed_coord.erase(allowed_coord.begin() + index_coord);
						if (Board[new_coordinate.first][new_coordinate.second] == 1) {
							Board[new_coordinate.first][new_coordinate.second] = 2;
							counter_shots += 1;
							std::cout << "Попал" << endl;
							Play_Board[new_coordinate.first][new_coordinate.second] = 1;
							ship.push_back(new_coordinate);
							ship = replace_horizontal(ship);
							flag = 0;
							if (The_Ship_Has_Been_Destroyed()) {
								Forbidden_Area(0);
								ship = Delete_Vector(ship);
							}
							return true;
						}
						else {
							std::cout << "Мимо" << endl;
							Play_Board[new_coordinate.first][new_coordinate.second] = 2;
							flag = 0;
							return false;
						}
					}
					else {
						flag = 0;
					}
				}
			}
		}
	}
}

void Player::Print_Play_Board() {
	for (int i = 0; i < Play_Board.size(); i++) {
		for (int j = 0; j < Play_Board.size(); j++) {
			std::cout << Play_Board[i][j] << " ";
		}
		std::cout << endl;
	}
}

void Player::Print_Board() {
	for (int i = 0; i < Board.size(); i++) {
		for (int j = 0; j < Board.size(); j++) {
			std::cout << Board[i][j] << " ";
		}
		std::cout << endl;
	}
}

bool Player::Check() {
	if (counter_shots == 20) {
		return 1;
	}
	else {
		return 0;
	}
}

bool Player::Shot(int a, int b) {
	if (Board[a][b] == 1) {
		ship.push_back(pair <int, int>(a, b));
		if (The_Ship_Has_Been_Destroyed()) {
			cout << "Убил" << endl;
			ship = Delete_Vector(ship);
		}
		else {
			std::cout << "Попал" << endl;
		}
		Board[a][b] = 0;
		Play_Board[a][b] = 1;
		counter_shots += 1;
		return 1;
	}
	else {
		std::cout << "Мимо" << endl;
		Play_Board[a][b] = 2;
		return 0;
	}
}