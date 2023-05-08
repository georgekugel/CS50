#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char *s = get_string("Input: ");
    if (s == NULL)
    {
        return 1;
    }

    char *t = malloc(strlen(s) + 1);
    if (t == NULL)
    {
        return 1;
    }

    int n = strlen(s);

    strcpy(t, s);

//    ANOTHER POSSIBILITY
//    for (int i = 0; i < n + 1; i++)
//    {
//        t[i] = s[i];
//    }

    if (strlen(t) > 0)
    {
        for (int j = 0; j < n + 1; j++)
        {
            t[j] = toupper(t[j]);
        }

        printf("Output: %s\n", t);
    }
    else
    {
        printf("Invalid input\n");
    }
    
    free(t);
    return 0;
}