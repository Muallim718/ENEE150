#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void reverse_string(char* string, int str_length);

int main() {
    char string[100];
    char c;
    // Figure out how to do multiple without missing first character
    printf("Enter string: ");
    int string_length = 0;
    while ((c = getchar()) != '\n') {
        string[string_length++] = c;
    }
    char resized_string[string_length];
    for (int i = 0; i < string_length; i++) {
        resized_string[i] = string[i];
        }

        for (int i = 0; i < string_length; i++) {
            printf("%c", string[i]);
        }

        reverse_string(resized_string, string_length);

        printf("Reversed string: ");
        for (int i = 0; i < string_length; i++) {
            printf("%c", resized_string[i]);
        }
        printf("\n");

    return 0;
}

// Reverse string function
void reverse_string(char* string, int str_length) {
    for (int i = 0; i < str_length / 2; i++) {
        char first = string[i];
        char last = string[str_length - i - 1];
        string[str_length - i - 1] = first;
        string[i] = last;
    }
    printf("\n");
}