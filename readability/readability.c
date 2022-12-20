#include <cs50.h>
#include <stdio.h>
#include <string.h>


int main(void)
{
    string text = get_string("Text: ");
    printf("Text: %s\n", text);
    int letters = strlen(text);
    printf("%i\n", letters);
}