#include <iostream>
#include <iomanip>
#include "vectors.h"
#include <ctime>
using std::cout;
using std::cin;
using std::endl;
using std::setw;
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
void vector:: set_random_vec(double a, double b)
{
    for(int i=0;i<size;i++)
    {
        vec[i]=a+(b-a)*(double)rand()/(double)RAND_MAX;
    }
}
void vector:: set_vector_size(int size_)
{
    size=size_;
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
double& vector:: operator [] (const int i)
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