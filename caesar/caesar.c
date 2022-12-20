#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

bool only_digits(string check);

int main(int argc, string argv[])
{
    if(argc == 0 || argc > 2){

        printf("Usage: ./caesar key\n");
        return 1;
    }



    if (!only_digits(argv[1]) || !argv[1])
    {
        printf("Usage: ./caesar key2\n");
        return 1;
    }
    else
    {

        string input = get_string("plaintext: ");
        int key = atoi(argv[1]);

        for (int i = 0; i < strlen(input); i++)
        {
            if(isalpha(input[i]) && islower(input[i]))
            {
               input[i] = (((input[i] - 97) + key) % 26) + 97;
            }
            else if(isalpha(input[i]) && isupper(input[i]))
            {
                input[i] = (((input[i] - 65) + key) % 26) + 65;
            }


        }

        printf("ciphertext: %s\n", input);

    }

}

bool only_digits(string s)
{
    int number;

    for (int i = 0; i < strlen(s); i++)
    {
        if (!isdigit(s[i]))
        {
            return false;
        }
    }
        return true;

}