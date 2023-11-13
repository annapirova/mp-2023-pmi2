#include <stdio.h>
#include <math.h>
#include <locale.h>
#include <stdlib.h> 
#include <stdbool.h>
//Ассортимент товаров :
// [0] - Сэндвич
// [1] - Пончик в глазури
// [2] - Пирожок с клубникой
// [3] - Торт Наполеон
// [4] - Чизкейк лавандовый

int sh[5] = { 2371, 8552, 9673, 4564, 1375 };
int cost[5] = {99, 49, 79, 399, 239};
double discount[5] = { 1.0, 1.0, 1.0, 1.30, 1.10 };
int kol[5] = { 0 };
double final_cost[5] = {0};
int product;
void commands()
{
	printf("1 - вывести информацию о товарах\n");
	printf("2 - добавить товар в чек\n");
	printf("3 - сформировать чек\n");
	printf("4 - закончить работу\n");
	printf("\n");
	printf("Введи новую команду)\n");
}
void assortment()
{
	printf("[1] - Сэндвич\n");
	printf("Цена - ""%d\n", cost[0]);
	printf("Штрих-код - ""%d\n", sh[0]);
	printf("Скидка - ""%lf\n", discount[0]);
	printf("\n");
	printf("[2] - Пончик в глазури\n");
	printf("Цена - ""%d\n", cost[1]);
	printf("Штрих-код - ""%d\n", sh[1]);
	printf("Скидка - ""%lf\n", discount[1]);
	printf("\n");
	printf("[3] - Пирожок с клубникой\n");
	printf("Цена - ""%d\n", cost[2]);
	printf("Штрих-код - ""%d\n", sh[2]);
	printf("Скидка - ""%lf\n", discount[2]);
	printf("\n");
	printf("[4] - Торт Наполеон\n");
	printf("Цена - ""%d\n", cost[3]);
	printf("Штрих-код - ""%d\n", sh[3]);
	printf("Скидка - ""%lf\n", discount[3]);
	printf("\n");
	printf("[5] - Чизкейк лавандовый\n");
	printf("Цена - ""%d\n", cost[4]);
	printf("Штрих-код - ""%d\n", sh[4]);
	printf("Скидка - ""%lf\n", discount[4]);
	printf("\n");
	printf("Введи новую команду)\n");
}
void scan(int product, int sh[], double discount[], int kol[], double final_cost[])
{
	printf("Введите штрих-код товара\n");
	scanf_s("%d", &product);
	for (int i = 0; i < 5; i++)
	{
		if (product == sh[i])
		{
			kol[i]++;
			final_cost[i] = cost[i] * discount[i];

			if (i == 0)
			{
				printf("Отсканировано: Сэндвич\n");
				printf("Цена без скидки:" "%d\n", cost[0]);
				printf("Цена со скидкой:" "%lf\n", final_cost[0]);
			}
			if ((product == sh[i]) && (i == 1))
			{
				printf("Отсканировано: Пончик в глазури\n");
				printf("Цена без скидки:" "%d\n", cost[1]);
				printf("Цена со скидкой:" "%lf\n", final_cost[1]);
			}
			if ((product == sh[i]) && (i == 2))
			{
				printf("Отсканировано: Пирожок с клубникой\n");
				printf("Цена без скидки:" "%d\n", cost[2]);
				printf("Цена со скидкой:" "%lf\n", final_cost[2]);
			}
			if ((product == sh[i]) && (i == 3))
			{
				printf("Отсканировано: Торт Наполеон\n");
				printf("Цена без скидки:" "%d\n", cost[3]);
				printf("Цена со скидкой:" "%lf\n", final_cost[3]);
			}
			if ((product == sh[i]) && (i == 4))
			{
				printf("Отсканировано: Чизкейк лавандовый\n");
				printf("Цена без скидки:" "%d\n", cost[4]);
				printf("Цена со скидкой:" "%lf\n", final_cost[4]);
			}
		}
		else
		{
			printf("Товар с таким штрих-кодом не в наличии :(\n");
		}
	}
	printf("\n");
	printf("Введи новую команду)\n");
}
void paycheck(int kol[], double final_cost[],double sum)
{
	printf("Итоговый чек:\n");
	for (int i = 0; i < 5; i++)
	{
		if (kol[i]!=0)
		{
			if (i == 0)
			{
				final_cost[i] *= kol[i];
				printf(" Сэндвич - ""%d" "шт. - ""%lf " "руб.\n",kol[i],final_cost[i]);
				
			}
			if (i == 1)
			{
				final_cost[i] *= kol[i];
				printf(" Пончик в глазури - ""%d" "шт. - ""%lf ""руб.\n", kol[i], final_cost[i]);
			}
			if (i == 2)
			{
				final_cost[i] *= kol[i];
				printf(" Пирожок с клубникой - ""%d" "шт. - ""%lf ""руб.\n", kol[i], final_cost[i]);
			}
			if (i == 3)
			{
				final_cost[i] *= kol[i];
				printf(" Торт Наполеон - ""%d" "шт. - ""%lf ""руб.\n", kol[i], final_cost[i]);
			}
			if (i == 4)
			{
				final_cost[i] *= kol[i]; 
				printf(" Чизкейк лавандовый - ""%d" "шт. - ""%lf ""руб.\n", kol[i], final_cost[i]);
			}
			sum += final_cost[i];
		}
		
	}
	printf("Итоговая сумма покупки - "  "%lf"" руб.\n", sum);
	printf("\n");
	printf("Введи новую команду)\n");
}
int main()
{
	int choice;
	double sum = 0.0;
	bool run = true;
	setlocale(LC_CTYPE, "Russian");
	printf(" Добро пожаловать в нашу пекарню! :3\n");
	printf(" Чем я могу вам помочь?\n");
	commands();

	while (run)
	{
		scanf_s("%d", &choice);
		switch (choice)
		{
		case 1: 
		{	assortment();
			break; }
		case 2: 
		{	scan(&product, sh, discount, kol, final_cost);
			break; }
		case 3: 
		{	paycheck(kol, final_cost, sum);
			break; }
		case 4: 
		{	printf("Всего доброго, заходите к нам еще! <3\n");
			run = false;
			break; }
		default:
		{
			printf("Солнце, операция не поддерживается :(\n");
			printf("Попробуй другую!\n");
			break;
		}
		}
	}
	return 0;
}
