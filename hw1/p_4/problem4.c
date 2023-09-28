#include <stdio.h>

int main() {
    /* Initialize blank counter */
    int blank_counter = 0;
    /* Initialize tab counter */
    int tab_counter = 0;
    /* Initialize new line counter */
    int new_line_counter = 0;
    /* Initialize char variable */
    char c;
    /* Read input from user */
    while ((c = getchar()) != EOF) {
        /* Increment count variables
         ASCII for new line character */
        if (c == 10) {
            new_line_counter++;
        /* ASCII for new line character */
        } else if (c == 9) {
            tab_counter++;
        /* ASCII for space character */
        } else if (c == 32) {
            blank_counter++;
        }
    }
    /* Print count variables */
    printf("Number of blanks counted: %i\n", blank_counter);
    printf("Number of tabs counted: %i\n", tab_counter);
    printf("Number of new lines counted: %i\n", new_line_counter);

    return 0;
}
