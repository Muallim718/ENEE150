#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define SIZE 100

typedef struct syntax_info {
    bool start[SIZE];
    bool end[SIZE];
    bool unbalanced;
    int count;
    int start_count;
    int end_count;
} syntax_info;

int string_length = 0;

void check_syntax(syntax_info *parenthesis, syntax_info *brace, syntax_info *bracket);
void count_syntax(char string[], syntax_info *parenthesis, syntax_info *brace, syntax_info *bracket);
void print_answers(syntax_info *parenthesis, syntax_info *brace, syntax_info *bracket);
void reset(syntax_info *character);
int read_string(char string[]);

int main() {
    printf("Enter text, enter EOF to end the program.\n");
    // Continue checking user for a line to be reversed until EOF is entered
    syntax_info parenthesis;
    syntax_info brace;
    syntax_info bracket;
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
        reset(&parenthesis), reset(&brace), reset(&bracket);
        count_syntax(resized_string, &parenthesis, &brace, &bracket);
        check_syntax(&parenthesis, &brace, &bracket);
        print_answers(&parenthesis, &brace, &bracket);
    }
    printf("EOF character entered, exiting program now.\n");
    
    return 0;
}

void check_syntax(syntax_info *parenthesis, syntax_info *brace, syntax_info *bracket) {
    if (parenthesis -> start_count != parenthesis -> end_count) {
        parenthesis -> unbalanced = true;
    } else {
        for (int i = 0; i < (parenthesis -> count) / 2; i++) {
            if (parenthesis -> start[i] != parenthesis -> end[i]) {
                parenthesis -> unbalanced = true;
            }
        }
    }

    if (brace -> start_count != brace -> end_count) {
        brace -> unbalanced = true;
    } else {
        for (int i = 0; i < (brace -> count) / 2; i++) {
            if (brace -> start[i] != brace -> end[i]) {
                brace -> unbalanced = true;
            }
        }
    } 
    
    if (bracket -> start_count != bracket -> end_count) {
        bracket -> unbalanced = true;
    } else {
        for (int i = 0; i < (bracket -> count) / 2; i++) {
            if (bracket -> start[i] != bracket -> end[i]) {
                bracket -> unbalanced = true;
            }
        }
    }
}

void count_syntax(char string[], syntax_info *parenthesis, syntax_info *brace, syntax_info *bracket) {
    for (int i = 0; i < string_length; i++) {
        if (string[i] == '(') {
            parenthesis -> start[parenthesis -> start_count] = true;
            parenthesis -> start_count++;
        } else if (string[i] == ')') {
            parenthesis -> end[parenthesis -> end_count] = true;
            parenthesis -> end_count++;
        } else if (string[i] == '{') {
            brace -> start[brace -> start_count] = true;
            brace -> start_count++;
        } else if (string[i] == '}') {
            brace -> end[brace -> end_count] = true;
            brace -> end_count++;
        } else if (string[i] == '[') {
            bracket -> start[bracket -> start_count] = true;
            bracket -> start_count++;
        } else if (string[i] == ']') {
            bracket -> end[bracket -> end_count] = true;
            bracket -> end_count++;
        }
        
        for (int i = 0; i < parenthesis -> count; i++) {
            if (parenthesis -> end[i] == true && parenthesis -> start[i] == false) {
                parenthesis -> unbalanced = true;
            }
        }
    
        for (int i = 0; i < brace -> count; i++) {
            if (brace -> end[i] == true && brace -> start[i] == false) {
                brace -> unbalanced = true;
            }
        }

        for (int i = 0; i < bracket -> count; i++) {
            if (bracket -> end[i] == true && bracket -> start[i] == false) {
                bracket -> unbalanced = true;
            }
        }
    }
}

void print_answers(syntax_info *parenthesis, syntax_info *brace, syntax_info *bracket) {
    if (parenthesis -> unbalanced) {
        printf("Parentheses are unbalanced!\n");
    } 
    if (brace -> unbalanced) {
        printf("Curly brackets are unbalanced!\n");
    } 
    if (bracket -> unbalanced) {
        printf("Square brackets are unbalanced!\n");
    } 
    if (!(parenthesis -> unbalanced) && !(brace -> unbalanced) && !(bracket -> unbalanced)) {
        printf("Perfectly balanced, as all things should be.\n");
    }
}

void reset(syntax_info *character) {
    for (int i = 0; i < SIZE; i++) {
        character -> start[i] = false;
        character -> end[i] = false; 
    }
    character -> unbalanced = false;
    character -> start_count = 0;
    character -> end_count = 0;
    character -> count = 0;
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