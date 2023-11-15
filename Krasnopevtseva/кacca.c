#include <stdio.h>
#include <math.h>
#include <locale.h>
#include <stdlib.h> 
#include <stdbool.h>
#include "string.h"
//Ассортимент товаров :
// [0] - Сэндвич
// [1] - Пончик в глазури
// [2] - Пирожок с клубникой
// [3] - Торт Наполеон
// [4] - Чизкейк лавандовый
char names[5][30];
int sh[5] = { 2371, 8552, 9673, 4564, 1375 };
int cost[5] = { 99, 49, 79, 399, 239 };
double discount[5] = { 1.0, 1.0, 1.0, 1.30, 1.10 };
int kol[5] = { 0 };
double final_cost[5] = { 0 };
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
	int i;
	for (i = 0; i < 5; i++)
	{
		printf("%s\n", names[i]);
		printf("Цена - ""%d\n", cost[i]);
		printf("Штрих-код - ""%d\n", sh[i]);
		printf("Скидка - ""%lf\n", discount[i]);
		printf("\n");
	}
	printf("\n");
	printf("Введи новую команду)\n");
}
void scan(int product, int sh[], double discount[], int kol[], double final_cost[])
{
	printf("Введите штрих-код товара\n");
	scanf_s("%d", &product);
	bool s = false;
	for (int i = 0; i < 5; i++)
	{
		if (product == sh[i])
		{
			s = true;
			kol[i]++;
			final_cost[i] = cost[i] * discount[i];
			printf("Отсканировано:" "%s\n",names[i]);
			printf("Цена без скидки:" "%d\n", cost[i]);
			printf("Цена со скидкой:" "%lf\n", final_cost[i]);
		}
	}
	if (!s)
	{
		printf("Товар с таким штрих-кодом не в наличии :(\n");
	}
	printf("\n");
	printf("Введи новую команду)\n");
}
void paycheck(int kol[], double final_cost[], double sum)
{
	printf("Итоговый чек:\n");
	for (int i = 0; i < 5; i++)
	{
		if (kol[i] != 0)
		{
			for (i = 0; i < 5; i++)
			{
				final_cost[i] *= kol[i];
				printf("%s"" -" "%d" "шт. - ""%lf " "руб.\n",names[i], kol[i], final_cost[i]);
				sum += final_cost[i];
			}
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
	strcpy_s(names[0],8, "Сэндвич");
	strcpy_s(names[1], 17, "Пончик в глазури");
	strcpy_s(names[2], 20, "Пирожок с клубникой");
	strcpy_s(names[3], 14, "Торт Наполеон");
	strcpy_s(names[4], 19, "Чизкейк лавандовый");
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
