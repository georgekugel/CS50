#include <stdio.h>

int main(void)
{
    char s[10]; // Allocate 11 bytes just in case.
    printf("s: ");
    scanf("%s", s);
    printf("s: %s\n", s);
}