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
    line[strcspn(line, "\n")] = '\0';

    char* token = strtok(line, " ");
    while (token != NULL) {
        if (token[0] == '\"') {
            strcpy(book->title, token + 1);
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
                break;
            }
        }
        token = strtok(NULL, " ");
    }
}

void printBook(const struct Book* book) {
    printf("Название: %s\n", book->title);
    printf("Автор: %s\n", book->author);
    printf("Год выпуска: %d\n", book->year);
    printf("Количество страниц: %d\n\n", book->pages);
}

void printBooksByAuthor(const struct Book* books, int bookCount, const char* author) {
    int found = 0;
    printf("Книги автора %s:\n", author);
    for (int i = 0; i < bookCount; i++) {
        if (strcmp(books[i].author, author) == 0) {
            printBook(&books[i]);
            found = 1;
        }
    }
    if (!found) {
        printf("Произведений автора %s не найдено.\n\n", author);
    }
}

void printBooksByYear(const struct Book* books, int bookCount, int year) {
    int found = 0;
    printf("Книги года %d:\n", year);
    for (int i = 0; i < bookCount; i++) {
        if (books[i].year == year) {
            printBook(&books[i]);
            found = 1;
        }
    }
    if (!found) {
        printf("Произведений года %d не найдено.\n\n", year);
    }
}

int main() {
    setlocale(LC_ALL, "Rus");
    struct Book library[MAX_BOOKS];
    int bookCount = 0;

    char input[MAX_FIELD_LENGTH];

    printf("Введите информацию о книгах (для завершения введите пустую строку):\n");

    while (bookCount < MAX_BOOKS) {
        fgets(input, sizeof(input), stdin);

        if (input[0] == '\n') {
            break; // Выход из цикла при пустой строке
        }

        parseLine(input, &library[bookCount]);
        bookCount++;
    }

    printf("\n");

    // Выбор запроса у пользователя
    int choice;
    printf("Выберите запрос:\n");
    printf("1. Показать все книги одного автора\n");
    printf("2. Показать все книги определенного года\n");
    printf("Введите число (1 или 2): ");
    scanf("%d", &choice);

    if (choice == 1) {
        char author[MAX_FIELD_LENGTH];
        printf("Введите имя автора: ");
        scanf(" %[^\n]%*c", author);
        printf("\n");
        printBooksByAuthor(library, bookCount, author);
    }
    else if (choice == 2) {
        int year;
        printf("Введите год: ");
        scanf("%d", &year);
        printf("\n");
        printBooksByYear(library, bookCount, year);
    }
    else {
        printf("Некорректный выбор. Программа завершается.\n");
    }

    return 0;
}
