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
    printf("1-look all input's films\n2-zapros_1\n3-zapros_2\n4-exit\n");
}
void all_films(FILMS *film_mas, int *count)
{
    for(int i=0;i<*count;i++)
    {
        printf("Author: %s\n",film_mas[i].author);
        printf("Name: %s\n",film_mas[i].name);
        printf("Year: %d\n",film_mas[i].year);
        printf("Time: %.10f\n\n",film_mas[i].time);
    }
}
void zapros_1(FILMS *film_mas, int *count)
{
    printf("Input author ");
    char str[50];
    fgets(str,sizeof(str),stdin);//kosyk!!!!!!
    int i,flag=0;
    fgets(str,sizeof(str),stdin);
    for(i=0;i<*count;i++)
    {
        if(strcmp (str,film_mas[i].author))
        {
            flag=1;
            printf("Author: %s\n",film_mas[i].author);
            printf("Name: %s\n",film_mas[i].name);
            printf("Year: %d\n",film_mas[i].year);
            printf("Time: %.10f\n\n",film_mas[i].time);
        }
    }
    if(flag==0) printf("NO exist\n");
}
void zapros_2(FILMS *film_mas, int *count)
{
    int start=0, end=0,i,flag=0;
    printf("Input interval of years\nstatr: ");
    scanf("%d",&start);
    printf("end: ");
    scanf("%d", &end);
    printf("\n");
    for(i=0;i<*count;i++)
    {
        if(film_mas[i].year<=end && film_mas[i].year>=start)
        {
            flag=1;
            printf("Author: %s\n",film_mas[i].author);
            printf("Name: %s\n",film_mas[i].name);
            printf("Year: %d\n",film_mas[i].year);
            printf("Time: %.10f\n\n",film_mas[i].time);            
        }
    }
    if(flag==0) printf("NO exist\n");

}
//Rimers #death 1964 12323.12312421
//Filtor #kiborg_ybica 1874 124.2343234
//#pypsik Gosling 124124.5433 1700
//2352.243523 #vladimir Gomer 145
//Filtor #winston 1845 135.6785
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
    printf("\n");
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
			zapros_1(film_mas, &count);// all films of one author
			break;
		}

		case 3:
		{
			zapros_2(film_mas, &count);// all films of  the interaval year
			break;
		}
        case 4:
        {
            printf("Thank's for your attention!\n");
        }
		default:
        {
			printf("Choose next correct command");
			break;
		}
        }
	} while (k!=4);
    free(film_mas);
    return 0;
}