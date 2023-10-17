#include <stdio.h>

int main()
{
    int x, y, F;
    printf("AND\n");
        for (x = 0; x <= 1; x++)
        {
            for (y = 0; y <= 1; y++)
            {
                for (F = 0; F <= 1; F++)
                {
                    if ((x && y) == F)
                    {
                        printf("%d " "%d " "%d\n", x, y, F);
                    }

                }
            }
        }
        printf("OR\n");
        for (x = 0; x <= 1; x++)
        {
            for (y = 0; y <= 1; y++)
            {
                for (F = 0; F <= 1; F++)
                {
                    if ((x || y) == F)
                    {
                        printf("%d " "%d " "%d\n", x, y, F);
                    }

                }
            }
        }
        printf("XOR\n");
        for (x = 0; x <= 1; x++)
        {
            for (y = 0; y <= 1; y++)
            {
                for (F = 0; F <= 1; F++)
                {
                    if ((x ^ y) == F)
                    {
                        printf("%d " "%d " "%d\n", x, y, F);
                    }

                }
            }
        }
}
