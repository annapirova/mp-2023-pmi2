#include<iostream>
#include "vectors.h"
using std::cout;
using std::cin;
using std::endl;
int main()
{
    srand(time(NULL));
    vector m_1(10), m_2;
    m_2.set_vector_size(10);
    m_1.set_random_vec(15,40);
    m_2.set_random_vec(50,100);
    m_1.Print();
    m_2.Print();
    cout<<endl;
    vector sum=m_1+m_2;
    sum.Print();
    vector zxc;
    zxc=m_2;
    zxc.Print();
    cout<<zxc[0]<<endl;
    cout<<zxc[5]<<endl;
    vector m_3(5);
    m_3.set_some_vec();
    m_3.Print();
    return 0;
}
