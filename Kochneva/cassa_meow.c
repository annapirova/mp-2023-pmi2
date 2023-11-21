#include <stdio.h>
#include <locale.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>

void startup_menu()		// Функция startup_menu выводит меню
{
	printf("What function do you need?\n");
	printf("1 - scan product\n");
	printf("2 - see view_info about last scan\n");
	printf("3 - close bill\n");
}

void scan(int* product, int n, int arr_product[], int arr_count_pr[]) // Функция scan заполняет массив product количеством товаров
{
	printf("input product\n");
	int i, c = 0;
	scanf_s("%d", product);		// Ввод номера товара
	printf("\n");
	for (i = 0; i < n; i++) {	// Проверка наличия товара
		if (arr_product[i] == *product) {
			arr_count_pr[i]++;
			c++;
		}
	}
	if (c == 0)
		printf("no such code in store\n");	// если код не найден
	c = 0;
	printf("select new command\n"); // если код найден

}
void view_info(int* product, int n, int arr_product[], int arr_product_cost[], int arr_discount[]) // Функция view_info выводит информацию о товаре
{
	int i;
	if (*product == -1)
		printf("scan any product\n");
	else
		for (i = 0; i < n; i++) {
			if (arr_product[i] == *product) {
				printf("code - %d\n", arr_product[i]);
				printf("cost(without discount) - %d\n", arr_product_cost[i]);
				printf("discount - %d\n", arr_discount[i]);
				printf("cost(with discount) - %.2lf\n", (double)arr_product_cost[i] * (1 - (double)arr_discount[i] / 100)); 
			}
		}
	printf("input new comand\n");

}
void close_bill(int arr_count_pr[], int n, int arr_product[], int arr_discount[], int arr_product_cost[], double* sum) // Функция close_bill выводит итоговую сумму с учетом скидки и закрывает чек
{
	int i;
	printf("bill:\n");
	printf("product code \tcount\t\tdiscount\tcost\n");
	for (i = 0; i < n; i++) {
		if (arr_count_pr[i] != 0) {
			printf("\t%d\t\t\t", arr_product[i]);
			printf("%d\t\t\t", arr_count_pr[i]);
			printf("  %d\t\t", arr_discount[i]);
			printf("%.2lf", (double)arr_product_cost[i] * (1 - (double)arr_discount[i] / 100) * arr_count_pr[i]);
			printf("\n");
			*sum += (double)arr_product_cost[i] * (1 - (double)arr_discount[i] / 100) * arr_count_pr[i];
		}
	}
	printf("\n");
	printf("   RESULT\t\t\t\t\t\t\t\t%.2lf", *sum);
	printf("\n");
}

int main() // Главная функция
{
	srand(time(NULL));
	int arr_product[10] = { 1111, 2222, 3333, 4444, 5555, 6666, 7777, 8888, 9999, 1234 }; // массив кодов товаров
	int arr_discount[10], arr_count_pr[10] = { 0 }, i, n = 10, k, product = -1, c = 0;
	double sum = 0;
	int arr_product_cost[10] = { 10, 20, 65, 58, 74, 120, 374, 71, 103, 512 }; // массив стоимостей товаров

	for (i = 0; i < n; i++)
		arr_discount[i] = 1 + rand() % 50; // рандомная скидка от 1 до 50%

	printf("|||||IBMeow cash termina|||||\n");
	printf("Shift 1\n");
	startup_menu(); // вывод главного меню
	do {
		scanf_s("%d", &k); // ввод команды 
                switch (k) {	// switch case для выбора команды
                case 1: // если ввели 1
		{
			scan(&product, n, arr_product, arr_count_pr); // вызов функции scan
			break;
		}
		case 2: // если ввели 2
		{
			view_info(&product, n, arr_product, arr_product_cost, arr_discount); // вызов функции view_info
			break;
		}
		case 3: // если ввели 3
		{
			close_bill(arr_count_pr, n, arr_product, arr_discount, arr_product_cost, &sum); // вызов функции close_bill
			break;
		}
		default: // обработка ошибок
		{
			printf("Unknown command\n");
			printf("Input new command\n");
			break;
		}

		}
	} while (k != 3); // цикл до команды 3
	return 0;
}
