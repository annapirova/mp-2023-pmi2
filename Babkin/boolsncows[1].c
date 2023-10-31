#include "stdio.h"
#include "math.h"
#include "stdlib.h"
int main()
{
  int n,i, c, k, yournum, u, q, z;
  int cows, bools = 0;
  int cpu[5] = {10,10,10,10,10}, yout[5] = {11,11,11,11,11};
  printf("Print the length of your number: ");
  scanf("%d\n", &n);
  if (n > 0)
  {cpu[0] = 1 + rand()%9;}
  for (i=1;i < n;i++)
  {
    c = k = 1;
    cpu[i] = rand()%10;
    while ((i - c != -1) || (i + k != (n+1)))
    {
      if (i - c > -1)
      {
        while (cpu[i - c] == cpu[i])
        {
          cpu[i] = rand()%10;
        }
        c += 1;
      }
      if ((i + k) < (n + 1))
      {
        while (cpu[i + k] == cpu[i])
        {
          cpu[i] = rand()%10;
        }
        k += 1; 
      }
    }
  }
  printf("print your number: ");
  scanf("%d\n", &yournum);
  for (u=n-1;u>-1;u--)
  {
    yout[u] = yournum % 10;
    yournum = yournum / 10;
  }
  while (bools != n)
  {
    bools = cows = 0;
    for (q=0;q<n;q++)
    {
      for (z=0;z<n;z++)
      {
        if (yout[q] == cpu[z])
        {
          if (q == z)
          {
          bools += 1;
          }
          else
          {
          cows += 1;
          }
        }
      }
    }
    if (bools != n) 
    {
      printf("Oopsy,you guessed wrong. There are %d cows and %d bools. Try again\n", cows, bools);
      printf("print your number: ");
      scanf("%d\n", &yournum);
      for (u=n-1;u>-1;u--)
      {
        yout[u] = yournum % 10;
        yournum = yournum / 10;
      }
    }
  }
  printf("Wow, I really appreciate your determination. You won a game. Congrats!!! ");
  return 0;
}