#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void) {
    /* Initialize name array */
    int num_students = 5;
    int i, j;
    char **students;
    students = (char **) malloc(num_students * sizeof(char*));
    students[0] = (char *) malloc(strlen("John Smith") + 1);
    strcpy(students[0], "John Smith");
    students[1] = (char *) malloc(strlen("Latasha Green") + 1);
    strcpy(students[1], "Latasha Green");
    students[2] = (char *) malloc(strlen("David Williams") + 1);
    strcpy(students[2], "David Williams");
    students[3] = (char *) malloc(strlen("Albert James") + 1);
    strcpy(students[3], "Albert James");
    students[4] = (char *) malloc(strlen("Nicole Johnson") + 1);
    strcpy(students[4], "Nicole James");

    /* Initialize grades array */
    int num_tests = 4;
    int **grades;
    grades = (int **) malloc(num_students * sizeof(int*));
    for (i = 0; i < num_students; i++) {
        grades[i] = (int *) malloc(num_tests * sizeof(int));
    }
    for (i = 0; i < num_students; i++) {
        printf("Input grades for %s\n", students[i]);
        for (j = 0; j < num_tests; j++) {
            int grade;
            printf("Test %i: ", j + 1);
            scanf("%d", &grade);
            grades[i][j] = grade;
        }
    }

    /* Initialize highest grades array */
    int *highest_grades;
    highest_grades = (int *) malloc(num_students * sizeof(int));

    /* Free highest grades array*/
    free(highest_grades);

    /* Free grades array */
    for (i = 0; i < num_students; i++) {
        free(grades[i]);
    }
    free(grades);

    /* Free students array*/
    for (i = 0; i < num_students; i++) {
        free(students[i]);
    }
    free(students);
    return 0;
}