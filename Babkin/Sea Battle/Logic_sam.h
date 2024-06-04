#pragma once
#include "matrix.h"
#include <iostream>
#include <cstdlib>
#include <tuple>
class PlayerSan
{
protected:
    matrix* field;
    matrix* field_optional;
    int stats[4] = {4,3,2,1};
public:
    PlayerSan()
    {
        field = new matrix(12, 12); field_optional = new matrix(12, 12);
    }
    ~PlayerSan()
    {
        delete[] field; delete[] field_optional;
    }
    PlayerSan(const PlayerSan& h) { field = new matrix(12, 12); field_optional = new matrix(12, 12); }
    void Nullify() 
    {
        for (int j = 1; j < 11; j++) { for (int i = 1; i < 11; i++) { (*field)(j, i) = 0.0; } }
        for (int i = 0; i < 12; i++) { (*field)(0, i) = 5.0; (*field)(i, 0) = 5.0; (*field)(i, 11) = 5.0; (*field)(11, i) = 5.0; }
        for (int j = 1; j < 11; j++) { for (int i = 1; i < 11; i++) { (*field_optional)(j, i) = 0.0; } }
        for (int i = 0; i < 12; i++) { (*field_optional)(0, i) = 5.0; (*field_optional)(i, 0) = 5.0; (*field_optional)(i, 11) = 5.0; (*field_optional)(11, i) = 5.0; }
    }
    int CheckSells()
    {
        int cells = 0;
        for (int u = 1; u < 12; u++) { for (int q = 1; q < 12; q++) { if ((*field)(u, q) == 1.0) { cells += 1; } } }
        return cells;
    }
    virtual tuple<int,int> SentAttack(int x, int y) {return {0,0};}
    void GetResponse(int x, int y, PlayerSan& conb)
    {
        if ((*field)(x,y) == 1.0 || (*field)(x,y) == 3.0)
        {
            if ((*field)(x-1,y) == 1.0 || (*field)(x+1,y) == 1.0 || (*field)(x,y-1) == 1.0 || (*field)(x,y+1) == 1.0 || ((*field)(x-1,y) == 3.0 && (*field)(x-2,y) == 1.0) || ((*field)(x+1,y) == 3.0 && (*field)(x+2,y) == 1.0) || ((*field)(x,y+1) == 3.0 && (*field)(x,y+2) == 1.0) || ((*field)(x,y-1) == 3.0 && (*field)(x,y-2) == 1.0) || ((*field)(x+1,y) == 3.0 && (*field)(x+2,y) == 3.0 && (*field)(x+3,y) == 1.0) && ((*field)(x-1,y) == 3.0 && (*field)(x-2,y) == 3.0 && (*field)(x-3,y) == 1.0) || ((*field)(x,y+1) == 3.0 && (*field)(x,y+2) == 3.0 && (*field)(x,y+3) == 1.0) || ((*field)(x,y-1) == 3.0 && (*field)(x,y-2) == 3.0 && (*field)(x,y-3) == 1.0))
            {
                cout << "ship hurt\n";
                (*field)(x,y) = 3.0;
                (*conb.field_optional)(x,y) = 3.0;
            }
            else
            {
                cout << "dead ship\n";
                (*field)(x,y) = 3.0;
                (*conb.field_optional)(x,y) = 3.0;
            }
        }
        else
        {
            (*field)(x,y) = 2.0;
            (*conb.field_optional)(x,y) = 2.0;
        }
    }
    virtual void Placeship(int x, int y, int shipkind, int rotate) {}
    matrix FieldGet() { return *field; };
    matrix FieldGet_op() { return *field_optional; };
};
class User : public PlayerSan
{
public:
    User() {}
    ~User() {}
    void Placeship(int x, int y, int shipkind, int rotate)
    {
        bool canexist;
        if (shipkind > -1 && shipkind < 4)
        {
            switch (rotate)
            {
            case(0):
                canexist = true;
                for (int h = 0; h <= shipkind; h++)
                {
                    if ((*field)(x-1 , y - h) != 1.0 && (*field)(x + 1 , y - h) != 1.0 && (*field)(x-1 , y - h - 1) != 1.0 && (*field)(x + 1 , y - h - 1) != 1.0 && (*field)(x-1 , y - h + 1) != 1.0 && (*field)(x+1 , y - h + 1) != 1.0 && (*field)(x , y - h - 1) != 1.0 && (*field)(x , y - h) != 5.0 && stats[shipkind] > 0)
                    {}
                    else
                    {
                        cout << "Invalid ship placement\n";
                        canexist = false;
                        break;
                    }
                }
                if (canexist)
                {
                    for (int h = 0; h <= shipkind; h++)
                    {
                        (*field)(x, y - h) = 1.0;
                    }
                    stats[shipkind] -= 1;
                    break;
                }
                else
                {break;}
            case(90):
                canexist = true;
                for (int h = 0; h <= shipkind; h++)
                {
                    if ((*field)(x+h , y-1) != 1.0 && (*field)(x + h , y + 1) != 1.0 && (*field)(x + h + 1, y - 1) != 1.0 && (*field)(x + h + 1 , y + 1) != 1.0 && (*field)(x+h - 1 , y - 1) != 1.0 && (*field)(x+h-1 , y - h + 1) != 1.0 && (*field)(x + h + 1,y) != 1.0 && (*field)(x + h,y) != 5.0 && stats[shipkind] > 0)
                    {}
                    else
                    {
                        cout << "Invalid ship placement\n";
                        canexist = false;
                        break;
                    }
                }
                if (canexist)
                {
                    for (int h = 0; h <= shipkind; h++)
                    {
                        (*field)(x + h, y) = 1.0;
                    }
                    stats[shipkind] -= 1;
                    break;
                }
                else
                {break;}
            case(180):
                canexist = true;
                for (int h = 0; h <= shipkind; h++)
                {
                    if ((*field)(x-1 , y + h) != 1.0 && (*field)(x + 1 , y + h) != 1.0 && (*field)(x-1 , y + h + 1) != 1.0 && (*field)(x + 1 , y + h + 1) != 1.0 && (*field)(x-1 , y + h - 1) != 1.0 && (*field)(x+1 , y + h - 1) != 1.0 && (*field)(x , y + h + 1) != 1.0 && (*field)(x , y + h) != 5.0 && stats[shipkind] > 0)
                    {}
                    else
                    {
                        cout << "Invalid ship placement\n";
                        canexist = false;
                        break;
                    }
                }
                if (canexist)
                {
                    for (int h = 0; h <= shipkind; h++)
                    {
                        (*field)(x, y + h) = 1.0;
                    }
                    stats[shipkind] -= 1;
                    break;
                }
                else
                {break;}
            case(270):
                canexist = true;
                for (int h = 0; h <= shipkind; h++)
                {
                    if ((*field)(x-h , y-1) != 1.0 && (*field)(x - h , y + 1) != 1.0 && (*field)(x - h + 1, y - 1) != 1.0 && (*field)(x - h + 1 , y + 1) != 1.0 && (*field)(x-h - 1 , y - 1) != 1.0 && (*field)(x-h-1 , y - h + 1) != 1.0 && (*field)(x - h - 1,y) != 1.0 && (*field)(x - h,y) != 5.0 && stats[shipkind] > 0)
                    {}
                    else
                    {
                        cout << "Invalid ship placement\n";
                        canexist = false;
                        break;
                    }
                }
                if (canexist)
                {
                    for (int h = 0; h <= shipkind; h++)
                    {
                        (*field)(x + h, y) = 1.0;
                    }
                    stats[shipkind] -= 1;
                    break;
                }
                else
                {break;}
            default:
                cout << "Wrong angle rotation\n";
                break;
            }
        }
    }
};
class ComputerSan : public PlayerSan
{
    public:
    ComputerSan() {}
    ~ComputerSan() {}
    void Placeship(int x, int y, int shipkind, int rotate)
    {
        for (int y = 3; y >= 0; y--)
        {
            while (stats[y] > 0)
            {
                int x = 1 + rand() % 10; int z = 1 + rand() % 10;
                double key = (*field)(x,z);
                bool logic = true;
                if (key != 1.0)
                {
                    for (int u = 0; u < y; u++)
                    {
                        if ((*field)(x , z + 1) == 1.0 && u == 0)
                        {break;}
                        if ((*field)(x-1 , z - u) != 1.0 && (*field)(x + 1 , z - u) != 1.0 && (*field)(x-1 , z - u - 1) != 1.0 && (*field)(x + 1 , z - u - 1) != 1.0 && (*field)(x-1 , z - u + 1) != 1.0 && (*field)(x+1 , z - u + 1) != 1.0 && (*field)(x , z - u - 1) != 1.0 && (*field)(x , z - u) != 5.0)
                        {}
                        else
                        {
                            logic = false;
                            break;
                        }
                    }
                    if (logic == true)
                    {
                        for (int u = 0; u < y; u++)
                        {
                            (*field)(x, z - u) = 1.0;
                        }
                        stats[y] -= 1;
                    }
                    logic = true;
                    for (int u = 0; u < y; u++)
                    {
                        if ((*field)(x - 1 , z) == 1.0 && u == 0)
                        {break;}
                        if ((*field)(x+u , z-1) != 1.0 && (*field)(x + u , z + 1) != 1.0 && (*field)(x + u + 1, z - 1) != 1.0 && (*field)(x + u + 1 , z + 1) != 1.0 && (*field)(x+u - 1 , z - 1) != 1.0 && (*field)(x+u-1 , z+1) != 1.0 && (*field)(x + u + 1,z) != 1.0 && (*field)(x + u,z) != 5.0)
                        {
                        }
                        else
                        {
                            break;
                            logic = false;
                        }
                    }
                    if (logic == true)
                    {
                        for (int u = 0; u < y; u++)
                        {
                            (*field)(x + u, z) = 1.0;
                        }
                        stats[y] -= 1;
                    }
                    logic = true;
                    for (int u = 0; u < y; u++)
                    {
                        if ((*field)(x , z - 1) == 1.0 && u == 0)
                        {break;}
                        if ((*field)(x-1 , z + u) != 1.0 && (*field)(x + 1 , z + u) != 1.0 && (*field)(x-1 , z + u + 1) != 1.0 && (*field)(x + 1 , z + u + 1) != 1.0 && (*field)(x-1 , z + u - 1) != 1.0 && (*field)(x+1 , z + u - 1) != 1.0 && (*field)(x , z + u + 1) != 1.0 && (*field)(x , z + u) != 5.0)
                        {
                        }
                        else
                        {
                            break;
                            logic = false;
                        }
                    }
                    if (logic == true)
                    {
                        for (int u = 0; u < y; u++)
                        {
                            (*field)(x, z+u) = 1.0;
                        }
                        stats[y] -= 1;
                        break;
                    }
                    logic = true;
                    for (int u = 0; u < y; u++)
                    {
                        if ((*field)(x + 1 , z) == 1.0 && u == 0)
                        {break;}
                        if ((*field)(x-u , z-1) != 1.0 && (*field)(x - u , z + 1) != 1.0 && (*field)(x - u + 1, z - 1) != 1.0 && (*field)(x - u + 1 , z + 1) != 1.0 && (*field)(x-u - 1 , z - 1) != 1.0 && (*field)(x-u-1 , y - z + 1) != 1.0 && (*field)(x - u - 1,z) != 1.0 && (*field)(x - u,z) != 5.0)
                        {
                        }
                        else
                        {
                            break;
                            logic = false;
                        }
                    }
                    if (logic == true)
                    {
                        for (int u = 0; u < y; u++)
                        {
                            (*field)(x - u, z) = 1.0;
                        }
                        stats[y] -= 1;
                        break;
                    }
                }
            }
        }
    }
    tuple<int,int> SentAttack(int x, int y)
    {
        for (int i = 1;i<11;i++)
        {
            for (int j = 1;j<11;j++)
            {
                if ((*field_optional)(i,j) == 3.0)
                {
                    if ((*field_optional)(i+1,j) != 2.0 || (*field_optional)(i+1,j) != 3.0 || (*field_optional)(i+1,j) != 5.0)
                    {
                        x = i + 1;
                        y = j;
                        return {x,y};
                    }
                    else
                    {
                        if ((*field_optional)(i-1,j) != 2.0 || (*field_optional)(i-1,j) != 3.0 || (*field_optional)(i-1,j) != 5.0)
                        {
                            x = i - 1;
                            y = j;
                            return {x,y};
                        }
                        else
                        {
                            if ((*field_optional)(i,j-1) != 2.0 || (*field_optional)(i,j-1) != 3.0 || (*field_optional)(i,j-1) != 5.0)
                            {
                                x = i;
                                y = j - 1;
                                return {x,y};
                            }
                            else
                            {
                                if ((*field_optional)(i,j+1) != 2.0 || (*field_optional)(i,j+1) != 3.0 || (*field_optional)(i,j+1) != 5.0)
                                {
                                    x = i;
                                    y = j + 1;
                                    return {x,y};
                                }
                            }
                        }
                    }
                }
            }
        }
        x = 1 + rand()%10;
        y = 1 + rand()%10;
        return {x,y};
    }
};
