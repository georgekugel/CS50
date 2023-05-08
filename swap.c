#include <stdio.h>

void swap(int *a, int *b);

int main(void)
{
    int x = 1;
    int y = 2;

    printf("(1) x is %i and y is %i\n", x, y);
    
    // Values don't get swapped, addresses do. Hence '&'.
    swap(&x, &y);

    printf("(2) x is %i and y is %i\n", x, y);
}

void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}