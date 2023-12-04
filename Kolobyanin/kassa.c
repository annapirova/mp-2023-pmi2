#include <stdio.h>
#include <locale.h>
#include <time.h>
#include <stdlib.h>

void command()
{
	printf("Choose a service\n");
	printf("1 - Articles products\n");
	printf("2 - Scan the new product\n");
	printf("3 - Information about the selected product\n");
	printf("4 - Final receipt\n");
}

void art()
{
	printf("Article  8460 - Snickers Chocolate Bar\n");
	printf("Article  7376 - Oreo Cookies\n");
	printf("Article  2568 - Bun with jam\n");
	printf("Article  4320 - Coca Cola soda\n");
	printf("Article  9126 - Dirol Gum\n");
	printf("\nChoose a new service\n");
}

void scan(int n, int* tovar , int code[], int count[], int check[], int* a, int* b)
{
	int i, k = 0, f = 0;
	printf("\nEnter the article number of the product you are interested in\n");
	scanf_s("%d", tovar);
	for (i = 0;i < n;i++)
	{
		if (code[i] == *tovar)
		{
			*b = i;
			count[i]++;
			for (i = 0;i < 100;i++)
			{
				if (check[i] == *tovar)
					f++;
			}
			if (f == 0)
			{
				check[*a] = *tovar;
				(*a)++;
			}
			k++;
			break;
		}
	}
	if (k == 0)
		printf("Error\n");
	k = 0;
	printf("\nChoose a new service\n");
}

void inf(int n, int* tovar ,int code[], int stoimost[], int skidka[])
{
	int i;
	for (i = 0;i < n;i++)
	{
		if (code[i] == *tovar)
		{
			printf("Cost without discount - %d\n", stoimost[i]);
			printf("Discount - %d\n", skidka[i]);
			printf("Discounted price - %.2lf\n", (double)stoimost[i] * (1 - (double)skidka[i] / 100));
		}
	}
	printf("\nChoose a new service\n");
}

void chek(int n, int code[], int stoimost[], int skidka[], int count[], double sum, int check[])
{
	int i,j;
	printf("Article Quantity Discount  Cost\n");
	for (i = 0; check[i]!=0 ;i++)
	{
		for (j = 0;j < n;j++)
		{
			if (code[j] == check[i])
				break;
		}
		if(count[j]!=0)
		{
			printf(" %d ", code[j]);
			printf("     %d ", count[j]);
			printf("       %d ", skidka[j]);
			printf("   % .2lf \n", (double)(stoimost[j] * (1 - (double)skidka[j] / 100)) * count[j]);
			sum += ((double)stoimost[j] * (1 - (double)skidka[j] / 100)) * count[j];
		}
	}
	printf("\n");
	printf("Итого %.2lf\n", sum);
}

int main()
{
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));
	int code[10] = { 8460,7376,2568,4320,9126 };
	int stoimost[10] = { 847,2366,316,3208,1617 };
	int count[10] = { 0 };
	int skidka[10];
	int i, n = 10, g, tovar = 0, k = 0;
	double sum = 0;
	int check[100] = { 0 };
	int a = 0,  b = -1;
	for (i = 0;i < n;i++)
	{
		skidka[i] = 1 + rand() % 10;
	}
	command();
	do
	{
		scanf_s("%d", &g);
		switch (g)
		{
		case 1:
		{
			art();
			break;
		}
		case 2:
		{
			scan(n, &tovar, code, count, check, &a, &b);
			break;
		}
		case 3:
		{
			inf(n, &tovar ,code, stoimost, skidka);
			break;
		}
		case 4:
		{
			chek(n, code, stoimost, skidka, count, sum, check);
			break;
		}
		default:
		{
			printf("There is no such command\n");
			printf("\nChoose a new service\n");
			break;
		}
		}
	} while (g != 4);
	return 0;
}
