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


    printf("ciphertext: %c", argv[1][0]);

}