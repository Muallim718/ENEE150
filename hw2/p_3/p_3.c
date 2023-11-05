#include <stdio.h>
#include <stdlib.h>

void quick_sort(int *V, int left, int right);
void swap(int *V, int left, int right);
void print_array(int *V, int n);

int main(void) {
    srand(42);
    /* Scan for user input */
    int i, n;
    do {
        printf("Enter array length:\n");
        scanf("%d", &n);
    } while(n < 10);
    /* Allocate space for the arry */
    int *arr = malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Seg fault danger.\n");
        return;
    }
    /* Initialize the array with random values*/
    for (i = 0; i < n; i++) {
        /* Generate integers from 0-999 */
        *(arr + i) = rand() % 1000;
    }
    printf("Before: ");
    print_array(arr, n);
    quick_sort(arr, 0, n);
    printf("After: ");
    print_array(arr, n);

    /* Free contents of the array*/
    free(arr);
}

void print_array(int *V, int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%i ", *(V + i));
    }
    printf("\n");
}

void quick_sort(int *V, int left, int right) {
    int i, last;
    if(left >= right) {
        return;
    }
    swap(V, left, (left + right) / 2);
    last = left;
    for (i = left + 1; i <= right; i++) {
        if (*(V + i) < *(V + left)) {
            swap(V, ++last, i);
        }
    }
    swap(V, left, last);
    quick_sort(V, left, last - 1);
    quick_sort(V, last + 1, right);
}

void swap(int *V, int left, int right) {
    int temp;
    temp = *(V + left);
    *(V + left) = *(V + right);
    *(V + right) = temp;
}