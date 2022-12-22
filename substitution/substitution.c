#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int toascii(int c);

int main(int argc, string argv[])
{
    //check if ./substitution + only 1 arg, if 26, if alphabetical
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    else if (strlen(argv[1]) != 26)
    {
        for (int y = 0; y < strlen(argv[1]); y++)
        {
            if (!isalpha(argv[1][y]))
            {
                printf("Key must contain only alphabetical characters.\n");
                return 1;
            }
        }
        printf("Key must contain 26 characters.\n");
        return 1;
    }

    // check for duplicate letters (part1), array of 0s, for each letter give 1
    int duplicate[26] = {0};

    for (int p = 0, b = 0; p < 26; p++)
    {
        if (islower(argv[1][p]))
        {
            b = (argv[1][p] - 97) % 26;
            duplicate[b] += 1;
        }
        else if (isupper(argv[1][p]))
        {
            b = (argv[1][p] - 65) % 26;
            duplicate[b] += 1;
        }

    }

    // if a 0 still in array = duplicate
    for (int m = 0; m < 26; m++)
    {
        if (duplicate[m] == 0)
        {
            printf("You have duplicate letters.\n");
            return 1;
        }
    }

    // get input to transform
    string input = get_string("plaintext: ");

    char key[26];
    int input_length = strlen(input);
    char cipher[input_length + 1];

    // transform letters in key in ascii numbers
    for (int j = 0; j < 26; j++)
    {
        key[j] = toupper(argv[1][j]);
        key[j] = toascii(key[j]);
    }

    // for each letter in input transoform to letter from key
    int a;
    for (int i = 0; i < input_length; i++)
    {
        cipher[i] = toascii(input[i]);

        if (isalpha(input[i]) && islower(input[i]))
        {
            a = (cipher[i] - 97) % 26;
            if (islower(key[a]))
            {
                cipher[i] = key[a];
            }
            else
            {
                cipher[i] = key[a] + 32;
            }
        }
        else if (isalpha(input[i]) && isupper(input[i]))
        {
            a = (cipher[i] - 65) % 26;
            if (islower(key[a]))
            {
                cipher[i] = key[a] - 32;
            }
            else
            {
                cipher[i] = key[a];
            }
        }
    }

    // give last bit a null to finish the string, could have use {0},
    // but i let it like this as example and to remember if i need one day
    cipher[input_length] = '\0';

    printf("ciphertext: %s\n", cipher);
}