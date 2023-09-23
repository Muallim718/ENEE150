#include <stdlib.h>
#include <stdio.h>

int main() {
    // Prompt the user for an array size (1 < n <= 16)
    int arr_size;
    do {
        printf("Enter array size: ");
        scanf("%d", &arr_size);
    } while (arr_size <= 1 || arr_size > 16);
    // Create the array
    int arr[arr_size];
    // Fill the array w/ random numbers in the range of 1 to 100
    for (int i = 0; i < arr_size; i++) {
        arr[i] = rand() % 100 + 1;
    }
    // Display the array
    printf("Contents of the original array: ");
    for (int i = 0; i < arr_size; i++) {
        printf("%i ", arr[i]);
    }
    printf("\n");
    // Prompt the user for the increment size (1 <= x <= 100)
    int increment_value;
    do {
        printf("Enter increment value: ");
        scanf("%d", &increment_value);
    } while (increment_value < 1 || increment_value > 100);
    // Increment the array
    for (int i = 0; i < arr_size; i++) {
        arr[i] += increment_value;
    }
    // Display the array
    printf("Contents of the incremented array: ");
    for (int i = 0; i < arr_size; i++) {
        printf("%i ", arr[i]);
    }
    printf("\n");

    return 0;
}