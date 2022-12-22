#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int toascii(int c);

int main(int argc, string argv[])
{

    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    else if (strlen(argv[1]) != 26)
    {
        for(int y = 0; y<strlen(argv[1]); y++)
        {
            if(!isalpha(argv[1][y])){
                printf("Key must contain only alphabetical characters.\n");
                return 1;
            }

        }
        printf("Key must contain 26 characters.\n");
        return 1;
    }

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

    int sum = 0;

    for(int m = 0; m < 26; m++){
        sum += duplicate[m];
    }

    if(sum > 26){
        printf("You have duplicate letters.\n");
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



    cipher[input_length] = '\0';

    printf("ciphertext: %s\n", cipher);


}