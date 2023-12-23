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
    // Инициализируем поля года и страниц нулями перед разбором строки.
    book->year = 0;
    book->pages = 0;

    char* token = strtok(line, " ");
    while (token != NULL) {
        if (token[0] == '\"') {
            // Копируем строку с кавычкой, а затем запускаем strtok снова, чтобы очистить кавычку.
            strcpy(book->title, token);
            // Удалить начальную кавычку
            memmove(book->title, book->title + 1, strlen(book->title));
            // Найти вторую кавычку и заменить её нулем, тем самым окончив строку
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
    printf("Книга: %s\n", book->title);
    printf("Автор: %s\n", book->author);
    printf("Год: %d\n", book->year);
    printf("Количество страниц: %d\n\n", book->pages);
}

void printBooksByAuthor(struct Book* books, int count, const char* author) {
    printf("Произведения автора %s:\n", author);
    for (int i = 0; i < count; i++) {
        if (strcmp(books[i].author, author) == 0) {
            printBook(&books[i]);
        }
    }
}

void printBooksByYear(struct Book* books, int count, int year) {
    printf("Произведения года %d:\n", year);
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

    printf("Введите данные о книгах (выход - пустая строка):\n");

    while (bookCount < MAX_BOOKS) {
        fgets(line, sizeof(line), stdin);

        // Удаление символа новой строки (\n)
        if (line[strlen(line) - 1] == '\n') {
            line[strlen(line) - 1] = '\0';
        }

        if (strlen(line) == 0) {
            break; // Выход из цикла при пустой строке
        }

        parseLine(line, &books[bookCount]);
        bookCount++;
    }

    printf("\n");

    // Запросы пользователю
    int choice;
    printf("Выберите запрос:\n");
    printf("1. Все произведения одного автора\n");
    printf("2. Все произведения одного года\n");
    printf("Введите число (1 или 2): ");
    scanf("%d", &choice);

    if (choice == 1) {
        char author[MAX_FIELD_LENGTH];
        printf("Введите имя автора: ");
        scanf(" %[^\n]%*c", author); // Используйте этот формат, чтобы считать строку полностью
        printf("\n");
        printBooksByAuthor(books, bookCount, author);
    }

    else if (choice == 2) {
        int year;
        printf("Введите год: ");
        scanf("%d", &year);
        printf("\n");
        printBooksByYear(books, bookCount, year);
    }
    else {
        printf("Некорректный выбор. Программа завершается.\n");
    }

    return 0;
}

