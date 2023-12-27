#include "stdio.h"
#include "math.h"

typedef double (*link)(double, int);
typedef double (*beg)(double);
double begash(double num)
{
	return num;
}
double linkash(double num, int n)
{
	return pow(-1,n)*((num*num*(2*n - 1)))/((2*n)*(2*n + 1));
}
double begexp(double num)
{
    return 1;
}
double nextexp(double num, int n)
{
    return (num / n);
}

double Tashtexp(double num, double accu, beg fish, link linkm, int it,double trueval)
{
	int n = 0;
	n++;
	double mn = fish(num);
	double sum = mn;
	double act = fabs(trueval - sum);
	while (act >= accu && n < it)
	{
		mn = mn * linkm(num, n);
		sum += mn;
		act = fabs(trueval - sum);
		n++;
	}
	return sum;
}
int nextp(double accu)
{
    int n = 0;
    while (accu != 1)
    {
        accu = accu*10;
        n++;
    }
    return n;
}
int main()
{
    int choice,iter;
    double num,accu;
    printf("Enter your x:");
    scanf(" %lf", &num);
    printf("\n");
    printf("Enter your accuracy:");
    scanf(" %lf", &accu);
    printf("\n");
    printf("Enter your choice:\n1.hyperbolical sinus\n2.exp\n");
    scanf(" %d", &choice);
    iter = nextp(accu);
    switch(choice)
    {
        case(1): printf("%.10f\n",Tashtexp(num,accu,begash,linkash,iter,asinh(num))); break;
        case(2): printf("%.10f\n",Tashtexp(num,accu,begexp,nextexp,iter,exp(num))); break;
        default: printf("No func available on this number"); break;
    }
}