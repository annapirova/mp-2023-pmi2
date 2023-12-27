#include "stdio.h"
#include "math.h"
#include "time.h"
#include "stdbool.h"
void Quicksort(int a[],int l, int r)
{

	int mid = (l+r) / 2;
	for (int k = l;k < r;k++)
	{
	}
}
void Shellsort()
{

}
void Choicesort()
{

}
int Bubblesort(int a[],int l)
{
	int nonchanged;
	for (int o = 0; o < l; o++)
	{
		for (int i = 0; i < l - 1; i++)
		{
			if (a[i + 1] < a[i])
			{
				int tmp = a[i + 1];
				a[i + 1] = a[i];
				a[i] = tmp;
			}
			else
			{nonchanged ++;}
			if (a[l - i] < a[l - i - 1])
			{
				int tmp1 = a[l - i];
				a[l - i] = a[l-i-1];
				a[l - i - 1] = tmp1;
			}
			else
			{nonchanged ++;}
		}
		if (nonchanged >= l - 1)
		{break;}
	}
	printf_s("Result: ");
	for (int b = 0; b < l; b++)
	{
		printf_s("%d ",a[b]);
	}
	printf_s("\n");
	return 1;
}
void laws(int amg[],int l)
{
	double timex = 0.0;
	clock_t begin = clock();
	int amk = Bubblesort(amg, l);
	clock_t end = clock();
	timex += (double)(end - begin) / CLOCKS_PER_SEC;
	printf("Time elapsed %lfs", timex);
}
void Piramidesort()
{

}
int Insertsort(int a[],int s)
{
	int min = __INT32_MAX__;
	int minj;
	for (int i = 0;i < s;i++)
	{
		if (a[i] < min)
		{
			min = a[i];
			minj = i;
		}
	}
	for (int g = minj;g > 0;g--)
	{
		a[g] = a[g - 1];
	}
	a[0] = min;
	for (int o = 1;o < s;o++)
	{
		for (int r = o - 1;r >= 0; r--)
		{
			if (a[o] < a[r])
			{
				int ym = a[o];
				for (int slo = o; slo < r;slo--)
				{
					a[slo] = a[slo - 1];
				}
				a[r] = ym;
				break;
			}
		}
	}
	printf_s("Result: ");
	for (int b = 0; b < s; b++)
	{
		printf_s("%d ",a[b]);
	}
	printf_s("\n");
	return 1;

}
void laws1(int amg[],int l)
{
	double timex = 0.0;
	clock_t begin = clock();
	int amk = Insertsort(amg, l);
	clock_t end = clock();
	timex += (double)(end - begin) / CLOCKS_PER_SEC;
	printf("Time elapsed %lfs", timex);
}
int main()
{
	int answq;
	int array[20];
	printf_s("Fill your massive: \n");
	for (int i = 0; i < 20; i++)
	{
		scanf_s("%d", &array[i]);
	}
	printf("Which sort do you want to start\n");
	printf("1.Quick sort\n2.Shell's sort\n3.Choice sort\n4.Bubble sort\n5.Piramide sort\n6.Insert sort\n");
	scanf_s("%d", &answq);
	switch(answq)
	{
		case 1:
			break;
		case 2:
			Shellsort();
			break;
		case 3:
			Choicesort();
			break;
		case 4:
			int pg[20];
			for (int y = 0;y < 20;y++)
			{
				pg[y] = array[y];
			}
			laws(pg, 20);
			break;
		case 5:
			Piramidesort();
			break;
		case 6:
			int ps[20];
			for (int p = 0;p < 20;p++)
			{
				ps[p] = array[p];
			}
			laws1(ps,20);
			break;
		default:
			printf("There is no such a sort number!");
	}
}
