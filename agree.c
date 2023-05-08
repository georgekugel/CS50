#include <cs50.h>
#include <stdio.h>

int main(void)
{
    //Prompt user for character*
    char c = get_char("Lieben Sie Ihren Mann?\n[J oder N] ");

    //'j' or 'J'
    if (c == 'j' || c == 'J')
    {
        printf("Gut gesagt.\n");
    }
    //'n' or 'N'
    else if (c == 'n' || c == 'N')
    {
        printf("Wtf?\n");
    }
}