#include "stdio.h"
#include "time.h"
#include "stdlib.h"
#include "locale.h"
int main()
{
srand(time(NULL));
setlocale(LC_CTYPE, "Russian");
int x=rand()%(1000+1), k=0, y;
 printf("%d\n", x);
 do
 {
  scanf("%d", &y);
  if(y<x) printf("Загаданное число больше\n");
  if(y>x) printf("Загаданное число меньше\n");
  k++;
 } while (y!=x);
 printf("Вы угадали! Это число-%d, кол-во попыток: %d\n",x,k);

  return 0;
}