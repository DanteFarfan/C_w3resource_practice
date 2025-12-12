#include <stdio.h>
#include <stdlib.h>

#define MAX_LEN 50

typedef struct
{
    char id[MAX_LEN];
    int number_of_items;
    float weight_of_item;
} purchase;

int main()
{
    int num = 0;
    float avg_weight = 0.0;
    int total_items = 0;
    int choice = 0;
    int new_num = 0;

    do
    {
        printf("Enter the amount of purchases: ");
        scanf("%d", &num);
    } while (num < 1);

    purchase *pPurchase = calloc(num, sizeof(purchase));

    if (pPurchase == NULL)
    {
        printf("Failed to allocate memory!\n");
        return 1;
    }

    for (int i = 0; i < num; i++)
    {
        printf("Enter the item #%d name: ", i + 1);
        scanf(" %s", &pPurchase[i].id);

        printf("Enter the item #%d amount: ", i + 1);
        scanf(" %d", &pPurchase[i].number_of_items);

        printf("Enter the item #%d weight: ", i + 1);
        scanf(" %f", &pPurchase[i].weight_of_item);
    }

    do
    {
        printf("Do you want to add more items? press 0 for 'no' and 1 for 'yes': ");
        scanf("%d", &choice);
    } while (choice != 0 && choice != 1);

    if (choice == 0)
    {
        for (int i = 0; i < num; i++)
        {
            printf("You bought %d %s/s\n", pPurchase[i].number_of_items, pPurchase[i].id);
            avg_weight += pPurchase[i].weight_of_item * pPurchase[i].number_of_items;
            total_items += pPurchase[i].number_of_items;
        }
        printf("The average weight of the purchase is %.2f\n", avg_weight / total_items);
    }
    else
    {
        do
        {
            printf("Enter how many items do you want to add: ");
            scanf("%d", &new_num);
        } while (new_num < 1);

        purchase *temp = realloc(pPurchase, (num + new_num) * sizeof(purchase));

        if (temp == NULL)
        {
            printf("Failed to allocate memory!\n");
            return 1;
        }

        pPurchase = temp;
        temp = NULL;

        for (int i = num; i < new_num + num; i++)
        {
            printf("Enter the item #%d name: ", i + 1);
            scanf(" %s", &pPurchase[i].id);

            printf("Enter the item #%d amount: ", i + 1);
            scanf(" %d", &pPurchase[i].number_of_items);

            printf("Enter the item #%d weight: ", i + 1);
            scanf(" %f", &pPurchase[i].weight_of_item);
        }

        for (int i = 0; i < new_num + num; i++)
        {
            printf("You bought %d %s/s\n", pPurchase[i].number_of_items, pPurchase[i].id);
            avg_weight += pPurchase[i].weight_of_item * pPurchase[i].number_of_items;
            total_items += pPurchase[i].number_of_items;
        }
        printf("The average weight of the purchase is %.2f\n", avg_weight / total_items);
    }

    free(pPurchase);
}