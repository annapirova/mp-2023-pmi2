#include "matrix.h"
#include "Logic_sam.h"

void main()
{
	Player* user1, *user2, *tmp;
	
	user1 = new User;
	user2 = new Comp;

	while ()
	{
		user1->Attack(); // это сработает, если функции виртуальные
		user2->Check();
		user->WriteAnswer();
		if (переход хода)
		{
			tmp = user;
			user = user2;
			user2 = user;
		}
	}

	delete user;
	delete user2;
	
	// battle plan
	// 1. Nullify previous battle - for CPU and  Player
	// 2. Place ships for Player
	// 3. CPU places ships
	// 4. Begin battle while (есть корабли)
	// 5. Player Attack(GetField1FromCpu --> Check CPU --> отметить у себя -- > PlaceOnFieldTwoForPlayer --> Message)
	// обмен указателей user, comp
	// 6. CPU(2 cases:ifAnyPlayerShipGetHurt --> Try to guess --> IfHurt(If not HUrt)(If destroyed) --> begin of case1(FromTryToGuess)(begin of case2),randomAttackOn0 --> Ifhurt/notHurt --> message
	// 7. BattleUntilWin
	// 8. If player wants to restart go to first punct
}