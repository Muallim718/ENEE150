#include <stdio.h>
#include <math.h>

int main() {
    int a, b, c;

    // Scan for input of a
    while (scanf("%d, %d, %d", &a, &b, &c) == 3) {
        // Compute the discriminant
        float discriminant = pow(b, 2) - 4 * a * c;

        float a_float = (float) a;
        float b_float = (float) b;

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
            float imaginary_part = sqrt(-discriminant) / (2 * a_float);
            printf("The solutions to the quadratic equation are as follows: \n");
            printf("Root: %0.3f + j%0.3f\n", real_part, imaginary_part);
            printf("Root: %0.3f - j%0.3f\n", real_part, imaginary_part);
        // If the discriminant is zero 
        } else {
            float real_part = (-1 * b_float) / (2 * a_float);
            printf("The solutions to the quadratic equation are as follows: \n");
            printf("Root: %0.3f, with a multiplicity of 2\n", real_part);
        }
    }
    
    return 0;
}
