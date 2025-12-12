#include <stdio.h>

const int year_len = 365;
const int week_len = 7;

int main()
{
    int days = 0;
    int years = 0;
    int weeks = 0;

    do
    {
        printf("Enter the number of days: ");
        scanf("%d", &days);
    } while (days < 0);

    years = days / year_len;
    weeks = (days % year_len) / week_len;
    days = (days % year_len) % week_len;

    if (years >= 1)
    {
        printf("%d year/s\n", years);
    }
    if (weeks >= 1)
    {
        printf("%d weeks/s\n", weeks);
    }
    if (days >= 1)
    {
        printf("%d day/s\n", days);
    }
}