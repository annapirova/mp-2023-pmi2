#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <ctime>
#include "GAUS_CLASS.h"
using std::cout;
using std::endl;
using std::cin;
double maxim_st(int j, matrix& MATRISA, vector& zxc)
{
    double maxj=0;
    int maxk=-1;
        for(int k=j;k<MATRISA.n;k++)
        { 
            if(abs(maxj)<abs(MATRISA(k,j)))
            {   maxj=MATRISA(k,j);
                maxk=k;
            }
        }
        double* tmp=MATRISA.A[j];
                MATRISA.A[j]=MATRISA.A[maxk];
                MATRISA.A[maxk]=tmp;
                double q=zxc.vec[j];
                zxc.vec[j]=zxc.vec[maxk];
                zxc.vec[maxk]=q;
    return maxj;
}
void prym_hod(matrix& MATRISA, vector& b)
{
    for(int i=0;i<MATRISA.n-1;i++)
    {
        double max_in_st=maxim_st(i, MATRISA,b);
        for(int j=i+1;j<MATRISA.n;j++)
        {
            double kef=MATRISA.A[j][i]/max_in_st;
            for(int k=i;k<MATRISA.m;k++)
            {
                MATRISA.A[j][k]=MATRISA.A[j][k]-(kef * (MATRISA.A[i][k]));
            }
            b.vec[j]=b.vec[j]-(kef*b.vec[i]);

        }
    }
}
void obr_hod(matrix& MATRISA,vector& otvet_polych, vector& b)
{ 
    for(int i=MATRISA.n-1;i>=0;i--)
    {   otvet_polych[i]=b[i];
        for(int j=i+1;j<MATRISA.n;j++)
        {
        otvet_polych[i]-=(MATRISA.A[i][j]*otvet_polych[j]);
        }
        otvet_polych[i]/=MATRISA.A[i][i];
    }
}
double Error(vector& otvet_polych, matrix& MATRISA, vector&b)
{
    vector e=MATRISA*otvet_polych-b;
    double e1 = e.norma() / b.norma();
return e1;

}
GAUS:: GAUS()
{
    MATRISA=NULL;
    X=NULL;
    b=NULL;
    otvet_polych=NULL;
    tek =created;
}

GAUS:: GAUS(matrix* myA, vector* myX, vector* myB, vector* otv) : MATRISA(myA), X(myX), b(myB),otvet_polych(otv){};
void GAUS:: Solve()
{
    prym_hod(*MATRISA, *b);
    obr_hod(*MATRISA,*otvet_polych,*b);
    tek = solved;
}
double GAUS:: Check()
{   if(tek==solved)
    return Error(*otvet_polych,*MATRISA, *b);
    else throw 1;
}
    void GAUS::print_matrix()
    {
        cout<<*MATRISA;
    }
    void GAUS::print_b()
    {
        cout<<*b;
    }
    void GAUS::print_x()
    {
        cout<<*X;
    }
    void GAUS::print_polych()
    {   if(tek==solved)
        cout<<*otvet_polych;
        else throw "ERROR";
    }

