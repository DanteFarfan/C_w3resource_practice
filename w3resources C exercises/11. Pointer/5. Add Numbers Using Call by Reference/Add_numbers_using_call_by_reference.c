#include <stdio.h>

void sum(int *pA, int *pB, int *pRes);

int main()
{
    int a = 0;
    int b = 0;

    printf("Enter the first value: ");
    scanf("%d", &a);

    printf("Enter the second value: ");
    scanf("%d", &b);

    int res = 0;

    sum(&a, &b, &res);

    printf("%d + %d = %d\n", a, b, res);
}

void sum(int *pA, int *pB, int *pRes)
{
    *pRes = (*pA) + (*pB);
}