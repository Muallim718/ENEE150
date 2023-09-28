#include <stdio.h>
#include <stdlib.h>

int main(void) {
    char *string;
    string = (char *) malloc(sizeof(char));
    if (string == NULL) {
        printf("Memory allocation failed.\n");
        return 0;
    }
    char c;
    int count = 0;
    int size = 1;

    while((c = getchar()) != EOF && c != '\n') {
        string[count++] = c;
        size++;
        string = (char *) realloc(string, size * sizeof(char));
        if (string == NULL) {
            printf("Memory allocation failed.\n");
            return 0;
        }
    }
    string[count] = '\0'; 
    printf("String: %s\n", string);
    free(string);

    return 0;
}