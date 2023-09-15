#include <stdio.h>
#include <math.h>

int main(){
    // Get input for a
    int a;
    do {
        printf("Enter a: ");
        scanf("%d", &a);
    } while (a < -100 || a > 100);
    // Get input for b
    int b;
    do {
        printf("Enter b: ");
        scanf("%d", &b);
    } while (b < -100 || b > 100);
    // Get input for c
    int c;
    do {
        printf("Enter c: ");
        scanf("%d", &c);
    } while (c < -100 || c > 100);

    // Compute the discriminant
    double discriminant = sqrt(pow(b, 2) - 4 * a * c);
    printf("This is the discriminant %f\n", discriminant);

    return 0;
}