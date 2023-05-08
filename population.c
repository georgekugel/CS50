#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int init;
    int final;

    do
    {
    init = get_int("Start size: ");
    }
    while (init <= 0);

    do
    {
    final = get_int("End size: ");
    }
    while (final <= init);

    int years = 0;

    do
    {
        init = init + (init / 3) - (init / 4);
        years = years + 1;a
    }
    while (init < final);

    printf("Years: %i\n", years);
}
