#ifndef MASSA_H
#define MASSA_H
#include <iostream>

using namespace std;
class Mass {
public:
    int kilograms;
    int grams;

    Mass(int kilograms, int grams);

    void print();

    Mass operator+(const Mass& m);
    Mass operator-(const Mass& m);
    bool operator==(const Mass& m);
};

#endif
