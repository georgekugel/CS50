
#include <stdio.h>
#include <cs50.h>


int main(void)
{
    char c;
    char d;
    string name;
    printf("\nWELCOME TO PHONEBOOK!");
    do
    {
        do
        {
            name = get_string("\nWhat's your contact's name?\n>> ");
            c = get_char("\nThe name is %s. Is that correct?\n[Y or N] >> ", name);
            if (c == 'n' || c == 'N')
            {
                printf("\nOops, let's try that again.\n");
            }
        }
        while (c == 'n' || c == 'N');

        if (c == 'y' || c == 'Y')
            {
                printf("Perfect! %s has been created\n\n", name);
            }
    //----------------------------------------------------------------------------
        string number;
        do
        {
            number = get_string("What's %s's number?\n>> ", name);
            c = get_char("\nThe number is %s. Is that correct?\n[Y or N] >> ", number);
            if (c == 'n' || c == 'N')
            {
                printf("\nOops, let's try that again.\n");
            }
        }
        while (c == 'n' || c == 'N');

        if (c == 'y' || c == 'Y')
            {
                printf("\nPerfect! %s's number has been saved\n", name);
            }
        printf("_________________\n|Name: %s\n", name);
        printf("|Phone: %s\n-----------------\n\n", number);

    //--------------------------------------------------------------------------
    d = get_char("Do you want to add another contact?\n[Y or N] >> ");
    }
    while (d == 'y' || d == 'Y');

    if (d == 'n' || d == 'N')
        {
        printf("\nOK. Thanks for using Phonebook!\n\n");
        }
}