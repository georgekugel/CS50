#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main(void)
{
    string word = get_string("Word: ");
    int length = strlen(word);

    for (int i = 1; i < length; i++)
    {
        if (word[i] > word[i - 1])
        {
            printf("Y ");
        }
        else
        {
            printf("N ");
        }
    }
    printf("\n");
}