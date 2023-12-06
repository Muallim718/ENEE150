#include <stdio.h>

void display_bits(unsigned char n);
void check_bits(unsigned char n);
int find_first_on_bit(unsigned char n);
unsigned char turn_off_first_on_bit(unsigned char n, int bit_position);
int find_last_off_bit(unsigned char n);
unsigned char turn_on_last_of_bit(unsigned char n, int bit_position);

int main(void) {
    int value;
    do {
        printf("Enter a number from 0 to 255: ");
        scanf("%i", &value);
    } while (!(value >= 0 && value <= 255));
    /* Typecast the result */
    unsigned char eight_bit_value = (unsigned char) value;
    /* Part a */
    /* Check is the second bit is ON*/
    unsigned char second_bit_mask = 0x20;
    unsigned char second_bit = eight_bit_value & second_bit_mask;
    if (second_bit == 0) {
        printf("The 2nd bit of %u is OFF\n", eight_bit_value);
    } else {
        printf("The 2nd bit of %u is ON\n", eight_bit_value);
    }
    /* Check is the fifth bit is ON*/
    unsigned char fifth_bit_mask = 0x04;
    unsigned char fifth_bit = eight_bit_value & fifth_bit_mask;
    if (fifth_bit == 0) {
        printf("The 5th bit of %u is OFF\n", eight_bit_value);
    } else {
        printf("The 5th bit of %u is ON\n", eight_bit_value);
    }

    /* Part b */
    int on_bit_position = find_first_on_bit(eight_bit_value);
    unsigned char b_newvalue = turn_off_first_on_bit(eight_bit_value, on_bit_position);
    if (on_bit_position != -1) {
        printf("Turn OFF the first bit that is ON\n");
        printf("Bits before: ");
        display_bits(eight_bit_value);
        printf("Bits after turning off the first on bit: ");
        display_bits(b_newvalue);
    }

    /* Part c */
    int off_bit_position = find_last_off_bit(eight_bit_value);
    unsigned char c_newvalue = turn_on_last_of_bit(eight_bit_value, off_bit_position);
    if (off_bit_position != -1) {
        printf("Turn ON the last bit that is OFF\n");
        printf("Bits before: ");
        display_bits(eight_bit_value);
        printf("Bits after turning on the last off bit: ");
        display_bits(c_newvalue);
    }

    return 0;
}

unsigned char turn_on_last_of_bit(unsigned char n, int bit_position) {
    unsigned char mask, w;

    w = 1 << 7;
    mask = w >> bit_position;
    return n | mask;
}

int find_last_off_bit(unsigned char n) {
    int x;
    unsigned char z, y, w;

    /* If 1111111*/
    if (n == (unsigned char) 255) {
        printf("No bits are off, sequence of bits will remain the same.\n");
        return -1;
    }

    /* 1000000 */
    w = 1 << 7;

    for (x = 7; x >= 0; x--) {
        /* Shift the mask by x amount*/
        y = w >> x;
        z = n & y;
        if (z == 0) {
            return x;
        }
    }
}

unsigned char turn_off_first_on_bit(unsigned char n, int bit_position) {
    unsigned char mask, w, y;

    w = 1 << 7;
    y = w >> bit_position;
    mask = ~y;
    return n & mask;
}

int find_first_on_bit(unsigned char n) {
    int x;
    unsigned char z, y, w;

    /* If 0000000*/
    if (n == (unsigned char) 0) {
        printf("No bits are on, sequence of bits will remain the same.\n");
        return -1;
    }

    /* 1000000 */
    w = 1 << 7;

    for (x = 0; x <= 7; x++) {
        /* Shift the mask by x amount*/
        y = w >> x;
        z = n & y;
        if (z != 0) {
            return x;
        }
    }
}

void display_bits(unsigned char n) {
    int x;
    unsigned char y, z, maskAND;

    for (x = 7; x >= 0; x--) {
        y = x;
        maskAND = 1 << y;
        z = n & maskAND;
        z == 0 ? printf("0") : printf("1");
    }
    printf("\n");
}