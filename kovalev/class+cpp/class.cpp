#include <iostream>
#include "hexs.h"
using std::cout;
using std::endl;
 
int main()
{
    hexs m_1, m_2(123.456);
    cout<<"asd"<<endl;
    m_1.set(93.213);
    cout<<"for m_1:"<<endl;
    m_1.print_kg();
    m_1.print_funtik();
    m_1.print_pudink();
    cout<<"for m_2:"<<endl;
    m_2.print_kg();
    m_2.print_funtik();
    m_2.print_pudink();
    hexs tst_s=m_1.sum(m_2);
    cout<<"for sum:"<<endl;
    tst_s.print_kg();
    tst_s.print_funtik();
    tst_s.print_pudink();
    return 0;
}