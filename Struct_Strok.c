#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#define MAX_BOOKS 100
#define MAX_FIELD_LENGTH 100

struct Book {
    char title[MAX_FIELD_LENGTH];
    char author[MAX_FIELD_LENGTH];
    int year;
    int pages;
};

void parseLine(char* line, struct Book* book) {
    // �������������� ���� ���� � ������� ������ ����� �������� ������.
    book->year = 0;
    book->pages = 0;

    char* token = strtok(line, " ");
    while (token != NULL) {
        if (token[0] == '\"') {
            // �������� ������ � ��������, � ����� ��������� strtok �����, ����� �������� �������.
            strcpy(book->title, token);
            // ������� ��������� �������
            memmove(book->title, book->title + 1, strlen(book->title));
            // ����� ������ ������� � �������� � �����, ��� ����� ������� ������
            char* end_quote = strchr(book->title, '\"');
            if (end_quote) {
                *end_quote = '\0';
            }
        }
        else if (isalpha(token[0])) {
            strcpy(book->author, token);
        }
        else if (isdigit(token[0])) {
            if (book->year == 0) {
                book->year = atoi(token);
            }
            else {
                book->pages = atoi(token);
            }
        }
        token = strtok(NULL, " ");
    }
}

void printBook(struct Book* book) {
    printf("�����: %s\n", book->title);
    printf("�����: %s\n", book->author);
    printf("���: %d\n", book->year);
    printf("���������� �������: %d\n\n", book->pages);
}

void printBooksByAuthor(struct Book* books, int count, const char* author) {
    printf("������������ ������ %s:\n", author);
    for (int i = 0; i < count; i++) {
        if (strcmp(books[i].author, author) == 0) {
            printBook(&books[i]);
        }
    }
}

void printBooksByYear(struct Book* books, int count, int year) {
    printf("������������ ���� %d:\n", year);
    for (int i = 0; i < count; i++) {
        if (books[i].year == year) {
            printBook(&books[i]);
        }
    }
}

int main() {
    setlocale(LC_ALL, "Rus");
    struct Book books[MAX_BOOKS];
    int bookCount = 0;

    char line[MAX_FIELD_LENGTH];

    printf("������� ������ � ������ (����� - ������ ������):\n");

    while (bookCount < MAX_BOOKS) {
        fgets(line, sizeof(line), stdin);

        // �������� ������� ����� ������ (\n)
        if (line[strlen(line) - 1] == '\n') {
            line[strlen(line) - 1] = '\0';
        }

        if (strlen(line) == 0) {
            break; // ����� �� ����� ��� ������ ������
        }

        parseLine(line, &books[bookCount]);
        bookCount++;
    }

    printf("\n");

    // ������� ������������
    int choice;
    printf("�������� ������:\n");
    printf("1. ��� ������������ ������ ������\n");
    printf("2. ��� ������������ ������ ����\n");
    printf("������� ����� (1 ��� 2): ");
    scanf("%d", &choice);

    if (choice == 1) {
        char author[MAX_FIELD_LENGTH];
        printf("������� ��� ������: ");
        scanf(" %[^\n]%*c", author); // ����������� ���� ������, ����� ������� ������ ���������
        printf("\n");
        printBooksByAuthor(books, bookCount, author);
    }

    else if (choice == 2) {
        int year;
        printf("������� ���: ");
        scanf("%d", &year);
        printf("\n");
        printBooksByYear(books, bookCount, year);
    }
    else {
        printf("������������ �����. ��������� �����������.\n");
    }

    return 0;
}

