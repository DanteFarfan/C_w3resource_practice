#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 50

void get_string(char string[]);
void no_new_line(char string[]);
void reverse_string(char string[]);

int main()
{
    char string[MAX_LENGTH] = "\0";

    get_string(string);
    no_new_line(string);
    reverse_string(string);

    printf("%s\n", string);
}

void get_string(char string[])
{
    int too_long = 0;

    do
    {
        too_long = 0;

        printf("Enter a string: ");
        if (!fgets(string, MAX_LENGTH, stdin))
        {
            printf("Input error!\n");
            continue;
        }

        if (string[strlen(string) - 1] != '\n')
        {
            printf("The string is too long!\n");
            too_long = 1;

            int c;
            while ((c = getchar()) != '\n' && c != EOF)
                ;
        }

    } while (string[0] == '\0' || string[0] == '\n' || too_long == 1);
}

void no_new_line(char string[])
{
    if (string[strlen(string) - 1] == '\n')
    {
        string[strlen(string) - 1] = '\0';
    }
}

void reverse_string(char string[])
{
    char temp_string[MAX_LENGTH];
    int len = strlen(string);

    for (int i = len; i > 0; i--)
    {
        temp_string[len - i] = string[i - 1];
    }

    temp_string[len] = '\0';

    strcpy(string, temp_string);
}