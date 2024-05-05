#pragma once
using namespace std;
#include <iostream>
#include "vector.h"
#include <cstdlib>
class Gauss
{
    private:
    int pain; int suffer;
    vector* matvix;
    vector* vectro;
    vector* resmult;
    public:
    Gauss(int _size = 3, int _sizex = 4)
    {
        pain = _size;
        suffer = _sizex;
        matvix = new vector[pain];
		for (int u = 0; u < pain; u++)
		{
			matvix[u] = vector(suffer);
		}
        vectro = new vector[pain];
        resmult = new vector[pain];
    }
    ~Gauss()
	{
		delete[] matvix;
        delete[] vectro;
        delete[] resmult;
	}
    Gauss(const Gauss& KAPPA)
    {
        pain = KAPPA.pain;
        suffer = KAPPA.suffer;
        matvix = new vector(pain);
		for (int u = 0; u < pain; u++)
		{
			matvix[u] = vector(suffer);
		}
        vectro = new vector(pain);
        resmult = new vector(pain);
    }
    vector transGenerateVector(int y)
    {
        vector eclise;
        for (int g = 0;g < y;g++)
        {
            eclise[g] = (double)(rand() % 1024);
        }
        return eclise;
    }
    Gauss Generate_(int y,int m)
    {
        Gauss nrt(y,m);
        for (int i = 0;i<y;i++)
        {
            nrt.matvix[i] = transGenerateVector(m);
            cout << nrt.matvix[i] << " " << "\n";
        }
        cout << "\n";
        cout << "\n";
        nrt.resmult[y] = transGenerateVector(y);
        cout << nrt.resmult;
        cout << "\n";
        return nrt;
    }
    double transMinelSearch(vector abyss, int size)
    {
        int k = 1;
        double min;
        int key;
        for (k;k<size;k++)
        {
            if (abyss[k] < abyss[k - 1] && abyss[k] != 0.0)
            {
                min = abyss[k];
                key = k;
            }
        }
        return k;
    }
    double transNoneZeroSearch(vector abyss, int size)
    {
        int kl = 0;
        double key;
        for (kl;kl<size;kl++)
        {
            if (abyss[kl] != 0.0)
            {
                key = abyss[kl];
                break;
            }
        }
        return key;
    }
    Gauss& NSwitch(Gauss& dippa)
    {
        int* kel = new int (dippa.pain);
        for (int k = 0;k < dippa.pain;k++)
        {
            kel[k] = transMinelSearch(dippa.matvix[k],dippa.suffer);
        }
        double fine = dippa.matvix[0][kel[0]];
        int eggs;
        for(int r = 1; r < dippa.pain; r++)
        {
            if (dippa.matvix[r][kel[r]] < fine)
            {
                fine = dippa.matvix[r][kel[r]];
                eggs = r;
            }
        }
        int u = 0;
        while((eggs + u < dippa.pain) || (eggs - u > -1))
        {
            if (eggs + u < dippa.pain)
            {
                dippa.matvix[eggs + u] -= (dippa.matvix[eggs]*=(dippa.matvix[eggs + u][kel[eggs]]/dippa.matvix[eggs][kel[eggs]]));
                dippa.resmult[eggs + u] -= (dippa.resmult[eggs] *= (dippa.resmult[eggs+u] / dippa.resmult[eggs]))
            }
            if (eggs - u > - 1)
            {
                dippa.matvix[eggs - u] -= (dippa.matvix[eggs]*=(dippa.matvix[eggs - u][kel[eggs]]/dippa.matvix[eggs][kel[eggs]]));
                dippa.resmult[eggs - u] -= (dippa.resmult[eggs] *= (dippa.resmult[eggs+u] / dippa.resmult[eggs]))
            }
            u += 1;
        }
        for (int j = 0;j<dippa.pain;j++)
        {
            dippa.vectro[j] = dippa.vectro[j] / transNoneZeroSearch(dippa.matvix[j],dippa.suffer);
        }
        return *this;
    }
    vector TryToSolve(Gauss inplemet)
    {
        for (int q = 0;q < inplemet.pain;q++)
        {
            inplemet.NSwitch(inplemet);
        }
        inplemet.vectro = inplemet.resmult;
        return *inplemet.vectro;
    }
};
