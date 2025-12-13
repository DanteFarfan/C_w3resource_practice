#include <stdio.h>

int main()
{
    int a = 5;
    int b = 6;

    int *pA = &a;
    int *pB = &b;

    printf("The sum of %d + %d = %d\n", a, b, *pA + *pB);
}