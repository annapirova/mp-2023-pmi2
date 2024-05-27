#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstdlib>
#include<vector>
using namespace std;

struct Ship {
    int size;
    char napravlenie;
    int x, y;
    int k;
    bool Popal(int x1, int y1)
    {
        if (napravlenie == 'g')
        {
            for (int i = 0;i < size;i++)
            {
                if (((x) == x1) && (y+i == y1))
                {
                    return true;
                }
            }
        }
        if (napravlenie == 'v')
        {
            for (int i = 0;i < size;i++)
            {
                if (((y) == y1) && (x+i == x1))
                {
                    return true;
                }
            }
        }
        return false;
    }
};

class Player {
protected:
    vector<vector<int>> board;
    vector<vector<int>> chd;
    vector<Ship>ships;
public:
    Player() : board(10, vector<int>(10, 0)), chd(10, vector<int>(10, 0)) {}

    virtual void placeShips() = 0;

    virtual bool checkWin() {
        int count = 0;
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                if (board[i][j] == 1) {
                    count++;
                }
            }
        }
        return count == 0;
    }

    virtual bool shoot(int x, int y) = 0;

    void hitship(int x, int y)
    {
        chd[x][y] = 2;
    }

    void displayBoard() {
        cout << "  0 1 2 3 4 5 6 7 8 9    0 1 2 3 4 5 6 7 8 9 " << endl;
        for (int i = 0; i < 10; i++) {
            cout << i << " ";
            for (int j = 0; j < 10; j++) {
                cout << board[i][j] << " ";
            }
            cout << "   ";
            for (int j = 0; j < 10; j++) {
                cout << chd[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    bool canPlaceShip(int x, int y, int size, char napravlenie) {
        // Проверка, что корабль не выходит за пределы поля
        if (napravlenie == 'g' && (y + size > 9)) return false;
        if (napravlenie == 'v' && (x + size > 9)) return false;

        // Проверка,что вокруг корабля нет других кораблей
        if (napravlenie == 'g')
        {
            for (int i = 0; i <= size+1;i++)
            {
                for (int j = 0;j <= 2;j++)
                {
                    int checkX = x - 1;
                    int checkY = y - 1;
                    if (checkX >= 0 && checkX < 10 && checkY >= 0 && checkY < 10 && board[checkX+j][checkY + i] != 0)
                    {
                            return false;
                    }
                }
            }
        }
        if (napravlenie == 'v')
        {
            for (int j = 0;j <= size + 1;j++)
            {
                for (int i = 0; i <= 2;i++)
                {
                    int checkX = x - 1;
                    int checkY = y - 1;

                    if (checkX>=0 && checkX<10 && checkY>=0 && checkY<10 && board[checkX+j][checkY + i] != 0)
                    {
                            return false;
                    }
                }
            }
        }
        return true; // Место для корабля свободно
    }

};


class Human : public Player {

public:
    void placeShips() override {
        int shipSizes[] = { 1, 2, 3}; // Размеры кораблей
        int x, y;
        char napravlenie;
        for (int size=1;size <= 3;size++)
        {
            Ship s;
            cout << "Расставляем корабль размером " << size << ". Введите координаты начала (x y) и направление (g/v): ";
            cin >> s.x >> s.y >> s.napravlenie;
            s.size = size;
            // Проверка корректности
            if (s.x < 0 || s.x >= 10 || s.y < 0 || s.y >= 10 || (s.napravlenie != 'g' && s.napravlenie != 'v'))
            {
                cout << "Некорректный ввод. Попробуйте еще раз." << endl;
                size--;
                continue;
            }
            ships.push_back(s); // Добавление начальной координаты корабля

            if (s.napravlenie == 'g') {
                for (int i = 0; i < s.size; ++i)
                {
                    board[s.x][s.y + i] = 1;
                }
            }
            else
            {
                for (int i = 0; i < s.size; ++i)
                {
                    board[s.x + i][s.y] = 1;
                }
            }
        }
    }

    bool shoot(int x, int y) override {
        if (board[x][y] == 1) {
            cout << "Компьютер подстрелил вражеский корабль!" << endl;
            board[x][y] = 2;
            for (int i = 0;i < ships.size();i++)
            {
                if (ships[i].Popal(x, y) == true)
                {
                    ships[i].k -= 1;
                    if (ships[i].k == 0)
                    {
                        cout << "Кораль потоплен" << endl;
                    }
                }
            }
            return true;
        }
        else {
            cout << "Компьютер промахнулся." << endl;
            return false;
        }
    }
};

class Computer : public Player {

public:
    void placeShips() override {                                    
        int shipSizes[] = { 1, 2, 3 }; // Размеры кораблей
        int x, y;
        char napravlenie;
        int flag = 0;

        for (int size = 1;size <= 3;size++)
        {
            Ship t;
            t.x = rand() % 10;  // а должно быть 10 но не работает
            t.y = rand() % 10;
            char napravlenie[] = { 'g', 'v' };
            t.napravlenie = napravlenie[rand() % 2];
            t.size = size;
            t.k = size;
            if (canPlaceShip(t.x, t.y, t.size, t.napravlenie) != true)
            {
                size--;
                continue;
            }
            ships.push_back(t); // Добавление начальной координаты корабля  
            if (t.napravlenie == 'g') {
                for (int i = 0; i < t.size; ++i)
                {


                    board[t.x][t.y + i] = 1;

                }
            }
            else
            {
                for (int i = 0; i < t.size; ++i)
                {

                    board[t.x + i][t.y] = 1;

                }
            }
            
        }
    }

    bool shoot(int x, int y) override { 
        if (board[x][y] == 1) {
            cout << "Человек подстрелил вражеский корабль!" << endl;
            board[x][y] = 2;
            for (int i = 0;i < ships.size();i++)
            {
                if (ships[i].Popal(x, y) == true)
                {
                    ships[i].k -= 1;
                    if (ships[i].k == 0)
                    {
                        cout << "Кораль потоплен" << endl;
                    }
                }
            }
            return true;
        }
        else {
            cout << "Человек промахнулся." << endl;
            return false;
        }
    }
};

int main() {
    setlocale(LC_ALL, "Russian");
    Human human;
    Computer computer;
    int x=0, y=0;
    char napravlenie=0;
    int size = 4;

    human.placeShips();
    computer.placeShips();

    cout << "Человек:" << endl;
    human.displayBoard();
    cout << "Компьютер:" << endl;
    computer.displayBoard();

    while (true) {
        cout << "Ход человека:" << endl;
        int x, y;
        cout << "Введите координаты для выстрела (формат: x y): ";
        cin >> x >> y;
        if (computer.shoot(x, y)) {
            human.hitship(x, y);
            if (computer.checkWin()) {
                cout << "Человек выиграл!" << endl;
                break;
            }
            continue;
        }

        human.displayBoard();

        cout << "Ход компьютера:" << endl;
        x = rand() % 10;
        y = rand() % 10;
        if (human.shoot(x, y)) {
            computer.hitship(x, y);
            if (human.checkWin()) {
                cout << "Компьютер выиграл!" << endl;
                break;
            }
        }
        computer.displayBoard();
    }

    return 0;
}