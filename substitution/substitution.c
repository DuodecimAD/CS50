#include <cs50.h>
#include <stdio.h>

int main(int argc, string argv[])
{

    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }



    string input = get_string("plaintext: ");

  //  printf("plaintext: %c", argv[1][0]);


        int key = atoi(argv[1]);

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


}