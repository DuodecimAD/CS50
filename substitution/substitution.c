#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int toascii(int c);

int main(int argc, string argv[])
{

    int length = strln(argv[1])

    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    else if (length != 26)
    {
        printf("Key must contain 26 characters.\n");
    }

    toupper(argv[1]);
    int key = toascii(argv[1]);

    string input = get_string("plaintext: ");
    int cipher = toascii(input);
    int a;
    for (int i = 0; i < 26; i++)
    {
        if (isalpha(input[i]) && islower(input[i]))
        {
            a = (cipher[i] - 97) % 26;
             cipher[i] = key[a];
        }
        else if (isalpha(input[i]) && isupper(input[i]))
        {
            a = (cipher[i] - 65) % 26;
            cipher[i] = key[a];
        }
    }
    printf("ciphertext: %s\n", cipher);

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