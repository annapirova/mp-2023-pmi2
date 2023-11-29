#include "stdio.h"
#include "math.h"
#include "time.h"
void Quicksort()
{}
void Shellsort()
{}
void Choicesort()
{}
int Bubblesort(int a[],int l)
{
	int med = l / 2;
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
		}
	}
	printf_s("Result: ");
	for (int b = 0; b < l; b++)
	{
		printf_s("%d ",a[b]);
	}
	printf_s("\n");
	return a;
}
void laws(int amg[],int l)
{
	double timex = 0.0;
	clock_t begin = clock();
	int amk = Bubblesort(amg, 12);
	clock_t end = clock();
	timex += (double)(end - begin) / CLOCKS_PER_SEC;
	printf("Time elapsed %lfs", timex);
}
void Piramidesort()
{}
void Insertsort()
{}
int main()
{
	int answq;
	int array[12];
	for (int i = 0; i < 12; i++)
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
			laws(array, 12);
			break;
		case 5:
			Piramidesort();
			break;
		case 6:
			Insertsort();
			break;
		default:
			printf("There is no such a sort number!");
	}
}
