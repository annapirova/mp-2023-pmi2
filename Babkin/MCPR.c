#include "stdio.h"
#include "string.h"
#include "stdlib.h"
typedef struct e {
	char name[20];
	int strchcode;
	double price;
	double discount;
} masc;
int main()
{
	FILE* f;
	f = fopen_s("TXAN.txt", "w",);
	if (f == NULL)
	{
		int n = 1;
		printf_s("If you want to type more products press 1\n");
		while (n == 1)
		{
			char* smth;
			smth = (char)malloc(sizeof(char) * 100);
			scanf_s("%c", smth);
			strchr(smth, " ");
			free(smth);
		}
	}
}