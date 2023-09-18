#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int quit = 0;

void prompt_string();

int main() {
    printf("Start of the program. \n");
    printf("Enter EOF to end the program. \n");
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
    int input_char;
    int check_eof;
    printf("Enter string: ");
    // Initialize string length
    int string_length = 0;
    
    // If user inputs EOF
    if ((check_eof = fgetc(stdin)) == EOF) {
        // Exit the function and while loop
        quit = 1;
        printf("\n");
        return;
    }
    // If not EOF, store the first character from the stream
    string[string_length++] = check_eof;

    // While the user inputs the text stream
    while ((input_char = fgetc(stdin)) != '\n') {
        // Insert the characters in the string array
        string[string_length++] = input_char;
    }
    // Create a new array which will be reversed
    char resized_string[string_length];
    // Copy over the elements
    for (int i = 0; i < string_length; i++) {
        resized_string[i] = string[i];
    }
    // Print the string containing thirty characters or less
    if (string_length <= 30) {
        printf("Input text contained thirty characters or less.\n");
        printf("Input text will be printed: ");
        for (int i = 0; i < string_length; i++) {
            printf("%c", resized_string[i]);
        }
        printf("\n");
    } else {
        printf("Input text contained more than thirty characters. \n");
        printf("Input text will not be printed. \n");
    }
}