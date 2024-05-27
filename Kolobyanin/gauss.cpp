using namespace std;
#include "gauss.h"
#include "matrixvector.h"
#include <iostream>

void Gauss::Solve()
{
    int n;
    double a = 0.0, d;
    Matrix M = *A;
    Vector v = *B;
    n = M.size();
    for (int i = 0; i < n - 1; i++)
    {
        int mainr = i;
        for (int p = i + 1; p < n; p++) {
            if (fabs(M(p, i)) > fabs(M(mainr, i))) {
                mainr = p;
            }
        }
        if (mainr != i) {
            M.swap(mainr, i);
            double tmp = v[i];
            v[i] = v[mainr];
            v[mainr] = tmp;
        }
        for (int j = i + 1; j < n; j++)
        {
            a = M(j, i) / M(i, i);
            for (int k = i; k < n; k++)
            {
                M(j, k) -= a * M(i, k);
            }
            v[j] -= a * v[i];
        }
    }
    for (int k = n - 1; k >= 0; k--)
    {
        d = 0.0;
        for (int j = k + 1; j < n; j++)
        {
            d += M(k, j) * (*res)[j];
        }
        (*res)[k] = (v[k] - d) / M(k, k);
    }
    status = 1;
}
double Gauss::Check() {
    Vector e(A->size());
    e = (*A) * (*res) - (*B);
    double a = e.norma();
    double y = B->norma();
    return (a / y);
}