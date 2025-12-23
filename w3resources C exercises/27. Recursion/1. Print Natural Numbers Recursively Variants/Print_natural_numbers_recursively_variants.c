#include <stdio.h>

void print_number(int number);

int main()
{
    int number = 0;
    printf("The natural numbers are: ");
    print_number(number);
}

void print_number(int number)
{
    if (number <= 50)
    {
        printf("%d ", number);
        print_number(number + 1);
    }
}