#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include "datehandling.h"

bool isLeap(int year) {
    return year % 400 == 0 || (year % 4 == 0 && year % 100 != 0);
}

bool isDateNotValid(Date date) {
    if (date.year < 1583) {
        return true;
    }

    if (date.day < 1 || date.day > 31) {
        return true;
    }

    if (date.month < 1 || date.month > 12) {
        return true;
    }

    if (date.month == 2) {
        if (date.day == 29) {
            if (!isLeap(date.year)) {
                return true;
            }
        } else if (date.day > 28) {
            return true;
        }
    }

    int month = date.month;
    if (month >= 8) {
        month -= 1;
        month %= 2;
    }

    if (month == 0 && date.day > 30) {
        return true;
    }

    return false;
}

Date calculate_next_date(Date date)
{
    if (isDateNotValid(date)) {
        return INVALID_DATE;
    }

    int month = date.month;
    if (date.month >= 8) {
        month %= 2;
        month -= 1;
    }

    if (date.month == 2) {
        if ((date.day == 28 && isLeap(date.year)) || date.day < 28) {
            date.day++;
        } else {
            date.day = 1;
        }
    } else if (month % 2 == 0) {
        if (date.day == 30) {
            date.day = 1;
        } else {
            date.day++;
        }
    } else {
        if (date.day == 31) {
            date.day = 1;
        } else {
            date.day++;
        }
    }

    if (date.day == 1) {
        if (date.month == 12) {
            date.month = 1;
            date.year++;
        } else {
            date.month++;
        }
    }

    return date;
}

int main(int argc, char* argv[])
{
    int day, month, year;

    if (scanf("%d %d %d", &day, &month, &year)) {
        Date date;
        date.day = day;
        date.month = month;
        date.year = year;

        Date newDate = calculate_next_date(date);

        printf("The next date is: %2d %2d %4d\n", newDate.day, newDate.month, newDate.year);
    }

    return EXIT_SUCCESS;
}
