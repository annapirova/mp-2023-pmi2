#pragma once
#include "matrix.h"
#include <iostream>
#include <cstdlib>
class PlayerSan
{
protected:
    matrix* field;
    matrix* field_optional;
    int stats[4] = {4,3,2,1};
public:
    PlayerSan()
    {
    }
    ~PlayerSan()
    {
    }
    PlayerSan(const PlayerSan& masfx)
    {
    }

    virtual void Nullify() {}
    virtual int CheckStatus() {}
    virtual int Attack() {}
    virtual void PlaceShips() {}
    matrix FieldGet() { return *field; };
};
class User : public PlayerSan
{
public:
    User() { field = new matrix(12, 12); field_optional = new matrix(12, 12);}
    ~User() { delete[] field; delete[] field_optional; }
    void Nullify()
    {
        for (int j = 1; j < 11; j++) { for (int i = 1; i < 11; i++) { field->operator()(j, i) = 0.0; } }
        for (int i = 0; i < 12; i++) { field->operator()(0, i) = 5.0; field->operator()(i, 0) = 5.0; field->operator()(i, 11) = 5.0; field->operator()(11, i) = 5.0; }
        for (int j = 1; j < 11; j++) { for (int i = 1; i < 11; i++) { field_optional->operator()(j, i) = 0.0; } }
        for (int i = 0; i < 12; i++) { field_optional->operator()(0, i) = 5.0; field_optional->operator()(i, 0) = 5.0; field_optional->operator()(i, 11) = 5.0; field_optional->operator()(11, i) = 5.0; }
    }
    void Placeship(int x, int y, int shipkind, int rotate)
    {
        if (shipkind > -1 && shipkind < 4)
        {
            switch (rotate)
            {
            case(0):
                if (y - shipkind > 0 && (field->operator()(x - 1, y) != 1.0) && (field->operator()(x + 1, y) != 1.0) && field->operator()(x, y - 1) != 2.0 && (field->operator()(x - 1, y - 1) != 1.0) && (field->operator()(x + 1, y - 1) != 1.0) && stats[shipkind] > 0)
                {
                    if (y + 1 < 11)
                    {
                        field->operator()(x - 1, y + 1) = 2.0;
                        field->operator()(x, y + 1) = 2.0;
                        field->operator()(x + 1, y + 1) = 2.0;
                    }
                    for (int h = 0; h <= shipkind; h++)
                    {
                        field->operator()(x, y - h) = 1.0;
                        field->operator()(x - 1, y - h) = 2.0;
                        field->operator()(x + 1, y - h) = 2.0;
                    }
                    field->operator()(x - 1, y - shipkind) = 2.0;
                    field->operator()(x, y - shipkind) = 2.0;
                    field->operator()(x + 1, y - shipkind) = 2.0;
                    stats[shipkind] -= 1;
                }
                else
                {
                    cout << "Invalid ship placement\n"; break;
                }
                break;
            case(90):
                if (x + shipkind < 11 && (field->operator()(x, y - 1) != 1.0) && (field->operator()(x, y + 1) != 1.0) && field->operator()(x + 1, y) != 2.0 && (field->operator()(x + 1, y - 1) != 1.0) && (field->operator()(x + 1, y + 1) != 1.0) && stats[shipkind] > 0)
                {
                    if (x - 1 > 0)
                    {
                        field->operator()(x - 1, y - 1) = 2.0;
                        field->operator()(x - 1, y) = 2.0;
                        field->operator()(x - 1, y + 1) = 2.0;
                    }
                    for (int h = 0; h <= shipkind; h++)
                    {
                        field->operator()(x + h, y) = 1.0;
                        field->operator()(x + h, y - 1) = 2.0;
                        field->operator()(x + h, y + 1) = 2.0;
                    }
                    field->operator()(x + shipkind, y + 1) = 2.0;
                    field->operator()(x + shipkind, y) = 2.0;
                    field->operator()(x + shipkind, y - 1) = 2.0;
                    stats[shipkind] -= 1;
                }
                else
                {
                    cout << "Invalid ship placement\n"; break;
                }
                break;
            case(180):
                if (y + shipkind < 11 && (field->operator()(x - 1, y) != 1.0) && (field->operator()(x + 1, y) != 1.0) && field->operator()(x, y + 1) != 2.0 && (field->operator()(x - 1, y + 1) != 1.0) && (field->operator()(x + 1, y + 1) != 1.0) && stats[shipkind] > 0)
                {
                    if (y - 1 > 0)
                    {
                        field->operator()(x - 1, y - 1) = 2.0;
                        field->operator()(x - 1, y) = 2.0;
                        field->operator()(x - 1, y + 1) = 2.0;
                    }
                    for (int h = 0; h <= shipkind; h++)
                    {
                        field->operator()(x, y + h) = 1.0;
                        field->operator()(x - 1, y + h) = 2.0;
                        field->operator()(x + 1, y + h) = 2.0;
                    }
                    field->operator()(x - 1, y + shipkind) = 2.0;
                    field->operator()(x, y + shipkind) = 2.0;
                    field->operator()(x + 1, y + shipkind) = 2.0;
                    stats[shipkind] -= 1;
                }
                else
                {
                    cout << "Invalid ship placement\n"; break;
                }
                break;
            case(270):
                if (x - shipkind > 0 && (field->operator()(x, y - 1) != 1.0) && (field->operator()(x, y + 1) != 1.0) && field->operator()(x - 1, y) != 2.0 && (field->operator()(x - 1, y - 1) != 1.0) && (field->operator()(x - 1, y + 1) != 1.0) && stats[shipkind] > 0)
                {
                    if (x - 1 > 0)
                    {
                        field->operator()(x - 1, y - 1) = 2.0;
                        field->operator()(x - 1, y) = 2.0;
                        field->operator()(x - 1, y + 1) = 2.0;
                    }
                    for (int h = 0; h <= shipkind; h++)
                    {
                        field->operator()(x + h, y) = 1.0;
                        field->operator()(x + h, y - 1) = 2.0;
                        field->operator()(x + h, y + 1) = 2.0;
                    }
                    field->operator()(x + shipkind, y + 1) = 2.0;
                    field->operator()(x + shipkind, y) = 2.0;
                    field->operator()(x + shipkind, y - 1) = 2.0;
                    stats[shipkind] -= 1;
                }
                else
                {
                    cout << "Invalid ship placement\n"; break;
                }
                break;
            default:
                cout << "Wrong angle rotation\n";
                break;
            }
        }
    }
    int CheckStatus()
    {
        int hurtedcells;
        for (int u = 1; u < 12; u++) { for (int q = 1; q < 12; q++) { if (field->operator()(u, q) == 3.0) { hurtedcells += 1; } } }
        return hurtedcells;
    }
    int Attack(int x, int y, PlayerSan& conb)
    {
        if (conb.FieldGet()(x, y) == 1.0 || conb.FieldGet()(x, y) == 3.0)
        {
            conb.FieldGet()(x, y) = 3.0;
            field_optional->operator()(x, y) = 3.0;
            if ((conb.FieldGet()(x + 1, y) == 1.0 || conb.FieldGet()(x, y + 1) == 1.0) && (conb.FieldGet()(x - 1, y) == 1.0 || conb.FieldGet()(x, y - 1) == 1.0))
            {
                cout << "Enemy ship got hurt\n";
            }
            else
            {
                cout << "Enemy ship destroyed\n";
            }
        }
        else
        {
            conb.FieldGet()(x, y) = 2.0;
            field_optional->operator()(x, y) = 2.0;
            cout << "missed\n";
        }
        return 0;
    }
};
class ComputerSan : public PlayerSan
{
protected:
    int Thonkx;  int Thonky; int demand;
    ComputerSan() { field = new matrix(12, 12); field_optional = new matrix(12, 12); demand = 0;}
    ~ComputerSan() { delete[] field; delete[] field_optional; }
    ComputerSan(const ComputerSan& h) { field = new matrix(12, 12); field_optional = new matrix(12, 12); }
    void Nullify()
    {
        for (int j = 1; j < 11; j++) { for (int i = 1; i < 11; i++) { field->operator()(j, i) = 0.0; } }
        for (int i = 0; i < 12; i++) { field->operator()(0, i) = 5.0; field->operator()(i, 0) = 5.0; field->operator()(i, 11) = 5.0; field->operator()(11, i) = 5.0; }
        for (int j = 1; j < 11; j++) { for (int i = 1; i < 11; i++) { field_optional->operator()(j, i) = 0.0; } }
        for (int i = 0; i < 12; i++) { field_optional->operator()(0, i) = 5.0; field_optional->operator()(i, 0) = 5.0; field_optional->operator()(i, 11) = 5.0; field_optional->operator()(11, i) = 5.0; }
    }
    void PlaceShipLogic()
    {
        for (int y = 3; y >= 0; y++)
        {
            while (stats[y] > 0)
            {
                int x = (1 + rand() % 10, 1 + rand() % 10), int z = (1 + rand() % 10, 1 + rand() % 10);
                double key = field->operator()(x,z) != 2.0;
                bool logic = true;
                if (key != 1.0 && key != 2.0)
                {
                    for (int u = 0; u < y; u++)
                    {
                        if (z - u > 0 && field->operator()(x, z - u) != 1.0 && field->operator()(x, z - u) != 2.0)
                        {}
                        else
                        {
                            break;
                            logic = false;
                        }
                        if (logic)
                        {
                            for (int u = 0; u < y; u++)
                            {
                                field->operator()(x, z - u) = 1.0;
                            }
                        }
                        else
                        {
                            break;
                        }
                    }
                    for (int u = 0; u < y; u++)
                    {
                        if (x + u < 11 && field->operator()(x + u, z) != 1.0 && field->operator()(x+u,z) != 2.0)
                        {
                        }
                        else
                        {
                            break;
                            logic = false;
                        }
                        if (logic)
                        {
                            for (int u = 0; u < y; u++)
                            {
                                field->operator()(x + u, z) = 1.0;
                            }
                        }
                        else
                        {
                            break;
                        }
                    }
                    for (int u = 0; u < y; u++)
                    {
                        if (x - u > 0 && field->operator()(x - u, z) != 1.0 && field->operator()(x - u, z) != 2.0)
                        {
                        }
                        else
                        {
                            break;
                            logic = false;
                        }
                        if (logic)
                        {
                            for (int u = 0; u < y; u++)
                            {
                                field->operator()(x - u, z) = 1.0;
                            }
                        }
                        else
                        {
                            break;
                        }
                    }
                    for (int u = 0; u < y; u++)
                    {
                        if (z + u < 11 && field->operator()(x, z + u) != 1.0 && field->operator()(x, z + u) != 2.0)
                        {
                        }
                        else
                        {
                            break;
                            logic = false;
                        }
                        if (logic)
                        {
                            for (int u = 0; u < y; u++)
                            {
                                field->operator()(x, z + u) = 1.0;
                            }
                        }
                        else
                        {
                            break;
                        }
                    }
                }
            }
        }
    }
    int CheckStatus()
    {
        int hurtedcells;
        for (int u = 1; u < 12; u++) { for (int q = 1; q < 12; q++) { if (field->operator()(u, q) == 3.0) { hurtedcells += 1; } } }
        return hurtedcells;
    }
    void Attack(int x, int y, PlayerSan& conb)
    {
        if (demand == 0)
        {
            if (conb.FieldGet()(x, y) == 1.0 || conb.FieldGet()(x, y) == 3.0)
            {
                conb.FieldGet()(x, y) = 3.0;
                demand = 1;
            }
        }
        else
        {
            if (conb.FieldGet()(x + 1, y) == 1.0 && demand == 1)
            {
                conb.FieldGet()(x + 1, y) = 3.0;
                demand = 1;
            }
            else
            {
                if (conb.FieldGet()(x, y+1) == 1.0 && demand == 1)
                {
                    conb.FieldGet()(x, y+1) = 3.0;
                    demand = 2;
                }
            }
        }
    }
};
