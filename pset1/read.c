#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int string_length = 0;

int read_string(char string[]);

int main() {
    printf("Enter text, enter EOF to end the program. \n");
    // Continue checking user for a line to be reversed until EOF is entered
    while (true) {
        char string[1000];
        printf("Enter string: ");
        int result = read_string(string);
        if (result == EOF) {
            printf("\n");
            break;
        }
        char resized_string[string_length];
        strcpy(resized_string, string);
    }
    printf("EOF character entered, exiting program now.\n");
    
    return 0;
}

int read_string(char string[]) {
    int c;
    string_length = 0;
    while(((c = getchar()) != EOF) && c != '\n') {
        string[string_length++] = c;
    }
    string[string_length] = '\0';
    return c;
}