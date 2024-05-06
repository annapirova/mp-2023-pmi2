#include "Project Aeturnus.h"
#include "vector.h"
#include <iostream>
using namespace std;
int main()
{
    int op,up;
    cout << "Enter matrix size\n";
    cin >> op;
    cin >> up;
    Gauss macro(op,up);
    cout << "Generation of the problem\n";
    macro.Generate_(op,up);
    cout << "Done successfuly (matrix is up,vector is down)\n";
    cout << "Now SOLVING\n";
    vector soq = macro.TryToSolve(macro);
    cout << soq;
    cout << "Result is on your screen\n";
    cout << "Do you want to check it? [1/2]\n";
    char q;
    cin >> q;
    switch(q)
    {
        case 1: soq.younormie(soq);break;
        case 2: break;
        default:"You must type Y or N";
    }
}