#include <cs50.h>
#include <stdio.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    if(isdigit(argv))
    {
        int key = argv;
    }
    

    string input = get_string("plaintext: \n");

    for (int i = 0; i < strlen(input); i++)
    {
        input[i] = (input[i] + key) % 26;
    }

    printf("ciphertext: %s\n", input);
}