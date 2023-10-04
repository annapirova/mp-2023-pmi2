#include<stdio.h>
void main()
{
	int n;
	int l = 1, r = 1000, m;
	char c ='!';
	int count = 0;
	scanf_s("%i", &n);
	while (c != '=')
	{
		count++;
		m = (l + r) / 2;
		printf("m = %i?\n", m);
		c = getchar();
		c = getchar();
		if (c == '=')continue;
		else
			if (c == '>')
			{
				l = m;
			}
			else
			{
				r = m;
			}
	}
	printf("m=%i\n", m);
	printf("cont = %i", count);
}