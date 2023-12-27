#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
typedef struct 
{
    char author[50];
    char name[50];
    int year;
    double time;

} FILMS;
void razbienie(char *str, FILMS *film)
{
    char* lecsema;
    lecsema=strtok(str," ");
    while(lecsema!=NULL)
    {
        if(isupper(lecsema[0])) strcpy(film->author,lecsema);
        else if (strchr(lecsema, '#')) strcpy(film->name, strchr(lecsema, '#')+1);
        else if (strchr(lecsema, '.')) film->time=atof(lecsema);
        else if (isdigit(lecsema[0])) film->year=atoi(lecsema);
        lecsema=strtok(NULL," ");
    }
}
void spisok_ability()
{
    printf("1-look all input's films\n 2-zapros_1\n 3-zapros_2\n4-exit\n");
}
void all_films(FILMS *film_mas, int *count)
{
    for(int i=0;i<*count;i++)
    {
        printf("%s\n",film_mas[i].author);
        printf("%s\n",film_mas[i].name);
        printf("%d\n",film_mas[i].year);
        printf("%.10f\n\n",film_mas[i].time);
    }
}
void zapros_1()
{

}
void zapros_2()
{

}
//Rimers #death 1964 12323.12312421
int main()
{
    int count,i,k;
    printf("How many films you wonna input?\n");
    scanf("%d",&count);
    getchar(); // skip \n after scanf
    FILMS *film_mas=(FILMS*)malloc(count*sizeof(FILMS));
    for(i=0;i<count;i++)
    {
        printf("Input %d film:\n",i+1);
        char str[50];
        fgets(str,sizeof(str),stdin);
        razbienie(str,&film_mas[i]);
    }

    spisok_ability();
	do
	{
        printf("\npick anymore-");
		scanf("%d", &k);
        printf("\n");
		switch (k)
		{
		case 1:
		{
			all_films(film_mas,&count);
			break;
		}

		case 2:
		{
			zapros_1();
			break;
		}

		case 3:
		{
			zapros_2();
			break;
		}
        case 4:
        {
            printf("Thank's for your attention!\n");
        }
		default:
			printf("Choose next correct command");
			break;
		}
	} while (k!=4);
    free(film_mas);
    return 0;
}