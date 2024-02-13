#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "math.h"
#include "stdlib.h"
#include "malloc.h"
#include "string.h"
#include "locale.h"
#include "stdbool.h"
#define LENGTH 100

struct Contact* contact;

struct Contact
{
	char* lastname;
	char* number;
	char* mail;
};

bool phone(const char* str)
{
	if ((str[0] == '+') && (strlen(str) == 12))
	{
		return true;
	}
	return false;
}

void showall(struct Contact* contact, int count)
{
	for (int i = 0; i < count; ++i) {
		printf("%d. ", i + 1);
		printf("Contact lastname: %s\n", contact[i].lastname);
		printf("Contact phone: %s\n", contact[i].number);
		printf("Contact mail: %s\n", contact[i].mail);
	}
}


void current(struct Contact* contact, const char* token) {
	if (phone(token)) {
		free(contact->number);
		contact->number = _strdup(token);
	}
	else if (strchr(token, '@') != NULL) {
		free(contact->mail);
		contact->mail = _strdup(token);
	}
	else {
		if (contact->lastname == NULL) {
			contact->lastname = _strdup(token);
		}
		else {
			size_t len = strlen(contact->lastname) + strlen(token) + 2;
			char* temp = (char*)malloc(len);
			if (temp != NULL) {
				sprintf_s(temp, len, "%s %s", contact->lastname, token);
				free(contact->lastname);
				contact->lastname = temp;
			}
		}
	}
}

struct Contact parsing(const char* str) {
	struct Contact contact = { NULL, NULL, NULL };

	char* strCopy = _strdup(str);
	char* token;
	char* context = NULL;

	token = strtok_s(strCopy, " ", &context);
	while (token != NULL) {
		current(&contact, token);
		token = strtok_s(NULL, " ", &context);
	}

	free(strCopy);
	return contact;
}

void findlastname(struct Contact* contact, int count)
{
	printf("Operation: Search by lastname\nEnter lastname - ");
	char lastname[LENGTH];
	scanf_s("%s", lastname, sizeof(lastname));

	for (int i = 0; i < count; i++) 
	{
		if (contact[i].lastname && strcmp(contact[i].lastname, lastname) == 0)
		{
			printf("Contact %d: \n", i);
			printf("His phone: %s\n", contact[i].number);
			printf("His mail: %s\n", contact[i].mail);
			return;
		}
	}
	printf("You have no contact with this lastname");
}

void findnumber(struct Contact* contact, int count)
{
	printf("Operation: Search by number\nEnter number - ");
	char number[LENGTH];
	scanf_s("%s", number, sizeof(number));

	for (int i = 0; i < count; i++)
	{
		if (contact[i].number && strcmp(contact[i].number, number) == 0)
		{
			printf("Contact %d: \n", i);
			printf("His lastname: %s\n", contact[i].lastname);
			printf("His mail: %s\n", contact[i].mail);
			return;
		}
	}
	printf("You have no contact with this number");
}

void findmail(struct Contact* contact, int count)
{
	printf("Operation: Search by mail\nEnter mail - ");
	char mail[LENGTH];
	scanf_s("%s", mail, sizeof(mail));

	for (int i = 0; i < count; i++)
	{
		if (contact[i].mail && strcmp(contact[i].mail, mail) == 0)
		{
			printf("Contact %d: \n", i);
			printf("His lastname: %s\n", contact[i].lastname);
			printf("His number: %s\n", contact[i].number);
			return;
		}
	}
	printf("You have no contact with this mail");
}


int main()
{
	const char* fplace = "C:\\Users\\cross\\OneDrive\\Рабочий стол\\structures\\Contacts.txt";
	FILE* f;
	if (fopen_s(&f, fplace, "r") != 0)
	{
		perror("Error occured while opening file");
		return 1;
	}
	contact = (struct Contact*)malloc(LENGTH * sizeof(struct Contact));
	if (contact == NULL)
	{
		perror("The list is empty");
		fclose(f);
		return 1;
	}

	int count = 0;
	char* buffer = (char*)malloc(LENGTH);
	while (fgets(buffer, LENGTH, f) != NULL)
	{
		contact[count++] = parsing(buffer);
		if (count >= LENGTH) 
		{
			break;
		}
	}
	int operation = 0;
	printf("Operation list:\n 1. Show all contacts.\n 2. Search by lastname.\n 3. Search by phone\n 4. Search by mail\n 5. Exit.\n");
	do
	{
		printf("Enter number of operation - ");
		scanf_s("%d", &operation);
		switch (operation)
		{
		case 1: showall(contact, count); break;
		case 2: findlastname(contact, count); break;
		case 3: findnumber(contact, count); break;
		case 4: findmail(contact, count); break;
		default: printf("Operation not found"); break;
		}
	} while (operation != 5);

	free(contact);
	free(buffer);
	fclose(f);
}