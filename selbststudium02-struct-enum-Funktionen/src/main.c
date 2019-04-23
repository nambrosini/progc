#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include "datehandling.h"

bool isDateOk(Date date) {
    if (date.year < 1583) {
        return false;
    }

    if (date.day > 31 || date.day < 1) {
        return false;
    }

    if (date.month < 1 || date.month > 12) {
        return false;
    }

    int month = date.month;

    if (month > 8) {
        month -= 1;
    }

    if (month == 2) {
        if (date.day == 29) {
            if (!(date.year % 4 == 0 && (date.year % 100 == 0 && date.year % 400 == 0))) {
                return false;
            }
        } else if (date.day > 29) {
            return false;
        }
    } else if (month % 2 == 0 && date.day > 30) {
        return false;
    }

    return true;
}

Date calculate_next_date(Date date)
{
    if (isDateOk(date)) {
        return INVALID_DATE;
    }

    int month = date.month;

    if (month >= 8) {
        month -= 1;
    }

    if (month == 2 && date.day == 28) {
        if (date.year % 4 == 0 && (date.year % 100 == 0 && date.year % 400 == 0)) {
            date.day++;
        } else {
            date.day = 1;
        }
    } else if ((month == 2 && date.day == 29) || (month % 2 == 1 && date.day == 31) || (month % 2 == 0 && date.day == 30)) {
        date.day = 1;
    } else {
        date.day++;
    }

    if (date.day == 1) {
        if (date.month == 12) {
            date.month = 1;
            date.year++;
        } else {
            date.month += 1;
        }
    }

    return date;
}

int main(int argc, char* argv[])
{
    int day, month, year;

    if (scanf("%d%d%d", &day, &month, &year)) {
        Date date;
        date.day = day;
        date.month = month;
        date.year = year;

        Date newDate = calculate_next_date(date);

        printf("The next date is: %2d %2d %4d\n", newDate.day, newDate.month, newDate.year);
    }

    return EXIT_SUCCESS;
}