#include <stdio.h>
#include <stdlib.h>


typedef struct node
{
    int number;
    struct node *next;
}
node;

int main(int argc, char *argv[])
{
    node *list = NULL;

    for (int i = 1; i < argc; i++)
    {
        int number = atoi(argv[i]);

        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            printf("Not enough memory!!\n");
            return 1;
        }

        n->number = number;
        n->next = NULL;

        n->next = list;
        list = n;
    }

    // Printing numbers
    node *ptr = list;
    int sum = 0;
    while (ptr != NULL)
    {
        printf("%i\n", ptr->number);
        sum += ptr->number;
        ptr = ptr->next;
    }
    printf("Sum of all numbers = %i\n", sum);

    //Free memory
    ptr = list;
    while (ptr != NULL)
    {
        node *next = ptr->next;
        free(ptr);
        ptr = next;
    }
}