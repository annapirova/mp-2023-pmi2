#pragma once
#include "matrix.h"
#include <iostream>
class PlayerSan
{
    private:
    matrix* field;
    int coordy,coordx;
    public:
    PlayerSan(int _x, int _y)
    {
        coordx = _x;
        coordy = _y;
        field = new matrix(10,10);
    }
    ~PlayerSan()
    {
        delete[] field;
    }
    PlayerSan(const PlayerSan& masfx)
    {
        coordx = masfx.coordx;
        coordy = masfx.coordy;
        field = new matrix(10,10);
    }
    PlayerSan& Nullify()
    {
        for (int j = 0;j<10;j++){for(int i = 0;i<10;i++){field->operator()(j,i) = 0.0;}}
        return *this;
    }
    PlayerSan& Placeship(int x,int y)
    {
        int angle, numofcells;
        cout << "What Kind of Ship?\n";
        cin >> numofcells;
        if (numofcells < 1 || numofcells > 4)
        {
            cout << "InvalidShipType\n";
            return *this;
        }
        cout << "Rotate your ship. Degrees allowed: 0,90,180,270\n";
        cin >> angle;
        switch(angle)
        {
            case(0):
            if (y - numofcells > -1)
            {
                for (int q = 0;q < numofcells;q++)
                {
                    if (field->operator()(x,y-q) == 1.0 || field->operator()(x,y-q) == 2.0)
                    {
                        cout << "Cannot place next to the other ship\n";
                        break;
                    }
                }
                for (int q = 0;q < numofcells;q++)
                {
                    field->operator()(x,y-q) = 1.0;
                    if (x+1 < 10)
                    {field->operator()(x+1,y-q) = 2.0;}
                    if (y-1 > 0)
                    {field->operator()(x+1,y-q) = 2.0;}
                }
            }
            else
            {
                cout << "invalid pattern\n";
                break;
            }
            break;
            case(90):
            if (x + numofcells < 10)
            {
                for (int q = 0;q < numofcells;q++)
                {
                    if (field->operator()(x+q,y) == 1.0 || field->operator()(x+q,y) == 2.0)
                    {
                        cout << "Cannot place next to the other ship\n";
                        break;
                    }
                    field->operator()(x+q,y) = 1.0;
                    if (y+1 < 10)
                    {field->operator()(x+q,y+1) = 2.0;}
                    if (y-1 > 0)
                    {
                        field->operator()(x+q,y-1) = 2.0;
                    }
                }
            }
            else
            {
                cout << "invalid pattern\n";
                break;
            }
            break;
            case(180):
            if (y + numofcells < 10)
            {
                for (int q = 0;q < numofcells;q++)
                {
                    if (field->operator()(x,y+q) == 1.0 || field->operator()(x,y+q) == 2.0)
                    {
                        cout << "Cannot place next to the other ship\n";
                        break;
                    }
                }
                for (int q = 0;q < numofcells;q++)
                {
                    field->operator()(x,y+q) = 1.0;
                    if (x+1 < 9)
                    {field->operator()(x+1,y+q) = 2.0;}
                    if (y-1 > 0)
                    {field->operator()(x+1,y+q) = 2.0;}
                }
            }
            else
            {
                cout << "invalid pattern\n";
                break;
            }
            break;
            case(270):
            if (x - numofcells > -1)
            {
                for (int q = 0;q < numofcells;q++)
                {
                    if (field->operator()(x-q,y) == 1.0 || field->operator()(x-q,y) == 2.0)
                    {
                        cout << "Cannot place next to the other ship\n";
                        break;
                    }
                    field->operator()(x-q,y) = 1.0;
                    if (y+1 < 10)
                    {field->operator()(x-q,y+1) = 2.0;}
                    if (y-1 > 0)
                    {
                        field->operator()(x-q,y-1) = 2.0;
                    }
                }
            }
            else
            {
                cout << "invalid pattern\n";
                break;
            }
            break;
            default:
            cout << "Incorrect pattern\n";
            break;
        }
        return *this;
    }
    PlayerSan& Attack(int x,int y)
    {
        if (field->operator()(x,y) == 1.0)
        {
            field->operator()(x,y) = 3.0;
            cout << "You hit the ship\n";
        }
        else 
        {cout << "Better Luck Next Time\n";}
        return *this;
    }
    PlayerSan& CheckStatus()
    {
        cout << field;
        return *this;
    }
};