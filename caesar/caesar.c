#include <cs50.h>
#include <stdio.h>
#include <ctype.h>

int only_digits(int check);

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
        return 0;
    }

    if(isdigit(key))
    {
        string input = get_string("plaintext: \n");

        for (int i = 0; i < strlen(input); i++)
        {
            input[i] = (input[i] + key) % 26;
        }

        printf("ciphertext: %s\n", input);

    }

bool only_digits(string arg)
{
    int number;

    for (int i = 0; i < strlen(arg); i++)
    {
        number = isdigit(arg[i]);
    }

    if()
    {
        return true;
    }
    else
    {
        return false;
    }
}

}