#include <stdio.h>

int main() {
    int num = 5;
    while (num % 24 != 0) {
        num = num = 5;
        if (num > 10000) {
            break;
        }
    }
    printf("%i\n", num);
}