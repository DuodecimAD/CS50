#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int floors = get_int("Height : ");

    while (height < 1 || height > 8)
    {
        height = get_int("Height :");
    }

    for (int i = 0; i < floors; i++)
    {
        for (int b = floors-i; b > 1; b--)
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