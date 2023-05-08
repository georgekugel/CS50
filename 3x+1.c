#include <stdio.h>
#include <cs50.h>

long l;
int i;

int main(void)
{
    printf("\nWELCOME TO 3X+1!\n----------------\n");
    l = get_long("Enter number to start ");
    printf("\n");

    i = 0;

    do
    {
        i++;
        printf("%i. ", i);

        if (l % 2 == 1)
        {
            printf("ODD: (%ld x 3) + 1 = ", l);
            l = (3 * l) + 1;
            printf("%ld\n\n", l);
        }
        else
        {
            printf("EVEN: %ld / 2 = ", l);
            l = l / 2;
            printf("%ld\n\n", l);
        }
    }
    while (l > 1);
}