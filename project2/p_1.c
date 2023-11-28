#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

#define NAME_SIZE 20
#define PHONE_NUM_SIZE 12

typedef struct node {
    char *name;
    char *phone_num;
    struct node *left;
    struct node *right;
} Node;

int debug = 0;
#define debug(args...) if (debug) printf(args)

int AddNode(Node **root, char *input_name, char* input_num);
Node *get_largest(Node **root);
Node *get_smallest(Node **root);
int DeleteNode(Node **root, char *input_name);
int DeleteAll(Node **root);
void printTree(Node **root);

int main(void) {
    Node *root = NULL;
    static char name[NAME_SIZE];
    char phone_num[PHONE_NUM_SIZE];
    printf("Start of the program. Enter EOF to end program.\n");
    while (true) {  
        printf("Enter name: ");
        int name_result = scanf("%s", name);
        if (name_result == EOF) {
            break;
        }
        int num_result = 0;
        do {
            printf("Enter phone number (###-###-####): ");
            num_result = scanf("%s", phone_num);
            if (num_result == EOF) {
                break;
            }
        } while ((int) strlen(phone_num) != PHONE_NUM_SIZE);
        AddNode(&root, name, phone_num);
    }
    printf("\n");
    printTree(&root);
    DeleteAll(&root);

    return 0;
}

int AddNode(Node **root, char *input_name, char* input_num) {
    Node *new = NULL;
    int ret = 0;
    int count = 0;

    /* Check if root was passed in null*/
    if (root) {
        if (*root) {
            if (strcmp((*root) -> name, input_name) > 0) {
                ret = AddNode(&((*root) -> left), input_name, input_num);
            }
            else if (strcmp((*root) -> name, input_name) < 0) {
                ret = AddNode(&((*root) -> right), input_name, input_num);
            }
        } else {
            /* Create new node */
            new = malloc(sizeof(*new));

            /* If successful creation */
            if (new) {
                /* Copy over elements */
                new -> name = (char*) malloc(strlen(input_name) + 1);
                new -> phone_num = (char*) malloc(strlen(input_num) + 1);
                if ((new -> name) && (new -> phone_num)) {
                    strcpy(new -> name, input_name);
                    strcpy(new -> phone_num, input_num);
                    new -> left = NULL;
                    new -> right = NULL;
                    *root = new;
                    ret = 1;
                }
            }
        }
    }
    return ret;
}

Node *get_largest(Node **root) {
    Node *temp = NULL;

    if (root && *root) {
        if ((*root) -> right) {
            temp = get_largest(&((*root) -> right));
        } else {
            temp = *root;
        }
    }
    return temp;
}

Node *get_smallest(Node **root) {
    Node *temp = NULL;

    if (root && *root) {
        if ((*root) -> left) {
            temp = get_smallest(&((*root) -> left));
        } else {
            temp = *root;
        }
    }
    return temp;
}


int DeleteNode(Node **root, char *input_name) {
    int ret = 0;
    Node *temp = 0;
    int count = 0;

    if (root) {
        if (*root) {
            if (strcmp((*root) -> name, input_name) > 0) {
                ret = DeleteNode(&((*root) -> left), input_name);
            } else if (strcmp((*root) -> name, input_name) < 0) {
                ret = DeleteNode(&((*root) -> right), input_name);
            } else {
                free((*root) -> name);
                free((*root) -> phone_num);
                if ((*root) -> left || (*root) -> right) {
                    temp = (*root) -> left ? get_largest(&((*root) -> left)) : get_smallest(&((*root) -> right));
                    (*root) -> name = malloc(strlen(temp -> name) + 1);
                    strcpy((*root) -> name, temp -> name);
                    (*root) -> name[strlen(temp -> name)] = '\0';
                    (*root) -> phone_num = malloc(strlen(temp -> phone_num) + 1);
                    strcpy((*root) -> phone_num, temp -> phone_num);
                    (*root) -> phone_num[strlen(temp -> phone_num)] = '\0';
                    ret = DeleteNode(((*root) -> left ? &((*root) -> left) : &((*root)) -> right), (*root) -> name);
                } else {
                    free((*root));
                    *root = NULL;
                    ret = 1;
                }
            }
        }
    }

    return ret;
}

int DeleteAll(Node **root) {
    int ret = 0;

    if (root) {
        while (*root) {
            ret = DeleteNode(root, (*root) -> name);
        }
    }
    return 0;
}

void printTree(Node **root) {
    if (root) {
        if (*root) {
            printTree(&((*root) -> left));
            printf("Name: %s\n", (*root) -> name);
            printf("Phone number: %s\n", (*root) -> phone_num);
            printTree(&((*root) -> right));
        }
    }
}