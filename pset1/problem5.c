#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int quit = 0;

void reverse_string(char string[], int length);
void prompt_string();

int main() {
    // Continue prompting the user for a line to be reversed until EOF is entered
    while (quit == 0) {
        prompt_string();
    }

    return 0;
}

// Prompt the user for a string
void prompt_string() {
    // Initialize a static char array 
    char string[100];
    // Read all characters up until the newline character
    int result = scanf("%99[^\n]%*c", string);

    if (result != 1) {
        quit = 1;
        return;
    }

    // Reverse the string
    reverse_string(string, strlen(string));
    // Print the reversed string
    printf("string: %s\n", string);
}

// Reverse string function
void reverse_string(char string[], int length) {
    // Swap the elements
    for (int i = 0; i < length / 2; i++) {
        char first = string[i];
        char last = string[length - i - 1];
        string[length - i - 1] = first;
        string[i] = last;
    }
}