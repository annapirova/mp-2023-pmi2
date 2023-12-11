#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>
//Дана целочисленная матрица А размером тхп. Сформировать массив индексов тех
//строк матрицы, которые являются палиндромами(палиндром - это строка, которая
	//читается одинаково с начала и с конца).
int Palindrome(int a[], int n) {
    for (int i = 0; i < n / 2; i++) {
        if (a[i] != a[n - i - 1]) {
            return 0;
        }
    }
    return 1;
}
int main()
{
    setlocale(LC_CTYPE, "Russian");
    int r = 4, c = 3, kol=0;
    int* index;
    index = (int*)malloc(sizeof(int)*r);
    int a[4][3] =
    { {1, 4, 5},
     {2, 6, 2},
     {1, 0, 9},
     {0, 0, 0} };
    printf("Дана матрица: \n");
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    printf("Индексы палиндромов: \n");
    for (int i = 0; i < r; i++) {
        if (Palindrome(a[i], c)) {
            index[kol] = i;
           kol++;
            printf("%d ", i);
        }
    }
	return 0;
}