#include <stdio.h>
#include <stdbool.h>

#define ROW_SIZE 3
#define COL_SIZE 3

int get_row_pos(void);
int get_col_pos(void);
bool check_empty();

bool pos[ROW_SIZE][COL_SIZE];

bool verify_square(int row_position, int col_position);
int check_win(int grid[][COL_SIZE], int choice_one, int choice_two);
int check_choice(int grid[][COL_SIZE], int choice);
void print_board(int grid[][COL_SIZE]);

int main(void) {
    /* Initialize the array */
    int grid[ROW_SIZE][COL_SIZE];
    int i, j;
    for (i = 0; i < ROW_SIZE; i++) {
        for (j = 0; j < COL_SIZE; j++) {
            grid[i][j] = '.';
        }
    }
    printf("Player 1, choose enter either 'x' or 'o'.\n");
    char choice_one;
    do {
            scanf("%c", &choice_one);
    } while(choice_one != 'x' && choice_one != 'o');
    printf("Player 2, you're left with the other choice.\n");
    char choice_two;
    if (choice_one == 'x') {
        choice_two = 'o';
    } else if (choice_one == 'o') {
        choice_two = 'x';
    }
    int result = 0;
    while (result == 0) {
        /* Prompt user 1 for placement of choice */
        printf("Player 1, enter coordinates.\n");
        int row_pos_one, col_pos_one;
        do {
            row_pos_one = get_row_pos();
            col_pos_one = get_col_pos();
        } while (verify_square(row_pos_one, col_pos_one));
        pos[row_pos_one][col_pos_one] = true;
        grid[row_pos_one][col_pos_one] = choice_one;
        print_board(grid);
        /* Check after every turn */
        /* Check for in the case if the win is a one square difference */
        result = check_win(grid, choice_one, choice_two);
        if (result == 1) {
            return 0;
        }
        /* If there are no empty squares left and no win, we have a tie */
        if (check_empty()) {
            printf("Tie!\n");
            return 0;
        }
        /* Prompt user 2 for placement of choice */
        printf("Player 2, enter coordinates.\n");
        int row_pos_two, col_pos_two;
        do {
            row_pos_two = get_row_pos();
            col_pos_two = get_col_pos();
        } while(verify_square(row_pos_two, col_pos_two));
        pos[row_pos_two][col_pos_two] = true; 
        grid[row_pos_two][col_pos_two] = choice_two;
        print_board(grid);
        result = check_win(grid, choice_one, choice_two);
    }
    return 0;
}

void print_board(int grid[][COL_SIZE]) {
    /* Clear console */
    printf("\033[H\033[J");
    /* Print table */
    int i, j;
    for(i = 0; i < ROW_SIZE; i++) {
        for (j = 0; j < COL_SIZE; j++) {
            printf(" %c |", grid[i][j]);
        }
        printf("\n------------\n");
    }
}

int check_win(int grid[][COL_SIZE], int choice_one, int choice_two) {
    int x = 'x';
    int o = 'o';
    /* Determine whether x or o won */
    int x_result = check_choice(grid, x);
    int o_result = check_choice(grid, o);
    /* If x won */
    if (x_result == 1) {
        /* Determine which player had x */
        /* Print the winner */
        if (choice_one = x) {
            printf("Player one won!\n");
        } else if (choice_two = x) {
            printf("Player two won!\n");
        }
        return 1;
    /* If o won */
    } else if (o_result == 1) {
        /* Determine which player had o */
        /* Printer the winner */
        if (choice_one = o) {
            printf("Player one won!\n");
        } else if (choice_two = o) {
            printf("Player two won!\n");
        }
        return 1;
    }
    /* If none of the above, continue the game */
    return 0;
}

int check_choice(int grid[][COL_SIZE], int choice) {
    int diagonal = 0;
    int opp_diagonal = 0;
    /* Check for vertical, horizontal, and diagonal wins */
    int i, j;
    for (i = 0; i < ROW_SIZE; i++) {
        int vertical = 0;
        int horizontal = 0;
        int opp_diagonal_pos = 2;
        for (j = 0; j < COL_SIZE; j++) {
            if (grid[i][j] == choice) {
                horizontal++;
            }
            if (grid[j][i] == choice) {
                vertical++;
            }
            if (i == j && grid[i][j] == choice) {
                diagonal++;
            }
            if (i + j == opp_diagonal_pos && grid[i][j] == choice) {
                opp_diagonal++;
            }
        }
        if (horizontal == 3 || vertical == 3 || diagonal == 3 || opp_diagonal == 3) {
            return 1;
        }
    }
    return 0;
}

bool check_empty() {
    int count = 0;
    int i, j;
    for (i = 0; i < ROW_SIZE; i++) {
        for (j = 0; j < COL_SIZE; j++) {
            if (pos[i][j] == true) {
                count++;
            }
        }
    }
    if (count == 9) {
        return true;
    }
    return false;
}

bool verify_square(int row_position, int col_position) {
    return pos[row_position][col_position];
}

int get_row_pos(void) {
    int row_pos;
    do {
        printf("Enter row position (0, 1, or 2): ");
        scanf("%d", &row_pos);
    } while (row_pos < 0 || row_pos > 2);
}

int get_col_pos(void) {
    int col_pos;
    do {
        printf("Enter col position (0, 1, or 2): ");
        scanf("%d", &col_pos);
    } while (col_pos < 0 || col_pos > 2);
}