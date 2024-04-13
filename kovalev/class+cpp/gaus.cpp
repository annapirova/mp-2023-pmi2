#include <iostream>
#include "GAUS_CLASS.h"
#include <ctime>
using std::cout;
using std::cin;
using std::endl;
void menuska()
{
    cout<<endl<<"1-SOLVE"<<endl<<"2-Check"<<"3-Print MATRIX"<<endl<<"4-Print B"<<endl<<"5-Print X"<<endl<<"6-Print polych_X"<<endl<<"0-exit"<<endl;
}
void inicial(matrix& matrica,vector& B, vector& X, vector& otvet_p,int& n)
{
    cout<<endl<<"1 - input matrix, 2 - generation matrix"<<endl;
    int k;
    cin>>k;
    if(k==1)
    {
        matrica.set_some();
    }
    if(k==2)
    {   double a,b;
        cout<<"input range: ";
        cin>>a;
        cin>>b;
        matrica.set_random(a,b);
    }
    if(!(k==1 || k==2))
    {
        cout<<"input correct"<<endl;/// iskl
    }
    cout<<endl<<"1 - input vector x, 2 - generation vector x"<<endl;
    cin>>k;
    if(k==1)
    {
        X.set_some_vec();
    }
    if(k==2)
    {   
        double a,b;
        cout<<"input range: ";
        cin>>a>>b;
        X.set_random_vec(a,b);
    }
    if(!(k==1 || k==2))/// iskl
    {
        cout<<"input correct"<<endl;
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            B[i]+=matrica(i,j)*X[j];
        }
    }

}
int main()
{
    srand(time(NULL));
    int menu,n;
    cout<<"Input SIZE matrix: ";
    cin>>n;
    matrix matrica(n,n);
    vector B(n);
    vector X(n);
    vector otvet_p(n); 
    inicial(matrica,B,X,otvet_p,n);
    GAUS gaus_element(&matrica,&X,&B,&otvet_p);
    matrix matrica_copy(matrica);
    menuska();
    do
    {   cout<<"input command"<<endl;
        cin>>menu;
        switch(menu)
        {
            case 0:
            {
                cout<<"good luck"<<endl;
                break;
            }
            case 1:
            {   
                gaus_element.Solve();
                break;
            }
            case 2:
            {
                try
                {
                cout<<"pogresh "<<gaus_element.Check()<<endl;
                }
                catch(int zxc)
                {
                    cout<<"ERROR"<<endl<<"You must solved matrix"<<endl;
                }
                break;
                
            }
            case 3:
            {   
                cout<<matrica_copy;
                break;
            }
            case 4:
            {   
                gaus_element.print_b();
                break;
            }
            case 5:
            {
                gaus_element.print_x();
                break;
            }
            case 6:
            {
                try
                {
                gaus_element.print_polych();
                }
                catch(const char* zxc)
                {
                    cout<<zxc<<endl<<"You must solved matrix"<<endl;
                }
                break;
            }
            default:
            {
                cout<<"input correct menu"<<endl;
                break;
            }
        }

    } while (menu!=0);
    return 0;
}