#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

struct Product
{
	char name[50];
	int ID;
	int price;
};

void Menu()
{
	printf("hi, user, what do u want to do?\n");
	printf("1. add new product\n");
	printf("2. print scanning products\n");
	printf("3. see description about last product\n");
	printf("4. see list of products\n");
	printf("5. go to check\n");
}

void Scan(int n, struct Product products[], int* product, struct Product not_uniq_products[], int* num)
{
	printf("type product ID:\n");
	scanf_s("%i", product);
	int found = 0;
	for (int i = 0; i < n; i++)
	{
		if (products[i].ID == *product)
		{
			found = 1;
			int is_unique = 1;
			if (is_unique)
			{
				not_uniq_products[(*num)++] = products[i];
			}
			break;
		}
	}

	if (found != 1)
	{
		printf("undefined ID\n");
	}
	printf("select new command:\n");
}

void Print(struct Product not_uniq_products[], int num)
{
	for (int i = 0; i < num; i++)
	{
		printf("%s(%i) ", not_uniq_products[i].name, not_uniq_products[i].ID);
	}
	printf("\n");
	printf("select new command:\n");
}

void Info(struct Product not_uniq_products[], int num, int* product, struct Product products[])
{
	if (*product == -1)
	{
		printf("scan product!\n");
		return;
	}

	for (int i = 0; i < num; i++)
	{
		if (not_uniq_products[i].ID == *product)
		{
			printf("name of product: %s\n", not_uniq_products[i].name);
			printf("ID of product: %i\n", not_uniq_products[i].ID);
			printf("price without discount: %i\n", not_uniq_products[i].price);
			break;
		}
	}
	printf("select new command:\n");
}

void List(int n, struct Product products[])
{
	for (int j = 0; j < n; j++)
	{
		printf("%s(%i)", products[j].name, products[j].ID);
		printf("\n");
	}
	printf("select new command:\n");
}

void SortCheck(struct Product uniq_products[], int count[], int num)
{
	for (int i = 0; i < num - 1; i++)
	{
		for (int j = 0; j < num - i - 1; j++)
		{
			if (uniq_products[j].price > uniq_products[j + 1].price)
			{
				struct Product temp_product = uniq_products[j];
				uniq_products[j] = uniq_products[j + 1];
				uniq_products[j + 1] = temp_product;

				int temp_count = count[j];
				count[j] = count[j + 1];
				count[j + 1] = temp_count;
			}
		}
	}
}

void Check(int num, struct Product not_uniq_products[], struct Product uniq_products[], int count[], int sum)
{
	int posA = 0, posB = 0;
	while (posA < num)
	{
		int m = 0;
		while ((m < posB) && (uniq_products[m].ID != not_uniq_products[posA].ID)) m++;
		{
			if (m == posB)
			{
				uniq_products[posB] = not_uniq_products[posA];
				count[posB] = 1;
				posA++; posB++;
			}
			else
			{
				count[m]++; posA++;
			}
		}
	}

	SortCheck(uniq_products, count, posB);

	printf("Check is:\n");
	printf(" Name(ID)       count        price          sum\n");

	for (int i = 0; i < posB; i++)
	{
		if (count[i] != 0)
		{
			printf("%s(%i)         %i              %i             %i \n", uniq_products[i].name, uniq_products[i].ID, count[i], uniq_products[i].price, uniq_products[i].price * count[i]);
			sum += uniq_products[i].price * count[i];
		}
	}
	printf("\n");
	printf("check sum: %i", sum);
}

int main()
{
	srand((unsigned int)time(NULL));
	int k;
	struct Product products[10] = { {"apple",1395,100}, {"carrot",5678,200}, {"potato",4098,300}, {"cabbage",4954,400}, {"onion",3406,500}, {"corn",5272,600}, {"strawberry",9657,700}, {"rice",1457,800}, {"milk",6634,900}, {"avocado",5741,1000} };
	struct Product not_uniq_products[100] = { 0 };
	struct Product uniq_products[100] = { 0 };
	int count[100] = { 0 };
	int amount = 0, sum = 0, n = 10, product = -1;
	int num = 0;


	Menu();

	do
	{
		scanf_s("%i", &k);
		switch (k)
		{
		case 1:
		{
			Scan(n, products, &product, not_uniq_products, &num);
			break;
		}

		case 2:
		{
			Print(not_uniq_products, num);
			break;
		}

		case 3:
		{
			Info(not_uniq_products, num, &product, products);
			break;
		}

		case 4:
		{
			List(n, products);
			break;
		}

		case 5:
		{
			Check(num, not_uniq_products, uniq_products, count, sum);
			break;
		}

		default:
			printf("type another number\n");
			break;
		}
	} while (k != 5);

	return 0;
}
