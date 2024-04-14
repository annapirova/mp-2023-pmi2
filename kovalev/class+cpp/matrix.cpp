#include <iostream>
#include "matrixs.h"
#include "vectors.h"
#include <ctime>
using std::cout;
using std::cin;
using std::endl;
int main()
{
    srand(time(NULL));
    matrix a(5,5);
    a.set_random(0,100);
    cout<<a;
    matrix c(2,2);
    cin>>c;
    matrix b(c);
    b.Print();
    a+=b;
    a=b;
    cout<<a<<endl;
    matrix zxc=a+a;
    matrix zxc1=a-a;
    matrix zxc2=a*a;
    cout<<zxc<<endl;
    cout<<zxc1<<endl;
    cout<<zxc2<<endl;
    vector v(10);
    v.set_random_vec(0,1);
    matrix m(5,10);
    m.set_random(0,100);
    vector t=m*v;
    cout<<t;
    return 0;
}