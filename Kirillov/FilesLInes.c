#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_STRING_LENGTH 1000
#define MAX_PEOPLE 100

struct Person {
    char* surname;
    char* phone;
    char* email;
};

bool checkPhone(const char* str) {
    if (str[0] == '+') {
        if (strlen(str) == 12) {
            for (int i = 1; i < 12; ++i) {
                if (str[i] < '0' || str[i] > '9') {
                    return false; 
                }
            }
            return true; 
        }
    }
    return false; 
}

void checkToken(struct Person* person, const char* token) {
    if (checkPhone(token)) {
        person->phone = _strdup(token);
    }
    else if (strchr(token, '@') != NULL) {
        person->email = _strdup(token);
    }
    else {
        if (person->surname == NULL) {
            person->surname = _strdup(token);
        }
        else {
            size_t len = strlen(person->surname) + strlen(token) + 2;
            char* temp = (char*)malloc(len);
            sprintf_s(temp, len, "%s %s", person->surname, token);
            free(person->surname);
            person->surname = temp;
        }
    }
}

struct Person parseString(const char* str) {
    struct Person person = { NULL, NULL, NULL };

    char* strCopy = _strdup(str);
    char* token;
    char* context = NULL;

    token = strtok_s(strCopy, " ", &context);
    while (token != NULL) {
        checkToken(&person, token);
        token = strtok_s(NULL, " ", &context);
    }
    
    free(strCopy);
    return person;
}

int main() {
    const char* filepath = "C:\\IT\\C-C++\\LinesFiles\\test.txt";
    FILE* file;
    
    if (fopen_s(&file, filepath, "r") != 0) {
        perror("Ошибка открытия файла");
        return 1;
    }

    struct Person* people = (struct Person*)malloc(MAX_PEOPLE * sizeof(struct Person));
    if (people == NULL) {
        perror("Ошибка выделения памяти для массива людей");
        fclose(file);
        return 1;
    }

    int numPeople = 0;

    char* buffer = (char*)malloc(MAX_STRING_LENGTH);
    while (fgets(buffer, MAX_STRING_LENGTH, file) != NULL) {
        people[numPeople++] = parseString(buffer);

        
        if (numPeople >= MAX_PEOPLE) {
            break;
        }
    }

    fclose(file);

    
    for (int i = 0; i < numPeople; ++i) {
        printf("Person %d:\n", i + 1);
        printf("Surname: %s\n", people[i].surname);
        printf("Phone number: %s\n", people[i].phone);
        printf("Email: %s\n", people[i].email);
        printf("\n");

        
        free(people[i].surname);
        free(people[i].phone);
        free(people[i].email);
    }

    free(people);
    free(buffer);

    return 0;
}
