#include <stdio.h>
#include <string.h>

void letter_swap(char *word, int word_length);
void permutation(char *word, int word_length);

int main()
{
    int word_length = 0;

    do
    {
        printf("Enter the length of the word: ");
        scanf("%d", &word_length);
    } while (word_length < 1);

    char *word = calloc(word_length, sizeof(char));

    if (word == NULL)
    {
        printf("Failed to allocate memory\n");
        return 1;
    }

    void permutation(word, word_length);

    free(word);
}

void permutation(char *word, int word_length)
{
    char *reulting_string = malloc((word_length + 1) * sizeof(char));
    
    if (reulting_string == NULL)
    {
        printf("Failed to allocate memory\n");
        return;
    }

    if (strlen(reulting_string) == word_length)
    {
        printf("%s", reulting_string);
    }

    for (int i = 0; i < word_length; i++)
    {

    }
    
    free(reulting_string);
}

void letter_swap(char *word, int word_length)
{
}