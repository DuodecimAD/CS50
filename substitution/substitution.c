#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int toascii(int c);

int main(int argc, string argv[])
{

    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    else if (strln(argv[1]) != 26)
    {
        printf("Key must contain 26 characters.\n");
    }

    toupper(argv[1]);
    int key = toascii(argv[1]);

    string input = get_string("plaintext: ");
    int cipher = toascii(input);

    for (int i = 0; i < 26; i++)
    {
        if (isalpha(input[i]) && islower(input[i]))
        {
            cipher[i] = (((cipher[i] - 97) % 26) + ((key[i] - 65) % 26)) + 97;
        }
        else if (isalpha(input[i]) && isupper(input[i]))
        {
            cipher[i] = (((cipher[i] - 65) % 26) + ((key[i] - 65) % 26)) + 65;
        }
    }
    printf("plaintext: %i\n", key);

/*

        for (int i = 0; i < strlen(input); i++)
        {
            if (isalpha(input[i]) && islower(input[i]))
            {
                input[i] = (((input[i] - 97) + key) % 26) + 97;
            }
            else if (isalpha(input[i]) && isupper(input[i]))
            {
                input[i] = (((input[i] - 65) + key) % 26) + 65;
            }
        }
        printf("ciphertext: %s\n", input);

*/
}