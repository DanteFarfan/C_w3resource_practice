#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

#define MAX_LEN_ID 10
#define MAX_LEN_HOURS 5
#define MAX_LEN_WAGE 10

typedef struct
{
    char id[MAX_LEN_ID];
    char hours[MAX_LEN_HOURS];
    char wage[MAX_LEN_WAGE];
} employee;

bool is_float(const char *s);
void get_employees(employee *pEmployee, int num);
void calculate_salary(employee *pEmployee, int num);

int main()
{
    int num = 0;

    do
    {
        printf("Enter the amount of employees: ");
        scanf(" %d", &num);
    } while (num < 1);

    employee *pEmployee = calloc(num, sizeof(employee));

    if (pEmployee == NULL)
    {
        printf("Error allocating memory!\n");
        return 1;
    }

    get_employees(pEmployee, num);
    calculate_salary(pEmployee, num);
}

bool is_float(const char *s)
{
    bool seen_point = false;
    bool seen_coma = false;
    bool seen_plus = false;
    bool seen_minus = false;
    bool seen_digit = false;
    bool end_number = false;

    int len = strlen(s);

    for (int i = 0; i < len; i++)
    {
        if (end_number && isdigit(s[i]))
        {
            return false;
        }
        if (isdigit(s[i]))
        {
            seen_digit = true;
            continue;
        }
        if (isspace(s[i]))
        {
            if (seen_point || seen_coma || seen_digit || seen_minus || seen_plus)
            {
                end_number = true;
            }
            continue;
        }
        switch (s[i])
        {
        case '.':
            if (seen_point || seen_coma || end_number)
            {
                return false;
            }
            else
                seen_point = true;
            break;
        case ',':
            if (seen_point || seen_coma || end_number)
            {
                return false;
            }
            else
                seen_coma = true;
            break;
        case '+':
            if (i == len - 1)
            {
                return false;
            }
            else if (seen_minus || seen_plus || !isdigit(s[i + 1]))
            {
                return false;
            }
            else if (seen_point || seen_coma || seen_digit || end_number)
            {
                return false;
            }
            else
                seen_plus = true;
            break;
        case '-':
            if (i == len - 1)
            {
                return false;
            }
            else if (seen_minus || seen_plus || !isdigit(s[i + 1]))
            {
                return false;
            }
            else if (seen_point || seen_coma || seen_digit || end_number)
            {
                return false;
            }
            else
                seen_minus = true;
            break;
        default:
            return false;
        }
    }
    if (!seen_digit)
    {
        return false;
    }
    return true;
}

void get_employees(employee *pEmployee, int num)
{
    int is_valid = 0;

    for (int i = 0; i < num; i++)
    {
        do
        {
            is_valid = 1;
            printf("Enter employee #%d id: ", i + 1);
            scanf("%9s", pEmployee[i].id);
            for (int j = 0; j < strlen(pEmployee[i].id); j++)
            {
                if (pEmployee[i].id[j] == '\n')
                    continue;

                if (!isdigit(pEmployee[i].id[j]))
                {
                    is_valid = 0;
                    break;
                }
            }

        } while (!is_valid || strlen(pEmployee[i].id) < 1);

        do
        {
            printf("Enter employee #%d amount of hours worked: ", i + 1);
            scanf("%4s", pEmployee[i].hours);
        } while (is_float(pEmployee[i].hours) || strlen(pEmployee[i].hours) == 0);

        do
        {
            printf("Enter employee #%d wage: ", i + 1);
            scanf("%9s", pEmployee[i].wage);
        } while (is_float(pEmployee[i].wage) || strlen(pEmployee[i].wage) == 0);
    }
}

void calculate_salary(employee *pEmployee, int num)
{
    for (int i = 0; i < num; i++)
    {
        printf("the employee #%s worked %.2f hours at a hourly rate of $%.2f per hour\n", pEmployee[i].id, atof(pEmployee[i].hours), atof(pEmployee[i].wage));
        printf("The total salary is $%.2f\n", atof(pEmployee[i].hours) * atof(pEmployee[i].wage));
    }
}
