#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

int main()
{
	srand(time(0));
	setlocale(LC_ALL, "Russian");
	
	int n, num_2, num_2copy, num_3, num_3copy, num_4, num_4copy;
	int a2, b2, a3, b3, c3, a4, b4, c4, d4;
	int z2 = 0, z3 = 0, z4 = 0, answer;
	int arr[10], attemps = 0;

	printf("Введите длину загадываемого числа: ");
	scanf_s("%i", &n);

	if ((n >= 2) && (n < 5))
	{
		if (n == 2)
		{
			while (1)
			{
				num_2 = 10 + rand() % (100 - 11);
				num_2copy = num_2;
				a2 = num_2 % 10;
				num_2copy = num_2 / 10;
				b2 = num_2copy % 10;
				if (a2 != b2)
				{
					z2 = num_2;
					arr[0] = b2;
					arr[1] = a2;
					break;
				}
			}
		}

		if (n == 3)
		{
			while (1)
			{
				num_3 = 100 + rand() % (1000 - 101);
				num_3copy = num_3;
				a3 = num_3 % 10;
				num_3copy = num_3 / 10;
				b3 = num_3copy % 10;
				num_3copy = num_3copy / 10;
				c3 = num_3copy % 10;
				if ((a3 != b3) && (a3 != c3) && (b3 != c3))
				{
					z3 = num_3;
					arr[0] = c3;
					arr[1] = b3;
					arr[2] = a3;
					break;
				}
			}
		}

		if (n == 4)
		{
			while (1)
			{
				num_4 = 1000 + rand() % (10000 - 1001);
				num_4copy = num_4;
				a4 = num_4 % 10;
				num_4copy = num_4 / 10;
				b4 = num_4copy % 10;
				num_4copy = num_4copy / 10;
				c4 = num_4copy % 10;
				num_4copy = num_4copy / 10;
				d4 = num_4copy % 10;
				if ((a4 != b4) && (a4 != c4) && (a4 != d4) && (b4 != c4) && (b4 != d4) && (c4 != d4))
				{
					z4 = num_4;
					arr[0] = d4;
					arr[1] = c4;
					arr[2] = b4;
					arr[3] = a4;
					break;
				}
			}
		}
	}
	else
	{
		printf("Введено недопустимое значение");
	}

	while (1)
	{
		printf("Введите %i-значное число с неповторяющимися цифрами: ", n);
		scanf_s("%i", &answer);
		int ans[10], digits = 0, cows = 0, bulls = 0;

		while (answer > 0)
		{
			ans[digits] = answer % 10;
			answer /= 10;
			digits++;
		}

		int left = 0;
		int right = digits - 1;

		while (left < right)
		{
			int temp = ans[left];
			ans[left] = ans[right];
			ans[right] = temp;

			left++;
			right--;
		}

		for (int i = 0; i < digits; i++)
		{
			if (arr[i] == ans[i])
			{
				bulls++;
			}
			else
			{
				for (int j = 0; j < digits; j++)
				{
					if (arr[i] == ans[j])
					{
						cows++;
						break;
					}
				}
			}
		}
		attemps++;
		printf("Загаданное число = %i %i %i\n", z2, z3, z4);
		printf("Быки = %i, Коровы = %i\n", bulls, cows);
		if (bulls == digits)
		{
			printf("Число угадано!\n");
			printf("Число попыток: %i", attemps);
			break;
		}
	}
	
	return 0;
}