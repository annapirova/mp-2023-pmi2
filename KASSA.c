#include <stdio.h>
#include <math.h>
#include <locale.h>
#include <stdlib.h> 
#include <string.h>
#include <time.h>

#define NUM_PRODUCTS 5  //  ���������� ���������

// ������� ��� ������ ������ ��������� ��������
void print_services_list() {
    printf("1 - scan new product\n");  // "����������� ����� �������"
    printf("2 - see information about last scanned product\n");  // "���������� ���������� � ��������� ��������������� ��������"
    printf("3 - produce info about product\n");  // "������� ���������� � ��������"
    printf("4 - exit the program\n");  // "����� �� ���������"
}

// ������� ��� ������������ ��������
void scan_product(int* product, int product_code[], int product_counts[]) {
    int total_scanned = 0; // переменная для подсчета общего количества отсканированных товаров
    int product_check = -1; // переменная для сверки введенного пользователем кода товара

    printf("Input product code\n"); // "Введите код продукта"
    scanf_s("%d", product);

    if (*product == product_check) {
        printf("Product is invalide\n"); // "Товар недействителен"
        return;
    }

    int index, f = 0;
    for (index = 0; index < NUM_PRODUCTS; index++) {
        if (product_code[index] == *product) {
            product_counts[index]++;
            f = 1;
            total_scanned++; // увеличиваем счетчик отсканированных товаров
        }
    }

    if (f == 0) {
        printf("Product doesn't exist\n"); // "Такого продукта не существует"
    }
    else {
        printf("Total scanned: %d\n", total_scanned); // выводим общее количество отсканированных товаров
    }
}

// ������� ��� ������ ���������� � ��������
void print_product_info(int* product, int product_code[], int product_prices[], double discounts[]) {
    int i;
    if (*product == -1) {
        printf("Scan any product first\n");  // "������� ������������ ����� �������"
        return;
    }

    // ���������� ��� �������� � ���� ���������� �� ����
    for (i = 0; i < NUM_PRODUCTS; i++) {
        if (product_code[i] == *product) {
            printf("Product code - %d\n", product_code[i]);  // ������� ��� ��������
            printf("Price(without discount) - %d\n", product_prices[i]);  // ������� ���� ��� ������
            printf("Discount - %.2lf\n", discounts[i]);  // ������� ������
            printf("Price(with discount) - %.2lf\n", (double)product_prices[i] * (1 - discounts[i]));  // ������� ���� �� �������
        }
    }
}

// ������� ��� ������������ ����
void produce_receipt(int product_counts[], int product_code[],
    double discounts[], int product_prices[], double* total) {

    printf("Receipt:\n");  // "���:"
    printf("Product code  count  discount  price\n");  // "��� ��������  ����������  ������  ����"

    for (int i = 0; i < NUM_PRODUCTS; i++) {
        if (product_counts[i] != 0) {
            // ��������� �������� ��������� �� ������� � ������ ������ � ����������(���� ������� ������������)
            double final_price = (double)product_prices[i] * (1 - discounts[i]) * product_counts[i];
            printf("%d %d %.2lf %.2lf\n", product_code[i], product_counts[i], discounts[i], final_price);
            *total += final_price;  //  ����� ��������� �������
        }
    }

    printf("\nTotal %.2lf\n", *total);
}
// ������� ��� ���������� ��������� �� ����
int diff_products_bought(int product_counts[]) {
    int count = 0;
    for (int i = 0; i < NUM_PRODUCTS; i++) {
        if (product_counts[i] > 0) count++;
    }
    return count;
}

// Функция показывает, сколько и какой продукт купил пользователь
void products_bought(int product_counts[], char names[][20]) {
    for (int i = 0; i < NUM_PRODUCTS; i++) {
        if (product_counts[i] > 0)
            printf("User bought %d of product: %s\n", product_counts[i], names[i]);
    }
}
void sort_by_price(int product_code[], int product_prices[], int products_number) {
    for (int i = 0; i < products_number - 1; i++) {
        for (int j = 0; j < products_number - i - 1; j++) {
            // ���� ������� ������� ������ ����������, ������ �� �������
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

    // ������� �������� ������ �����
    print_services_list();

    int command;
    double total = 0;

    do {
        scanf_s("%d", &command);
        switch (command) {
        case 1:
            scan_product(&product, product_code, product_counts);
            if (product != -1) {
                for (int i = 0; i < NUM_PRODUCTS; i++) {
                    if (product_code[i] == product) {
                        printf("Scanned product: %s\n", names[i]);
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
            printf("User bought the following amount and types of products:\n");
            products_bought(product_counts, names);  // Новая функция
            printf("Total types of products bought: %d\n", diff_products_bought(product_counts)); // Новая функция
            printf("Exiting the program, thanks for using!\n");
            break;
        default:
            printf("Command doesn't exist\n");
            break;
        }
    } while (command != 4);
    return 0;
}


