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
}
void scan(int *tovar,int n,int tovari[], int count_tovarov[])
{
                printf("input tovar\n");
                int i, c=0;
                scanf("%d",tovar);
                printf("\n");
                for(i=0;i<n;i++)
                {
                    if(tovari[i]==*tovar)
                    {
                        count_tovarov[i]++;
                        c++;
                    }
                }
                if(c==0) printf("don't exist the tovar\n");
                c=0;
                printf("select new comand\n");

}
void inf(int *tovar,int n, int tovari[],int stoimost_tovara[],int skidki[])
{
                int i;
                if(*tovar==-1)
                {
                    printf("scan any tovar\n");
                }
                else
                {
                    for(i=0;i<n;i++)
                {
                    if(tovari[i]==*tovar)
                    {
                        printf("code - %d\n",tovari[i]);
                        printf("stoimost(bez skidki) - %d\n",stoimost_tovara[i]);
                        printf("skidka - %d\n",skidki[i]);
                        printf("stoimost(with skidka) - %.2lf\n",(double)stoimost_tovara[i]*(1-(double)skidki[i]/100));
                    }
                }
                }
                printf("select new comand\n");

}
void do_chek(int count_tovarov[],int n,int tovari[],int skidki[], int stoimost_tovara[],double *sum)
{
    int i;
    printf("Godlike chek:\n");
                printf("code tovara     count        skidka      stoimost\n");
                for(i=0;i<n;i++)
                {
                    if(count_tovarov[i]!=0)
                    {
                        printf("   %d           ",tovari[i]);
                        printf("%d            ",count_tovarov[i]);
                        printf("%d       ",skidki[i]);
                        printf("  %.2lf",(double)stoimost_tovara[i]*(1-(double)skidki[i]/100)*count_tovarov[i]);
                        printf("\n");
                        *sum+=(double)stoimost_tovara[i]*(1-(double)skidki[i]/100)*count_tovarov[i];

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
    int skidki[10], count_tovarov[10]={0}, i, n=10, k, tovar=-1, c=0;
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
                scan(&tovar, n, tovari, count_tovarov);
                break;
            }
            case 2:
            {
                inf(&tovar,n,tovari,stoimost_tovara,skidki);
                break;
            }
            case 3:
            {
                do_chek(count_tovarov,n,tovari,skidki,stoimost_tovara, &sum);
                break;
            }
            default:
            {
                printf("don't exist the comand\n");
                printf("select new comand\n");
                break;
            }

        }
        
    } while (k!=3);
    return 0;
}