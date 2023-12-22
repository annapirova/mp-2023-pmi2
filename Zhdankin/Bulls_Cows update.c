#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

int generateNumber(int n)
{
	int number = 0, digit;
	int used[10] = { 0 };

	for (int position = n - 1; position >= 0; --position)
	{
		do
		{
			digit = rand() % 10;
		} while ((used[digit] == 1) || (position == n - 1 && digit == 0));

		used[digit] = 1;
		number = number * 10 + digit;
	}

	return number;
}

int main()
{
	srand(time(0));
	setlocale(LC_ALL, "Russian");
	
	int n, number_to_guess;
	int attempts = 0;
	int arr[4];

	printf("Введите длину загадываемого числа: ");
	scanf_s("%i", &n);

	if (n < 2 || n > 4) {
		printf("Введено недопустимое значение\n");
		return -1;
	}

	number_to_guess = generateNumber(n);
	int temp = number_to_guess;
	for (int i = n - 1; i >= 0; --i)
	{
		arr[i] = temp % 10;
		temp /= 10;
	}

	int check = 0;
	do
	{
		int answer;
		printf("Введите %i-значное число с неповторяющимися цифрами: ", n);
		scanf_s("%i", &answer);
		int ans[4], digits = 0;

		for (int temp = answer; temp > 0; temp /= 10)
		{
			ans[digits++] = temp % 10;
		}

		int cows = 0, bulls = 0;
		for (int i = 0; i < n; i++)
		{
			if (arr[i] == ans[i])
			{
				bulls++;
			}
			else
			{
				for (int j = 0; j < n; j++)
				{
					if (arr[i] == ans[j] && arr[j] != ans[j])
					{
						cows++;
						break;
					}
				}
			}
		}
		attempts++;
		printf("Быки = %d, Коровы = %d\n", bulls, cows);
		if (bulls == n)
		{
			printf("Число угадано!\n");
			printf("Число попыток: %d\n", attempts);
			check = 1;

		}
	} while (check == 0);

	
	return 0;
}