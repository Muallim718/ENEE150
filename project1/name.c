#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int num_students = 5;
    int i, j;
    int c;
    char **students;
    char *name;
    students = (char **) malloc(num_students * sizeof(char*));
    if (students == NULL) {
        printf("Seg fault danger 1.\n");
        return 1;
    }

    for (i = 0; i < num_students; i++) { 
        printf("Enter name for student %i: ", i + 1);
        name = (char *) malloc(sizeof(char));
        if (name == NULL) {
            printf("Seg fault danger 2.\n");
            return 1;
        }
        int count = 0;
        while((c = getchar()) != '\n') {
            *(name + count++) = c;
            name = (char *) realloc(name, (count + 1) * sizeof(char));
            if (name == NULL) {
                printf("Seg fault danger 3.\n");
            return 1;
            }
        }
        *(students + i) = name; 
    }
    for (i = 0; i < num_students; i++) {
        free(*(students + i));
    }
    free(students);
    return 0;
}