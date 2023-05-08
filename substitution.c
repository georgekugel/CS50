#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

bool is_valid_key(string key);
string encrypt(string plaintext, string key);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: %s KEY\n", argv[0]);
        return 1;
    }

    string key = argv[1];
    if (!is_valid_key(key))
    {
        printf("Key must contain 26 unique alphabetic characters.\n");
        return 1;
    }

    string plaintext = get_string("plaintext: ");
    string ciphertext = encrypt(plaintext, key);
    printf("ciphertext: %s\n", ciphertext);

    return 0;
}

bool is_valid_key(string key)
{
    int counts[26] = {0};
    int length = strlen(key);

    if (length != 26)
    {
        return false;
    }

    for (int i = 0; i < length; i++)
    {
        char c = key[i];
        if (!isalpha(c))
        {
            return false;
        }
        c = toupper(c);
        int index = c - 'A';
        if (counts[index] > 0)
        {
            return false;
        }
        counts[index]++;
    }

    return true;
}

string encrypt(string plaintext, string key)
{
    string ciphertext = plaintext;
    int length = strlen(ciphertext);

    for (int i = 0; i < length; i++)
    {
        char c = ciphertext[i];
        if (isalpha(c))
        {
            char replacement = key[toupper(c) - 'A'];
            if (islower(c))
            {
                replacement = tolower(replacement);
            }
            ciphertext[i] = replacement;
        }
    }

    return ciphertext;
}
