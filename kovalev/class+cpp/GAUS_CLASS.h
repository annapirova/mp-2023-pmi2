#ifndef GAUS_CLASS
#define GAUS_CLASS
#include "matrixs.h"
#include "vectors.h"
enum sost
{
    created, solved
};
class GAUS
{
    private:
    matrix* MATRISA;
    vector* X;
    vector* b;
    vector* otvet_polych;
    sost tek;
    public:
    GAUS(matrix* myA, vector* myX, vector* myB, vector* otv);
    GAUS();
    void Solve();
    double Check();
    void print_matrix();
    void print_b();
    void print_x();
    void print_polych();

};
#endif