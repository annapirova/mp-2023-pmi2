#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <ctime>
enum class kategoria
    {
        ovoshi,
        molochka,
        hoz,
        vipechka,
        soki
    };
class tovar
{
    int strix;
    double skidka;
    double cost_za_kg;
    double countt;
    kategoria kat;
    string name;
    public:
    tovar(string zxc)
    {
        strix=1000+rand()%5000;
        double skidka=rand()%RAND_MAX;
        name="persik";
    }
    bool operator ==(const tovar& zxc)
    {
        return (strix==zxc.strix);
    }
    bool operator < (const tovar& zxc)
    {
        return((cost_za_kg*skidka*countt)<(zxc.cost_za_kg*zxc.skidka*zxc.countt));
    }
    tovar& operator + (const tovar& zxc)
    {
        if(strix==zxc.strix)
        {
            countt+=zxc.countt;
        }
        return *this;
    }
    tovar& operator - (const tovar& zxc)
    {
        if(strix==zxc.strix && countt>zxc.countt)
        {
            countt-=zxc.countt;
        }
        return *this;
    }
    friend ostream& operator <<(ostream& os, const tovar&zxc);
    int get_strix()
    {
        return strix;
    }
    double get_skidka()
    {
        return skidka;
    }
    string get_name()
    {
        return name;
    }
};
ostream& operator <<(ostream& os, const tovar&zxc)
{
    cout<<"name: "<<zxc.name<<endl<<"strix: "<<zxc.strix<<endl;//////
}
using namespace std;
int main()
{
    srand(time(NULL));
    vector <tovar> tovari(20);
    vector <tovar>::iterator it;
    for(it=tovari.begin();it!=tovari.end();it++)
    {  
         cout<<it->get_strix();
    }
   cout<<endl;
    vector <int> check;
    int k, zxc;
    do
    {
        cout<<"input command"<<endl;
        cin>>k;
        switch(k)
        {
            case 1:
            {   cout<<"INPUT SHTRIX tovara"<<endl;
                cin>>zxc;// mb po polym i pririvnyt
                if(find(tovari.begin(), tovari.end(), zxc)==tovari.end())// vot s etim think
                {
                    cout<<"INPUT COORECT SHTrIX"<<endl;
                }
                else
                {
                    check.push_back(zxc);
                }
                //scan_new_tovar
                break;
            }
            case 2:
            {    if(check.empty())
                cout<<"SCAN ANY TOVAR"<<endl;
                else
                cout<<check.back()<<" count: "<<count(check.begin(), check.end(),check.back())<<" ";//!!!! tak je kak i !!!!!!!!!!
                
                break;
            }
            case 3:
            {
                for(auto& zxc : tovari)
                {
                    if(find(check.begin(), check.end(),zxc.get_strix())!=check.end())
                    {
                        cout<<zxc.get_strix()<<"  "<<count(check.begin(), check.end(),zxc.get_strix())<<" "<<zxc.get_skidka()<<" "<< zxc.get_name()<<endl;//!!!!!
                    }
                }
                //chek
                break;
            }
            default:
            {
                if(k!=4)
                {
                printf("don't exist the comand\n");
                printf("select new comand\n");
                }
                break;
            }

        }
        
    } while (k!=4);
    return 0;
}