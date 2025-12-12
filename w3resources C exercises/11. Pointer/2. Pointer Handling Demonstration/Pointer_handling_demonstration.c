#include <stdio.h>

int main()
{
    int *ab;
    int m;

    m = 29;
    ab = &m;

    printf("Now ab is assigned with the address of m.\n");
    printf("Address of pointer ab : %p\n", ab);
    printf("Pointer ab (address of m) : %p\n", ab);
    printf("Value pointed to by ab : %d\n", *ab);

    m = 34;

    printf("\nThe value of m assigned to %d now.\n", m);
    printf("Address of pointer ab : %p\n", ab);
    printf("Pointer ab (address of m) : %p\n", ab);
    printf("Value pointed to by ab : %d\n", *ab);

    *ab = 7;

    printf("Address of m : %p\n", &m);
    printf("Value of m : %d\n", m);
}