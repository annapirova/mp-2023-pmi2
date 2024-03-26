#ifndef vectors_H
#define vectors_H
#include <iostream>
using std::istream;
using std::ostream;
class vector
{
    private:
    int size;
    double* vec;
    public:
    vector(int size_=1);
    vector(const vector &B);
    ~vector();
    vector& operator = (const vector &B);
    vector operator + (const vector &B);
    vector operator - (const vector &B);
    vector& operator += (const vector &B); 
    vector& operator -= (const vector &B);
    friend vector operator * (vector zxc, double q);
    friend vector operator * (double q, vector zxc);
    vector operator ++ (int k);
    vector& operator ++ ();
    vector operator - ();
    double& operator [] (const int i) const;
    void set_random_vec(double a, double b);
    void set_vector_size(int size_);
    void  Print();
    void set_some_vec();
    friend istream& operator >> (istream& in, vector& b);
    friend ostream& operator << (ostream& out, const vector& b);
    //функция вычмлсления нормы

    friend class matrix;
};
#endif