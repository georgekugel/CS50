#include <stdio.h>
#include <cs50.h>

//Print however many powers of 2 as the user wants

int main(void)
{
    int length
    do
    {
        length = get_int("Length: ");
    }
    while (length < 1);

    int powers[length];

    powers[0] = 1;
    printf("%i\n", powers[0]);

    for (int i = 1; i < length; i++)
    {
        powers[i] = 2 * powers [i - 1];
        printf("%i\n", powers[i]);
    }
}