#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define BUFFER 100

float *compute_average(float **grades, float *highest_grades, 
                       int num_students, int num_tests);

char *determine_grades(float *average_scores, int num_students);

void display_scores(char** students, float **grades, float *highest_grades);

void display_final(char** students, float *average_scores, char *final_grades);

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
        *(name + count) = '\0';
        *(students + i) = name; 
    }

    /* Initialize grades array */
    int num_tests = 4;
    float **grades;
    grades = (float **) malloc(num_students * sizeof(float*));
    for (i = 0; i < num_students; i++) {
        grades[i] = (float *) malloc(num_tests * sizeof(float));
    }
    for (i = 0; i < num_students; i++) {
        printf("Input grades for %s\n", students[i]);
        for (j = 0; j < num_tests; j++) {
            float grade;
            do {
                printf("Test %i: ", j + 1);
                scanf("%f", &grade);
            } while (grade < 0.0 || grade > 100.0);
            grades[i][j] = grade;
        }
    }

    /* Initialize highest grades array */
    float *highest_grades;
    float max_grade = 0.0;
    highest_grades = (float *) malloc(num_students * sizeof(float));

    for (i = 0; i < num_students; i++) {
        max_grade = 0.0;
        for (j = 0; j < num_tests; j++) {
            if (grades[i][j] > max_grade) {
                max_grade = grades[i][j];
            }
        }
        highest_grades[i] = max_grade;
    }

    float *average_scores = compute_average(grades, highest_grades, 
                            num_students, num_tests);

    char *final_grades = determine_grades(average_scores, num_students);

    display_scores(students, grades, highest_grades);
    display_final(students, average_scores, final_grades);

    /* Free final grades array*/
    free(final_grades);

    /* Free average scores array*/
    free(average_scores);

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

void display_scores(char** students, float **grades, float *highest_grades) {
    int count = 0;
    int num_students = 5;
    int num_test = 4;
    int spacing = 20;
    int i, j;
    /* Table header */
    printf("Names");
    for (i = 0; i < spacing - strlen("Names"); i++) {
        printf(" ");
    }
    for (i = 0; i < num_test; i++) {
        printf("Test %i  ", i + 1);
    }
    printf("  Highest Score");
    printf("\n");
    /* Student info */
    for (i = 0; i < num_students; i++) {
        printf("%s", students[i]);
        int spacing_amount = spacing - strlen(students[i]);
        for (j = 0; j < spacing_amount; j++) {
            printf(" ");
        }
        for (j = 0; j < num_test; j++) {
            printf("%i      ", (int) grades[i][j]);
        }
        printf("  ");
        printf("%i", (int) highest_grades[i]);
        printf("\n");
    }
}

void display_final(char** students, float *average_scores, char *final_grades) {
    int count = 0;
    int num_students = 5;
    int num_test = 4;
    int spacing = 20;
    int i, j;
    /* Table header */
    printf("Names");
    for (i = 0; i < spacing - strlen("Names"); i++) {
        printf(" ");
    }
    printf("Average");
    printf(" Grade");
    printf("\n");
    /* Student info */
    for (i = 0; i < num_students; i++) {
        printf("%s", students[i]);
        int spacing_amount = spacing - strlen(students[i]);
        for (j = 0; j < spacing_amount; j++) {
            printf(" ");
        }
        printf("%0.1f    ", average_scores[i]);
        printf("%c    ", final_grades[i]);
        printf("\n");
    } 
    printf("\n");
}

float *compute_average(float **grades, float *highest_grades, 
                       int num_students, int num_tests) {
    int i, j;
    float *average_scores;
    float sum = 0;
    float result = 0;
    average_scores = (float *) malloc(num_students * sizeof(float));
    for (i = 0; i < num_students; i++) {
        sum += highest_grades[i];
        for (j = 0; j < num_tests; j++) {
            sum += grades[i][j];
        }
        result = sum / (float) (num_tests + 1);
        average_scores[i] = result; 
        sum = 0;
    }
    return average_scores;
}

char *determine_grades(float *average_scores, int num_students) {
    int i;
    char *final_grades;
    final_grades = (char *) malloc(num_students * sizeof(char) + 1);
    for (i = 0; i < num_students; i++) {
        int rounded_answer = (int) average_scores[i];
        if (rounded_answer >= 90 && rounded_answer <= 100) {
            final_grades[i] = 'A';
        } else if (rounded_answer >= 80 && rounded_answer <= 89) {
            final_grades[i] = 'B';
        } else if (rounded_answer >= 70 && rounded_answer <= 79) {
            final_grades[i] = 'C';
        } else if (rounded_answer >= 60 && rounded_answer <= 69) {
            final_grades[i] = 'D';
        } else {
            final_grades[i] = 'F';
        }
    }

    return final_grades;
}