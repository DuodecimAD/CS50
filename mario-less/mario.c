#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int floors = get_int("Height : ");

    for (int i = 0; i < floors; i++)
    {
        for (int j = 0; j < i + 1; j++)
        {
            printf(" ", floors-j);
            printf("#");
        }
        printf("\n");
    }
}