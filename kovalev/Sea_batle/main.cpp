#include <iostream>
#include <vector>
#include <ctime>
#include"game.h"
using std::cout;
using std::cin;
using std::endl;
/// 0-miss 1-hurt 2-nor ship 3-ship
int main()
{
    srand(time(NULL));
    Bootinok Botiha;
    Geniy Alexey;
    player* A=&Alexey;
    player* B=&Botiha;
    Alexey.set_ship();
    Botiha.set_ship();
    Alexey.copy_not_my_pole(&Botiha);
    Botiha.copy_not_my_pole(&Alexey);
    cout<<endl<<endl<<endl;
    do
    {   Alexey.cheating();
        cout<<endl<<endl<<endl;
        A->attack();
        B->attack();
    } while (Alexey.count_heart()!=20 && Botiha.count_heart()!=20);
    if(Alexey.count_heart()!=20)
    cout<<"congratulate you are winner"<<endl;
    if(Botiha.count_heart()!=20)
    cout<<"Botiha win, you are looser"<<endl;
    return 0;
}