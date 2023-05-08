#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int x = 0;
    int * pX = &x;
    int y = *pX;
    printf("%i\n", y);
}