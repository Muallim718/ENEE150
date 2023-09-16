#include <stdio.h>

int main(){
    // Starting temperature in celsius
    float celsius_temp = 100;
    // Initialize fahrenheit temperature
    float fahrenheit_temp = 0;
    // Initialize count variable
    int count = 0;
    // Initialize array of temperatures
    int array_size = 20;
    float temps[array_size];
    // For loop decrementating the temperature
    while (!(celsius_temp < -20)) {
        printf("Celsius temp: %0.3f\n", celsius_temp);
        fahrenheit_temp = (9.0 / 5.0) * celsius_temp + 32.0;
        temps[count++] = fahrenheit_temp;
        printf("Fahrenheit temp: %0.3f\n", fahrenheit_temp);
        celsius_temp = celsius_temp - 10;
    }
    // Convert temperature from celsius to fahrenheit 
    // Store result in array
    // Print table
}