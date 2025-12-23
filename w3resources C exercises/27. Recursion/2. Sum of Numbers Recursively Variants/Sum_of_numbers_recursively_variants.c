#include <stdio.h>

int sum_of_numbers(int number);

int main()
{
    int number = 5;
    printf("the sum of the numbers from 1 to %d is: ", number);
    int result = sum_of_numbers(number);
    printf("%d\n", result);
}

int sum_of_numbers(int number)
{
    int result;
    if (number == 1)
    {
        return 1;
    }
    else
    {
        result = number + sum_of_numbers(number - 1);
    }
    return result;
}