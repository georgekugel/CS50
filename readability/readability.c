#include <ctype.h>
#include <cs50.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    // Prompt user for text
    string text = get_string("Text: ");

    // Count number of letters, words, and sentences
    int letters = 0, words = 0, sentences = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (isalpha(text[i]))
        {
            letters++;
        }
        else if (isspace(text[i]))
        {
            words++;
        }
        else if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentences++;
        }
    }
    words++; // Last word doesn't end with a space, so add one more word

    // Compute Coleman-Liau index
    float L = (float) letters / words * 100.0;
    float S = (float) sentences / words * 100.0;
    int index = round(0.0588 * L - 0.296 * S - 15.8);

    // Print grade level
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }

    return 0;
}