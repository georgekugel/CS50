#include <stdio.h>

int main(void)
{
    char *s = "Hello, world!";
    printf("%s\n", s); // Prints the string.
    printf("1st character: %c\n", *s); // Prints the one char stored at that memory slot.
    printf("(Without 1st char) %s\n", s+1); // Prints from the second character of the string on.
    printf("3rd char: %c\n", s[2]); // Prints ONLY the third character of the string.
    printf("1st char stored at %p\n", s); // Prints location of first char.

    //POINTERS = Addresses
    //int n = 50;
    //int *p = &n; //<-- '&' precedes a type to refer to its location
    //printf("%p\n", p);

//int numbers[] = {1, 2, 3};
//printf("Numbers %i, %i and %i are stored in %p,\n %p and %p respectively.\n", numbers[0], numbers[1], numbers[2], &numbers[0], &numbers[1], &numbers[2]);

//string = char * (A string is actually the address of the first character)
}