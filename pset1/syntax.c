#include <stdio.h>
#include <stdbool.h>
#include <string.h>

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

int string_length = 0;
bool parenthesis_start[100];

void check_syntax();
void count_syntax(char string[]);
void print_answers();
void reset_parenthesis(bool arr[]);
void reset_brace(bool arr[]);
void reset_bracket(bool arr[]);
int read_string(char string[]);

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
        char resized_string[string_length];
        strcpy(resized_string, string);
        count_syntax(resized_string);
        check_syntax();
        print_answers();
        reset_parenthesis(parenthesis_start);
        reset_parenthesis(parenthesis_end);
        reset_brace(brace_start);
        reset_brace(brace_end);
        reset_bracket(bracket_start);
        reset_bracket(bracket_end);
        parenthesis_count = 0;
        parenthesis_start_count = 0;
        parenthesis_end_count = 0;
        brace_count = 0;
        brace_start_count = 0;
        brace_end_count = 0;
        bracket_count = 0;
        bracket_start_count = 0;
        bracket_end_count = 0;
    }
    printf("EOF character entered, exiting program now.\n");
    
    return 0;
}

void check_syntax() {
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
}

void count_syntax(char string[]) {
    for (int i = 0; i < string_length; i++) {
        if (string[i] == '(') {
            parenthesis_start[parenthesis_start_count++] = true;
            parenthesis_count++;
        } else if (string[i] == ')') {
            parenthesis_end[parenthesis_end_count++] = true;
            parenthesis_count++;
        } else if (string[i] == '{') {
            brace_start[brace_start_count++] = true;
            brace_count++;
        } else if (string[i] == '}') {
            brace_end[brace_end_count++] = true;
            brace_count++;
        } else if (string[i] == '[') {
            bracket_start[bracket_start_count++] = true;
            bracket_count++;
        } else if (string[i] == ']') {
            bracket_end[bracket_end_count++] = true;
            bracket_count++;
        }
        
        for (int i = 0; i < parenthesis_count; i++) {
            if (parenthesis_end[i] == true && parenthesis_start[i] == false) {
                parenthesis_unbalanced = true;
            }
        }
    
        for (int i = 0; i < brace_count; i++) {
            if (brace_end[i] == true && brace_start[i] == false) {
                brace_unbalanced = true;
            }
        }

        for (int i = 0; i < bracket_count; i++) {
            if (bracket_end[i] == true && bracket_start[i] == false) {
                bracket_unbalanced = true;
            }
        }
    }
}

void reset_parenthesis(bool arr[]) {
    parenthesis_unbalanced = false;
    for (int i = 0; i < parenthesis_count; i++) {
        arr[i] = false;
    }
}

void reset_brace(bool arr[]) {
    brace_unbalanced = false;
    for (int i = 0; i < brace_count; i++) {
        arr[i] = false;
    }
}

void reset_bracket(bool arr[]) {
    bracket_unbalanced = false;
    for (int i = 0; i < bracket_count; i++) {
        arr[i] = false;
    }
}

void print_answers() {
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

int read_string(char string[]) {
    int c;
    string_length = 0;
    while(((c = getchar()) != EOF) && c != '\n') {
        string[string_length++] = c;
    }
    string[string_length] = '\0';
    return c;
}