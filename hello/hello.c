#include <stdio.h>
#include <cs50.h>
#include <ctype.h>

// Hello CS50

int main(void)
{
    char name[] = "antony";

    for (int i = 0; i<6; i++)
    {
    name[i] = toupper(name[i]);
    }


    printf("%s\n", name);
}