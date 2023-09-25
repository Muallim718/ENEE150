#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 100

int quit = 0;

void prompt_string();

int main() {
    // Continue prompting user for a line to be reversed until EOF is entered
    while (quit == 0) {
        prompt_string();
    }

    return 0;
}

// Prompt user for a string
void prompt_string() {
    // Initialize a static char array 
    char string[SIZE];
    int c = 0;
    int length = 0;
    
    while ((c = getchar()) != '\n' && c != EOF) {
        string[length++] = c;
    }
    string[length] = '\0';

    if (c == EOF) {
        quit = 1;
    }
    // Print the string containing thirty characters or less
    if (length > 30) {
        printf("%s\n", string);
    }
}