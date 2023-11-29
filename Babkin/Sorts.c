#include "stdio.h"
#include "math.h"
#include "time.h"
void Quicksort(int a[],int l,int r)
{
	int med = round((l+r) / 2);
	int next = a[med];
}
void Shellsort()
{}
void Choicesort()
{}
void Bubblesort()
{}
void Piramidesort()
{}
void Insertsort()
{}
int main()
{
	int answq;
	int array[12] = {8,12,78,65,1,23,53,11,90,45,100,123};
	printf("Which sort do you want to start\n");
	printf("1.Quick sort\n2.Shell's sort\n3.Choice sort\n4.Bubble sort\n5.Piramide sort\n6.Insert sort\n");
	scanf_s("%d",&answq);
	switch (answq)
	{
	case 1:
		double timer = 0.0;
		clock_t begin = clock();
		Quicksort(array,0,12);
		clock_t end = clock();
		timer += (double)(end - begin) / CLOCKS_PER_SEC;
		printf("Time elapsed %lfs",timer);
		break;
	case 2:
		Shellsort();
		break;
	case 3:
		Choicesort();
		break;
	case 4:
		Bubblesort();
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
