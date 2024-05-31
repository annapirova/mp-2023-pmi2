//#include <iostream>
#include "Class.h"
//#include "Game.cpp"

bool Game(Field& CompField, Field& PlField) {
	CompField.FieldCompFill(CompField);	
	GetShipField(PlField);
	std::cout << "You and the Computer have a field with ships. The moves are made alternately, you do it first\n";

	// prosto dla ydobstva: proverit kak komp korabli rasstavil (i bistree proverit vse varianti kak shodit samomy)
	std::cout << "\nComp field:\n";
	CompField.fieldOut();
	std::cout << "\nYour field:\n";
	PlField.fieldOut();
	//

	bool lastPlMove = 0;
	bool lastCompMove = 1;	
	std::cout << "Your move:\n";
	lastPlMove = CompField.Attack(CompField, 'p'); // samyi pervui hod
	do {
		std::cout << "\nYour field:\n";
		PlField.fieldOut();
		char cwin = CompField.Win();
		char pwin = PlField.Win();
		if (cwin == 'w') return 0;
		if (pwin == 'w') return 1;

		if (!lastCompMove) { // opredelaem chia ochered hodit
			std::cout << "Your move:\n";
			lastPlMove = CompField.Attack(CompField, 'p');
			lastCompMove = !lastPlMove;
		}
		else if(lastCompMove) {
			std::cout << "Now the computer makes the move!\n";
			lastCompMove = PlField.Attack(PlField, 'c');
		}
	} while (true);
}
int main() {
	Field playerField(10, 10); playerField.FieldZeroFill(); // sozdaem pole nulei
	Field compField(10, 10); compField.FieldZeroFill();

	bool gameEnd = Game(compField, playerField);
	if(gameEnd == 0) std::cout << "\nComputer wins!\n";
	else if (gameEnd == 1) std::cout << "\nYou win!\n";
	else std::cout << "\nChtoto slomalos (sovsem)\n";
	return 0;
}