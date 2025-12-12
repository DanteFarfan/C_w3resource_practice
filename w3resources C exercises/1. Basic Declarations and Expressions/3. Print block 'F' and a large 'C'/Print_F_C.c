#include <stdio.h>

void get_f_size(int *h, int *w);
void draw_f(int *h, int *w);
void get_c_size(int *size);
void draw_c(int *size);

int main()
{
    int height = 0;
    int width = 0;
    int c_size = 0;

    get_f_size(&height, &width);
    get_c_size(&c_size);
    draw_f(&height, &width);
    draw_c(&c_size);
}

void get_f_size(int *height, int *width)
{
    const int min_height = 4;
    const int min_width = 3;

    do
    {
        printf("Enter the height of the F (at least 4): ");
        scanf("%d", height);
    } while (*height < min_height);
    do
    {
        printf("Enter the width of the F (at least 3): ");
        scanf("%d", width);
    } while (*width < min_width);
}

void draw_f(int *height, int *width)
{
    const float ratio = 0.8;

    int h = *height;
    int w = *width;

    for (int i = 0; i < h; i++)
    {
        if (i == 0)
        {
            for (int j = 0; j < w; j++)
            {
                printf("#");
            }
            printf("\n");
        }
        else if (i == (*height) / 2)
        {
            for (int k = 0; k < w * ratio; k++)
            {
                printf("#");
            }
            printf("\n");
        }
        else
        {
            printf("#\n");
        }
    }
}

void get_c_size(int *size)
{
    const int min_size = 4;
    do
    {
        printf("Enter the height of the C (at least 4): ");
        scanf("%d", size);
    } while (*size < min_size);
}

void draw_c(int *size)
{
    const float width_ratio = 1.222;
    const float top_space_width_ratio = 0.182;
    const float top_width_ratio = 0.555;

    int s = *size;
    int width = s * width_ratio;

    for (int i = 0; i <= s; i++)
    {
        if (i == 0)
        {
            printf(" ");
            for (int j = 0; j < width * top_space_width_ratio; j++)
            {
                printf(" ");
            }
            for (int k = 0; k < width * top_width_ratio; k++)
            {
                printf("#");
            }
            printf("\n");
        }
        else if (i == 1)
        {
            printf(" ");
            for (int j = 0; j < width * top_space_width_ratio; j++)
            {
                printf("#");
            }
            for (int k = 0; k < width * top_width_ratio; k++)
            {
                printf(" ");
            }
            for (int l = 0; l < width * top_space_width_ratio; l++)
            {
                printf("#");
            }
            printf("\n");
        }
        else if (i == s - 1)
        {
            printf(" ");
            for (int j = 0; j < width * top_space_width_ratio; j++)
            {
                printf("#");
            }
            for (int k = 0; k < width * top_width_ratio; k++)
            {
                printf(" ");
            }
            for (int l = 0; l < width * top_space_width_ratio; l++)
            {
                printf("#");
            }
            printf("\n");
        }
        else if (i == s)
        {
            printf(" ");
            for (int j = 0; j < width * top_space_width_ratio; j++)
            {
                printf(" ");
            }
            for (int k = 0; k < width * top_width_ratio; k++)
            {
                printf("#");
            }
            printf("\n");
        }
        else
        {
            printf("#\n");
        }
    }
}