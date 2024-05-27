#include "Player.h"
#include <random>
#include <ctime>

using namespace std;

Player::Player(int size, int ships) : myP(size), otherP(size), nShips(ships), nWin(0)
{
}

void Player::PrintBoards()
{
	cout << "My board" << endl;
	myP.Print();
	cout << endl;
	cout << "Opponent Board:" << endl;
	otherP.Print();
}

bool Player::CheckAttack(int x, int y)
{
	x -= 1;
	y -= 1;
	if (otherP.GetValue(x, y) == 1)
	{
		otherP(y, x) = 2;
		if (otherP.IsShipSunk(x, y))
		{
			cout << "Ship sunk!" << endl;
		}
		return true;
	}
	else
	{
		return false;
	}


}

bool Player::CheckWin()
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (myP.GetValue(i, j) == 1) // Если есть хотя бы одна клетка с кораблем
			{
				return false;
			}
		}
	}
	return true;
}

bool Matrix::IsShipSunk(int x, int y)
{
	// Проверка горизонтально
	int i = x;
	while (i >= 0 && A[y][i] == 2) --i; // Идём влево до конца корабля
	if (i >= 0 && A[y][i] == 1) return false; // Если найдена часть корабля, которая не подбита, значит корабль не потоплен

	i = x;
	while (i < 10 && A[y][i] == 2) ++i; // Идём вправо до конца корабля
	if (i < 10 && A[y][i] == 1) return false; // Если найдена часть корабля, которая не подбита, значит корабль не потоплен

	// Проверка вертикально
	int j = y;
	while (j >= 0 && A[j][x] == 2) --j; // Идём вверх до конца корабля
	if (j >= 0 && A[j][x] == 1) return false; // Если найдена часть корабля, которая не подбита, значит корабль не потоплен

	j = y;
	while (j < 10 && A[j][x] == 2) ++j; // Идём вниз до конца корабля
	if (j < 10 && A[j][x] == 1) return false; // Если найдена часть корабля, которая не подбита, значит корабль не потоплен

	return true;
}

void Matrix::SetValue(int x, int y, int count, char direct)
{
	if ((x >= 0 && x < 10) && (y >= 0 && y < 10))
	{
		if (direct == 'h')
		{
			for (int l = 0; l < count; l++)
			{
				if (x + l < 10)
				{
					A[y][x + l] = 1;
				}
				else
				{
					cout << "out of bounds";
					break;
				}
			}
		}
		else if (direct == 'v')
		{
			for (int l = 0; l < count; l++)
			{
				if (y + l < 10)
				{
					A[y + l][x] = 1;
				}
				else
				{
					cout << "out of bounds";
					break;
				}
			}
		}
	}
}



Human::Human(int size, int ships) : Player(size, ships)
{
}

void Human::PrintBoards()
{
	cout << "My board" << endl;
	myP.Print();
	cout << endl;
}

void Human::SetShips()
{
	int Ships[] = {4, 3, 3, 2, 2, 2, 1, 1, 1, 1};
	char direction;
	int x, y;
	for (int sizes : Ships)
	{	
		cout << "Enter Coordinates(x, y) and direction(h or v) for " << sizes << "-deck ship" << endl;
		cin >> x >> y >> direction;
		myP.SetValue(x-1, y-1, sizes, direction);
		myP.Print();
	}
}

pair<int, int> Human::Attack()
{
	int x, y;
	cout << "Enter coords of Attack(x, y):" << endl;
	cin >> x >> y;
	return { x, y };
}




AI::AI(int size, int ships) : Player(size, ships)
{
}

void AI::SetShips()
{
	int Ships[] = { 4, 3, 3, 2, 2, 2, 1, 1, 1, 1 };
	char directions[] = { 'h', 'v' };
	std::mt19937 gen(static_cast<unsigned int>(std::time(nullptr)));
	std::uniform_int_distribution<> dir_dist(0, 1);

	for (int size : Ships)
	{
		bool placed = false;
		while (!placed)
		{
			char direction = directions[dir_dist(gen)];
			int x = rand() % 10;
			int y = rand() % 10;

			if (CanPlaceShip(x, y, size, direction))
			{
				otherP.SetValue(x, y, size, direction);
				placed = true;
			}
		}
	}
}

bool AI::CanPlaceShip(int x, int y, int size, char direction)
{
	if (direction == 'h')
	{
		if (x + size > 10) return false;
		for (int i = 0; i < size; i++)
		{
			if (otherP.GetValue(x + i, y) != 0) return false;
		}
	}
	else if (direction == 'v')
	{
		if (y + size > 10) return false;
		for (int i = 0; i < size; i++)
		{
			if (otherP.GetValue(x, y + i) != 0) return false;
		}
	}

	for (int i = -1; i <= size; i++)
	{
		for (int j = -1; j <= 1; j++)
		{
			int checkX = (direction == 'h') ? x + i : x + j;
			int checkY = (direction == 'v') ? y + i : y + j;
			if (checkX >= 0 && checkX < 10 && checkY >= 0 && checkY < 10)
			{
				if (otherP.GetValue(checkX, checkY) != 0) return false;
			}
		}
	}
	return true;
}

pair<int, int> AI::Attack()
{
	int x = rand() % 10;
	int y = rand() % 10;
	return { x, y };
}

void AI::PrintBoards()
{
	cout << "AI board" << endl;
	otherP.Print();
	cout << endl;
}