#ifndef MATRIX_H
#define MATRIX_H
#include "vectors.h"
using std::istream;
using std::ostream;
class matrix
{

    private:
    double** A;
    int n,m;
    public:
    matrix(int n=1, int m=1);
    matrix(const matrix &B);
    ~matrix();
    void set_random(double a, double b);
    void Print();
    matrix plus(const matrix& B);
    matrix operator + (const matrix& B);
    matrix operator - (const matrix& B);
    matrix operator * (const matrix& B);
    matrix& operator = (const matrix& B);
    matrix& operator += (const matrix& B);
    matrix& operator -= (const matrix& B);
    vector operator *( const vector& b);
    friend matrix operator *(const matrix& a,const double zxc);
    friend matrix operator *(const double zxc, const matrix& a);
    double operator()(const int i,const  int j);
    friend ostream& operator <<(ostream& out, const matrix& a);
    friend istream& operator >>(istream& in, matrix&a);
    friend double maxim_st(int i, matrix& MATRISA, vector& zxc);
    friend void prym_hod(matrix& MATRISA, vector& b);
    friend void obr_hod(matrix& MATRISA,vector& otvet_polych, vector& b);
};

#endif