#include <stdio.h>
#include <string.h>
#include <stdlib.h>

float *compute_average(float **grades, float *highest_grades, 
                       int num_students, int num_tests);

char *determine_grades(float *average_scores, int num_students);

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

    for (i = 0; i < num_students; i++) {
        printf("%0.2f\n", average_scores[i]);
    }

    for (i = 0; i < num_students; i++) {
        printf("%c\n", final_grades[i]);
    }

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
        if (average_scores[i] >= 90 && average_scores[i] <= 100) {
            final_grades[i] = 'A';
        } else if (average_scores[i] >= 80 && average_scores[i] <= 89) {
            final_grades[i] = 'B';
        } else if (average_scores[i] >= 70 && average_scores[i] <= 79) {
            final_grades[i] = 'C';
        } else if (average_scores[i] >= 60 && average_scores[i] <= 69) {
            final_grades[i] = 'D';
        } else {
            final_grades[i] = 'E';
        }
    }

    return final_grades;
}