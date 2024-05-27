#include <iostream>
#include <string>
#include <vector>
#include <locale.h>
#include "class player.h"
using namespace std;

int main()
{
  
    setlocale(LC_CTYPE, "Russian");
    int choice;
    int Length;
    std::cout << "Выберите длину загадываемого числа (1 или 4): ";
    std::cin >> Length;
    bool run = 1;
    while (run)
    {
        cout << "Кто загадывает первым?" << std::endl;
        cout << "1 - я, 2 - компьютер" << std::endl;
        cout << "Чтобы выйти нажми 3" << endl;
        std::cin >> choice;
        switch (choice)
        {
        case 1:
        {
            std::vector <int> guess;
            std::pair <int, int> animals = std::make_pair(-2, -2);
            User user(Length);
            user.SetX();
            Comp computer(Length);
            computer.SetBCandCOUNT();
            while ((animals.first != -1) && (animals.second != -1))
            {
                guess = computer.MaybeIt(animals.first, animals.second);
                animals = user.GuessNumber(guess);
            }
            int c1 = computer.GetCount();
            cout << "Комп угадал за " << c1 << " ходов *-*" << endl;
            break;

        }
        case 2:
        {
            std::vector <int> guess;
            bool win = 0;
            Comp computer(Length);
            computer.SetX();
            User user(Length);
            while (win != 1)
            {
                guess = user.MaybeIt();
                win = computer.GuessNumber(guess);
            }
            int c2 = user.GetCount();
            cout << "Ты угадал за " << c2 << " ходов ^-^" << endl;
            break;
        }
        case 3:
        {
            run = 0;
        }
    }}
    return 0;
}