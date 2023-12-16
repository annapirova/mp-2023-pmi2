#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
int maisdn()
{
	int N, a, b, c; 
	srand(time(NULL)); 
	b = 0;
	N = rand() % 1000;
	c = 0;
	while (c!=20)
	{
		printf("vedite chislo\n");
		scanf_s("%d", &a);
		if (a == N)
		{
			b++;
			printf("vi ugadali zadannoe chislo %d\n", a);
			printf("kol vo popitok %d", b);
			c = 20;
		}
		else
		{
			if (a > N) {
				printf("iskomoe chislo menshe\n");
				b++;
			}
			else {
				printf("iskomoe chislo bolshe\n");
				b++;
			}




		}
	}
		

	return 0;

	}

		


	


	//switch (N)
	//{
	//case'>a': printf("iskomoe chislo menshe");
	//	b++; break;
	//case'<a': printf("iskomoe chislo bolshe");
	//	b++; break;
	//default: b++;
	//	printf("vi ugadali zadannoe chislo %d", a);
	//	printf("kol vo popitok %d", b);









