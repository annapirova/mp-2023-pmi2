using namespace std;
#include <iostream>
#include "Player.h"
#include <vector>
#include <locale.h>
#include <random>
#include <ctime>

int main() {
	setlocale(LC_CTYPE, "Rus");
	vector <vector <vector <int>>> all_boards_for_comp;
	vector <vector <int>> a, b, c, Board, Play_Board, result_board_computer;
	pair <int, int> start, end, tmp;
	vector <vector <vector <pair <int, int>>>> all_coordinate_ships_computer;
	vector <vector <pair <int, int>>> coordinate_ships_user, coordinate_ships_computer_1, coordinate_ships_computer_2, coordinate_ships_computer_3;
	int number;
	a = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		 {0, 1, 0, 0, 1, 0, 0, 1, 1, 0, 1, 0},
		 {0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		 {0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		 {0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0},
		 {0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0},
		 {0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0},
		 {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		 {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		 {0, 0, 0, 1, 1, 1, 0, 1, 1, 0, 0, 0},
		 {0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
		 {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	};
	coordinate_ships_computer_1.push_back(App_Coord(0, 0, 3, 0));
	coordinate_ships_computer_1.push_back(App_Coord(8, 2, 8, 4));
	coordinate_ships_computer_1.push_back(App_Coord(3, 7, 5, 7));
	coordinate_ships_computer_1.push_back(App_Coord(0, 7, 0, 8));
	coordinate_ships_computer_1.push_back(App_Coord(3, 9, 4, 9));
	coordinate_ships_computer_1.push_back(App_Coord(8, 6, 8, 7));
	coordinate_ships_computer_1.push_back(App_Coord(9, 0, 9, 0));
	coordinate_ships_computer_1.push_back(App_Coord(9, 9, 9, 9));
	coordinate_ships_computer_1.push_back(App_Coord(0, 9, 0, 9));
	coordinate_ships_computer_1.push_back(App_Coord(5, 3, 5, 3));

	b = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		 {0, 1, 0, 0, 0, 0, 0, 1, 1, 0, 1, 0},
		 {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		 {0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
		 {0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
		 {0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		 {0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
		 {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
		 {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
		 {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		 {0, 1, 0, 1, 1, 1, 0, 1, 1, 0, 1, 0},
		 {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	};
	coordinate_ships_computer_2.push_back(App_Coord(2, 0, 5, 0));
	coordinate_ships_computer_1.push_back(App_Coord(9, 2, 9, 4));
	coordinate_ships_computer_1.push_back(App_Coord(5, 9, 7, 9));
	coordinate_ships_computer_1.push_back(App_Coord(9, 6, 9, 7));
	coordinate_ships_computer_1.push_back(App_Coord(2, 9, 3, 9));
	coordinate_ships_computer_1.push_back(App_Coord(0, 6, 0, 7));
	coordinate_ships_computer_1.push_back(App_Coord(0, 0, 0, 0));
	coordinate_ships_computer_1.push_back(App_Coord(9, 0, 9, 0));
	coordinate_ships_computer_1.push_back(App_Coord(0, 9, 0, 9));
	coordinate_ships_computer_1.push_back(App_Coord(9, 9, 9, 9));


	c = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		 {0, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 0},
		 {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		 {0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0},
		 {0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0},
		 {0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0},
		 {0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0},
		 {0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0},
		 {0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0},
		 {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		 {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
		 {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	};
	coordinate_ships_computer_3.push_back(App_Coord(0, 0, 0, 3));
	coordinate_ships_computer_3.push_back(App_Coord(0, 5, 0, 7));
	coordinate_ships_computer_3.push_back(App_Coord(5, 9, 7, 9));
	coordinate_ships_computer_3.push_back(App_Coord(2, 9, 3, 9));
	coordinate_ships_computer_3.push_back(App_Coord(3, 7, 4, 7));
	coordinate_ships_computer_3.push_back(App_Coord(6, 7, 7, 7));
	coordinate_ships_computer_3.push_back(App_Coord(0, 9, 0, 9));
	coordinate_ships_computer_3.push_back(App_Coord(5, 5, 5, 5));
	coordinate_ships_computer_3.push_back(App_Coord(2, 2, 2, 2));
	coordinate_ships_computer_3.push_back(App_Coord(9, 9, 9, 9));

	Board = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		 {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		 {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		 {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		 {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		 {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		 {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		 {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		 {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		 {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		 {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		 {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	};
	Play_Board = { {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		 {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		 {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		 {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		 {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		 {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		 {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		 {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		 {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		 {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		 {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		 {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	};
	all_boards_for_comp = { a, b, c };
	all_coordinate_ships_computer = { coordinate_ships_computer_1,
									coordinate_ships_computer_2,
									coordinate_ships_computer_3 };
	cout << "Для расстановки кораблей вводите координату начала, а затем конца"<< endl;
	cout << "Координата принимает значение от 0 до 9 и имеет вид: (вертикаль, горизонталь)" << endl;
	cout << "Четырёхпалубный" << endl;
	cout << "Start: " << endl;
	cin >> start.first >> start.second;
	cout << "End: " << endl;
	cin >> end.first >> end.second;
	coordinate_ships_user.push_back(App_Coord(start.first, start.second, end.first, end.second));
	for (int i = 0; i < 2; i++) {
		cout << "Трёхпалубный" << endl;
		cout << "Start: " << endl;
		cin >> start.first >> start.second;
		cout << "End: " << endl;
		cin >> end.first >> end.second;
		coordinate_ships_user.push_back(App_Coord(start.first, start.second, end.first, end.second));
	}

	for (int i = 0; i < 3; i++) {
		cout << "Двухпалубный" << endl;
		cout << "Start: " << endl;
		cin >> start.first >> start.second;
		cout << "End: " << endl;
		cin >> end.first >> end.second;
		coordinate_ships_user.push_back(App_Coord(start.first, start.second, end.first, end.second));
	}

	for (int i = 0; i < 4; i++) {
		cout << "Однопалубный" << endl;
		cout << "Coordinate: " << endl;
		cin >> start.first >> start.second;
		end.first = start.first;
		end.second = start.second;
		coordinate_ships_user.push_back(App_Coord(start.first, start.second, end.first, end.second));
	}
	for (int i = 0; i < coordinate_ships_user.size(); i++) {
		for (int j = 0; j < coordinate_ships_user[i].size(); j++) {
			int a, b;
			a = coordinate_ships_user[i][j].first + 1;
			b = coordinate_ships_user[i][j].second + 1;
			Board[a][b] = 1;
		}
	}
	number = Random_Board(0, 2);
	User Human(all_boards_for_comp[number], Play_Board, 0, all_coordinate_ships_computer[number]);
	Comp Computer(Board, Play_Board, 0, coordinate_ships_user);
	Human.Print_Board();
	int flag = 1;
 	while ((Human.Check() == 0) && (Computer.Check() == 0)) {
		int a, b;
		if (flag) {
			cout << "Ваш ход" << endl;
			cout << "Координата: " << endl;
			cin >> a >> b;
			if (Human.Shot(a + 1, b + 1) == false) {
				flag = 0;
			}
			Human.Print_Play_Board();
		}
		else {
			cout << "Ход компьютера" << endl;
			if (Computer.Shot() == false) {
				flag = 1;
			}
			Computer.Print_Play_Board();
		}
	}
	if (Computer.Check()) {
		cout << "Компьютер победил";
	}
	else {
		cout << "Вы выйграли";
	}
}