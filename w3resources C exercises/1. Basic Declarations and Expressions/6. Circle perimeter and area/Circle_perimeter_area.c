#include <stdio.h>
#include <stdbool.h>
#include <math.h>

#define PI 3.14159

const int min_size = 5;
const float size_correction = 2.3;

int draw_circle(float r);

int main()
{
    float r = 0;

    do
    {
        printf("Enter the circle radius: ");
        scanf("%f", &r);
    } while (r < 0);

    float area = PI * r * r;
    float circunference = 2 * PI * r;

    printf("The circunference is %.2f\n", circunference);
    printf("The area is %.2f\n", area);

    draw_circle(r);
}

int draw_circle(float r)
{
    int len = 2 * (int)r;
    float pitagoras = 0.0;

    if (r < min_size)
    {
        printf("The circle is to small to print!");
        return 1;
    }

    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < len; j++)
        {
            if (i < r && j < r)
            {
                if (hypot(r - j, (r - i) * size_correction) <= r)
                {
                    printf("#");
                }
                else
                {
                    printf(" ");
                }
            }
            if (i < r && j >= r)
            {
                if (hypot((j + 1) - r, (r - i) * size_correction) <= r)
                {
                    printf("#");
                }
                else
                {
                    printf(" ");
                }
            }
            if (i >= r && j < r)
            {
                if (hypot(r - j, ((i + 1) - r) * size_correction) <= r)
                {
                    printf("#");
                }
                else
                {
                    printf(" ");
                }
            }
            if (i >= r && j >= r)
            {
                if (hypot((j + 1) - r, ((i + 1) - r) * size_correction) <= r)
                {
                    printf("#");
                }
                else
                {
                    printf(" ");
                }
            }
        }
        printf("\n");
    }
    return 0;
}
