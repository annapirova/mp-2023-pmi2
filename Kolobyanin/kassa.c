#include <stdio.h>
#include <locale.h>
#include <time.h>
#include <stdlib.h>

int main()
{
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));
	int code[10] = { 8460,7376,2568,4320,9126 };
	int stoimost[10] = { 847,2366,316,3208,1617 };
	int count[10] = { 0 };
	int skidka[10];
	int i, n = 10, g, tovar = 0, k = 0;
	double sum = 0;
	for (i = 0;i < n;i++)
	{
		skidka[i] = 1 + rand() % 10;
	}
	printf("Выберете услугу\n");
	printf("1 - Артикулы товаров\n");
	printf("2 - Отсканируйте новый товар\n");
	printf("3 - Информация о выбранном товаре\n");
	printf("4 - Итоговый чек\n");
	do
	{
		scanf_s("%d", &g);
		switch (g)
		{
		case 1:
		{
			printf("Артикул товара  8460 - Шоколадный батончик Snickers\n");
			printf("Артикул товара  7376 - Печенье Oreo\n");
			printf("Артикул товара  2568 - Слоёная булочка с джемом\n");
			printf("Артикул товара  4320 - Газировка Coca Cola\n");
			printf("Артикул товара  9126 - Жвачка Dirol\n");
			printf("\nВыберете новую услугу\n");
			break;
		}
		case 2:
		{
			printf("\nВведите артикул интересуещего вас товара\n");
			scanf_s("%d", &tovar);
			for (i = 0;i < n;i++)
			{
				if (code[i] == tovar)
				{
					count[i]++;
					k++;
				}
			}
			if (k == 0)
				printf("Такого товара не существует\n");
			k = 0;
			printf("\nВыберете новую услугу\n");
			break;
		}
		case 3:
		{
			for (i = 0;i < n;i++)
			{
				if (code[i] == tovar)
				{
					printf("Стоимость без скидки - %d\n", stoimost[i]);
					printf("Скидка - %d\n", skidka[i]);
					printf("Стоимость со скидкой - %.2lf\n", (double)stoimost[i] * (1 - (double)skidka[i] / 100));
				}
			}
			printf("\nВыберете новую услугу\n");
			break;
		}
		case 4:
		{
			printf("Код товара Количество Скидка Стоимость\n");
			for (i = 0;i < n;i++)
			{
				if (count[i] != 0)
				{
					printf("   %d ", code[i]);
					printf("       %d ", count[i]);
					printf("        %d ", skidka[i]);
					printf("    %.2lf \n", (double)(stoimost[i] * (1 - (double)skidka[i] / 100)) * count[i]);
					sum += ((double)stoimost[i] * (1 - (double)skidka[i] / 100)) * count[i];
				}
			}
			printf("\n");
			printf("Итого %.2lf\n", sum);
			break;
		}
		default:
		{
			printf("Нет такой команды\n");
			printf("\nВыберете новую услугу\n");
			break;
		}
		}
	} while (g != 4);
	return 0;
}
