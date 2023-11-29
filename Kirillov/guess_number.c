#include <stdio.h>
#include <stdbool.h>



int main()
{
    int a = 0;
    int b = 1000;

    int findRes = b;
    int myNum;

    printf("Choose your number: ");
    scanf_s("%d", &myNum);

    int counter = 0;
    while (true)
    {
        int selection;
        counter++;
        findRes = (a + b) / 2;
        printf("I think is %d" ,findRes , ". Is it true?" );

        printf("Press 1 if number smaller/2 if number bigger or 0 if is your number!");
        scanf_s("%d", &selection);

        if (selection == 0) {
            break;
        }
        else if (selection == 2)
        {
            a = findRes;
        }
        else if (selection == 1)
        {
            b = findRes;
        }
    }

    printf( "Congratulations!");


    printf("Counter steps:%d " ,counter );
    return 0;
}