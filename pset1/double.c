#include <stdlib.h>
#include <stdio.h>

int main() {
    // Prompt the user for the row size (1 < n < 5)
    int row_size;
    do {
        printf("Enter row size: ");
        scanf("%d", &row_size);
    } while (row_size <= 1 || row_size >= 5);
    // Prompt the user for the column size (1 < n < 5)
    int col_size;
    do {
        printf("Enter col size: ");
        scanf("%d", &col_size);
    } while (col_size <= 1 || col_size >= 5);
    // Create the double array
    int arr[row_size][col_size];
    // Fill the array w/ random numbers in the range of 1 to 100
    for (int i = 0; i < row_size; i++) {
        for (int j = 0; j < col_size; j++) {
            arr[i][j] = rand() % 100 + 1;
        }
    }
    // Display the array
    printf("Contents of the original array:\n");
    for (int i = 0; i < row_size; i++) {
        for (int j = 0; j < col_size; j++) {
            printf("%i ", arr[i][j]);
        }
        printf("\n");
    }
    // Prompt the user for the increment size (1 <= x <= 100)
    int increment_value;
    do {
        printf("Enter increment value: ");
        scanf("%d", &increment_value);
    } while (increment_value < 1 || increment_value > 100);
    // Increment the array
    for (int i = 0; i < row_size; i++) {
        for (int j = 0; j < col_size; j++) {
            arr[i][j] += increment_value;
        }
    }
    // Display the array
    for (int i = 0; i < row_size; i++) {
        for (int j = 0; j < col_size; j++) {
            printf("%i ", arr[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}