#include <stdio.h>
#include <math.h>
#include <locale.h>
#include <stdlib.h> 
#include <string.h>
#include <time.h>

#define NUM_PRODUCTS 5  //  количество продуктов

// Функция для вывода списка возможных операций
void print_services_list() {
    printf("1 - scan new product\n");  // "сканировать новый продукт"
    printf("2 - see information about last scanned product\n");  // "посмотреть информацию о последнем отсканированном продукте"
    printf("3 - produce info about product\n");  // "создать информацию о продукте"
    printf("4 - exit the program\n");  // "выход из программы"
}

// Функция для сканирования продукта
void scan_product(int* product, int product_code[], int product_counts[]) {
    printf("Input product code\n");  // "Введите код продукта"
    scanf_s("%d", product);  

    int index, f = 0;
    for (index = 0; index < NUM_PRODUCTS; index++) {
        if (product_code[index] == *product) {
            product_counts[index]++;  
            f = 1;
        }
    }

    if (f == 0) {
        printf("Product doesn't exist\n");  // "Такого продукта не существует"
    }
}

// Функция для вывода информации о продукте
void print_product_info(int* product, int product_code[], int product_prices[], double discounts[]) {
    int i;
    if (*product == -1) {
        printf("Scan any product first\n");  // "Сначала отсканируйте любой продукт"
        return;
    }

    // Перебираем все продукты и ищем совпадение по коду
    for (i = 0; i < NUM_PRODUCTS; i++) {
        if (product_code[i] == *product) {
            printf("Product code - %d\n", product_code[i]);  // выводим код продукта
            printf("Price(without discount) - %d\n", product_prices[i]);  // выводим цену без скидки
            printf("Discount - %.2lf\n", discounts[i]);  // выводим скидку
            printf("Price(with discount) - %.2lf\n", (double)product_prices[i] *(1 - discounts[i]));  // выводим цену со скидкой
        }
    }
}

// Функция для формирования чека
void produce_receipt(int product_counts[], int product_code[],
    double discounts[], int product_prices[], double* total) {

    printf("Receipt:\n");  // "Чек:"
    printf("Product code  count  discount  price\n");  // "Код продукта  количество  скидка  цена"

    for (int i = 0; i < NUM_PRODUCTS; i++) {
        if (product_counts[i] != 0) {  
            // Вычисляем итоговую стоимость за продукт с учетом скидки и количества(если продукт отсканирован)
            double final_price = (double)product_prices[i] *(1 - discounts[i]) * product_counts[i];
            printf("%d %d %.2lf %.2lf\n", product_code[i], product_counts[i], discounts[i], final_price);
            *total += final_price;  //  общая стоимость покупок
        }
    }

    printf("\nTotal %.2lf\n", *total);  
}
// Функция для сортировки продуктов по цене
void sort_by_price(int product_code[], int product_prices[], int products_number) {
    for (int i = 0; i < products_number - 1; i++) {
        for (int j = 0; j < products_number - i - 1; j++) {
            // Если текущий элемент больше следующего, меняем их местами
            if (product_prices[j] > product_prices[j + 1]) {
                int temp_price = product_prices[j];
                product_prices[j] = product_prices[j + 1];
                product_prices[j + 1] = temp_price;

                int temp_code = product_code[j];
                product_code[j] = product_code[j + 1];
                product_code[j + 1] = temp_code;
            }
        }
    }
}

int main() {

    
    int product_code[NUM_PRODUCTS] = { 2125, 2136, 2147, 2158, 2169 };
    int product_prices[NUM_PRODUCTS] = { 666, 66, 96, 999, 23 };
    double discounts[NUM_PRODUCTS] = { 0.30, 0.05, 0.10, 0.40, 0 };
    int product_counts[NUM_PRODUCTS] = { 0 };
    int product = -1;

    char names[NUM_PRODUCTS][20] = {
        "Book",
        "Pen",
        "Notebook",
        "Backpack",
        "Eraser"
    };

    // Выводим исходный список услуг
    print_services_list();

    int command;
    double total = 0;

    do {
        scanf_s("%d", &command);
        switch (command) {
        case 1:   // команда "сканировать новый продукт"
            scan_product(&product, product_code, product_counts);
            if (product != -1) {
                for (int i = 0; i < NUM_PRODUCTS; i++) {
                    if (product_code[i] == product) {
                        printf("Scanned product: %s\n", names[i]);  // "Отсканированный продукт:"
                    }
                }
            }
            break;
        case 2:  
            print_product_info(&product, product_code, product_prices, discounts);
            break;
        case 3:  
            produce_receipt(product_counts, product_code, discounts, product_prices, &total);
            break;
        case 4:  
            printf("Exiting the program, thanks for using!\n");  // "Выход из программы, спасибо за использование!"
            break;
        default:  
            printf("Command doesn't exist\n");  
            break;
        }
    } while (command != 4); 

    return 0;  
}

