#include "Player.h"
#include <iostream>

using namespace std;

int main()
{
	

	AI AI_Player(10, 10);
	AI_Player.SetShips();

	AI_Player.PrintBoards();

	Human Human_Player(10, 10);

	Human_Player.SetShips();
	Human_Player.PrintBoards();

    bool gameOver = false;
    while (!gameOver)
    {
        // Ход человека
        cout << "Human player's turn:" << endl;
        pair<int, int> HumanCoords = Human_Player.Attack();
        bool hit = AI_Player.CheckAttack(HumanCoords.first, HumanCoords.second);
        if (hit == true)
        {
            cout << "Hit!" << endl;
        }
        else
        {
            cout << "Miss!" << endl;
        }
        AI_Player.PrintBoards();


        // Ход компьютера
        cout << "AI player's turn:" << endl;
        pair<int, int> AICoords = AI_Player.Attack();
        hit = Human_Player.CheckAttack(AICoords.first, AICoords.second);

        if (hit == true)
        {
            cout << "Hit!" << endl;
        }
        else
        {
            cout << "Miss!" << endl;
        }
    }

	return 0;
}