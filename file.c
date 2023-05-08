#include <cs50.h>
#include <stdint.h>
#include <stdio.h>

int main(int argc, string argv[])
{
    // If number of command arguments is not 2 (e.g. ./file sth.pdf) then shut down.
    if (argc != 2)
    {
        printf("Invalid usage.\n");
        return 1;
    }

    // Open file
    string filename = argv[1];
    FILE *file = fopen(filename, "r");

    // Check if file exists.
    if (file == NULL)
    {
        printf("No such file found.\n");
        return 1;
    }

    uint8_t buffer[4];
    uint8_t signature[] = {35, 105, 110, 99};

    fread(buffer, 1, 4, file);

    // Does the buffer signature match?
    for (int i = 0; i < 4; i++)
    {
        if (buffer[i] != signature[i])
        {
            printf("Likely NOT a C file\n");
            return 0;
        }
    }
    printf("Likely a C file\n");
    return 0;
}

// --> FILE *input = fopen("hi.txt", "r");
// Create a type FILE with address 'input' called "hi.txt" in reading mode ('r').

// --> fread(buffer, 1, 3, input)
// Data goes inside a buffer.
// 1: Size of blocks to read (in bytes).
// 3: Number of blocks to read (in bytes).
// input: Location to read from.