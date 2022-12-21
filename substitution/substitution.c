#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int toascii(int c);

int main(int argc, string argv[])
{

    string length = argv[1];

    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    else if (strlen(length) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }

    string input = get_string("plaintext: ");

    char key[26];
    int input_length = strlen(input);
    char cipher[input_length + 1];

    for (int j = 0; j < 26; j++)
    {
        key[j] = toupper(argv[1][j]);
        key[j] = toascii(key[j]);
    }


    int a;

    for (int i = 0; i < input_length; i++)
    {
        cipher[i] = toascii(input[i]);

        if (isalpha(input[i]) && islower(input[i]))
        {
            a = (cipher[i] - 97) % 26;
             cipher[i] = key[a] + 32;
        }
        else if (isalpha(input[i]) && isupper(input[i]))
        {
            a = (cipher[i] - 65) % 26;
            cipher[i] = key[a];
        }
    }
    cipher[input_length + 1] = '\0';

    printf("ciphertext: %s\n", cipher);


}