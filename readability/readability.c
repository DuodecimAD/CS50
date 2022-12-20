#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

string input;

int count_letters(string text);


int main(void)
{
    input = get_string("Text: ");
    printf("Text: %s\n", input);

    int letters = count_letters(input);
    printf("letters : %i\n", letters);

}

int count_letters(string text)
{
    int j = 0;

    for (int i = 0; i < strlen(text); i++)
    {
        if(!isspace(text[i]))
        {
            j++;
        }

    }
    return strlen(text) - j;
}
