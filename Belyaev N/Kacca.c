#include "stdio.h"
#include "math.h"
#include "stdlib.h"
#include "malloc.h"




int func_show(int a[], char* b[], int c[], double d[], int length)
{
	for (int i = 0; i < length; i++)
	{
		printf("QR-Code: %d | ", a[i]);
		printf("Name: %s | ", b[i]);
		printf("Price: %d | ", c[i]);
		printf("Discount(percent): %.1f\n", d[i]);
	}
	return 0;
}

int func_scan(int current)
{
	printf("Enter QR-code of the product - ");
	scanf_s("%d", &current);
	return current;
}

void func_desc(int a[], char* b[], int c[], double d[], int current, int length)
{
	int check = 0;
	int pos;
	pos = 0;
	for (int i = 0; i < length; i++)
	{
		if (a[i] == current)
		{
			check = 1;
			pos = i;
		}
	}
	if (check == 0)
	{
		printf("QR-code does not exist\n");
	}
	else 
	{
		printf("QR-Code: %d | ", a[pos]);
		printf("Name: %s | ", b[pos]);
		printf("Price: %d | ", c[pos]);
		printf("Discount(percent): %.1f\n", d[pos]);
	}


}

void func_add(int a[], int current, int count)
{
	a[count] = current;
	printf("Product added to receipt\n");
}

void func_gen(int a[], char* b[], int c[], double d[], int e[], int count) // a - QR, b - Name, c - Price, d - Discount, e - Purchases
{
	int B[10] = { 0 };
	int C[10] = { 0 };
	int pos_A, pos_B, pos_C;
	double sum;
	int total; // total - без скидок, sum - к оплате || За все товары вместе
	total = 0; sum = 0;
	pos_A = pos_B = pos_C = 0;
	while (pos_A < count)
	{
		int k = 0;
		while ((k < pos_B) && (B[k] != e[pos_A])) k++;
		{
			if (k == pos_B)
			{
				B[pos_B] = e[pos_A];
				C[pos_B] = 1;
				pos_A++; pos_B++;
			}
			else
			{
				C[k]++; pos_A++;
			}
		}
	}
	for (int i = 0; i < count; i++)
	{
		for (int j = 0; j < count; j++)
		{
			if (B[i] == a[j])
			{
				printf("Product: %s - ", b[j]);
				printf("Price: %d - ", c[j]);
				printf("Amount: %d - ", C[i]);
				printf("Total: %d \n", c[j] * C[i]);
				total += c[j] * C[i];
				sum += (c[j] - (c[j]*(d[j]/100))) * C[i];
			}
		}
	}

	printf("Receipt:\n Total: %d\n Discount: %.1f\n To pay: %.1f\n", total, total - sum, sum);
 }

void func_error()
{
	printf("Operation not found\n");
}





int main()
{	
	int current, operation, count;
	int QR[] = { 3251, 5483, 3966, 2784, 3243, 2371}; // Штрихкоды товаров
	char* Name[] = { "T80BVM", "M1 Abrams", "Leopard 2A6", "Merkava mk.1", "Challenger 2", "Leclerc SXXI"}; // Наименование товаров
	int Price[] = { 37500, 40000, 27000, 30000, 33000, 29000 }; // Цена товаров
	double Discount[] = { 10, 25, 20, 15, 10, 15 }; // Скидка в процентах
	int* Purchases;
	Purchases = (int*)malloc(0 * sizeof(int));
	int length;
	length = sizeof(QR) / sizeof(QR[0]);
	operation = 0;
	current = 0;
	count = 0;
	printf("Operation list:\n 1. Show product list\n 2. Scan QR-code of a new product\n 3. Description of the scanned product\n 4. Add product details to the receipt\n 5. Generate a purchase receipt\n 6. Exit\n");
	do
	{
		printf("Enter number operation - ");
		scanf_s("%d", &operation);
		switch (operation)
		{
		case 1: func_show(QR, Name, Price, Discount, length); break;
		case 2: current = func_scan(current); break;
		case 3: func_desc(QR, Name, Price, Discount, current, length); break;
		case 4: func_add(Purchases, current, count); count++; break;
		case 5: func_gen(QR, Name, Price, Discount, Purchases, count); break;
		default: func_error(); break;
		}
	} while (operation != 6);
	return 0;
}
