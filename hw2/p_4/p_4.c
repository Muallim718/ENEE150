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
    int pmonth = 0;
    int pday = 0;
    scanf("%d, %d, %d", &year, &month, &day);
    int day_of_year_result = day_of_year(year, month, day);
    printf("year, month, day: %i\n", day_of_year_result);
    scanf("%d, %d", &year, &year_day);
    month_day(year, year_day, &pmonth, &pday);
    printf("year, yearday: %i, %i\n", pmonth, pday);
    return 0;
}

/* Day_of_year: set day of year from month & day */ 
int day_of_year(int year, int month, int day) {
    if (year < 0) {
        return -1;
    }
    if (!(month >= 1 && month <= 12)) {
        return -1;
    }
    if (!(day >= 1 && day <= 31)) {
        return -1;
    }
    int i, leap; 
    leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0; 
    for (i = 1; i < month; i++) {
        day += daytab[leap][i];
    }
    return day; 
}

/* Month_day: set month, day from day of year */ 
void month_day(int year, int yearday, int *pmonth, int *pday) {
    if (year < 0) {
        *pmonth = -1;
        *pday = -1;
        return;
    }
    if (!(yearday >= 1 && yearday <= 366)) {
        *pmonth = -1;
        *pday = -1;
        return;
    }
    if (pmonth == NULL || pday == NULL) {
        *pmonth = -1;
        *pday = -1;
        return;
    }
    int i, leap; 
    leap  = year % 4 == 0 && year % 100 != 0 || year % 400 == 0; 
    for (i = 1; yearday > daytab[leap][i]; i++) {
        yearday -= daytab[leap][i]; 
    }
    *pmonth = i; 
    *pday = yearday; 
} 
