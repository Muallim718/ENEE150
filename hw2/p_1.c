#include <stdio.h>

int gcd(int x, int y);

int main(void) {
    /* Scan for user input */
    int x, y;
    do {
        printf("Enter x and y (Usage: x, y):\n");
        scanf("%d, %d", &x, &y);
    } while(x < 0 || y < 0);
    /* Print the answer */
    int answer = gcd(x, y);
    printf("The GCD is %i\n", answer);

    return 0;
}

int gcd(int x, int y) {
    /* Implement the given equation */
    if (y != 0) {
        return gcd(y, x % y);
    }
    return x;
}