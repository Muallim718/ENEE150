#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef struct person_info {
    char *first_name;
    char *last_name;
    char *birth_date;
    int account_number;
    char *account_type;
    float balance;
} person_info;

void swap_person_info(person_info **a, person_info **b);

#define BUFFER_SIZE 20
#define NUM_CUSTOMERS 4

int main(void) {
    
    person_info *customers[NUM_CUSTOMERS];

    int i, j; 
    for (i = 0; i < NUM_CUSTOMERS; i++) {
        customers[i] = malloc(sizeof(person_info));
        if (customers[i] == NULL) {
            return -1;
        }
        customers[i] -> first_name = (char *) malloc(BUFFER_SIZE * sizeof(char));
        if (customers[i] -> first_name == NULL) {
            printf("Malloc failed for first name\n");
            return -1;
        }
        customers[i] -> last_name = (char *) malloc(BUFFER_SIZE * sizeof(char));
        if (customers[i] -> last_name == NULL) {
            printf("Malloc failed for last name\n");
            return -1;
        }
        customers[i] -> birth_date = (char *) malloc(BUFFER_SIZE * sizeof(char));
        if (customers[i] -> birth_date == NULL) {
            printf("Malloc failed for birth date\n");
            return -1;
        }
        customers[i] -> account_type = (char *) malloc(BUFFER_SIZE * sizeof(char));
        if (customers[i] -> birth_date == NULL) {
            printf("Malloc failed for account type\n");
            return -1;
        }
    }

    int count = 0;

    /* Fill in contents */
    /* Dr. Wade said we didn't have to implement error checking */
    printf("Input information for four users\n");
    while (count < NUM_CUSTOMERS) {
        printf("Enter first name: ");
        int first_name = scanf("%s", customers[count] -> first_name);
        if (first_name != 1) {
            break;
        }

        printf("Enter last name: ");
        int last_name = scanf("%s", customers[count] -> last_name);
        if (last_name != 1) {
            break;
        }

        printf("Enter birth date (##/##/####): ");
        int birth_date = scanf("%s", customers[count] -> birth_date);
        if (birth_date != 1) {
            break;
        }


        printf("Enter a 6 digit account number (######): ");
        int account_number = scanf("%i", &(customers[count] -> account_number));
        if (account_number != 1) {
            break;
        }

        printf("Enter 'Savings' or 'Checking': ");
        int account_type = scanf("%s", customers[count] -> account_type);
        if (account_type != 1) {
            break;
        }

        printf("Enter balance: ");
        int balance = scanf("%f", &(customers[count] -> balance));
        if (balance != 1) {
            break;
        }

        count++;
    }

    char first_name_temp[BUFFER_SIZE];
    char last_name_temp[BUFFER_SIZE];
    char birth_date_temp[BUFFER_SIZE];
    int account_number_temp = 0;
    char account_type_temp[BUFFER_SIZE];
    int balance_temp = 0;

    for (i = 0; i < count; i++) {
        for (j = 0; j < count - 1; j++) {
            /* Bubble sort*/
            /* If there is an instance such that there is a name that should be
            at the front of the list */
            if (strcmp(customers[j] -> first_name, customers[j + 1] -> first_name) > 0) {
                swap_person_info(&customers[j], &customers[j + 1]);
            }
        }
    }

    printf("\n%-15s%-15s%-15s%-20s%-15s%-10s\n", "First Name", "Last Name", "Birth Date", "Account Number", "Account Type", "Balance");
    for (i = 0; i < NUM_CUSTOMERS; i++) {
        printf("%-15s%-15s%-15s%-20i%-15s$%-10.2f\n", customers[i] -> first_name, customers[i] -> last_name, 
               customers[i] -> birth_date, customers[i] -> account_number, customers[i] -> account_type, customers[i] -> balance);
    }

    /* Free table */
    for (i = 0; i < NUM_CUSTOMERS; i++) {
        free(customers[i] -> first_name);
        free(customers[i] -> last_name);
        free(customers[i] -> birth_date);
        free(customers[i] -> account_type);
        free(customers[i]);
    }

    return 0;
}

void swap_person_info(person_info **a, person_info **b) {
    person_info *temp = *a;
    *a = *b;
    *b = temp;
}