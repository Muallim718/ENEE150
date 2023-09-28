#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

#define SIZE 1000

void reverse_string(char string[], int length);

int main() {
    char string[SIZE];
    int c;
    
    /* Until EOF is reached */
    while (true) {
	/* Get string from user */
        int length = 0;
        
        while ((c = getchar()) != '\n' && c != EOF) {
            string[length++] = c;
        }
        if (c == EOF) {
            break;
        }

        string[length] = '\0';
	/* Reverse string */
        reverse_string(string, length);
	/* Print the reversed string */
        if (string[0] == '\r') {
	    printf("string: %s\n", string + 1);
	} else {
	    printf("string: %s\n", string);
	}
    }

    return 0;
}

void reverse_string(char string[], int length) {
    int i;
    /* Swap the elements of the string */
    for (i = 0; i < length / 2; i++) {
        char temp = string[i];
	/* Ensure with the -1 there is no indexing error */
        string[i] = string[length - i - 1];
        string[length - i - 1] = temp;
    }
}
