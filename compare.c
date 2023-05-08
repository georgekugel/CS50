#include <cs50.h>
#include <stdio.h>

// #include <string.h>
// if (strcmp(s, t) == 0) <-- Strings are identical.

int main(void)
{
    //Prompt for number/value
    string s = get_string("String 1: ");
    string t = get_string("String 2: ");

    printf("String 1 is at %p\n", &s);
    printf("String 2 is at %p\n", &t);
}