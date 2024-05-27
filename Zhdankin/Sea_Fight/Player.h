#pragma once
#ifndef PLAYER__
#define PLAYER__
#include "../MatrixClass/Matrix.h"
#include <utility>

class Player
{
protected:
	Matrix myP;
	Matrix otherP;
	int nShips;
	int nWin;
public:
	Player(int size, int ships);
	virtual void PrintBoards();
	virtual void SetShips() = 0;
	virtual std::pair<int, int> Attack() = 0;
	bool CheckAttack(int x, int y);
	bool CheckWin();

};

class Human : public Player
{
public:
	Human(int size, int ships);
	void SetShips() override;
	void PrintBoards() override;
	std::pair<int, int> Attack() override;
};

class AI : public Player
{
public:
	AI(int size, int ships);
	void SetShips() override;
	void PrintBoards() override;
	pair<int, int> Attack();
private:
	bool CanPlaceShip(int x, int y, int size, char direction);
	
};
#endif

