#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int quit = 0;

void reverse_string(char* string, int str_length);
void prompt_string();

int main() {
    printf("Enter text to be reversed. \n");
    // Continue prompting user for a line to be reversed until EOF is entered
    while (quit == 0) {
        prompt_string();
    }
    printf("EOF character entered, exiting program now.\n");

    return 0;
}

// Prompt user for a string
void prompt_string() {
    // Initialize static char array 
    char string[100];
    char c;
    printf("Enter string: ");
    // Initialize string length
    int string_length = 0;
    // If user inputs EOF
    if (c = getchar() == EOF) {
        // Exit the function and while loop
        quit = 1;
        printf("\n");
        return;
    }
    // While the user inputs the text stream
    while ((c = getchar()) != '\n') {
        // Insert the characters in the string array
        string[string_length++] = c;
    }
    // Create a new array which will be reversed
    char resized_string[string_length];
    // Copy over the elements
    for (int i = 0; i < string_length; i++) {
        resized_string[i] = string[i];
    }
    // Reverse the string
    reverse_string(resized_string, string_length);
    // Print the reversed string
    printf("Reversed string: ");
    for (int i = 0; i < string_length; i++) {
        printf("%c", resized_string[i]);
    }
    printf("\n");
}

// Reverse string function
void reverse_string(char* string, int str_length) {
    // Swap the elements
    for (int i = 0; i < str_length / 2; i++) {
        char first = string[i];
        char last = string[str_length - i - 1];
        string[str_length - i - 1] = first;
        string[i] = last;
    }
}