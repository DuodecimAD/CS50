#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

bool only_digits(string check);

int main(int argc, string argv[])
{
    if(argc > 1){

        printf("Usage: ./caesar key\n");
        return 1;
    }

    bool check = only_digits(argv[1]);

    if (!check)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    else
    {

        string input = get_string("plaintext: \n");
        int key = atoi(argv[1]);

        for (int i = 0; i < strlen(input); i++)
        {
            input[i] = (input[i] + key) % 26;

        }

        printf("ciphertext: %s\n", input);

    }

bool only_digits(string s)
{
    int number;

    for (int i = 0; i < strlen(arg); i++)
    {
        if (!isdigit(s[i]))
        {
            return false;
        }
    }
        return true;

}

}