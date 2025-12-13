#include <stdio.h>
#include <stdlib.h>

void fill_array(int *numbers_array, int array_size);
void print_array(int *numbers_array, int array_size);

int main()
{
    int array_size = 0;

    do
    {
        printf("Enter how many numbers do you want");
        scanf("%d", &array_size);
    } while (array_size < 1);

    int *numbers_array = calloc(array_size, sizeof(int));

    if (numbers_array == NULL)
    {
        printf("Error allocating memory\n");
        return 1;
    }

    fill_array(numbers_array, array_size);
    print_array(numbers_array, array_size);

    free(numbers_array);
}

void fill_array(int *numbers_array, int array_size)
{
    for (int i = 0; i < array_size; i++)
    {
        printf("Enter the #%d number of the array: ", i + 1);
        scanf("%d", &numbers_array[i]);
    }
}

void print_array(int *numbers_array, int array_size)
{
    for (int i = 0; i < array_size; i++)
    {
        printf("the #%d number of the array is %d\n", i + 1, numbers_array[i]);
    }
}