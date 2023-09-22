#include <stdio.h>
#include <stdbool.h>

#define SIZE 100

typedef struct syntax_info {
    bool start[SIZE];
    bool end[SIZE];
    bool unbalanced;
    int count;
    int start_count;
    int end_count;
} syntax_info;

int quit = 0;
void initialize_info(syntax_info *character);
void check_string(char input_char, syntax_info *parenthesis, syntax_info *brace, syntax_info *bracket);
void check_syntax();

int main() {
    printf("Enter text, enter EOF to end the program. \n");
    // Continue checking user for a line to be reversed until EOF is entered
    while (quit == 0) {
        check_syntax();
    }
    printf("EOF character entered, exiting program now.\n");

    return 0;
}

void check_syntax() {
    // Initialize parenthesis variables
    syntax_info parenthesis;
    initialize_info(&parenthesis);
    // Initialize curly brace variables
    syntax_info brace;
    initialize_info(&brace);
    // Initialize bracket variables
    syntax_info bracket;
    initialize_info(&bracket);

    // Initialize static char array 
    int input_char;
    printf("Enter string: ");

    // If user inputs EOF
    if ((input_char = fgetc(stdin)) == EOF) {
    // Exit the function and while loop
        quit = 1;
        printf("\n");
        return;
    }
    check_string(input_char, &parenthesis, &brace, &bracket);

    // While the user inputs the text stream
    while ((input_char = fgetc(stdin)) != '\n') {
        check_string(input_char, &parenthesis, &brace, &bracket);
    }

    if (parenthesis.start_count != parenthesis.end_count) {
        parenthesis.unbalanced = true;
    } else {
        for (int i = 0; i < parenthesis.count / 2; i++) {
            if (parenthesis.start[i] != parenthesis.end[i]) {
                parenthesis.unbalanced = true;
            }
        }
    }

    if (brace.start_count != brace.end_count) {
        brace.unbalanced = true;
    } else {
        for (int i = 0; i < brace.count / 2; i++) {
            if (brace.start[i] != brace.end[i]) {
                brace.unbalanced = true;
            }
        }
    } 
    
    if (bracket.start_count != bracket.end_count) {
        bracket.unbalanced = true;
    } else {
        for (int i = 0; i < bracket.count / 2; i++) {
            if (bracket.start[i] != bracket.end[i]) {
                bracket.unbalanced = true;
            }
        }
    }

    if (parenthesis.unbalanced) {
        printf("Parentheses are unbalanced!\n");
    } 
    if (brace.unbalanced) {
        printf("Curly brackets are unbalanced!\n");
    } 
    if (bracket.unbalanced) {
        printf("Square brackets are unbalanced!\n");
    } 
    if (!parenthesis.unbalanced && !brace.unbalanced && !bracket.unbalanced) {
        printf("Perfectly balanced, as all things should be.\n");
    }
}

void initialize_info(syntax_info *character) {
    for (int i = 0; i < SIZE; i++) {
        character -> start[i] = false;
        character -> end[i] = false;
    }

    character -> unbalanced = false;
    character -> count = 0;
    character -> start_count = 0;
    character -> end_count = 0;
}

void check_string(char input_char, syntax_info *parenthesis, syntax_info *brace, syntax_info *bracket) {
    if (parenthesis -> end[parenthesis -> count] == true 
        && parenthesis -> start[parenthesis -> count] == false) {
        parenthesis -> unbalanced  = true;
    } else if (brace -> end[brace -> count] == true
        && brace -> start[brace -> count] == false) {
        brace -> unbalanced = true;
    } else if (bracket -> end[bracket -> count] == true
        && bracket -> start[bracket -> count] == false) {
        bracket -> unbalanced = true;
    }

    if (input_char == '(') {
        parenthesis -> start[parenthesis -> start_count++] = true;
        parenthesis -> count++;
    } else if (input_char == ')') {
        parenthesis -> end[parenthesis -> end_count++] = true;
        parenthesis -> count++;
    } else if (input_char == '{') {
        brace -> start[brace -> start_count++] = true;
        brace -> count++;
    } else if (input_char == '}') {
        brace -> end[brace -> end_count++] = true;
        brace -> count++;
    } else if (input_char == '[') {
        bracket -> start[bracket -> start_count++] = true;
        bracket -> count++;
    } else if (input_char == ']') {
        bracket -> end[bracket -> end_count++] = true;
        bracket -> count++;
    }
}