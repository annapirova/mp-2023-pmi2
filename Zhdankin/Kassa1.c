#include <stdio.h>
#include <locale.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

void Menu()
{
	printf("hi, user, what do u want to do?\n");
	printf("1. add new product\n");
	printf("2. add a lot of product\n");
	printf("3. see description about last product\n");
	printf("4. see list of products\n");
	printf("5. go to check\n");
	
	
}

void Scan(int n, int products[], int *product, int count_products[])
{
	printf("type product ID:\n");
	scanf_s("%i", product);
	int i, count = 0;
	for (i = 0; i < n; i++)
	{
		if (products[i] == *product)
		{
			count_products[i]++;
			count++;
			break;
		}
	}
	
	if (count == 0)
	{
		printf("undefined ID\n");
	}
	count = 0;
	printf("select new command:\n");
}

void Discount(int n, int discount[], int discount_price[], int price[])
{
	for (int i = 0; i < n; i++)
	{
		discount[i] = 1 + rand() % 50;
		discount_price[i] = (price[i] - ((discount[i]/100.0) * price[i]));
	}

}

void Info(int *product, int n, int products[], int count_products[], int price[], char names[][20], int discount_price[], int discount[])
{
	if (*product == -1)
	{
		printf("scan product!\n");
	}

	for (int i = 0; i < n; i++)
	{
		if (products[i] == *product)
		{
			printf("price without discount: %i\n", price[i]);
			printf("name of product: %s\n", names[i]);
			printf("discount: %i proc\n", discount[i]);
			printf("price with discount: %i\n", discount_price[i]);
		}
	}
	printf("select new command:\n");
}

void List(int n, int products[], char names[][20])
{
	for (int j = 0; j < n; j++)
	{
		printf("%s (%i)", names[j], products[j]);
		printf("\n");
	}
	printf("select new command:\n");
}

void Amount(int n, int products[], int* product, int count_products[], int *amount)
{
	printf("type product Id:\n");
	scanf_s("%i", product);
	printf("type amount of product:\n");
	scanf_s("%i", amount);
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		if (products[i] == *product)
		{
			count_products[i] += *amount;
			count++;
			break;
		}
	}

	if (count == 0)
	{
		printf("undefined ID\n");
	}
	count = 0;

	printf("select new command:\n");
}

void Check(int n, int count_products[], int products[], char names[][20], int discount_price[], int sum)
{
	printf("Check is:\n");
	printf(" Name(ID)       count        price          sum\n");
	
	for (int i = 0; i < n; i++)
	{
		if (count_products[i] != 0)
		{
			printf("%s (%i)      %i           %i           %i \n", names[i], products[i], count_products[i], discount_price[i], discount_price[i]*count_products[i]);
			sum += discount_price[i] * count_products[i];
			printf("\n");
		}
	}
	printf("\n");
	printf("check sum: %i", sum);
}

int main()
{
	srand(time(NULL));
	int products[10] = { 1395, 5678, 4098, 4954, 3406, 5272, 9657, 1457, 6634, 5741 };
	int price[10] = { 493, 887, 398, 14, 316, 72, 851, 137, 66, 574 };
	char names[10][20] = { "apple", "banana", "carrot", "cabbage", "wine", "orange", "Coca-cola", "Twix", "cocoa", "coffee" };
	int discount[10];
	int discount_price[10] = { 0 };
	int count_products[10] = { 0 };
	int k, amount = 0, sum = 0, n = 10, product = -1;

	Discount(n, discount, discount_price, price);
	Menu();

	do
	{
		scanf_s("%i", &k);
		switch (k)
		{
		case 1:
		{
			Scan(n, products, &product, count_products);
			break;
		}
		
		case 2:
		{
			Amount(n, products, &product, count_products, &amount);
			break;
		}


		case 3:
		{
			Info(&product, n, products, count_products, price, names, discount_price, discount);
			break;
		}
		
		case 4:
		{
			List(n, products, names);
			break;
		}

		case 5:
		{
			Check(n, count_products, products, names, discount_price, sum);
			break;
		}

		default:
			printf("type another number\n");
			break;
		}
	} while (k != 5);

	return 0;
}
	