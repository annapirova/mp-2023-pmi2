#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

typedef struct {
	char Name[50];
	char Date[15];
	char Row[5];
	char Seat[5];
} Ticket;

void Menu()
{
	printf("hi, user, what do u want to do?\n");
	printf("1. See info about anyone ticket\n");
	printf("2. Displays all tickets for a entered day\n");
	printf("3. Displays all tickets from entered row and range of seats\n");
	printf("4. Exit\n");
}

void razdelstr(char* stroka, Ticket* tickets)
{
	char* token;
	int i = 0;
	token = strtok(stroka, " ");
	while (token != NULL)
	{
		if (isupper(token[0]))
		{
			strcpy(tickets->Name, token);
		}
		else if (strchr(token, 'r') != NULL)
		{
			strcpy(tickets->Row, (strchr(token, 'r') + 1));
		}
		else if (strchr(token, 'm') != NULL)
		{
			strcpy(tickets->Seat, (strchr(token, 'm') + 1));
		}
		else if (isdigit(token[0]))
		{
			strcpy(tickets->Date, token);
		}

		token = strtok(NULL, " ");
	}
}

void Info(Ticket tickets[], int k)
{
	int j;
	printf("Print num of ticket(no more than %i)\n", k);
	scanf_s("%i", &j);
	printf("Ticket %i\n", j);
	j--;
	printf("Name: %s\n", tickets[j].Name);
	printf("Date: %s\n", tickets[j].Date);
	printf("Row: %s\n", tickets[j].Row);
	printf("Seat: %s\n", tickets[j].Seat);
	printf("select new command:\n");
}

void zapros(Ticket tickets[], int k)
{
	char strDate[15];
	printf("Enter date of event (DD.MM.YYYY):\n");

	do
	{
		fgets(strDate, sizeof(strDate), stdin);
		strDate[strcspn(strDate, "\n")] = '\0';
	} while (strlen(strDate) != 10);

	printf("\n");

	int check = 0;
	for (int i = 0; i < k; i++)
	{
		if (strcmp(tickets[i].Date, strDate) == 0)
		{
			printf("Ticket %i:\n", i+1);
			printf("Name: %s\n", tickets[i].Name);
			printf("Date: %s\n", tickets[i].Date);
			printf("Row: %s\n", tickets[i].Row);
			printf("Seat: %s\n", tickets[i].Seat);
			printf("\n");
			check = 1;
		}
	}

	if (check == 0)
	{
		printf("No events on this day\n");
	}

	printf("Select new command:\n");
}

void zapros1(int k, Ticket tickets[])
{
	char r[5], m_str[5], m1_str[5];
	printf("Enter row number and the range of seats:\n");
	printf("Row: ");
	scanf_s("%s", &r, (unsigned)_countof(r));
	printf("Range of seats:\n");
	printf("from: ");
	scanf_s("%s", &m_str, (unsigned)_countof(m_str));
	printf("to: ");
	scanf_s("%s", &m1_str, (unsigned)_countof(m1_str));

	int m = atoi(m_str);
	int m1 = atoi(m1_str);

	printf("\n");

	int check = 0;
	for (int i = 0; i < k; i++)
	{
		if ((strcmp(tickets[i].Row, r) == 0) && (m <= atoi(tickets[i].Seat) && atoi(tickets[i].Seat) <= m1))
		{
			printf("Ticket %i:\n", i + 1);
			printf("Name: %s\n", tickets[i].Name);
			printf("Date: %s\n", tickets[i].Date);
			printf("Row: %s\n", tickets[i].Row);
			printf("Seat: %s\n", tickets[i].Seat);
			printf("\n");
			check = 1;
		}
	}

	if (check == 0)
	{
		printf("Undefined row and seats\n");
	}

	printf("Select new command:\n");
}

//25.10.2023 Cinderella m1 r2
//Lion_Heart 05.07.2023 r35 m25
//11.11.2023 r5 m90 Ice_Queen
//25.10.2023 r7 My_little_pony m11
//11.11.2023 m9 Thunder_Strike r7
//11.11.2023 r7 Space_Odyssey m4

int main()
{
	int k, b;

	printf("how many positions do you want to enter?\n");
	scanf_s("%i", &k);

	getchar();

	Ticket *tickets = (Ticket*)malloc(k * sizeof(Ticket));

	for (int i = 0; i < k; i++)
	{
		char stroka[100];
		printf("enter data for %i ticket\n", i+1);
		
		fgets(stroka, sizeof(stroka), stdin);
		stroka[strcspn(stroka, "\n")] = '\0';

		razdelstr(stroka, &tickets[i]);
	}
	printf("\n");
	Menu();
	do
	{
		scanf_s("%i", &b);
		switch (b)
		{
		case 1:
		{
			Info(tickets, k);
			break;
		}

		case 2:
		{
			zapros(tickets, k);
			break;
		}

		case 3:
		{
			zapros1(k, tickets);
			break;
		}
		default:
			printf("type another number\n");
			break;
		}
	} while (b != 4);

	free(tickets);

	return 0;
}