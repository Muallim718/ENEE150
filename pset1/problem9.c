#include <stdlib.h>
#include <stdio.h>

int main() {
    // Prompt the user for the row size (1 < n < 5)
    int row_size;
    int col_size;
    do {
        scanf("%d, %d", &col_size, &row_size);
    } while ((row_size <= 1 || row_size >= 5) && (col_size <= 1 || col_size >= 5));
    // Create the double array
    int arr[row_size][col_size];
    int max_value;
    do {
        scanf("%d", &max_value);
    } while (max_value <= 0 || max_value > 100);
    int i;
    for (i = 0; i < row_size; i++) {
        for (int j = 0; j < col_size; j++) {
            arr[i][j] = rand() % max_value + 1;
        }
    }
    // Prompt the user for the increment size (1 <= x <= 100)
    int increment_value;
    do {
        scanf("%d", &increment_value);
    } while (increment_value < 1 || increment_value > 100);
    // Increment the array
    for (i = 0; i < row_size; i++) {
        for (int j = 0; j < col_size; j++) {
            arr[i][j] += increment_value;
        }
    }
    // Display the array
    for (i = 0; i < row_size; i++) {
        for (int j = 0; j < col_size; j++) {
            printf("%i ", arr[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}