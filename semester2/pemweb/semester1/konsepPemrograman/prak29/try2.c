#include <stdio.h>
#define MAX 255

int is_kabisat(int);
int find_days(int, int);

void main()
{
    struct date
    {
        int day, month, year;
    } today = {29, 2, 2024}, tomorrow;

    int max_days, max_months = 12;

    max_days = find_days(today.month, today.year);
    printf("%d", max_days);
    tomorrow.day = today.day;
    tomorrow.year = today.year;
    tomorrow.month = today.month;
    if (today.day == max_days)
    {
        tomorrow.day = 1;
        if (today.month == max_months)
        {
            tomorrow.month = 1;
            tomorrow.year++;
        }
        else
            tomorrow.month++;
    }
    else
        tomorrow.day++;

    printf("Today is %d-%d-%d.\n", today.day, today.month, today.year);
    printf("Tomorrow is %d-%d-%d.\n", tomorrow.day, tomorrow.month, tomorrow.year);
}

int find_days(int month, int year)
{
    int max_days = 0;
    if (month == 2)
    {
        if (is_kabisat(year))
            max_days = 29;
        else
            max_days = 28;
    }
    else if (month <= 7)
    {
        if (month % 2 == 0)
            max_days = 30;
        else
            max_days = 31;
    }
    else if (month <= 12)
    {
        if (month % 2 == 0)
            max_days = 31;
        else
            max_days = 30;
    }
    return max_days;
}

int is_kabisat(int year)
{
    if (year % 100 == 0)
        return (year % 400 == 0 ? 1 : 0);
    else
        return (year % 4 == 0 ? 1 : 0);
}