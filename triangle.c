#include <stdio.h>
#include <cs50.h>

//Create a function that tells whether 3 ints could possibly form a triangle
int real_trngl(int a, int b, int c);

int main(void)
{
    printf("\nWELCOME TO TRIANGLER 3000\n\n");
    int x = get_int("Enter first number\n>> ");
    int y = get_int("Enter second number\n>> ");
    int z = get_int("Enter third number\n>> ");

    int w = real_trngl (x, y, z);

    if (w == 0)
    {
        printf("_____________________________\nTHIS TRIANGLE IS NOT POSSIBLE\n-----------------------------\n");
    }
    else if (w == 1)
    {
        printf("_________________________\nTHIS TRIANGLE IS POSSIBLE\n-------------------------\n");
    }
}

int real_trngl(int a, int b, int c)
{
    //Calculate if the 3 ints can be a triangle
    //The sum of two sides must be greater than the third
    int t;
    if (a + b <= c || a + c <= b || b + c <= a)
    {
        t = 0;
    }
    else if (a <= 0 || b <= 0 || c <= 0)
    {
        t = 0;
    }
    else
    {
        t = 1;
    }
    return t;
}