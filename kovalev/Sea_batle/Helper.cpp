#include <iostream>
#include <ctime>
#include <vector>
#include"game.h"
using std::cout;
using std::cin;
using std::endl;
using std::istream;
using std::ostream;
std::vector<std::vector<std::pair<int,int>>> player::ships1;
std::vector<std::vector<std::pair<int,int>>> player::ships2;
std::vector<std::vector<std::pair<int,int>>> player::copy_ships1;
std::vector<std::vector<std::pair<int,int>>> player::copy_ships2;
player:: player()
{
    MY_pole=new int* [SIZE_POLE];
    NOT_MY_pole=new int* [SIZE_POLE];
    Kuda_palil=new int* [SIZE_POLE];
    for(int i=0;i<SIZE_POLE;i++)
    {
        MY_pole[i]=new int [SIZE_POLE];
        NOT_MY_pole[i]=new int [SIZE_POLE];
        Kuda_palil[i]=new int [SIZE_POLE];
        for(int j=0;j<SIZE_POLE;j++)
        {
            MY_pole[i][j]=2;
            Kuda_palil[i][j]=2;
            NOT_MY_pole[i][j]=2;
        }
    }
}
void player::copy_not_my_pole(const player* A)
{   for(int i=0;i<SIZE_POLE;i++)
    {
        for(int j=0;j<SIZE_POLE;j++)
        {
            NOT_MY_pole[i][j]=(A)->MY_pole[i][j];
        }
    }

}
int player::count_heart()
{
    return count_in;
}
void player::cheating()
{   cout<<"CHEATING!"<<endl;
    cout<<"  0 1 2 3 4 5 6 7 8 9"<<endl;
    for( int i=0;i<player::SIZE_POLE;i++)
    {   cout<<i<<' ';
        for(int j=0;j<player::SIZE_POLE;j++)
        {
            cout<<NOT_MY_pole[i][j]<<" ";
        }
        cout<<endl;
    }
}
bool player::check_free_cube_for_set(int i, int j)
{  
    for(int k=-1;k<2;k++)
    {
        for(int p=-1;p<2;p++)
        {
            if((k+i>=0) && (k+i<10) && (p+j>=0) && (p+j<10))
                {                                                   ////все вокруг!!!!
                    if(MY_pole[k+i][p+j]!=2)
                        return false;
                }
        }
    }
    return true;
}
player:: ~player()
{
    for(int i=0;i<SIZE_POLE;i++)
    {
        delete MY_pole[i];
        delete NOT_MY_pole[i];
        delete Kuda_palil[i];
    }
    delete Kuda_palil;
    delete NOT_MY_pole;
    delete MY_pole;

}
ostream& operator <<(ostream& out, const player* a)
{
    out<<"  0 1 2 3 4 5 6 7 8 9"<<endl;
    for( int i=0;i<player::SIZE_POLE;i++)
    {   cout<<i<<' ';
        for(int j=0;j<player::SIZE_POLE;j++)
        {
            out<<(*a).Kuda_palil[i][j]<<" ";
        }
        out<<endl;
    }
    return out;
}
void Geniy:: attack()
{   cout<<this<<endl;
    int i,j;
    bool Nsucceful=true;
    while(Nsucceful)
    {
    cout<<"Attack in i = ";
    cin>>i;
    cout<<" j=";
    cin>>j;
    cout<<endl;
    if(i<10 && i>-1 && j<10 && j>-1 && Kuda_palil[i][j]==2)
    {
    cout<<"Nice attack"<<endl;
    if(NOT_MY_pole[i][j]==3)
    {
    Kuda_palil[i][j]=1;
    cout<<"POPAL!"<<endl;
    count_in++;
    for(int k=0;k<ships2.size();k++)
    {
        for(int p=0;p<ships2[k].size();p++)
        {
            if(ships2[k][p].first==i && ships2[k][p].second==j)
            {
                ships2[k].erase(ships2[k].begin()+p);
                break;
            }
        }
        if(ships2[k].empty())
        {   ships2.erase(ships2.begin()+k);
            cout<<"Podbit FULL SHIP"<<endl;
            ///удаление целого корабля и боковинок
            for(int y=0;y<copy_ships2[k].size();y++)
            {
                int f=copy_ships2[k][y].first;
                int s=copy_ships2[k][y].second;
                Kill_ship(f, s);
            }
            copy_ships2.erase(copy_ships2.begin()+k);
        }
    }
    }
    else
    {
     Kuda_palil[i][j]=0;
     cout<<"MISS"<<endl;
    }
    Nsucceful=false;
    }
    else cout<<"input correct"<<endl;
    }
}
void player:: Kill_ship(int f, int s)/////////////////////////////// поменял проверку вместо ифов два форика
{
    for(int i=-1;i<2;i++)
    {
        for(int j=-1;j<2;j++)
        {
            if((f+i>=0) && (f+i<10) && (s+j>=0) && (s+j<10))
                {
                    if(Kuda_palil[f+i][s+j]!=1)
                        Kuda_palil[f+i][s+j]=0;
                }

        }
    }

}

void Geniy::set_ship()
{
    int i,j;
    int count_ship_vec=0;
    int sh_el=4;
    int count_4_el=0;
    int count_3_el=0;
    int count_2_el=0;
    int count_1_el=0;
    while(count_ship_vec!=10)
    {
    if(count_4_el==1) sh_el=3;
    if(count_3_el==2) sh_el=2;
    if(count_2_el==3) sh_el=1;
    if(count_1_el==4) break;
    cout<<"SET THE SHIPS: "<<endl<<sh_el<<" elements ship: "<<endl<<"input i = ";
    cin>>i;
    cout<<"input j = ";
    cin>>j;
    if(i<10 && i>=0 && j<10 && j>=0 && MY_pole[i][j]==2)
    {
        int k;
        cout<<"choose a way: 1-up,2-down,3-right,4-left"<<endl;
        cin>>k;
        if(k==1)
        {   int zxc=0;
            for(int k=0;k<sh_el;k++)
            {
                if(i+k<10)
                zxc+=int(check_free_cube_for_set(i+k,j));
                else
                {
                cout<<"you cann't set here ship"<<endl;
                break;
                }
            }
            if(zxc==sh_el)
            {
                if(sh_el==4) count_4_el++;
                if(sh_el==3) count_3_el++;
                if(sh_el==2) count_2_el++;
                if(sh_el==1) count_1_el++;
                std::vector<std::pair<int, int>> trash;
                for(int k=0;k<sh_el;k++)
                    {
                    MY_pole[i+k][j]=3;
                    std:: pair <int,int> rep(i+k,j);
                    trash.push_back(rep);
                    }
                count_ship_vec++;
                ships1.push_back(trash);
            }
        }
        if(k==2)
        {
            int zxc=0;
            for(int k=0;k<sh_el;k++)
            {
                if(i-k>=0)
                zxc+=int(check_free_cube_for_set(i-k,j));
                else
                { 
                    cout<<"you cann't set here ship"<<endl;
                    break;
                }
            }
            if(zxc==sh_el)
            {
                if(sh_el==4) count_4_el++;
                if(sh_el==3) count_3_el++;
                if(sh_el==2) count_2_el++;
                if(sh_el==1) count_1_el++;
                std::vector<std::pair<int, int>> trash;
                for(int k=0;k<sh_el;k++)
                    {
                    MY_pole[i-k][j]=3;
                    std:: pair <int,int> rep(i-k,j);
                    trash.push_back(rep);
                    }
                count_ship_vec++;
                ships1.push_back(trash);
            }
            
        }
        if(k==3)
        {
            int zxc=0;
            for(int k=0;k<sh_el;k++)
            {
                if(j+k<10)
                zxc+=int(check_free_cube_for_set(i,j+k));
                else 
                {
                cout<<"you cann't set here ship"<<endl;
                break;
                }
            }
            if(zxc==sh_el)
            {
                if(sh_el==4) count_4_el++;
                if(sh_el==3) count_3_el++;
                if(sh_el==2) count_2_el++;
                if(sh_el==1) count_1_el++;
                std::vector<std::pair<int, int>> trash;
                for(int k=0;k<sh_el;k++)
                    {
                    MY_pole[i][j+k]=3;
                    std:: pair <int,int> rep(i,j+k);
                    trash.push_back(rep);
                    }
                count_ship_vec++;
                ships1.push_back(trash);
            }            
        }
        if(k==4)
        {
            int zxc=0;
            for(int k=0;k<sh_el;k++)
            {
                if(j-k>=0)
                zxc+=int(check_free_cube_for_set(i,j-k));
                else 
                {
                cout<<"you cann't set here ship"<<endl;
                break;
                }
            }
            if(zxc==sh_el)
            {
                if(sh_el==4) count_4_el++;
                if(sh_el==3) count_3_el++;
                if(sh_el==2) count_2_el++;
                if(sh_el==1) count_1_el++;
                std::vector<std::pair<int, int>> trash;
                for(int k=0;k<sh_el;k++)
                    {
                    MY_pole[i][j-k]=3;
                    std:: pair <int,int> rep(i,j-k);
                    trash.push_back(rep);
                    }
                count_ship_vec++;
                ships1.push_back(trash);
            }            
        }
    }
    else
    {
        cout<<"Input coorect i and j"<<endl;
    }
    }
    copy_ships1=ships1;
}
/// //////
void Bootinok:: attack()
{   
    int i,j;
    bool Nsucceful=true;
    while(Nsucceful)
    {
        if(last_i==-1 || ship_last_hod)
    {
        i=rand()%10;
        j=rand()%10;
        naprav=1;
    }
    else
    {
        if(last_i!=-1 && !last_hod)
        {
            if(naprav==1) naprav=2;
            if(naprav==2) naprav=3;
            if(naprav==3) naprav=4;
            if(naprav==4) naprav=1;
        }
    if(last_i!=-1 && last_hod)   
    {   if(naprav==1) 
        {
            if(last_i+1<10)
            {
            i=last_i+1;
            j=last_j;
            }else
            {
            i=last_i-1;
            j=last_j;
            naprav=2;
            }
        }
        if(naprav==2) 
        {
            if(last_i-1>-1)
            {
            i=last_i-1;
            j=last_j;
            }
            else
            {
            i=last_i+1;
            j=last_j;
            naprav=1;
            }
        }
        if(naprav==3) 
        {
            if(last_j-1>-1)
            {
            i=last_i;
            j=last_j-1;
            }
            else
            {
            i=last_i;
            j=last_j+1;
            naprav=4;
        }
        }
        if(naprav==4) 
        {
            if(last_j+1<10)
            {
            i=last_i;
            j=last_j+1;
            }
            else
            {
            i=last_i;
            j=last_j-1;
            naprav=3;
        }
        }
    } 
    }
    if(i<10 && i>-1 && j<10 && j>-1 && Kuda_palil[i][j]==2)
    {
    if(NOT_MY_pole[i][j]==3)
    {
    Kuda_palil[i][j]=1;
    int last_i=i;
    int last_j=j;
    count_in++;
    for(int k=0;k<10;k++)
    {
        for(int p=0;p<ships1[k].size();p++)
        {
            if(ships1[k][p].first==i && ships1[k][p].second==j)
            ships1[k].erase(ships1[k].begin()+p);
            break;
        }
        if(ships1[k].empty())
        {
            ship_last_hod=1;
            last_i=-1;
            last_j=-1;
            ///удаление целого корабля и боковинок)
            for(int y=0;y<copy_ships1[k].size();y++)//беру каждую клеточку коробля и все вокруг вырезаю
            {
                int f=copy_ships1[k][y].first;
                int s=copy_ships1[k][y].second;
                Kill_ship(f, s);
            }
            copy_ships1.erase(copy_ships1.begin()+k);
        }
        else  ship_last_hod=0;
    }
    }
    else
    {
     NOT_MY_pole[i][j]=0;
    }
    Nsucceful=false;
    }
    {

    }
    }
    
}///////

void Bootinok:: set_ship()
{
    int i,j;
    int count_ship_vec=0;
    int sh_el=4;
    int count_4_el=0;
    int count_3_el=0;
    int count_2_el=0;
    int count_1_el=0;
    while(count_ship_vec!=10)
    {
    if(count_4_el==1) sh_el=3;
    if(count_3_el==2) sh_el=2;
    if(count_2_el==3) sh_el=1;
    if(count_1_el==4) break;
    i=rand()%10;
    j=rand()%10;
    if(i<10 && i>=0 && j<10 && j>=0 && MY_pole[i][j]==2)
    {
        int k;
        k=1+rand()%4;
        if(k==1)
        {   int zxc=0;
            for(int k=0;k<sh_el;k++)
            {
                if(i+k<10)
                zxc+=int(check_free_cube_for_set(i+k,j));
            }
            if(zxc==sh_el)
            {
                if(sh_el==4) count_4_el++;
                if(sh_el==3) count_3_el++;
                if(sh_el==2) count_2_el++;
                if(sh_el==1) count_1_el++;
                std::vector<std::pair<int, int>> trash;
                for(int k=0;k<sh_el;k++)
                    {
                    MY_pole[i+k][j]=3;
                    std:: pair <int,int> rep(i+k,j);
                    trash.push_back(rep);
                    }
                count_ship_vec++;
                ships2.push_back(trash);
            }
            
        }
        if(k==2)
        {
            int zxc=0;
            for(int k=0;k<sh_el;k++)
            {
                if(i-k>=0)
                zxc+=int(check_free_cube_for_set(i-k,j));
            }
            if(zxc==sh_el)
            {
                if(sh_el==4) count_4_el++;
                if(sh_el==3) count_3_el++;
                if(sh_el==2) count_2_el++;
                if(sh_el==1) count_1_el++;
                std::vector<std::pair<int, int>> trash;
                for(int k=0;k<sh_el;k++)
                    {
                    MY_pole[i-k][j]=3;
                    std:: pair <int,int> rep(i-k,j);
                    trash.push_back(rep);
                    }
                count_ship_vec++;
                ships2.push_back(trash);
            }
            
        }
        if(k==3)
        {
            int zxc=0;
            for(int k=0;k<sh_el;k++)
            {
                if(j+k<10)
                zxc+=int(check_free_cube_for_set(i,j+k));
            }
            if(zxc==sh_el)
            {
                if(sh_el==4) count_4_el++;
                if(sh_el==3) count_3_el++;
                if(sh_el==2) count_2_el++;
                if(sh_el==1) count_1_el++;
                std::vector<std::pair<int, int>> trash;
                for(int k=0;k<sh_el;k++)
                    {
                    MY_pole[i][j+k]=3;
                    std:: pair <int,int> rep(i,j+k);
                    trash.push_back(rep);
                    }
                count_ship_vec++;
                ships2.push_back(trash);
            }
            
        }
        if(k==4)
        {
            int zxc=0;
            for(int k=0;k<sh_el;k++)
            {
                if(j-k>=0)
                zxc+=int(check_free_cube_for_set(i,j-k));
            }
            if(zxc==sh_el)
            {
                if(sh_el==4) count_4_el++;
                if(sh_el==3) count_3_el++;
                if(sh_el==2) count_2_el++;
                if(sh_el==1) count_1_el++;
                std::vector<std::pair<int, int>> trash;
                for(int k=0;k<sh_el;k++)
                    {
                    MY_pole[i][j-k]=3;
                    std:: pair <int,int> rep(i,j-k);
                    trash.push_back(rep);
                    }
                count_ship_vec++;
                ships2.push_back(trash);
            }
            
        }
    }
    }
    copy_ships2=ships2;
}
