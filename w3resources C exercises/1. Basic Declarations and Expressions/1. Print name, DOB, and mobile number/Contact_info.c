#include <stdio.h>
#include <stdlib.h>

#define MAX_NAME 50
#define MAX_DOB 20
#define MAX_CONTACT 15

typedef struct
{
    char name[MAX_NAME];
    char DOB[MAX_DOB];
    char contact[MAX_CONTACT];
} person;

int main()
{
    int people_amount = 0;
    int new_people_amount = 0;

    do
    {
        printf("Enter how many people do you need: ");
        scanf("%d", &people_amount);
        getchar();
    } while (people_amount < 1);

    person *people = calloc(people_amount, sizeof(person));

    if (people == NULL)
    {
        printf("Memory allocation failed!\n");
        return 1;
    }

    for (int i = 0; i < people_amount; i++)
    {
        printf("Enter the #%d name: ", i + 1);
        fgets(people[i].name, MAX_NAME, stdin);

        printf("Enter the #%d DOB (month day, year): ", i + 1);
        fgets(people[i].DOB, MAX_DOB, stdin);

        printf("Enter the #%d phone number: ", i + 1);
        fgets(people[i].contact, MAX_CONTACT, stdin);
    }

    do
    {
        printf("Enter the new amount of people do you need: ");
        scanf("%d", &new_people_amount);
        getchar();
    } while (new_people_amount < 0);

    person *temp = realloc(people, new_people_amount * sizeof(person));

    if (temp == NULL)
    {
        printf("Memory reallocation failed!\n");

        for (int i = 0; i < new_people_amount; i++)
        {
            printf("\n***Person #%d***\n\n", i + 1);
            printf("Name: %s", people[i].name);
            printf("DOB: %s", people[i].DOB);
            printf("Contact: %s", people[i].contact);
        }
    }
    else
    {
        people = temp;
        temp = NULL;

        for (int i = people_amount; i < new_people_amount; i++)
        {
            printf("Enter the #%d name: ", i + 1);
            fgets(people[i].name, MAX_NAME, stdin);

            printf("Enter the #%d DOB (month day, year): ", i + 1);
            fgets(people[i].DOB, MAX_DOB, stdin);

            printf("Enter the #%d phone number: ", i + 1);
            fgets(people[i].contact, MAX_CONTACT, stdin);
        }

        for (int i = 0; i < new_people_amount; i++)
        {
            printf("\n***Person #%d***\n\n", i + 1);
            printf("Name: %s", people[i].name);
            printf("DOB: %s", people[i].DOB);
            printf("Contact: %s", people[i].contact);
        }
    }
    free(people);
}