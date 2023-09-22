#include <stdio.h>
#include <stdbool.h>

int quit = 0;
void prompt_string();

int main() {
    printf("Start of the program WOW.\n");
    char input_text[1000];
    scanf("%s", input_text);

    /*
    printf("Enter text, enter EOF to end the program. \n");
    // Continue prompting user for a line to be reversed until EOF is entered
    while (quit == 0) {
        prompt_string();
    }
    printf("EOF character entered, exiting program now.\n");
    */

    return 0;
}

void prompt_string() {
    // Initialize parenthesis variables
    bool parenthesis_start[100] = {false};
    bool parenthesis_end[100] = {false};
    bool parenthesis_unbalanced = false;
    int parenthesis_count = 0;
    int parenthesis_start_count = 0;
    int parenthesis_end_count = 0;
    // Initialize curly brace variables
    bool brace_start[100] = {false};
    bool brace_end[100] = {false};
    bool brace_unbalanced = false;
    int brace_count = 0;
    int brace_start_count = 0;
    int brace_end_count = 0;
    // Initialize bracket variables
    bool bracket_start[100] = {false};
    bool bracket_end[100] = {false};
    bool bracket_unbalanced = false;
    int bracket_count = 0;
    int bracket_start_count = 0;
    int bracket_end_count = 0;

    // Initialize static char array 
    char input_text[1000];
    int input_char;
    int check_eof;
    printf("Enter string: ");
    // Initialize string length
    int string_length = 0;

    /*
    // If user inputs EOF
    if ((check_eof = fgetc(stdin)) == EOF) {
        // Exit the function and while loop
        quit = 1;
        printf("\n");
        return;
    }
    // If not EOF, store the first character from the stream
    input_text[string_length++] = check_eof;
    */
    scanf("%s", input_text);

    return;

    // While the user inputs the text stream
    while ((input_char = fgetc(stdin)) != '\n') {
        if (parenthesis_end[parenthesis_count] == true 
            && parenthesis_start[parenthesis_count] == false) {
            parenthesis_unbalanced = true;
        } else if (brace_end[brace_count] == true
            && brace_start[brace_count] == false) {
            brace_unbalanced = true;
        } else if (bracket_end[bracket_count] == true
            && bracket_start[bracket_count] == false) {
            bracket_unbalanced = true;
        }

        if (input_char == '(') {
            parenthesis_start[parenthesis_start_count++] = true;
            parenthesis_count++;
        } else if (input_char == ')') {
            parenthesis_end[parenthesis_end_count++] = true;
            parenthesis_count++;
        } else if (input_char == '{') {
            brace_start[brace_start_count++] = true;
            brace_count++;
        } else if (input_char == '}') {
            brace_end[brace_end_count++] = true;
            brace_count++;
        } else if (input_char == '[') {
            bracket_start[bracket_start_count++] = true;
            bracket_count++;
        } else if (input_char == ']') {
            bracket_end[bracket_end_count++] = true;
            bracket_count++;
        }
    }

    if (parenthesis_start_count != parenthesis_end_count) {
        parenthesis_unbalanced = true;
    } else {
        for (int i = 0; i < parenthesis_count / 2; i++) {
            if (parenthesis_start[i] != parenthesis_end[i]) {
                parenthesis_unbalanced = true;
            }
        }
    }

    if (brace_start_count != brace_end_count) {
        brace_unbalanced = true;
    } else {
        for (int i = 0; i < brace_count / 2; i++) {
            if (brace_start[i] != brace_end[i]) {
                brace_unbalanced = true;
            }
        }
    } 
    
    if (bracket_start_count != bracket_end_count) {
        bracket_unbalanced = true;
    } else {
        for (int i = 0; i < bracket_count / 2; i++) {
            if (bracket_start[i] != bracket_end[i]) {
                bracket_unbalanced = true;
            }
        }
    }

    if (parenthesis_unbalanced) {
        printf("Parentheses are unbalanced!\n");
    } 
    if (brace_unbalanced) {
        printf("Curly brackets are unbalanced!\n");
    } 
    if (bracket_unbalanced) {
        printf("Square brackets are unbalanced!\n");
    } 
    if (!parenthesis_unbalanced && !brace_unbalanced && !bracket_unbalanced) {
        printf("Perfectly balanced, as all things should be.\n");
    }
}