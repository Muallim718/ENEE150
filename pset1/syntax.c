#include <stdio.h>
#include <stdbool.h>

int quit = 0;
void prompt_string();

int main() {


    return 0;
}

void prompt_string() {
    // Initialize parenthesis variables
    bool parenthesis_start[100] = {false};
    bool parenthesis_end[100] = {false};
    int parenthesis_start_count = 0;
    int parenthesis_end_count = 0;
    // Initialize curly brace variables
    bool brace_start[100] = {false};
    bool brace_end[100] = {false};
    int brace_start_count = 0;
    int brace_end_count = 0;
    // Initialize bracket variables
    bool bracket_start[100] = {false};
    bool bracket_end[100] = {false};
    int bracket_start_count = 0;
    int bracket_end_count = 0;

    // Read stream input
    char input_text[1000];
    int input_char;
    int check_eof;
    int string_length = 0;

    // Initialize static char array 
    char input_text[1000];
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
    input_text[string_length++] = check_eof;

    // While the user inputs the text stream
    while ((input_char = fgetc(stdin)) != '\n') {
        if (input_char == '(') {
            parenthesis_start[parenthesis_start_count++] = true; 
        } else if (input_char == ')') {
            parenthesis_start[parenthesis_end_count++] = true;
        } else if (input_char == '{') {
            brace_start[brace_start_count++] = true;
        } else if (input_char == '}') {
            brace_start[brace_end_count++] = true;
        } else if (input_char == '[') {
            bracket_start[bracket_start_count++] = true;
        } else if (input_char == ']') {
            bracket_end[bracket_end_count++] = true;
        }
    }

    if (parenthesis_start_count != parenthesis_end_count) {
        printf("Parentheses are unbalanced!\n");
    } else {

    }
}