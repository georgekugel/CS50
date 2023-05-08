#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    string strings[] = {"3x+1", "alpha", "agree", "array", "calculator", "compare", "hello", "initials", "loop", "mario", "pb", "pb2", "pointer", "search", "triangle"};

    string s = get_string("Search in /CS50: ");
    for (int i = 0; i < 13; i++)
    {
        if (strcmp(strings[i], s) == 0)
        {
            printf("Found\n");
            return 0;
        }
    }
    printf("Not found\n");
    return 1;
}