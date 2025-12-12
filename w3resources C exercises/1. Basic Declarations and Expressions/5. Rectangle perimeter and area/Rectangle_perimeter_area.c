#include <stdio.h>

void draw_rectangle(int ih, int iw);

int main()
{
    float h = 0;
    float w = 0;

    float area = 0;
    float perimeter = 0;

    do
    {
        printf("Enter the rectangle height: ");
        scanf("%f", &h);

        printf("Enter the rectangle width: ");
        scanf("%f", &w);
    } while (h <= 0 || w <= 0);

    area = h * w;
    perimeter = (2 * h) + (2 * w);

    int ih = (int)h;
    int iw = (int)w;

    printf("the perimeter is %.2f\n", perimeter);
    printf("the area is %.2f\n", area);

    draw_rectangle(ih, iw);
}

void draw_rectangle(int ih, int iw)
{
    printf("***Rectangle size could be inaccurate due to terminal limitations***\n");

    if (iw < 2 || ih < 2)
    {
        printf("Rectangle too small to display.\n");
        return;
    }

    for (int i = 0; i < ih; i++)
    {
        if (i == 0)
        {
            for (int j = 0; j < iw; j++)
            {
                printf("#");
            }
            printf("\n");
        }
        else if (i == ih - 1)
        {
            for (int j = 0; j < iw; j++)
            {
                printf("#");
            }
            printf("\n");
        }
        else
        {
            printf("#");
            for (int j = 0; j < iw - 2; j++)
            {
                printf(" ");
            }
            printf("#\n");
        }
    }
}