#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define SIZE 1000

void reverse_string(char string[], int length);

int main() {
    char string[SIZE];
    int c;
    
    while (true) {
        int length = 0;
        
        while ((c = getchar()) != '\n' && c != EOF) {
            string[length++] = c;
        }
        if (c == EOF) {
            break;
        }

        string[length] = '\0';
        reverse_string(string, length);
        printf("string: %s\n", string);
    }

    return 0;
}

void reverse_string(char string[], int length) {
    int i;
    for (i = 0; i < length / 2; i++) {
        char temp = string[i];
        string[i] = string[length - i - 1];
        string[length - i - 1] = temp;
    }
}
