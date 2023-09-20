#include <stdio.h>

int main() {
    // Get number of items from user
    int num_items;
    do {
        printf("Enter number of items: ");
        scanf("%i", &num_items);
    } while (num_items < 0 || num_items > 100);

    // Initialize unit price
    float unit_price = 20.0;
    // Initialize coupon price
    float coupon = 18.0;

    // Calculate total price
    float total_price = num_items * unit_price;
    // Initialize dicounted price 
    float discounted_price = 0.0;

    // Determine the discount rate
    if (num_items >= 10 && num_items <= 15) {
        discounted_price = total_price * (1 - 0.1);
        printf("Price the customer must pay: $%0.2f\n", discounted_price);
    } else if (num_items >= 16 && num_items <= 25) {
        discounted_price = total_price * (1 - 0.2);
        printf("Price the customer must pay: $%0.2f\n", discounted_price);
    } else if (num_items > 25) {
        discounted_price = total_price * (1 - 0.3) + coupon;
        printf("Price the customer must pay: $%0.2f\n", discounted_price);
    } else {
        printf("Price the customer must pay: $%0.2f\n", total_price);
    }

    return 0;
}