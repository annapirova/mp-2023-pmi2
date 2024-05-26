#ifndef PLAYER_H
#define PLAYERT_H
#include <iostream>
#include <string>
#include <vector>
#include <locale.h>
#include <ctime>
#include <algorithm>
#include <random> 
using namespace std;
//функция, разбивающая число на цифры для передачи в вектор
std::vector <int> ConvertToVector(int num, int count)
{
    int a = num;
    std::vector<int> v;
    int l = count - 1;
    while (l >= 0)
    {
        for (int i = 0; i < count; i++)
        {
            int y = pow(10, l);
            v.push_back(a / y);
            //v[i] = a/ y;
            a %= y;
            l--;
        }
    }
    return v;
}
int ConvertToDigit(std::vector <int> vec, int count)
{
    int l = count - 1;
    int y = 0;
    for (int i = 0; i < count; i++)
    {
        y += vec[i] * pow(10, l);
        l--;
    }
    return y;
}
int findElementIndex(const std::vector<int>& vec, int element) {
    for (size_t i = 0; i < vec.size(); ++i) {
        if (vec[i] == element) {
            return i; // Возвращаем индекс найденного элемента
        }
    }
}
bool contains(const std::vector<int>& v, int val) {
    return std::find(v.begin(), v.end(), val) != v.end();
}

class Player
{
protected:
    int n;
    std::vector<int> x;
    int count;

public:
    Player(int l) { n = l; std::vector <int> w(l); x = w; }
    virtual void SetX() = 0;
    int GetCount()
    {
        return count;
    }
    bool GuessNumber(std::vector<int>& vec) {

        int bulls = 0;
        int cows = 0;
        if (vec != x)
        {
            for (int i = 0; i < n; ++i) {
                if (x[i] == vec[i]) {
                    bulls++;
                }
            }
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (x[i] == vec[j] && (i != j)) {
                        cows++;
                        break;
                    }
                }
            }
            std::cout << "Не угадал, быков: " << bulls << ", коров: " << cows << std::endl;
            return 0;
        }
        else {
            std::cout << "Ты выиграл!!" << std::endl;
            std::pair <int, int> res = std::make_pair(0, 0);
            return 1;
        }
    }
};

class User : public Player
{
public:
    using Player::Player;
    virtual void SetX()
    {
        int number;
        std::cout << "Введи число длины " << n << std::endl;
        std::cin >> number;
        x = ConvertToVector(number, n);
    }
    void SetCount()
    {
        count = 0;
    }
    std::pair<int, int> GuessNumber(std::vector<int>& vec) {
        int cows = 0;
        int bulls = 0;
        if (vec != x)
        {
            for (int i = 0; i < n; ++i) {
                if (x[i] == vec[i]) {
                    bulls++;
                }
            }
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (x[i] == vec[j] && i != j) {
                        cows++;
                        break;
                    }
                }
            }
            std::cout << "Не угадал, быков: " << bulls << ", коров: " << cows << std::endl;
            std::pair <int, int> res = std::make_pair(bulls, cows);
            return res;
        }
        else {
            std::cout << "Компьютер угадал!!" << std::endl;
            std::pair <int, int> res = std::make_pair(-1, -1);
            return res;
        }
    }
    std::vector<int> MaybeIt()
    {
        count++;
        int mb;
        std::cout << "Попробуй угадать" << std::endl;
        std::cin >> mb;
        x = ConvertToVector(mb, n);
        return x;
    }
};

class Comp : public Player
{
protected:
    std::vector <std::vector <int>> bc; // вектор, который показывает, встречается ли цифра индекса: 0 - нет, 1 - бык, 2 - корова, -1 - хз
    std::vector <int> ten; //-1 - цифры точно нет
    std::vector <int> tryses;
    std::vector <std::pair<int, int>> answers;
public:
    using Player::Player;
    void SetBCandCOUNT()
    {
        bc.assign(10, { -1 });
        count = 0;
        ten = { 0,1,2,3,4,5,6,7,8,9 };
    }
    virtual void SetX()
    {
        srand(time(NULL));
        int tmp = 0, z = 0;
        std::vector <int> ten1 = { 0,1,2,3,4,5,6,7,8,9 };
        for (int i = 0; i < n; i++)
        {
            z = rand() % 9 + 1;
            while (ten1[z] == -1)
            {
                z = rand() % 9 + 1;
            }
            tmp += (ten1[z] * pow(10, i));
            ten1[z] = -1;
        }
        x = ConvertToVector(tmp, n);
    }
    void SetXForGuess(std::vector<int>& numbers)
    {
        srand(time(NULL));
        int tmp = 0, z = 0;
        std::vector <int> ten2 = numbers;
        for (int i = 0; i < n; i++)
        {
            z = rand() % 10;
            while ((ten2[z] == -1) || (ten2[z] == -2) || ((i == n-1) && (z == 0)))
            {
                z = rand() % 10;
            }
            tmp += (z * pow(10, i));
            ten2[z] = -2;
        }
        x = ConvertToVector(tmp, n);
    }
    bool NewOrNot(std::vector<int>& vec)
    {
        int w = ConvertToDigit(vec, n);
        auto result{ std::find(begin(tryses), end(tryses), w) };
        if (result == end(tryses))
            return 0;
        else
            return 1;
    }

    std::vector<int> MaybeIt(int b, int k)
    {
        std::vector <int> tmp;
        count++;
        if (count == 1)
        {
            SetX();
            int y = ConvertToDigit(x, n);
            tryses.push_back(y);
            std::cout << "Может это " << y << " ?" << std::endl;
            return x;
        }
        if ((b != 0) || (k != 0))
        {
            int last = tryses[(count - 2)];
            tmp = ConvertToVector(last, n);
            
            if ((b == 0) && (k != 0))
            {
                if (k == n) {
                    for (int i = 0; i < n; i++)
                    {
                        bc[tmp[i]].push_back(i);
                    }    
                    std::vector <int >tmp1 = tmp;
                    while ((tmp1[0] == 0) || (NewOrNot(tmp1) == 1) || contains(bc[tmp[0]],findElementIndex(tmp1,tmp[0]))==1 || contains(bc[tmp[1]], findElementIndex(tmp1, tmp[1])) == 1 || contains(bc[tmp[2]], findElementIndex(tmp1, tmp[2])) == 1 || contains(bc[tmp[3]], findElementIndex(tmp1, tmp[3])) == 1)
                    {
                        random_device rd;
                        mt19937 g(rd());
                        std::shuffle(tmp1.begin(), tmp1.end(), g);
                    }
                    x = tmp1;
                    int y = ConvertToDigit(x, n);
                    tryses.push_back(y);
                    answers.push_back(std::pair <int, int>(b, k));
                    std::cout << "Может это " << y << "?" << std::endl;
                    return x;
                }
                if (k != n)
                {
                   
                    std::vector <int >tmp1 = tmp;
                    while ((tmp1[0] == 0))
                    {
                        random_device rd;
                        mt19937 g(rd());
                        std::shuffle(tmp1.begin(), tmp1.end(), g);
                    }
                    x = tmp1;
                    int z = 0;
                    while ((NewOrNot(x) == 1)||(x==tmp)) {
                        for (int i = 0; i < (n - k); i++)
                        {
                            srand(time(NULL));
                            z = rand() % 10;
                            while ((ten[z] == -1) || contains(tmp, z) == 1 || contains(x, z) == 1 || ((k+i == 0) && (z == 0)))
                            {
                                z = rand() % 10;
                            }
                            x[k + i] = ten[z];
                        }
                    }
                    int y = ConvertToDigit(x, n);
                    tryses.push_back(y);
                    answers.push_back(std::pair <int, int>(b, k));
                    std::cout << "Может это " << y << " ?" << std::endl;
                    return x;
                }
            }

            if ((b != 0) && (k == 0))
            {
               
                for (int i = 0; i < b; i++)
                {
                    x[i] = tmp[i];
                }
                int z = 0;
                while (NewOrNot(x) == 1)
                {
                    for (int i = 0; i < (n - b); i++)
                    {
                        srand(time(NULL));
                        z = rand() % 10;
                        while ((ten[z] == -1) || (x[0] == z) || contains(tmp, z) == 1 || contains(x, z) == 1 || ((b + i == 0) && (z == 0)))
                        {
                            z = rand() % 10;
                        }
                        x[b + i] = ten[z];
                    }
                }
                int y = ConvertToDigit(x, n);
                tryses.push_back(y);
                answers.push_back(std::pair <int, int>(b, k));
                std::cout << "Может это " << y << " ?" << std::endl;
                return x;
            }
            if ((b != 0) && (k != 0))
            {
                if ((b + k) == n)
                {
                    if (n == 2)
                    {
                        while ((NewOrNot(tmp) == 1) || (tmp[0] == 0))
                        {
                            random_device rd;
                            mt19937 g(rd());
                            std::shuffle(tmp.begin(), tmp.end(), g);
                        }
                        x = tmp;
                        int y = ConvertToDigit(x, n);
                        tryses.push_back(y);
                        answers.push_back(std::pair <int, int>(b, k));
                        std::cout << "Может это " << y << " ?" << std::endl;
                        return x;
                    }
                    if (n == 4)
                    {
                        std::vector <int> tmp1 = tmp;
                        while ((NewOrNot(tmp1) == 1) || (tmp1[0] == 0) || contains(bc[tmp1[0]],0) == 1 || contains(bc[tmp1[1]], 1) == 1 || contains(bc[tmp1[2]], 2) == 1 || contains(bc[tmp1[3]], 3) == 1)
                        {
                            random_device rd;
                            mt19937 g(rd());
                            std::shuffle(tmp1.begin(), tmp1.end(), g);
                        }
                        x = tmp1;
                        int y = ConvertToDigit(x, n);
                        tryses.push_back(y);
                        answers.push_back(std::pair <int, int>(b, k));
                        std::cout << "Может это " << y << " ?" << std::endl;
                        return x;
                    }
                }
                else
                {
                    if ((b == 1) && (k == 1))
                    { 
                        int z, z1;
                        int p1, p2, pk, pb;
                        p1 = p2 = pk = pb = 0;
                        srand(time(NULL));
                        while ((p1 == p2) || (p2 == pk) || (pk == pb) || (p1 == pb) || (p1 == pk) || (p2 == pb))
                        {
                            p1 = rand() % n;
                            p2 = rand() % n;
                            pk = rand() % n;
                            pb = rand() % n;
                        }
                        while (NewOrNot(x) == 1)
                        {
                                srand(time(NULL));
                                z = rand() % 10;
                                z1 = rand() % 10;
                                while ((ten[z] == -1) || (ten[z1] == -1)||(z == z1) || (z == tmp[pb]) || (z1 == tmp[pb]) || (z1 == tmp[p1]) || (z == tmp[p1]) || ((p2 == 0) && (z == 0)) || ((p1 == 0) && (z1 == 0)))
                                {
                                    z = rand() % 10;
                                    z1 = rand() % 10;
                                }
                                x[p2] = ten[z];
                                x[p1] = ten[z1];
                                x[pb] = tmp[pb];
                                x[pk] = tmp[p1];
                        }
                        int y = ConvertToDigit(x, n);
                        tryses.push_back(y);
                        answers.push_back(std::pair <int, int>(b, k));
                        std::cout << "Может это " << y << " ?" << std::endl;
                        return x;
                    }
                    if ((b == 1) && (k == 2))
                    {
                        int z;
                        int p1, pk, pk1, pb;
                        p1 = pk1 = pk = pb = 0;
                        while ((p1 == pk1) || (pk1 == pk) || (pk == pb) || (p1 == pb) || (p1 == pk) || (pk1 == pb))
                        {
                            srand(time(NULL));
                            p1 = rand() % n;
                            pk1 = rand() % n;
                            pk = rand() % n;
                            pb = rand() % n;
                        }                        
                        while (NewOrNot(x) == 1)
                        {
                                srand(time(NULL));
                                z = rand() % 10;
                                while ((ten[z] == -1) || (z==tmp[pb]) || (z==tmp[p1]) || (z==tmp[pk]) || ((p1 == 0) && (z == 0)))
                                {
                                    z = rand() % 10;
                                }
                                x[p1] = ten[z];
                                x[pb] = tmp[pb];
                                x[pk] = tmp[p1];
                                x[pk1] = tmp[pk];
                        }
                        int y = ConvertToDigit(x, n);
                        tryses.push_back(y);
                        answers.push_back(std::pair <int, int>(b, k));
                        std::cout << "Может это " << y << " ?" << std::endl;
                        return x;
                    }
                    if ((b == 2) && (k == 1)) 
                    {
                        int z, z1;
                        int p1, pk, pb1, pb;
                        p1 = pb1 = pk = pb = 0;
                        while ((p1 == pb1) || (pb1 == pk) || (pk == pb) || (p1 == pb) || (p1 == pk) || (pb1 == pb))
                        {
                            srand(time(NULL));
                            p1 = rand() % (n);
                            pb1 = rand() % (n);
                            pk = rand() %(n);
                            pb = rand() % (n);
                        }                        
                        while (NewOrNot(x) == 1)
                        {
                                srand(time(NULL));
                                z = rand() % 10;
                                while ((ten[z] == -1) || (z == tmp[pb]) || (z == tmp[p1]) || (z == tmp[pb1]) || ((p1 == 0) && (z == 0)))
                                {
                                    z = rand() % 10;
                                }
                                x[p1] = ten[z];
                                x[pb] = tmp[pb];
                                x[pk] = tmp[p1];
                                x[pb1] = tmp[pb1];
                        }
                        int y = ConvertToDigit(x, n);
                        tryses.push_back(y);
                        answers.push_back(std::pair <int, int>(b, k));
                        std::cout << "Может это " << y << " ?" << std::endl;
                        return x;
                    }
                }
            }
        }
        if ((b == 0) && (k == 0))
        {
            for (int i = 0; i < n; i++)
            {
                ten[x[i]] = -1;
            }
            SetXForGuess(ten);
            int y = ConvertToDigit(x, n);
            tryses.push_back(y);
            answers.push_back(std::pair <int, int>(b, k));
            std::cout << "Может это " << y << " ?" << std::endl;
            return x;
        }
    }
};
#endif // PLAYER_H
