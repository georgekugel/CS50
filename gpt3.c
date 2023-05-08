#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main(void)
{
    printf("\nWELCOME TO NUMBER PRINT!\n");

    string input = get_string("Enter a number: ");
    printf("\n");
    int length = strlen(input);

    // Define the patterns for each digit
    string patterns[10][5] = {
        {" 0000  ", "00  00 ", "00  00 ", "00  00 ", " 0000  "},
        {"1111  ", "  11  ", "  11  ", "  11  ", "11111 "},
        {" 2222  ", "22  22 ", "   22  ", "  22   ", "222222 "},
        {" 3333  ", "33  33 ", "   333 ", "33  33 ", " 3333  "},
        {"44  44 ", "44  44 ", "444444 ", "    44 ", "    44 "},
        {"555555 ", "55     ", "55555  ", "    55 ", "55555  "},
        {" 6666  ", "66     ", "66666  ", "66  66 ", " 6666  "},
        {"777777 ", "   77  ", "  77   ", " 77    ", "77     "},
        {" 8888  ", "88  88 ", " 8888  ", "88  88 ", " 8888  "},
        {" 9999  ", "99  99 ", " 99999 ", "    99 ", " 9999  "}
    };

    // Loop through each line of the patterns and print out the corresponding digit
    for (int line = 0; line < 5; line++)
    {
        for (int i = 0; i < length; i++)
        {
            int digit = input[i] - '0';  // convert char to int
            if (digit < 0 || digit > 9)
            {
                printf("Input is invalid. Shutting down.\n");
                return 1;
            }
            printf("%s", patterns[digit][line]);
        }
        printf("\n");
    }
    //Extra line to leave space for command line.
    printf("\n");

    return 0;
}
