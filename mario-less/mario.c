#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int floors = 0;

    while (floors < 1 || floors > 8)
    {
        floors = get_int("Height : ");
    }

    for (int i = 0; i < floors; i++)
    {
        for (int b = floors - i; b > 1; b--)
        {
            printf(" ");
        }
        for (int j = 0; j < i + 1; j++)
        {
            printf("#");
        }
        printf("\n");
    }
}