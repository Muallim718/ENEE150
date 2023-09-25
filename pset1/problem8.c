#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

int main() {
    int arr_size;
    do {
        scanf("%d", &arr_size);
    } while (arr_size <= 1 || arr_size > 16);
    // Create the array
    int arr[arr_size];
    // Get max value
    int max_value;
    do {
        scanf("%d", &max_value);
    } while (max_value <= 0 || max_value > 100);
    // Fill the array w/ random numbers in the range of 1 to 100
    for (int i = 0; i < arr_size; i++) {
        arr[i] = rand() % max_value + 1;
    }
    // Display the array
    for (int i = 0; i < arr_size; i++) {
        printf("%i ", arr[i]);
    }
    printf("\n");
    // Prompt the user for the increment size (1 <= x <= 100)
    int increment_value;
    do {
        scanf("%d", &increment_value);
    } while (increment_value < 1 || increment_value > 100);
    // Increment the array
    for (int i = 0; i < arr_size; i++) {
        arr[i] += increment_value;
    }
    // Display the array
    for (int i = 0; i < arr_size; i++) {
        printf("%i ", arr[i]);
    }
    printf("\n");

    return 0;
}