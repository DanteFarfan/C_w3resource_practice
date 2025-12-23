#include <stdio.h>

int fibonacci(int input_number, int number);

int main()
{
    int input_number = 10;
    int number = 0;

    printf("The series are: ");

    fibonacci(input_number, number);
}

int fibonacci(int input_number, int number)
{
    int last_number;
    int result;
    if (input_number == 10)
    {
        return 0;
    }
    else
    {
        result = number;
        last_number = number;
    }
}