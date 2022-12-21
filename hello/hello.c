#include <stdio.h>
#include <cs50.h>
#include <ctype.h>

// Hello CS50

int main(void)
{
    char name[] = "antony";
    name = toupper(name);


    printf("%s\n", name);
}