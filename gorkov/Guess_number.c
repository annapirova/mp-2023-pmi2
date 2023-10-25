//угадай число Вар1
#include "stdio.h"
#include "time.h"
#include "stdlib.h"
int main()
{
	srand(time(0));
	int b, n, a = rand() % 1000;
	printf("enter a number");
	printf("%d", a);
	n = 1;
	while (1)
	{
		scanf_s("%d", &b);
		if (a != b) {
			if (a > b)
			{
				printf("bigger ");
			}
			else printf("smaller");
		}
		else break;
		n++;
	}
	printf("%d attemps number=%d", n, a);
	return 0;
}