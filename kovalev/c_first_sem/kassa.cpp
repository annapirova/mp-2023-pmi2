#define _SCL_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
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
    int strix;
    double skidka;
    double cost_za_kg;
    double countt;
    kategoria kat;
    string name;
    public:
    tovar(int a=0,double b=0, double c=0, double d=0, kategoria e=kategoria::hoz, string f=""): strix(a),skidka(b),cost_za_kg(c), countt(d), kat(e), name(f){}
    tovar (const tovar& zxc)
    {
        strix=zxc.strix;
        skidka=zxc.skidka;
        cost_za_kg=zxc.cost_za_kg;
        countt=zxc.countt;
        kat=zxc.kat;
        name=zxc.name;
    }

    tovar& operator =(const tovar& zxc)
    {
        strix=zxc.strix;
        skidka=zxc.skidka;
        cost_za_kg=zxc.cost_za_kg;
        countt=zxc.countt;
        kat=zxc.kat;
        name=zxc.name;
        return *this;
    }
    tovar(string zxc,int a=0,double b=0, double c=0, double d=0, kategoria e=kategoria::hoz): strix(a),skidka(b),cost_za_kg(c),kat(e), name(zxc), countt(d){};
    bool operator ==(const tovar& zxc)
    {
        return (name==zxc.name);
    }
    bool operator > (const tovar& zxc)
    {
        return((cost_za_kg*skidka*countt)>(zxc.cost_za_kg*zxc.skidka*zxc.countt));
    }
    friend bool less1(const tovar& z, const tovar& zxc);
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
bool less1(const tovar& z, const tovar& zxc) 
    {
        return((z.cost_za_kg*z.skidka*z.countt)<(zxc.cost_za_kg*zxc.skidka*zxc.countt));
    }

class sklad
{
    public:
    static vector <tovar> skladik;
 
    static void inicial()
    {
        skladik.push_back(tovar(3457,0.15,249.57,30,kategoria::fruit,"persik"));
        skladik.push_back(tovar(7563,0.07,30,200,kategoria::fruit,"arbuzin"));
        skladik.push_back(tovar(2901,0.10,67,50,kategoria::fruit,"mandarin"));
        skladik.push_back(tovar(1657,0.25,95,30,kategoria::ovoshi,"ogurec"));
        skladik.push_back(tovar(1927,0.03,100,41,kategoria::ovoshi,"pomidor"));
        skladik.push_back(tovar(5413,0.12,144,74,kategoria::molochka,"milk"));
        skladik.push_back(tovar(9850,0.01,52,21,kategoria::molochka,"jogurt"));
        skladik.push_back(tovar(9654,0.00,500,98,kategoria::molochka,"tvorog"));
        skladik.push_back(tovar(1789,0.046,120,125,kategoria::hoz,"grabli"));
        skladik.push_back(tovar(1405,0.034,721,96,kategoria::hoz,"cleaning voda"));
        skladik.push_back(tovar(6540,0.073,31,11,kategoria::vipechka,"baget"));
        skladik.push_back(tovar(1111,0.02,24,12,kategoria::vipechka,"sosiska_v_teste"));
        skladik.push_back(tovar(2222,0.01,900,37,kategoria::soki,"dobryi"));
        skladik.push_back(tovar(3333,0.09,174,75,kategoria::soki,"lybimi"));
        skladik.push_back(tovar(7777,0.11,673,23,kategoria::soki,"fruit_sad"));

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
            else if(isdigit((*it)[0], loc))
            {
            it2=it;
            it_2++;
            }
        }
            if(it_1!=1 || it_2!=1) throw "this tovar no exist or input 2naming or 2count";
            else 
            {   tovar ibz(*it1);
                stringstream sd(*it2);
                double x=0.0;
                sd>>x;
                ibz.get_count()+=x;
                vector<tovar>::iterator in_chek=find(chekkk.begin(),chekkk.end(),ibz);
                vector<tovar>::iterator in_sklad=find(sklad::skladik.begin(),sklad::skladik.end(),ibz);
                if(in_chek!=chekkk.end())
                {   if(((*in_chek).get_count()+ibz.get_count()) <= (*(in_sklad)).get_count())
                    {
                        *(in_chek)+=ibz;
                    }
                    else throw "net stol'ko na sklade";
                }
                else
                { 
                    tovar pipka(*(in_sklad));// проверка на количество
                    if(pipka.get_count()>=ibz.get_count())
                    {
                    pipka.get_count()=ibz.get_count();
                    chekkk.push_back(pipka);
                    }
                    else throw "net stol'ko na sklade";
                }
            }
        
    }
    static void print_check()
    {
        if(!(chekkk.empty()))
        {
        cout<<"                         Piterochka"<<endl;
        cout<<"name     count    skidka    cost(kg)    kategoria    stoimost"<<endl;
        for(auto& a:chekkk)
        {
            cout<<std::setw(7)<<a.get_name()<<" "<<setw(4)<<a.get_count()<<"        "<<setw(3)<<a.get_skidka()<<"      "<<setw(4)<<a.get_cost()<<"    "<<setw(10)<<a.get_kat()<<"         "<<setw(6)<<a.stoimost()<<endl;
        }
        }
        else throw "add any tovar in check";
    }
    static void sort_check()
    {
        sort(chekkk.begin(),chekkk.end(), less1);
        reverse(chekkk.begin(),chekkk.end());
        print_check();
    }
    
};
void info()
{
    cout<<"What are you wannt?\n1-Scan new tovar\n2-view sklad\n3-search tovar in sklad for name\n4-print check\n5-print sort check\n0-exit\n";
}
vector<tovar> sklad::skladik;
vector<tovar> chek::chekkk;
int main()
{   
    sklad::inicial();
    srand(time(NULL));
    int k;
    string stroka;
    info();
    do// файлы запрос пользователь и вывод чека можно закинуть базу 
    {
        cout<<"input command"<<endl;
        cin>>k;
        switch(k)
        {
            case 1:
            {   cout<<"INPUT name tovara and count"<<endl;
                getchar();
                getline(cin, stroka);
                try
                {
                    chek::add_tovar(stroka);
                }
                catch(char const* error)
                {
                    cout<<error<<endl;
                }
                break;
            }
            case 2://win
            {    
                sklad::print_sklad();
                break;
            }
            case 3://win
            {
                cout<<"name of tovar for search: ";
                string pups;
                cin>>pups;
                try
                {
                sklad::find_tovar(pups);
                }
                catch(char const* error)
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
                catch(char const* error)
                {
                    cout<<error<<endl;
                }
                break;
            }
            case 5:
            {
                chek::sort_check();
                try
                {
                    chek::print_check();
                }
                catch(char const* error)
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