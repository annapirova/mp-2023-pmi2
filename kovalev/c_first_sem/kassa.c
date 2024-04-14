#include "stdio.h"
#include "locale.h"
#include "time.h"
#include "stdlib.h"
#include "math.h"
void spisok_uslug()
{
    printf("Godlike senior what you want?\n");
    printf("1 - scan new tovar\n");
    printf("2 - see information about last scan tovarv\n");
    printf("3 - do chek\n");
    printf("4 - sort chek\n");
    printf("5 - close the program\n");

}
void scan(int n,int tovari[], int count_tovarov[], int chek[],int *z, int *zxc)
{
                printf("input tovar\n");
                int i, c=0, flag=0,  tovar;
                scanf("%d",&tovar);
                printf("\n");
                for(i=0;i<n;i++)
                {
                    if(tovari[i]==tovar)
                    {
                        *zxc=i;
                        count_tovarov[i]++;
                        for(i=0;i<100;i++)
                        if (chek[i]==tovar) flag++;
                        if(flag==0)
                        {
                        chek[*z]=tovar;
                        (*z)++;
                        }
                        c++;
                        break;
                    }
                }
                if(c==0) printf("don't exist the tovar\n");
                c=0;
                printf("select new comand\n");
}
void inf( int tovari[],int stoimost_tovara[],int skidki[],int zxc)
{
                if(zxc==-1)
                {
                    printf("scan any tovar\n");
                }
                else
                {

                        printf("code - %d\n",tovari[zxc]);
                        printf("stoimost(bez skidki) - %d\n",stoimost_tovara[zxc]);
                        printf("skidka - %d\n",skidki[zxc]);
                        printf("stoimost(with skidka) - %.2lf\n",(double)stoimost_tovara[zxc]*(1-(double)skidki[zxc]/100));
                }
                printf("select new comand\n");

}
void do_chek(int count_tovarov[],int n,int tovari[],int skidki[], int stoimost_tovara[],double *sum, int chek[])
{
    int k,j;
    printf("Godlike chek:\n");
                printf("code tovara     count        skidka      stoimost\n");
                for(j=0;chek[j]!=0;j++)
                {
                    for(k=0;k<n;k++)
                    {
                        if(tovari[k]== chek[j]) break;
                    }
                    if(count_tovarov[k]!=0)
                    {
                        printf("   %d           ",tovari[k]);
                        printf("%d            ",count_tovarov[k]);
                        printf("%d       ",skidki[k]);
                        printf("  %.2lf",(double)stoimost_tovara[k]*(1-(double)skidki[k]/100)*count_tovarov[k]);
                        printf("\n");
                        *sum+=(double)stoimost_tovara[k]*(1-(double)skidki[k]/100)*count_tovarov[k];

                    }
                }
                printf("\n");
                printf("   ITOGO                                 %.2lf",*sum);
                printf("\n");

}
int main()
{
    srand(time(NULL));
    int tovari[10]={4673,4756,8973,3542,3453,5690,6782,8436,2354,7613};
    int skidki[10], count_tovarov[10]={0}, i, n=10, k, tovar=-1, c=0,z=0, chek[100]={0},zxc=-1;
    double sum=0;
    int stoimost_tovara[10]={2344,125,645,3467,744,4577,353,100,213,865};
    for(i=0;i<n;i++)
    {
        skidki[i]=1+rand()%50;
    }
    printf("/////Supper pupper pyterochka/////\n");
    printf("Kassir Alexey I\n");
    spisok_uslug();
    do
    {
        scanf("%d",&k);
        switch(k)
        {
            case 1:
            {
                scan(n, tovari, count_tovarov, chek, &z, &zxc);
                break;
            }
            case 2:
            {
                inf(tovari,stoimost_tovara,skidki, zxc);
                break;
            }
            case 3:
            {
                do_chek(count_tovarov,n,tovari,skidki,stoimost_tovara, &sum,chek);
                sum=0;
                break;
            }
            case 4:
            {
                    int sort_chek[100];
                    int p,q,d;
                    for(d=0;d<100;d++)
                    {
                        sort_chek[d]=chek[d];
                    }

                    for(p=0;sort_chek[p+1]!=0;p++)
                    {
                        for(q=p+1;sort_chek[q]!=0;q++)
                        {
                            int t,s,v;
                            for(v=0;v<n;v++)
                            {
                                if(tovari[v]==sort_chek[p]) t=v;
                                if(tovari[v]==sort_chek[q]) s=v;
                            }
                            if(((double)stoimost_tovara[t]*(1-(double)skidki[t]/100)*count_tovarov[t])<((double)stoimost_tovara[s]*(1-(double)skidki[s]/100)*count_tovarov[s]))
                            {int tmp=sort_chek[p];
                            sort_chek[p]=sort_chek[q];
                            sort_chek[q]=tmp;
                            }

                        }
                    }
                    do_chek(count_tovarov,n,tovari,skidki,stoimost_tovara, &sum,sort_chek);
                    sum=0;
                    break;
            }
            default:
            {
                if(k!=5)
                {
                printf("don't exist the comand\n");
                printf("select new comand\n");
                }
                break;
            }

        }
        
    } while (k!=5);
    return 0;
}