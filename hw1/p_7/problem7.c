#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int string_length = 0;

int read_string(char string[]);
int check_balance(char string[], char open_char, char end_char);

int main() {
    /* Continue checking user for a line 
     to be reversed until EOF is entered */
    while (true) {
        char string[1000];
        int result = read_string(string);
        if (result == EOF) {
            break;
        }
        int parenthesis_balance = check_balance(string, '(', ')');
        int curly_balance = check_balance(string, '{', '}');
        int bracket_balance = check_balance(string, '[', ']');

        if (parenthesis_balance != 0) {
            printf("parentheses unbalanced!\n");
        }
        if ((curly_balance != 0)) {
            printf("curly brackets unbalanced!\n");
        }
        if ((bracket_balance != 0)) {
            printf("square brackets unbalanced!\n");
        }
        if (parenthesis_balance == 0 && curly_balance == 0 && bracket_balance == 0) {
            printf("Perfectly balanced, as all things should be.\n");
        }
    }
    
    return 0;
}

int check_balance(char string[], char open_char, char end_char) {
    int count = 0;
    int i;
    for (i = 0; i < string_length; i++) {
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
