#include "stdio.h"
#include "trian_gh.h"
using namespace std;
int main()
{
	int choice;
	trian_gh g(10, 4, 5);
	double x = g.S();
	double y = g.p();
	printf("Choose an option to know about Perimeter(1) or Area(2)");
	printf("\n");
	scanf("%d",&choice);
	printf("\n");
	switch (choice)
	{
		case(1): printf("%d\n",y);
		case(2): printf("%d\n",x);
		default: printf("sorry no matches to your search");
	}
}
