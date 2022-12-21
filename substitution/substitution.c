#include <cs50.h>
#include <stdio.h>

int main(int argc, string argv[])
{

    if (argc != 2)
    {
        if(argv[1])
        printf("Usage: ./substitution key\n");
        return 1;
    }

    printf("%c\n", argv[1][0]);

}