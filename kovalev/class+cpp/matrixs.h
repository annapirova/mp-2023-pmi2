#ifndef MATRIX_H
#define MATRIX_H
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
    void set_size_matrix(int n=1, int m=1);
    matrix plus(const matrix& B);
    matrix operator + (const matrix& B);
    matrix operator - (const matrix& B);
    matrix operator * (const matrix& B);
    matrix& operator = (const matrix& B);
    matrix& operator += (const matrix& B);
    matrix& operator -= (const matrix& B);
    matrix& operator *= (const matrix& B);
};

#endif