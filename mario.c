
//Program displays a grid of bricks of sorts

#include <cs50.h>
#include <stdio.h>

int get_size(void);
void print_grid(int size);

int n;

int main(void)
{
    n = get_size();
    print_grid(n);
}
//-------------------------------------------------------------------------
int get_size(void)
{
    //Do as follows: as long as n < 1, keep prompting for int.
    do
    {
        n = get_int("Height: ");
    }
    while (n < 1 || n > 8);
    return n;
}
//-------------------------------------------------------------------------
void print_grid(int size)
{
    for (int i = 1; i <= size; i++)
    {
        // Print dots
        for (int j = 0; j < size - i; j++)
        {
            printf(" ");
        }

        // Print hashes
        for (int j = 0; j < i; j++)
        {
            printf("#");
        }

        printf("\n");
    }
}
