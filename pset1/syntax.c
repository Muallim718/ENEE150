#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int string_length = 0;

int read_string(char string[]);
int check_balance(char string[], char open_char, char end_char);

int main() {
    printf("Enter text, enter EOF to end the program.\n");
    // Continue checking user for a line to be reversed until EOF is entered
    while (true) {
        char string[1000];
        printf("Enter string: ");
        int result = read_string(string);
        if (result == EOF) {
            printf("\n");
            break;
        }
        int parenthesis_balance = check_balance(string, '(', ')');
        int curly_balance = check_balance(string, '{', '}');
        int bracket_balance = check_balance(string, '[', ']');

        if (parenthesis_balance != 0) {
            printf("Parentheses are unbalanced!\n");
        }
        if ((curly_balance != 0)) {
            printf("Curly braces are unbalanced!\n");
        }
        if ((bracket_balance != 0)) {
            printf("Square brackets are unbalanced!\n");
        }
        if (parenthesis_balance == 0 && curly_balance == 0 && bracket_balance == 0) {
            printf("Perfectly balanced, as all things should be.\n");
        }
    }
    printf("EOF character entered, exiting program now.\n");
    
    return 0;
}

int check_balance(char string[], char open_char, char end_char) {
    int count = 0;
    for (int i = 0; i < string_length; i++) {
        if (string[i] == open_char) {
            count++;
        } else if (string[i] == end_char) {
            count--;
        }
        if (count < 0) {
            return -1;
        }
    }
    if (count > 0) {
        return 1;
    }
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