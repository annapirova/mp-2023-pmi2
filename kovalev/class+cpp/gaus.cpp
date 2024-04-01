#include <iostream>
#include "matrixs.h"
#include "vectors.h"
#include <ctime>
using std::cout;
using std::cin;
using std::endl;
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
    {   cout<<MATRISA<<endl;
        double max_in_st=maxim_st(i, MATRISA,b);
        for(int j=i+1;j<MATRISA.n;j++)
        {
            double kef=MATRISA.A[j][i]/max_in_st;
            for(int k=i;k<MATRISA.m;k++)
            {
                MATRISA.A[j][k]=(abs((MATRISA.A[j][k]-(kef * (MATRISA.A[i][k]))))>0.00000001) ? MATRISA.A[j][k]-(kef * (MATRISA.A[i][k])) : 0.0;
            }
            b.vec[j]=abs(b.vec[j]-(kef*b.vec[i]))>0.000001 ? (b.vec[j]-(kef*b.vec[i])) : 0.0;

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




int main()
{
    srand(time(NULL));
    int n=5, m=5;
    matrix MATRISA(n,m);// квадратная ну по-любому, иначе дискотека с диагонлью
    MATRISA.set_random(10.0,1000.0);
    cout<<MATRISA<<endl;
    vector otvet(m);
    vector b(n);
    otvet.set_some_vec();//+generation
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            b[i]+=MATRISA(i,j)*otvet[j];
        }
    }
    vector otvet_polych(m);
    prym_hod(MATRISA,b);
    cout<<MATRISA<<endl;
    obr_hod(MATRISA,otvet_polych,b);
    cout<<otvet<<endl;
    cout<<otvet_polych;
    return 0;
}