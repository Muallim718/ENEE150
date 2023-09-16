#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main() {
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
    float discriminant = pow(b, 2) - 4 * a * c;

    float a_float = (float) a;
    float b_float = (float) b;
    float c_float = (float) c;

    // If the discriminant is positive
    if (discriminant > 0) {
        float positive_root = (-1 * b + sqrt(discriminant)) / (2 * a_float);
        float negative_root = (-1 * b - sqrt(discriminant)) / (2 * a_float);
        printf("The solutions to the quadratic equation are as follows: \n");
        printf("Root: %0.3f\n", positive_root);
        printf("Root: %0.3f\n", negative_root);
    // If the discriminant is negative
    } else if (discriminant < 0) {
        float real_part = (-1 * b_float) / (2 * a_float);
        printf("Real part: %0.3f\n", real_part);
        float imaginary_part = sqrt(abs(discriminant)) / (2 * a_float);
        printf("The solutions to the quadratic equation are as follows: \n");
        printf("Root: %0.3f + j%0.3f\n", real_part, imaginary_part);
        printf("Root: %0.3f - j%0.3f\n", real_part, imaginary_part);
    // If the discriminant is zero 
    } else {
        float real_part = (-1 * b_float) / (2 * a_float);
        printf("The solutions to the quadratic equation are as follows: \n");
        printf("Root: %0.3f, with a multiplicity of 2\n", real_part);
    }
    
    return 0;
}