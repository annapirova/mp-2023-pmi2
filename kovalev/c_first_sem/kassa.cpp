#define _SCL_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <ctime>
#include <sstream>
#include <locale>
using namespace std;
enum  kategoria
    {
        ovoshi,
        fruit,
        molochka,
        hoz,
        vipechka,
        soki
    };
class tovar
{
    int strix=0;
    double skidka=0;
    double cost_za_kg=0;
    double countt=0;
    kategoria kat=kategoria::hoz;
    string name;



    public:
    tovar(int a,double b, double c, double d, kategoria e, string f): strix(a),skidka(b),cost_za_kg(c),kat(e), name(f){}
    tovar (const tovar& zxc)
    {
        strix=zxc.strix;
        skidka=zxc.skidka;
        cost_za_kg=zxc.cost_za_kg;
        countt=zxc.countt;
        kat=zxc.kat;
        name=zxc.name;
    }
    tovar(string zxc): name(zxc){};
    bool operator ==(const tovar& zxc)
    {
        return (name==zxc.name);
    }
    bool operator > (const tovar& zxc)
    {
        return((cost_za_kg*skidka*countt)>(zxc.cost_za_kg*zxc.skidka*zxc.countt));
    }
    bool operator < (const tovar& zxc)
    {
        return((cost_za_kg*skidka*countt)<(zxc.cost_za_kg*zxc.skidka*zxc.countt));
    }
    tovar& operator += (const tovar& zxc)
    {
        if(name==zxc.name)
        {
            countt+=zxc.countt;
        }
        return *this;
    }
    double stoimost()
    {
        return(cost_za_kg*skidka*countt);
    }
    int get_strix()
    {
        return strix;
    }
    double get_skidka()
    {
        return skidka;
    }
    double get_cost()
    {
        return cost_za_kg;
    }
    double& get_count()
    {
        return countt;
    }
    string get_name()
    {
        return name;
    }
    string get_kat() const
    {
        switch (kat)
        {
        case kategoria::fruit :
        {
            return "fruit";
            break;
        }
        case kategoria::hoz :
        {
            return "hoz";
            break;
        }
        case kategoria::molochka :
        {
            return "molochka";
            break;
        }
        case kategoria::ovoshi :
        {
            return "ovoshi";
            break;
        }
        case kategoria::soki :
        {
            return "soki";
            break;
        }
        default:
        {
            return "vipechka";
            break;
        }
        }
    }
};
ostream& operator <<(ostream& os, tovar& zxc) 
{
    os<<"kategoria: "<<zxc.get_kat()<<endl<<"name: "<<zxc.get_name()<<endl<<"strix: "<<zxc.get_strix()<<endl<<"skidka "<<zxc.get_skidka()<<endl<<"cost_za_kg "<<zxc.get_cost()<<endl<<"count "<<zxc.get_count()<<endl;
    return os;
}

class sklad
{
    static vector <tovar> skladik;
    public:
    static void inicial()
    {
        skladik.push_back(tovar(3457,0.15,249.57,25,kategoria::fruit,"persik"));
        skladik.push_back(tovar(7563,0.07,30,25,kategoria::fruit,"arbuzin"));
        skladik.push_back(tovar(2901,0.10,67,25,kategoria::fruit,"mandarin"));
        skladik.push_back(tovar(1657,0.25,95,25,kategoria::ovoshi,"ogurec"));
        skladik.push_back(tovar(1927,0.03,100,25,kategoria::ovoshi,"pomidor"));
        skladik.push_back(tovar(5413,0.12,144,25,kategoria::molochka,"milk"));
        skladik.push_back(tovar(9850,0.01,52,25,kategoria::molochka,"jogurt"));
        skladik.push_back(tovar(9654,0.00,500,25,kategoria::molochka,"tvorog"));
        skladik.push_back(tovar(1789,0.046,120,25,kategoria::hoz,"grabli"));
        skladik.push_back(tovar(1405,0.034,721,25,kategoria::hoz,"cleaning voda"));
        skladik.push_back(tovar(6540,0.073,31,25,kategoria::vipechka,"baget"));
        skladik.push_back(tovar(1111,0.02,24,25,kategoria::vipechka,"sosiska v teste"));
        skladik.push_back(tovar(2222,0.01,900,25,kategoria::soki,"dobryi"));
        skladik.push_back(tovar(3333,0.09,174,25,kategoria::soki,"lybimi"));
        skladik.push_back(tovar(7777,0.11,673,25,kategoria::soki,"fruit_sad"));

    }
    static void Add_tovar(int a,double b, double c, double d, kategoria e, string f)
    {
        tovar zxc(a,b,c,d,e,f);
        skladik.push_back(zxc);
    }
    static void find_tovar(string naming)
    {
        tovar zxc(naming);
        if(find(skladik.begin(),skladik.end(),zxc)!=skladik.end())
        cout<<(*(find(skladik.begin(),skladik.end(),zxc)))<<endl;
        else throw "NO EXIST";
    }
    static void print_sklad()
    {
        for(auto it=skladik.begin();it!=skladik.end();it++)
        cout<<*it<<endl;
    }
    friend class chek;
};
class chek
{
    static vector<tovar> chekkk;
    public:
    static void add_tovar(const string& zxc)
    {
        stringstream ss(zxc);
        string item;
        vector<string> lecsema;
        while(getline(ss,item,' '))
        {
            lecsema.push_back(item);
        }
        locale loc;
        int it_1=0;
        int it_2=0;
        vector<string>::iterator it;
        vector<string>::iterator it1;
        vector<string>::iterator it2;
        for(it=lecsema.begin();it!=lecsema.end();it++)
        {   tovar q(*it);
            if(find((sklad::skladik).begin(),sklad::skladik.end(),q)!=sklad::skladik.end())
            {
            it1=it;
            it_1++;
            }
            if(isdigit((*it)[0], loc))
            {
            it2=it;
            it_2++;
            }
            if(it_1!=1 || it_2!=1) throw "this tovar no exist or input 2naming or 2count";
            if(it_1==1 && it_2==1)
            {   tovar ibz(*it1);
                stringstream sd(*it2);
                double x;
                sd>>x;
                ibz.get_count()+=x;
                if((find(chekkk.begin(),chekkk.end(),ibz)!=chekkk.end()))
                {   if(  ((*(find(chekkk.begin(),chekkk.end(),ibz))).get_count()+ibz.get_count()) <= (*(find((sklad::skladik).begin(),sklad::skladik.end(),ibz))).get_count() )
                    *(find(chekkk.begin(),chekkk.end(),ibz))+=ibz;
                }
                else
                {   tovar pipka(*(find((sklad::skladik).begin(),sklad::skladik.end(),ibz)));
                    pipka.get_count()=ibz.get_count();
                    chekkk.push_back(pipka);

                }
            }
        }


    }
    static void print_check()
    {
        if(!(chekkk.empty()))
        for(auto& a:chekkk)
        {
            cout<<a;
        }
        else throw "add any tovar in check";
    }
   /* static void sort_check()
    {
        sort(chekkk.begin(),chekkk.end());
    }
    */
};
int main()
{
    sklad::inicial();
    srand(time(NULL));
    int k;
    string stroka;// 1 скан товара // 4чек// 5сорт чек// 2склад товаров// 3поиск товара по складу //6 добавить товар на склад
    do
    {
        cout<<"input command"<<endl;
        cin>>k;
        switch(k)
        {
            case 1:
            {   cout<<"INPUT name tovara and count"<<endl;
                getline(cin, stroka);
                try
                {
                    chek::add_tovar(stroka);
                }
                catch(char* error)
                {
                    cout<<error<<endl;
                }
                
                chek::add_tovar(stroka);
                break;
            }
            case 2:
            {    
                sklad::print_sklad();
                break;
            }
            case 3:
            {
                cout<<"name of tovar for search: ";
                string pups;
                cin>>pups;
                try
                {
                sklad::find_tovar(pups);
                }
                catch(char* error)
                {
                    cout<<error<<endl;
                }
                break;
            }
            case 4:
            {
                try
                {
                   chek::print_check();
                }
                catch(char* error)
                {
                    cout<<error<<endl;
                }
                break;
            }
            case 5:
            {
                //chek::sort_check();
                try
                {
                    chek::print_check();
                }
                catch(char* error)
                {
                    cout<<error<<endl;
                }
                
                break;
            }
            default:
            {
                if(k!=0)
                {
                printf("don't exist the comand\n");
                printf("select new comand\n");
                }
                break;
            }

        }
        
    } while (k!=0);
    
    return 0;
}