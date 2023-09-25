#include <stdio.h>

void print_top_row();
void print_celsius_spaces();
void print_celsius_value(int celsius_temp);
void print_fahrenheit_value(int fahrenheit_temp);
void print_fahrenheit_spaces();

int celsius_spaces = 0;
int fahrenheit_spaces = 0;

int main() {
    // Starting temperature in celsius
    float celsius_temp = 100;
    // Initialize fahrenheit temperature
    float fahrenheit_temp = 0;
    // Initialize count variable
    int count = 0;
    // Initialize array of temperatures
    int array_size = 13;
    float temps[array_size];
    while (!(celsius_temp < -20)) {
        // Convert temperature from celsius to fahrenheit
        fahrenheit_temp = (9.0 / 5.0) * celsius_temp + 32.0;
        // Store result in array
        temps[count++] = fahrenheit_temp;
        // Decrementate the temperature
        celsius_temp = celsius_temp - 10;
    }

    // Reinitialize values
    int celsius_temperature = 100;
    count = 0;

    // Print table
    int table_rows = 29;
    int table_col = 48;
    int space_amount = 8;
    int top_row = 1; 

    for (int i = 0; i < table_rows; i++) {
        if (i % 2 == 0) {
            for (int j = 0; j < table_col; j++) {
                printf("-");
            }
            printf("\n");
        } else {
            if (i == top_row) {
                print_top_row();
            } else {
                printf("| ");
                print_celsius_value(celsius_temperature);
                celsius_temperature -= 10;
                print_celsius_spaces();
                printf("| ");
                int fahrenheit_temperature = (int) temps[count++];
                print_fahrenheit_value(fahrenheit_temperature);
                print_fahrenheit_spaces();
                printf("|");
                printf("\n");
            }
        }
    }

    return 0;
}

void print_celsius_spaces() {
    for (int i = 0; i < celsius_spaces; i++) {
        printf(" ");
    }
}

void print_celsius_value(int celsius_temp) {
    printf("%i", celsius_temp);

    if (celsius_temp >= 10 && celsius_temp <= 90) {
        celsius_spaces = 18;
    } else if (celsius_temp == 100 || celsius_temp < 0) {
        celsius_spaces = 17;
    } else if (celsius_temp == 0) {
        celsius_spaces = 19;
    }
}

void print_fahrenheit_spaces() {
    for (int i = 0; i < fahrenheit_spaces; i++) {
        printf(" ");
    }
}

void print_fahrenheit_value(int fahrenheit_temp) {
    printf("%i", fahrenheit_temp);

    if (fahrenheit_temp > 100) {
        fahrenheit_spaces = 20;
    } else if (fahrenheit_temp < 100) {
        fahrenheit_spaces = 21;
    }
}

void print_top_row() {
    printf("| ");
    printf("Celsius Temperature");
    printf(" | ");
    printf("Fahrenheit Temperature");
    printf(" |");
    printf("\n");
}