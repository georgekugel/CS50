#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int x = 0;
    printf("Number of ints: ");
    scanf("%d", &x);

    int *list = malloc(x * sizeof(int));

    for (int i = 0; i < x; i++)
    {
        printf("Enter int %i: ", i + 1);
        scanf("%d", &list[i]);
    }

    for (int i = 0; i < x; i++)
    {
        printf("%d\n", list[i]);
    }

    free(list);
    return 0;
}
