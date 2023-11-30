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


int debug = 1;
#define debug(args...) if (debug) printf(args)
int person_found = 0;

int AddNode(Node **root, char *input_name, char* input_num);
Node *get_largest(Node **root);
Node *get_smallest(Node **root);
int DeleteNode(Node **root, char *input_name);
int DeleteAll(Node **root);
void printTree(Node **root);
void FindPerson(Node **root, char *input_name);
void change_rightmost_leaf(Node **root, char *input_name);
void DeleteLeftNode(Node **root);

int main(void) {
    Node *root = NULL;
    static char name1[NAME_SIZE];
    static char name2[NAME_SIZE];
    char phone_num[PHONE_NUM_SIZE];
    printf("Building the tree.\n");
    /* Part a */
    /* Build the tree */
    AddNode(&root, "John", "202-254-6958");
    AddNode(&root, "Edward", "240-987-9875");
    AddNode(&root, "Paul", "202-658-5687");
    AddNode(&root, "Charles", "202-897-9875");
    AddNode(&root, "Gerald", "202-987-6587");
    AddNode(&root, "Brandon", "301-896-6785");
    AddNode(&root, "David", "202-987-6587");
    AddNode(&root, "Natasha", "202-548-6987");
    AddNode(&root, "Victor", "240-458-6897");
    AddNode(&root, "Same", "301-587-7895");
    AddNode(&root, "Williams", "301-405-6587");
    printTree(&root);
    printf("\n");
    /* Part b */
    /* Find person */
    printf("Enter a person's name from the phone book: ");
    scanf("%s", name1);
    FindPerson(&root, name1);
    if (person_found != 1) {
        printf("Person not found.\n");
    }
    printf("\n");
    /* Part c*/
    /* Change nood*/
    printf("Enter a name to replace the rightmost leaf: ");
    scanf("%s", name2);
    change_rightmost_leaf(&root, name2);
    printTree(&root);
    /* Part d*/
    /* Delete left child of the root */
    printf("\n");
    printf("Remove left child of the root: ");
    DeleteLeftNode(&root);
    printTree(&root);


    DeleteAll(&root);

    return 0;
}

void DeleteLeftNode(Node **root) {
    if (root) {
        if (*root) {
            char left_name[NAME_SIZE];
            strcpy(left_name, (*root) -> left -> name);
            printf("%s\n", left_name);
            DeleteNode(&((*root) -> left), left_name);
        }
    }
}

void FindPerson(Node **root, char *input_name) {
    if (root) {
        if (*root) {
            FindPerson(&((*root) -> left), input_name);
            if (strcmp((*root) -> name, input_name) == 0) {
                printf("Person found.\n");
                printf("Name: %s\n", (*root) -> name);
                printf("Phone number: %s\n", (*root) -> phone_num);
                person_found = 1;
            }
            FindPerson(&((*root) -> right), input_name);
        }
    }
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

void change_rightmost_leaf(Node **root, char *input_name) {
    if (root) {
        if (*root) {
            change_rightmost_leaf(&((*root) -> right), input_name);
            if ((*root) -> right == NULL) {
                free((*root) -> name);
                (*root) -> name = (char*) malloc((int) strlen(input_name) + 1);
                strcpy((*root) -> name, input_name);
                (*root) -> name[(int) strlen(input_name)] = '\0';
                return;
            }   
        }
    }
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