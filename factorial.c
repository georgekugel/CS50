#include <stdio.h>
#include <cs50.h>

long long factorial(int n);

int main(void)
{
    int n = get_int("Enter number to find factorial: ");
    printf("%lld\n", factorial(n));
}

long long factorial(int n)
{
    if (n == 0)
    {
        return 1;
    }

    return n * factorial(n - 1);
}
