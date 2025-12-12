#include <stdio.h>

int main()
{
    switch (__STDC_VERSION__)
    {
    case 199901L:
        printf("We are running C99!");
        break;
    case 201112L:
        printf("We are running C11!");
        break;
    case 201710L:
        printf("We are running C17!");
        break;
    case 202311L:
        printf("We are running C23!");
        break;
    default:
        printf("We are running pre-standard C");
        break;
    }

    return 0;
}