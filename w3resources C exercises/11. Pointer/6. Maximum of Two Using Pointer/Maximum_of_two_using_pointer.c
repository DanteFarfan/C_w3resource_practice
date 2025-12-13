#include <stdio.h>

void get_max(int *pA, int *pB);

int main()
{
    int a = 0;
    int b = 0;

    printf("Enter the first value: ");
    scanf("%d", &a);

    printf("Enter the second value: ");
    scanf("%d", &b);

    get_max(&a, &b);
}

void get_max(int *pA, int *pB)
{
    if ((*pA) > (*pB))
    {
        printf("%d is bigger than %d", *pA, *pB);
    }
    else if ((*pA) < (*pB))
    {
        printf("%d is bigger than %d", *pB, *pA);
    }
    else
    {
        printf("%d is equal to %d", *pA, *pB);
    }
}