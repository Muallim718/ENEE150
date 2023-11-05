#include <stdio.h>

int day_of_year(int year, int month, int day);
void month_day(int year, int yearday, int *pmonth, int *pday);

static char daytab[2][13] = { 
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}, 
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31} 
}; 

int main(void) {
    int year;
    int month;
    int day;
    int year_day;
    printf("Enter year, month, day for day_of_year usage\n");
    scanf("%d, %d, %d", &year, &month, &day);
    printf("%i\n", year);
    printf("%i\n", month);
    printf("%i\n", day);
    printf("Enter year, yearday for month_day usage\n");
    scanf("%d, %d", &year, &year_day);
    printf("%i\n", year);
    printf("%i\n", year_day);
    return 0;
}

/* Day_of_year: set day of year from month & day */ 
int day_of_year(int year, int month, int day) {
    /*
    if (year >= 0) {
        return -1;
    }
    if (month >= 1 && month <= 12) {
        return -1;
    }
    if () {

    }
    */
    int i, leap; 
    leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0; 
    for (i = 1; i < month; i++) {
        day += daytab[leap][i];
    }
    return day; 
}

/* Month_day: set month, day from day of year */ 
void month_day(int year, int yearday, int *pmonth, int *pday) { 
    int i, leap; 
    leap  = year % 4 == 0 && year % 100 != 0 || year % 400 == 0; 
    for (i = 1; yearday > daytab[leap][i]; i++) {
        yearday -= daytab[leap][i]; 
    }
    *pmonth = i; 
    *pday = yearday; 
} 
