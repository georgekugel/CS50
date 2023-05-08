#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct node
{
    int number;
    struct node *next;
}
node;
// A structure that points to an address where the next element of a list is stored at.

int main(int argc, char *argv[])
{
    node *list = NULL;

    for (int i = 1; i < argc; i++)
    {
        int number = atoi(argv[i]);

        if (!isdigit(*argv[i]))
        {
            printf("Only integers can be command line arguments!\n");
            return 1;
        }

        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            printf("Out of memory!\n");
            return 1;
        }
        n->number = number;
        n->next = NULL;

        n->next = list;
        list = n;
    }

    node *ptr = list;
    while (ptr != NULL)
    {
        printf("%i\n", ptr->number);
        ptr = ptr->next;
    }

    ptr = list
    while (ptr != NULL)
    {
        node *next = ptr->next;
        free(ptr);
        ptr = next;
    }
}
//    if (argc != 4) // ./node 1 2 3 <-- 4 command line arguments
//    {
//        return 1; // Kill the program
//    }