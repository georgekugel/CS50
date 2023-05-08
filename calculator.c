#include <cs50.h>
#include <stdio.h>

int main(void)
{
    //int: small values
    //long: large values
    //float: values for division
    //double: values for precise division
    long x = get_long("x: ");
    long y = get_long("y: ");

    double z = (double) x / (double) y;
    printf("Result: %.20f\n", z);
}