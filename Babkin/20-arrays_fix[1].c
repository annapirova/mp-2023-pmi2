#include "stdio.h"
#include "math.h"
#include "stdlib.h"
int main()
{
    int a,num,j,i,k;
    int m[100];
    for (a = 0; a < 100; a++) //o
    {
        m[a] = rand()%100;
    }
    scanf("%d",&num);
    for (k = 0; k < 100; k++)
    {
      for (i = 0;i < 100; i++)
      {
        for (j = 0; i+j < 100; j++)
        {
          if ((m[i] + m[i+j] == num + k) || (m[i] + m[i+j] == num - k)) 
          {
            printf("%d, %d", m[i], m[i+j]);
            return 0;
          }
        }
      }
    }
    return 0;
}