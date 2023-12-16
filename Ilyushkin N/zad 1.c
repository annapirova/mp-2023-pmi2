#include <math.h>
#include <stdio.h>
int main() {
	double a, b, c, d, f, n, k;
	printf("write n and chislo");
	scanf_s("%d%d", &n, &f);
	d = 100000;
	b = 1;
	do
	{
		a = b * sin(1 / b);
		if (abs(a - f) <= d)
		{
			d = abs(a - f);
			break;
		}
		b++;

	} while (b = n + 1);
	printf("min size %d", d);
	if (a >= f)
	{
		k = d + f;
	}
	else { k = f - d; }
	printf("to samoe a %d", k);
}
