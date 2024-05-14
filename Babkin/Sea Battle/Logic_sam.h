#pragma once
#include "matrix.h"
#include <iostream>

class PlayerSan
{
private:
    matrix* field;
    matrix* field_optional;
public:
    PlayerSan()
    {
        field = new matrix(10,10);
        field_optional = new matrix(10, 10);
    }
    ~PlayerSan()
    {
        delete[] field;
        delete[] field_optional;
    }
    PlayerSan(const PlayerSan& masfx)
    {
        field = new matrix(10,10);
        field_optional = new matrix(10, 10);
    }

    void Nullify()
    {
        for (int j = 0; j < 10; j++) { for (int i = 0; i < 10; i++) { field->operator()(j, i) = 0.0; } }

    }
    // 1. я атакую --> € ввожу x, y, возвращаю пару чисел. соперник провер€ет
    // 2. ћен€ атакуют --> мне дают x, y, € отвечаю попал /  не попал
    virtual void CheckStatus() {}
    virtual void Attack() {}
    virtual void PlaceShips() {}
    virtual void FieldGet() {}
};
class User : public PlayerSan
{
protected:
    int x, y, countShips;
public:
    User(){}
    User(int _x, int _y) { x = _x; y = _y; countShips = 10;}
    ~User(){}
    void Placeship(int x, int y, int shipkind,int rotate)
    {

    }
    void CheckStatus(int x , int y)
    {
    }
    void Attack()
    {}
};


// -------------------------------------------------------
void Attack(int x, int y)
{
    //        matrix* a, * b;
    //        (*a) += (*b);

    if ((*field)(x, y) == 1.0)
    {
        (*field)(x, y) = 3.0;
        cout << "You hit the ship\n";
    }
    else
    {
        cout << "Better Luck Next Time\n";
    }
    //return *this;
}
