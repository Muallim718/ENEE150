#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    int age;
    char *name;
    struct node *next;
} Node;

int insert(Node **head, int age, char *name);
int delete(Node **head, int age, char *name);
int delete_first_instance(Node **head, int input_age);
int delete_all_instances(Node **head, int input_age);
int delete_all(Node **head);
int find_max_age(Node **head);
void print_list(Node **head);

int main(void) {
    Node *root = NULL;

    insert(&root, 23, "John");
    insert(&root, 31, "Jacob");
    insert(&root, 52, "Amy");
    insert(&root, 52, "Scott");
    insert(&root, 32, "Scarlet");
    insert(&root, 15, "Jenny");
    insert(&root, 52, "Bob");
    insert(&root, 28, "Feb");
    insert(&root, 52, "Kaz");
    insert(&root, 17, "Terp");
    print_list(&root);

    int max_age = find_max_age(&root);

    delete_first_instance(&root, max_age);
    printf("\nList after first instance of max age is deleted\n");
    print_list(&root);

    delete_all_instances(&root, max_age);
    printf("\nList after all instances of max age is deleted\n");
    print_list(&root);


    delete_all(&root);

    return 0;
}

int delete_first_instance(Node **head, int input_age) {
    Node *curr = NULL, *prev = NULL, *temp = NULL;
    int result = 0;

    if (head != NULL) {
        curr = *head;

        while (curr != NULL) {
            if (curr -> age == input_age) {
                temp = curr;
                free(temp -> name);
                free(temp);
                prev -> next = curr -> next;
                result = 1;
                return result;
            }
            prev = curr;
            curr = curr -> next;
        }
    }

    return result;
}

int delete_all_instances(Node **head, int input_age) {
    Node *curr = NULL, *prev = NULL, *temp = NULL;
    int result = 0;

    if (head != NULL) {
        curr = *head;

        while (curr != NULL) {
            if (curr -> age == input_age) {
                temp = curr;
                if (curr -> next != NULL) {
                    prev -> next = curr -> next;
                    curr = prev -> next;
                } else {
                    result = 1;
                    prev -> next = NULL;
                    free(temp -> name);
                    free(temp);
                    return result;
                }
                free(temp -> name);
                free(temp);
            } else {
                prev = curr;
                curr = curr -> next;
            }
        }
    }

    return result;
}

int insert(Node **head, int input_age, char *input_name) {
    Node *curr = NULL, *prev = NULL, *new_node = NULL;
    int result = 0;

    if (head != NULL) {
        curr = *head;
        while (curr != NULL && curr -> age < input_age) {
            prev = curr;
            curr = curr -> next;
        }

        new_node = malloc(sizeof(*new_node));
        if (new_node != NULL) {
            new_node -> name = (char *) malloc(strlen(input_name) * sizeof(char) + 1);
            if (new_node -> name == NULL) {
                printf("Malloc failed for name\n");
                return -1;
            } else {
                strcpy(new_node -> name, input_name);
            }
            new_node -> age = input_age;
            new_node -> next = curr;

            if (prev == NULL) {
                *head = new_node;
            } else {
                prev -> next = new_node;
            }
            result = 1;
        }
    }

    return result;
}

void print_list(Node **head) {
    Node *curr = NULL;

    if (head) {
        curr = *head;

        while (curr) {
            printf("Person's name: %s\n", curr -> name);
            printf("Person's age: %i\n", curr -> age);
            
            curr = curr -> next;
        }
    }
}

int find_max_age(Node **head) {
    Node *curr = NULL;
    int max_age = 0;

    if (head) {
        curr = *head;

        while (curr) {
            if (curr -> age > max_age) {
                max_age = curr -> age;
            }
            curr = curr -> next;
        }
    }

    return max_age;
}

int delete_all(Node **head) {
    Node *curr = NULL, *prev = NULL;
    int result = 0;

    if (head != NULL) {
        curr = *head;

        while (curr != NULL) {
            prev = curr;
            curr = curr -> next;
            free(prev -> name);
            free(prev);
        }
    }

    return result;
}