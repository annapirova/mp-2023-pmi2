#include "matrix.h"
#include "Logic_sam.h"
#include <iostream>
using namespace std;
int main()
{
	PlayerSan* user1, *user2;
	int wink = 0; int proc;
	user1 = new User;
	user2 = new ComputerSan;
	cout << "do you want to start a game?[1(y)/2(n)]\n";
	cin >> proc;
	while (proc == 1)
	{
		int px,py,shipkind,rotation,cx,cy;
		user1->Nullify();
		user2->Nullify();
		cout << user1->FieldGet();
		cout << "\n";
		cout << user2->FieldGet_op();
		int loop = 1;
		while (loop == 1)
		{
			cout << "Write coords for ship. Then you must write type of ship and rotation angle\n";
			cin >> px;
			cout << "\n";
			cin >> py;
			cout << "\n";
			cin >> shipkind;
			cout << "\n";
			cin >> rotation;
			cout << "\n";
			user1->Placeship(px,py,shipkind,rotation);
			cout << user1->FieldGet();
			cout << "\n";
			cout << user1->FieldGet_op();
			cout << "If you want to place more ships press 1\n";
			cin >> loop;
		}
		user2->Placeship(0,0,0,0);
		while (user1->CheckSells()!= 0 && user2->CheckSells() != 0)
		{
			cout << "Enter your coo-s\n";
			cin >> px;
			cin >> py;
			user2->GetResponse(px,py,*user1);
			user2->SentAttack(cx,cy);
			user1->GetResponse(cx,cy,*user2);
			cout << user1->FieldGet();
			cout << "\n";
			cout << user1->FieldGet_op();
		}
		if (user1->CheckSells() == 0)
		{
			cout << "Human's win\n";
		}
		else
		{
			cout << "Human's defeat\n";
		}
		}
		delete user1;
		delete user2;
		cout << "Do you want to play again?(1 for yes)\n";
		cin >> proc;
}
