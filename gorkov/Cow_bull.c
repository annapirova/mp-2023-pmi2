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
	int a = 0, b, c, d, e, ch[MAX_NUMS], k, pos;
	while (a != 0) {
		a = rand() % 10;
	}
	b = rand() % 10;
	d = rand() % 10;
	c = rand() % 10;
	e = rand() % 10;
	while (b == a)
	{
		b = rand() % 10;
	}
	while ((c == a) || (c == b)) {
		c = rand() % 10;
	}
	while ((d == c) || (d == a) || (d == b))
	{
		d = rand() % 10;
	}
	while ((e == c) || (e == a) || (e == b) || (e == d))
	{
		e = rand() % 10;
	}
	ch[0] = e;
	ch[1] = d;
	ch[2] = c;
	ch[3] = b;
	ch[4] = a;

	for (i = 0; i < n; i++)
	{
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