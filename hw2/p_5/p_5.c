#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 10

typedef struct number_info {
    char *digit;
    int count;
} number_info;

void process_string(char *string, int string_length);

int main(void) {
    int i;
    char *string;
    size_t buffer = 1000;
    printf("Enter 20+ words written in the form of digits.\n");
    size_t characters = getline(&string, &buffer, stdin);
    printf("%s", string);
    int string_length = strlen(string);
    process_string(string, string_length);
    return 0;
}

void process_string(char *string, int string_length) {
    int i, j;
    int space = 32;
    int count = 0;
    char number[SIZE];
    number_info digit_info[SIZE];
    char *digits[] = {"zero", "one", "two", "three", "four", 
                      "five", "six", "seven", "eight", "nine"};

    for (i = 0; i < SIZE; i++) {
        digit_info[i].digit = (char *) malloc(SIZE * sizeof(char));
        strcpy(digit_info[i].digit, digits[i]);
        if (digit_info[i].digit == NULL) {
            printf("Seg fault danger.\n");
            return;
        }
        digit_info[i].count = 0;
    }

    for (i = 0; i < string_length; i++) {
        if (string[i] != space && string[i] != '\n') {
            number[count++] = string[i];
        } else if (string[i] == space || string[i] == '\0' || string[i] == '\n') {
            number[count] = '\0';
            for (j = 0; j < SIZE; j++) {
                if (strcmp(digit_info[j].digit, number) == 0) {
                    digit_info[j].count++;
                }
            }
            count = 0;
            memset(number, ' ', sizeof(number));
        }
    }

    for (i = 0; i < SIZE; i++) {
        printf("%s: %i\n", digit_info[i].digit, digit_info[i].count);
    }

    for (i = 0; i < SIZE; i++) {
        free(digit_info[i].digit);
    }
}