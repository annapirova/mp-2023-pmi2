#define pi 3.1415926535
#include "stdio.h"
#include "math.h"
//sin cos exp Обратный гиперболический синус - arsh(x)
void spisok()
{
    printf("1-input x\n2-pogreshnost\n3-N_MAX\n4-sin\n5-cos\n6-exp\n7-arsh\n8-close the program\n");
}
double input_x()
{   double d;
printf("enter x=");
    scanf("%lf",&d);
    return d;
}
double input_pogreshnost()
{   double d;
printf("enter pogreshnost=");
    scanf("%lf",&d);
    return d;
}
int input_N_MAX()
{   int d;
printf("enter N_MAX=");
    scanf("%d",&d);
    return d;
}
double first_arsh_sin(double x)
{
    return x;
}
double first_cos_e(double x)
{
    return 1;
}
double next_cos(double x, int n)
{
	return (-x * x / (2*n-1) / (2 * n));
}

double next_sin(double x, int n)
{
	return (-x*x / (2*n) / (2 * n + 1));
}

double next_exp(double x, int n)
{

	return (x / n);
}
double next_arsh(double x, int n)
{
    return ((-1)*x*x*(2*n-1)/(2*n)/(2*n+1)*(2*(n-1)+1));
}
typedef double(*next_type)(double,int);
typedef double(*first_type)(double);
void get_sum(double x,double pogreshnost,int N_MAX, first_type first, next_type next, double real)
{
    int n=1;
    double elem=first(x), sum=first(x);
    while((fabs(real-sum)>pogreshnost)&&(N_MAX>n))
    {
        elem=elem*next(x,n);
        sum+=elem;
        n++;
    }
    printf("to chto polychiloc'=%lf\n",sum);
    printf("real znach=%lf\n",real);
    printf("pogreshnost'=%lf\n",fabs(real-sum));
    printf("count member=%d\n",n);
}
double diap(double x)
{
    int k=x/(2*pi);
    return x-k*2*pi;
}
int main()
{
    double x=0, pogreshnost=1e-4;
    int N_MAX=17, key;
    spisok();
    printf("std settings:x=0.00, N_MAX=17,pogreshnost=1e-4\n");
    do
    {
        printf("\nchoose command\n");
        scanf("%d", &key);
        switch (key)
        {
        case 1: x=input_x(); break;
        case 2: pogreshnost=input_pogreshnost(); break;
        case 3: N_MAX=input_N_MAX(); break;
        case 4: get_sum(diap(x),pogreshnost,N_MAX,first_arsh_sin,next_sin,sin(x)); break;
        case 5: get_sum(diap(x),pogreshnost,N_MAX,first_cos_e,next_cos,cos(x)); break;
        case 6: get_sum(x,pogreshnost,N_MAX,first_cos_e,next_exp,exp(x)); break;
        case 7:// ot -1 do 1!!!!!!
        if(x<1 && x>-1) get_sum(x,pogreshnost,N_MAX,first_arsh_sin,next_arsh,asinh(x));
        else printf("ERROR"); break;
        case 8: printf("Thank's for your attention!\n"); break;
        default:printf("ERROR"); break;
        }
    } while (key!=8);
    return 0;
}