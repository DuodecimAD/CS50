#include <stdio.h>
#include <cs50.h>
#include <ctype.h>

// Hello CS50

int main(void)
{
    string name = "antony";
    char final[6];

    for(int i = 0; i<6; i++)
    {
       final[i] = toupper(name[i]);
    }

    printf("%s\n", final);
}