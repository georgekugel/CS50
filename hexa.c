#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    long number;

    printf("Please enter a number: ");
    scanf("%ld", &number);

    printf("%ld in hexadecimal is: 0x%lX\n", number, number);
    // %lX is used to print the number in hexadecimal format

    return 0;
}
