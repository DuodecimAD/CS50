#include <stdio.h>
#include <cs50.h>

// Hello CS50

int main(void)
{
    string name = get_string("what is your name : \n");
    printf("hello, %s\n", name);
}