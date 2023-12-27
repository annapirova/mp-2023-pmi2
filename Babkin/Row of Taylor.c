#include "stdio.h"
#include "math.h"

typedef (*link)(double, int);
typedef(*beg)(double);
double begash(double num)
{
	return num;
}
double linkash(double num, int n)
{
	return pow(-1,n)*(((2*n-1)/2*n) * (((2*n-1) * num*num) / (2*n + 1)));
}
double Tash(double num, double accu, beg begash, link linkash, int it,double trueval)
{
	int n = 0;
	n++;
	double mn = begash(num);
	double sum = mn;
	double act = fabs(trueval - sum);
	while (act > accu && n < it)
	{
		mn = mn * linkash(num, n);
		sum += mn;
		act = fabs(trueval - sum);
		n++;
	}
	return sum;
}











int main()
{

}