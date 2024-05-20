#ifndef _SORT_H_
#define _SORT_H

#include <iostream>
using namespace std;
class vector
{
private:
    int n;
    double* mem;  
public:
    vector(int n = 3);
    vector(const vector& B);
    ~vector();
    vector operator=(const vector& B);
    vector operator+(const vector& B);
    vector operator-(const vector& B);
    vector& operator+=(const vector& B);
    vector& operator-=(const vector& B);
    vector& operator++();
    vector operator++(int k);
    vector operator*(double number);
    double& operator[](const int i);
    const double& operator[](const int i) const;
    friend istream& operator>>(istream& in, vector& vec);
    friend ostream& operator<<(ostream& os, const vector& vec);
    void generate(double min, double max);
};

#endif 
