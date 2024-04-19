#include <iostream>
#include <iomanip>
#include "vectors.h"
#include <ctime>
using std::cout;
using std::cin;
using std::endl;
using std::setw;
using std::setprecision;
using std::fixed;
vector:: vector(int size_): size(size_)
{
    vec=new double[size];
    for(int i=0;i<size;i++)
    {
        vec[i]=0.0;
    }

}
vector::vector (const vector &B)
{
    size=B.size;

    vec=new double[size];
    for(int i=0;i<size;i++)
    {
        vec[i]=B.vec[i];
    }
}
vector:: ~vector()
{
    delete[] vec;
}
vector vector:: operator + (const vector &B)
{
    vector c(size);
    if(size==B.size)
    {
    for(int i=0;i<size;i++)
    {
        c.vec[i]=vec[i]+B.vec[i];
    }
    }
    else
    {
        cout<<"ERROR size!=size1"<<endl<<"return NULL vector"<<endl;
    }
        return c;
}
vector vector:: operator - (const vector &B)
{
    vector c(size);
    if(size==B.size)
    {
        for(int i=0;i<size;i++)
        {
            c.vec[i]=vec[i]-B.vec[i];
        }
    }
    else
    {
        cout<<"ERROR size!=size1"<<endl<<"return NULL vector"<<endl;
    }
    return c;
}
vector& vector:: operator += (const vector &B)
{
    if(size==B.size)
    {
    for(int i=0;i<size;i++)
    {
        vec[i]+=B.vec[i];
    }
    }
    else
    {
        cout<<"ERROR size!=size1"<<endl<<"return vec1"<<endl;
    }
    return *this;
}
vector& vector:: operator -= (const vector &B)
{
    if(size==B.size)
    {
    for(int i=0;i<size;i++)
    {
        vec[i]-=B.vec[i];
    }
    }
    else
    {
        cout<<"ERROR size!=size1"<<endl<<"return vec1"<<endl;
    }
    return *this;
}
vector operator * (vector zxc, double q)
{
    vector c(zxc.size);
    for(int i=0;i<zxc.size;i++)
    {
        c.vec[i]=zxc.vec[i]*q;
    }
    return c;
}
vector operator * (double q, vector zxc)
{
    vector c(zxc.size);
    for(int i=0;i<zxc.size;i++)
    {
        c.vec[i]=zxc.vec[i]*q;
    }
    return c;
}
vector& vector:: operator ++()
{
    for(int i=0;i<size;i++)
    {
        vec[i]+=1.0;
    }
    return *this;
}
vector vector:: operator ++(int k)
{
    vector c(*this);
    for(int i=0;i<size;i++)
    {
        vec[i]+=1.0;
    }
    return c;
}
vector vector:: operator -()
{
    return (*this)*(-1.0);
}
void vector:: set_random_vec(double a, double b)
{
    for(int i=0;i<size;i++)
    {
        vec[i]=a+(b-a)*(double)rand()/(double)RAND_MAX;
    }
}
void vector:: set_vector_size(int size_)
{
    vector zxc(size_);
    *this=zxc;
}
vector& vector:: operator = (const vector &B)
{
    if(this==&B) return *this;
    if(size!=B.size)
    {
        delete[] vec;
        vec=new double[B.size];
        size=B.size;
    }
        for(int i=0;i<size;i++)
        {
            vec[i]=B.vec[i];
        }
    return *this;
}
double& vector:: operator [] (const int i) const
{
    return vec[i];
}
void vector:: Print()
{
    for (int i=0;i<size;i++)
    {
        cout<<setw(4)<<vec[i]<<" ";
    }
    cout<<endl;

}
void vector:: set_some_vec()
{
    for(int i=0;i<size;i++)
    {
        cout<<"input ["<<i<<"]: ";
        cin>>vec[i];
        cout<<endl;
    }
}
istream& operator >> (istream& in, vector& b)
{
    for(int i=0;i<b.size;i++)
    {
        cout<<"input ["<<i<<"]: ";
        in>>b.vec[i];
        cout<<endl;
    }
    return in;
}
ostream& operator << (ostream& out, const vector& b)
{
    for (int i=0;i<b.size;i++)
    {
        out<<fixed<<setprecision(10)<<b.vec[i]<<" ";
    }
    out<<endl;
    
    return out;
}
double vector::norma()
{
    double zxc=0.0;
    for(int i=0;i<size;i++)
    {  
        zxc+=vec[i]*vec[i];
    }
    return sqrt(zxc);
}