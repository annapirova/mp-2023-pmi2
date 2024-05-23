#pragma once
#include <vector>
class Player {
protected:
	vector <vector <int>> Board;
	vector <vector <int>> Play_Board;
	int counter_shots;
	vector <vector <pair <int, int>>> Ships_Shots;
	vector <pair <int, int>> ship;
public:
	Player(vector <vector <int>> brd, vector <vector <int>> pl_brd, int counter_shots, vector <vector <pair <int, int>>> ships_shots);
	virtual bool Shot(int a, int b);
	virtual bool Check();
	bool The_Ship_Has_Been_Destroyed();
	void Print_Board();
	void Print_Play_Board();
};


class Comp : public Player {
	vector <pair <int, int>> allowed_coord;
	int flag = 0;
public:
	Comp(vector <vector <int>> brd, vector <vector <int>> pl_brd, int counter_shots, vector <vector <pair <int, int>>> ships_shots);
	void Forbidden_Area(int k);
	int Search_Coord(pair <int, int> coord);
	using Player::Player;
	using Player::Check;
	bool Shot();
};

class User : public Player {
public:
	using Player::Player;
	using Player::Shot;
	using Player::Check;
};

vector <pair <int, int>> App_Coord(int start_y, int start_x, int end_y, int end_x);

int Random_Board(int min_value, int max_value);
