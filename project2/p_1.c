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

static int AddNode(Node **root, char *input_name, char* input_num);
static char *get_largest(Node **root);
static char *get_smallest(Node **root);
static int DeleteNode(Node **root, char *input_name, char* input_num);
static int DeleteAll(Node **root);
static void printTree(Node **root);

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

static int AddNode(Node **root, char *input_name, char* input_num) {
    Node *new = NULL;
    int ret = 0;

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

static char *get_largest(Node **root) {
    char *ret = NULL;

    if (root && *root) {
        if ((*root) -> right) {
            ret = get_largest(&((*root) -> right));
        } else {
            ret = malloc(strlen((*root) -> name) + 1);
            if (ret) {
                strcpy(ret, (*root) -> name);
            }
        }
    }
    return ret;
}

static char *get_smallest(Node **root) {
    char *ret = NULL;

    if (root && *root) {
        if ((*root) -> left) {
            ret = get_smallest(&((*root) -> left));
        } else {
            ret = malloc(strlen((*root) -> name) + 1);
            if (ret) {
                strcpy(ret, (*root) -> name);
            }
        }
    }
    return ret;
}


static int DeleteNode(Node **root, char *input_name, char* input_num) {
    int ret = 0;

    if (root) {
        if (*root) {
            if (strcmp((*root) -> name, input_name) > 0) {
                ret = DeleteNode(&((*root) -> left), input_name, input_num);
            } else if (strcmp((*root) -> name, input_name) < 0) {
                ret = DeleteNode(&((*root) -> right), input_name, input_num);
            } else {
                if ((*root) -> left) {
                    (*root) -> name = get_largest(&((*root) -> left));
                    ret = DeleteNode(&((*root) -> left), input_name, input_num);
                } else if ((*root) -> right) {
                    (*root) -> name = get_smallest(&((*root) -> right));
                    ret = DeleteNode(&((*root) -> right), input_name, input_num);
                } else {
                    free((*root) -> name);
                    free((*root) -> phone_num);
                    free((*root));
                    *root = NULL;
                    ret = 1;
                }
            }
        }
    }

    return ret;
}

static int DeleteAll(Node **root) {
    if (root && *root) {
        DeleteNode(root, (*root)->name, (*root)->phone_num);
        DeleteAll(root);
    }
    return 0;
}

static void printTree(Node **root) {
    if (root) {
        if (*root) {
            printTree(&((*root) -> left));
            printf("Name: %s\n", (*root) -> name);
            printf("Phone number: %s\n", (*root) -> phone_num);
            printTree(&((*root) -> right));
        }
    }
}