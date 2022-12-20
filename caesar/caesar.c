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

    if (check)

    if(isdigit(key))
    {
        string input = get_string("plaintext: \n");

        for (int i = 0; i < strlen(input); i++)
        {
            input[i] = (input[i] + key) % 26;
        }

        printf("ciphertext: %s\n", input);

    }

int only_digits(string arg)
{
    if(isdigit(arg))
    {
        return true;
    }
    else
    {
        return false;
    }
}

}