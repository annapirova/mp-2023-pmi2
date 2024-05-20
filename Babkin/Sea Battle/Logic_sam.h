#pragma once
#include "matrix.h"
#include <iostream>
class PlayerSan
{
    protected:
    matrix* field;
    matrix* field_optional;
    int stats[4];
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

    virtual void Nullify(){}
    virtual int CheckStatus() {}
    virtual void Attack() {}
    virtual void PlaceShips() {}
    matrix FieldGet() {return *field;};
};
class User : public PlayerSan
{
public:
    User(){field = new matrix(12,12);field_optional = new matrix(12,12);stats = {4,3,2,1};}
    ~User(){delete[] field;delete[] field_optional;}
    void Nullify()
    {
        for (int j = 1; j < 11; j++) { for (int i = 1; i < 11; i++) {field->operator()(j, i) = 0.0; } }
        for (int i = 0; i < 12; i++) {field->operator()(0, i) = 5.0; field->operator()(i,0) = 5.0;field->operator()(i,11) = 5.0;field->operator()(11,i) = 5.0;}
        for (int j = 1; j < 11; j++) { for (int i = 1; i < 11; i++) {field_optional->operator()(j, i) = 0.0; } }
        for (int i = 0; i < 12; i++) {field_optional->operator()(0, i) = 5.0; field_optional->operator()(i,0) = 5.0;field_optional->operator()(i,11) = 5.0;field_optional->operator()(11,i) = 5.0;}
    }
    void Placeship(int x, int y, int shipkind,int rotate)
    {
        if (shipkind > -1 && shipkind < 4)
        {
            switch(rotate)
            {
                case(0):
                if (y-shipkind > 0 && (field->operator()(x-1,y) != 1.0) && (field->operator()(x+1,y) != 1.0) && field->operator()(x,y-1) != 2.0 && (field->operator()(x-1,y-1) != 1.0) && (field->operator()(x+1,y-1) != 1.0) && stats[shipkind] > 0)
                {
                    if (y+1 < 11)
                    {
                        field->operator()(x-1,y+1) = 2.0;
                        field->operator()(x,y+1) = 2.0;
                        field->operator()(x+1,y+1) = 2.0;
                    }
                    for (int h = 0;h<=shipkind;h++)
                    {
                        field->operator()(x,y-h) = 1.0;
                        field->operator()(x-1,y-h) = 2.0;
                        field->operator()(x+1,y-h) = 2.0;
                    }
                    field->operator()(x-1,y-shipkind) = 2.0;
                    field->operator()(x,y-shipkind) = 2.0;
                    field->operator()(x+1,y-shipkind) = 2.0;
                    stats[shipkind] -= 1;
                }
                else
                {cout << "Invalid ship placement\n";break;}
                break;
                case(90):
                if (x+shipkind < 11 && (field->operator()(x,y-1) != 1.0) && (field->operator()(x,y+1) != 1.0) && field->operator()(x+1,y) != 2.0 && (field->operator()(x+1,y-1) != 1.0) && (field->operator()(x+1,y+1) != 1.0) && stats[shipkind] > 0)
                {
                    if (x - 1 > 0)
                    {
                        field->operator()(x-1,y-1) = 2.0;
                        field->operator()(x-1,y) = 2.0;
                        field->operator()(x-1,y+1) = 2.0;
                    }
                    for (int h = 0;h<=shipkind;h++)
                    {
                        field->operator()(x+h,y) = 1.0;
                        field->operator()(x+h,y-1) = 2.0;
                        field->operator()(x+h,y+1) = 2.0;
                    }
                    field->operator()(x+shipkind,y+1) = 2.0;
                    field->operator()(x+shipkind,y) = 2.0;
                    field->operator()(x+shipkind,y-1) = 2.0;
                    stats[shipkind] -= 1;
                }
                else
                {cout << "Invalid ship placement\n";break;}
                break;
                case(180):
                if (y+shipkind < 11 && (field->operator()(x-1,y) != 1.0) && (field->operator()(x+1,y) != 1.0) && field->operator()(x,y+1) != 2.0 && (field->operator()(x-1,y+1) != 1.0) && (field->operator()(x+1,y+1) != 1.0) && stats[shipkind] > 0)
                {
                    if (y-1 > 0)
                    {
                        field->operator()(x-1,y-1) = 2.0;
                        field->operator()(x-1,y) = 2.0;
                        field->operator()(x-1,y+1) = 2.0;
                    }
                    for (int h = 0;h<=shipkind;h++)
                    {
                        field->operator()(x,y+h) = 1.0;
                        field->operator()(x-1,y+h) = 2.0;
                        field->operator()(x+1,y+h) = 2.0;
                    }
                    field->operator()(x-1,y+shipkind) = 2.0;
                    field->operator()(x,y+shipkind) = 2.0;
                    field->operator()(x+1,y+shipkind) = 2.0;
                    stats[shipkind] -= 1;
                }
                else
                {cout << "Invalid ship placement\n";break;}
                break;
                case(270):
                if (x-shipkind > 0 && (field->operator()(x,y-1) != 1.0) && (field->operator()(x,y+1) != 1.0) && field->operator()(x-1,y) != 2.0 && (field->operator()(x-1,y-1) != 1.0) && (field->operator()(x-1,y+1) != 1.0) && stats[shipkind] > 0 )
                {
                    if (x - 1 > 0)
                    {
                        field->operator()(x-1,y-1) = 2.0;
                        field->operator()(x-1,y) = 2.0;
                        field->operator()(x-1,y+1) = 2.0;
                    }
                    for (int h = 0;h<=shipkind;h++)
                    {
                        field->operator()(x+h,y) = 1.0;
                        field->operator()(x+h,y-1) = 2.0;
                        field->operator()(x+h,y+1) = 2.0;
                    }
                    field->operator()(x+shipkind,y+1) = 2.0;
                    field->operator()(x+shipkind,y) = 2.0;
                    field->operator()(x+shipkind,y-1) = 2.0;
                    stats[shipkind] -= 1;
                }
                else
                {cout << "Invalid ship placement\n";break;}
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
        for (int u = 1;u<12;u++) {for (int q = 1;q<12;q++) {if (field->operator()(u,q) == 3.0){hurtedcells += 1;}}}
        return hurtedcells;
    }
    void Attack(int x,int y,PlayerSan& conb)
    {
        if (conb.FieldGet()(x,y) == 1.0)
        {
            conb.FieldGet()(x,y) = 3.0;
            field_optional->operator()(x,y) = 3.0;
            if ((conb.FieldGet()(x+1,y) == 1.0 || conb.FieldGet()(x,y+1) == 1.0) && (conb.FieldGet()(x-1,y) == 1.0 || conb.FieldGet()(x,y-1) == 1.0))
            {
                cout << "Enemy ship got hurt\n";
            }
            else
            {cout << "Enemy ship destroyed\n";}
        }
        else
        {
            conb.FieldGet()(x,y) = 2.0;
            field_optional->operator()(x,y) = 2.0;
            cout << "missed\n";
        }
    }
};
class ComputerSan : public PlayerSan
{
    
};
