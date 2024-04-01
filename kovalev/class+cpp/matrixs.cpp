#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <ctime>
#include "matrixs.h"
using std::cout;
using std::endl;
using std::setw;
matrix::matrix(int n_, int m_): n(n_), m(m_)
{
    A=new double* [n];
    for(int i=0;i<n;i++)
    {
        A[i]=new double [m];
        for(int j=0;j<m;j++)
            A[i][j]=0.0;
    }
}
matrix:: matrix(const matrix &B): n(B.n), m(B.m)
{
    A=new double* [n];
    for(int i=0;i<n;i++)
    {
        A[i]=new double [m];
        for(int j=0;j<m;j++)
            A[i][j]=B.A[i][j];
    }
}
matrix:: ~matrix()
{
    for(int i=0;i<n;i++)
    delete[] A[i];
    delete[] A;
}
void matrix:: set_random (double a, double b)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            A[i][j]=a+(b-a)*(double)rand()/(double)RAND_MAX;
        }
    }
}
void matrix:: Print()
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cout<<setw(4)<<A[i][j]<<" ";;
        }
        cout<<endl;
    }
}
matrix matrix:: plus(const matrix& B)
{
    matrix c(n,m);
    if(n==B.n && m==B.m)
    {
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            c.A[i][j]=A[i][j]+B.A[i][j];
        }
    }
    }
    else
    {
        cout<<"ERROR size!=size1, return NULL matrix"<<endl;
    }
        return c;
}
matrix matrix::operator +(const matrix& B)
{
    matrix c(n,m);
    if(n==B.n && m==B.m)
    {
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            c.A[i][j]=A[i][j]+B.A[i][j];
        }
    }
    }
    else
    {
        cout<<"ERROR size!=size1,return NULL matrix"<<endl;
    }
        return c;
}
matrix& matrix:: operator+=(const matrix& B)
{   
    if(m==B.m && n==B.n)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                A[i][j]+=B.A[i][j];
            }
        }
    }
    else
    {
        cout<<"ERROR size!=size1, return NULL matrix"<<endl;
    }
    return *this;
}
matrix matrix::operator -(const matrix& B)
{
    matrix c(n,m);
    if(n==B.n && m==B.m)
    {
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            c.A[i][j]=A[i][j]-B.A[i][j];
        }
    }
    }
    else
    {
        cout<<"ERROR size!=size1, return NULL matrix"<<endl;
    }
    return c;
}
matrix& matrix:: operator -=(const matrix& B)
{  
    if(m==B.m && n==B.n)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                A[i][j]-=B.A[i][j];
            }
        }
    }
    else
    {
        cout<<"ERROR size!=size1, return NULL matrix"<<endl;
    }
    return *this;
}
matrix& matrix:: operator = (const matrix& B)
{
    if(this==&B) return *this;
    if(n!=B.n || m!=B.m)
    {
        for(int i=0;i<n;i++)
        delete[] A[i];
        delete[] A;
        A=new double*[B.n];
        for(int i=0;i<n;i++)
        A[i]=new double[B.m];
        m=B.m;
        n=B.n;
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            A[i][j]=B.A[i][j];
        }
    }
    return *this;
}
matrix matrix::operator * (const matrix& B)
{ 
    matrix c(n,B.m);
    if(m==B.n)
    {
    for(int i=0;i<c.n;i++)
    {
        for(int j=0;j<c.m;j++)
        {
            double q=0.0;
            for(int k=0;k<m;k++)
            {
                q+=A[i][k]*B.A[k][j];
            }
            c.A[i][j]=q;
        }
    }
    }
    else
    {
        cout<<"ERROR size!=size1, return NULL matrix"<<endl;
    }
    return c;
}
matrix operator *(const matrix& a, const double zxc)
{
    matrix c(a.n,a.m);
    for(int i=0;i<a.n;i++)
    {
        for(int j=0;j<a.m;i++)
        {
            c.A[i][j]=a.A[i][j]*zxc;
        }
        
    }
    return c;
}
matrix operator *(const double zxc, const matrix& a)
{
    matrix c(a.n,a.m);
    for(int i=0;i<a.n;i++)
    {
        for(int j=0;j<a.m;i++)
        {
            c.A[i][j]=a.A[i][j]*zxc;
        }
        
    }
    return c;
}
double matrix:: operator()(const int i,const int j)
{
    return A[i][j];
}
ostream& operator <<(ostream& out, const matrix& a)
{
    for( int i=0;i<a.n;i++)
    {
        for(int j=0;j<a.m;j++)
        {
            out<<setw(8)<<a.A[i][j]<<" ";
        }
        out<<endl;
    }
    return out;

}
istream& operator >>(istream& in, matrix& a)
{
    for(int i=0;i<a.n;i++)
    {
        for(int j=0;j<a.m;j++)
        {
        cout<<"input ["<<i<<"]["<<j<<"]: ";
        in>>a.A[i][j];
        cout<<endl;
        }
    }
    return in;

}
vector matrix:: operator *( const vector& b)
{
    vector c(n);
    if(m==b.size)
    {
        for(int i=0;i<n;i++)
        {
            c.vec[i]=0;
            for(int j=0;j<m;j++)
            c.vec[i]+=A[i][j]*b.vec[j];
        }
    }
    else
    cout<<"ERROR m!=size"<<endl<<"return NULL vector"<<endl;
    return c;
}
