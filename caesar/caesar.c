#include <cs50.h>
#include <stdio.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    argc = 1;
    int key = argv[1];

    if(isdigit(key))
    {
        string input = get_string("plaintext: \n");

        for (int i = 0; i < strlen(input); i++)
        {
            input[i] = (input[i] + key) % 26;
        }

        printf("ciphertext: %s\n", input);

    }



}