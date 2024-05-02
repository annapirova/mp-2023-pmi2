#include "Gauss.h"
#include "Matrix.h"
#include "Vector.h"
#include <iostream>

using namespace std;

Gauss::Gauss(Matrix* myA, Vector* myx, Vector* myb) : status(0), A(myA), res(myx), b(myb)
{
    Z = *A;
    swsw = *b;
}

void Gauss::Solve()
{
    int n = A->GetRowCount();
    for (int i = 0; i < n - 1; i++)
    {
        for (int k = i + 1; k < n; k++)
        {
            double alpha = 0.0;
            if ((*A)(i, i) != 0.0)
            {
                alpha = (*A)(k, i) / (*A)(i, i);
            }
            for (int j = i; j < n; j++)
            {
                (*A)(k, j) -= alpha * (*A)(i, j);
            }
            (*b)[k] -= alpha * (*b)[i];
        }
    }

    for (int i = n - 1; i >= 0; i--)
    {
        double sum = 0;
        for (int j = i + 1; j < n; j++)
        {
            sum += (*A)(i, j) * (*res)[j];
        }
        (*res)[i] = ((*b)[i] - sum) / (*A)(i, i);
    }
    status = 1;
}

double Gauss::Check()
{
    if (status != 1) {
        return -1;
    }

    Vector e = Z * (*res) - swsw;
    double a = e.Norma();
    double d = swsw.Norma();
    return (a / d);
}


std::ostream& operator<<(std::ostream& os, const Gauss& G)
{
    os << "Matrix A: " << std::endl << *(G.A) << std::endl;
    os << "Vector res: " << std::endl << *(G.res) << std::endl;
    os << "Vector b: " << std::endl << *(G.b) << std::endl;
    os << "Status: " << G.status << std::endl;
    return os;
}
