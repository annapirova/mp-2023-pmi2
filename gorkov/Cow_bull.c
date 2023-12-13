#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#define MAX_NUMS 5

int main()
{
	srand(time(0));
	int n, i, l;
	printf("Enter len of number ");
	scanf_s("%d", &n);
	l = n;
	int a, c=0, ch[MAX_NUMS],pac[10], pos;
	for (i = 0; i < 10; i++) {
		pac[i] = -1;
	}
	for (i = 0; i < MAX_NUMS; i++) {
		ch[i] = -1;
	}

	for (i = 0; i < n; i++)
	{
		a = rand() % 10;
		c = 0;
		if ((i == 0) && (a == 0))a++;
		while (c == 0) {
			if (pac[a] == -1) { pac[a] = 1; ch[i] = a; c = 1; }
			else a = rand() % 10;
		}
		printf("%d", ch[i]);
	}
	
	
	printf("\nEnter a number of given len ");
	printf("\n");

	int vd, copy;
	scanf_s("%d", &vd);
	copy = vd;
	int r, bik = 0, cow = 0;
	while (copy != 0)
	{
		pos = l - 1;
		r = copy % 10;
		for (i = 0; i < n; i++) {
			if ((r == ch[i]) && (pos == i)) bik++;
			if ((r == ch[i]) && (pos != i)) cow++;
		}
		copy /= 10;
		l--;
	}
	printf("bik=%d cow=%d", bik, cow);

	return 0;
}
