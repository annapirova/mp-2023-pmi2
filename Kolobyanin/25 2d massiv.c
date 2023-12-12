#include <stdio.h>
#include <stdlib.h>

int MagicSquare(int A[3][3])
{
    int n = 3;
    int i = 0, j = 0;
    int sum1 = 0, sum2 = 0;
    for (i = 0; i < n; i++)
    {
        sum1 += A[i][i];
        sum2 += A[i][n - 1 - i];
    }
    if (sum1 != sum2)
        return 0;
    for (i = 0; i < n; i++) 
    {
        int stroka = 0, stolbec = 0;
        for (j = 0; j < n; j++)
        {
            stroka += A[i][j];
            stolbec += A[j][i];
        }
        if (stroka != stolbec || stolbec != sum1)
            return 0;
    }
    return 1;
}

int main()
{
    int A[3][3] = { { 2, 7, 6 },
                    { 9, 5, 1 },
                    { 4, 3, 8 } };

    if (MagicSquare(A))
        printf("Magic Square");
    else
        printf("Not a magic Square");

    return 0;
}
