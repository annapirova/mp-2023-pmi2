using namespace std;
#include "gauss.h"
#include "matrix&vector.h"
#include <iostream>

void Gauss::Solve()
{
    int n;
    double a = 0.0, d;
    matrix M = *A;
    vector v = *b;
    //vector x;
    n = M.GetSize();
    for (int i = 0; i < n - 1; i++)
    {
        // Поиск главного элемента
        int mainRow = i;
        for (int p = i + 1; p < n; p++) {
            if (fabs(M(p, i)) > fabs(M(mainRow, i))) {
                mainRow = p;
            }
        }

        // Обмен строк
        if (mainRow != i) {
            M.swapRows(mainRow, i);
            double tmp = v[i];
            v[i] = v[mainRow];
            v[mainRow] = tmp;
        }

        //cout << "матрица M:\n" << M;
        //прямой ход
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
    cout << "матрица M после прямого хода:\n" << M;
    //cout << "v:\n" << v;
    //обратный ход
    for (int k = n - 1; k >= 0; k--)
    {
        d = 0.0;
        for (int j = k + 1; j < n; j++)
        {
            d += M(k, j) * (*res)[j];
            //M(j, n) -= M(j, k) * x[k];
        }
        (*res)[k] = (v[k] - d) / M(k, k);
    }
    //cout << "x:\n" << (*res);
    status = 1;
}

double Gauss::Check() {
    vector e(A->GetSize());
    e = (*A) * (*res) - (*b);
    double a = e.norma();
    double y = b->norma();
    return (a / y);
}