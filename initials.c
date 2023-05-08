#include <stdio.h>
#include <cs50.h>

int main(int argc, string argv[])
{
    int i = 0;

    do
    {
        i++;
        printf("%c ", argv[i][0]);
    }
    //While the value of the char is not \0 (when the string ends)
    while (true);

    printf("\n");
}