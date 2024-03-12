#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#include <math.h>
#include <string.h>

typedef struct {
    char index[10];
    char city[50];
    char street[50];
    char house[10];
} Address;

void parse_address(const char* input, Address* addr) {
    const char* delimiter = ",";
    char* token = strtok((char*)input, delimiter);

    while (token != NULL) {
        if (isdigit(token[0])) {
            strcpy(addr->index, token);
        }
        else if (strstr(token, "г.") == token) {
            strcpy(addr->city, token);
        }
        else if (strstr(token, "ул.") == token) {
            strcpy(addr->street, token);
        }
        else if (strstr(token, "д.") == token) {
            strcpy(addr->house, token);
        }
        token = strtok(NULL, delimiter);
    }
}


void insertion_sort_by_street(Address* addresses, int n) {
    Address temp;
    int j;
    for (int i = 1; i < n; i++) {
        temp = addresses[i];
        j = i - 1;
        while (j >= 0 && strcmp(addresses[j].street, temp.street) > 0) {
            addresses[j + 1] = addresses[j];
            j--;
        }
        addresses[j + 1] = temp;
    }
}

int search_by_street(Address* addresses, int n, const char* street_name) {
    for (int i = 0; i < n; i++) {
        if (strcmp(addresses[i].street, street_name) == 0) {
            return i;
        }
    }
    return -1;
}

void commands() {
    printf("1 - Ввести самостоятельно\n");
    printf("2 - Прочитать с файла\n");
    printf("3 - Сортировать\n");
    printf("4 - Вывести все адреса\n");
    printf("5 - Поиск по улице\n");
    printf("6 - Список команд\n");
}

Address* allocate_addresses(int* n) {
    printf("Введите количество адресов: ");
    scanf("%d", n);
    return (Address*)malloc(*n * sizeof(Address));
}

void enter_addresses_manually(Address* addresses, int n) {
    char buffer[100];
    for (int i = 0; i < n; i++) {
        printf("Введите адрес %d в формате 'Индекс Город Улица Дом': ", i + 1);
        scanf(" %[^\n]", buffer);
        parse_address(buffer, &addresses[i]);
    }
}

void read_addresses_from_file(Address* addresses, int* n) {
    char filename[50];
    printf("Введите имя файла с адресами: ");
    scanf("%s", filename);
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        perror("Ошибка при открытии файла");
        return;
    }
    char buffer[100];
    int i = 0;
    while (fgets(buffer, sizeof(buffer), file)) {
        if (i >= *n) {
            *n += 1;
            addresses = (Address*)realloc(addresses, *n * sizeof(Address));
        }
        parse_address(buffer, &addresses[i]);
        i++;
    }
    fclose(file);
}

int main() {
    setlocale(LC_CTYPE, "Russian"); 
    Address* addresses = NULL;
    int n = 0;
    int command;
    char street_to_search[50];
    commands();

    while (1) {
        printf("\nВведите команду (6 для списка команд): ");
        scanf("%d", &command);

switch (command) {
        case 1:
            if (addresses != NULL) free(addresses);
            addresses = allocate_addresses(&n);
            enter_addresses_manually(addresses, n);
            break;
        case 2:
            if (addresses != NULL) free(addresses);
             addresses = allocate_addresses(&n);
        read_addresses_from_file(addresses, &n);
        break;

        case 3:
            if (addresses != NULL && n > 0) {
                insertion_sort_by_street(addresses, n);
                printf("Адреса отсортированы.\n");
            }
            else {
                printf("Нет адресов для сортировки.\n");
            }
            break;
        case 4:
            if (addresses != NULL && n > 0) {
                for (int i = 0; i < n; i++) {
                    printf("Address %d: %s, %s, %s, %s\n",
                        i + 1,
                        addresses[i].index,
                        addresses[i].city,
                        addresses[i].street,
                        addresses[i].house);
                }
            }
            else {
                printf("Нет адресов для отображения.\n");
            }
            break;
        case 5:
    if (addresses != NULL) {
        const char street_to_search[] = "Main Street"; // Пример названия улицы для поиска
        int count = search_by_street(addresses, n, street_to_search);
        
        if (count == -1) {
            printf("Улица '%s' не найдена в адресах.\n", street_to_search);
        } else {
            printf("Улица '%s' встречается %d раз(а) в адресах.\n", street_to_search, count);
        }
    } else {
        printf("Массив адресов пуст. Необходимо сначала загрузить данные.\n");
    }
    break;
        case 6:
            commands();
            break;
        default:
            printf("Неизвестная команда.\n");
            break;
        }
    }

    if (addresses != NULL) {
        free(addresses);
    }
    return 0;
}
