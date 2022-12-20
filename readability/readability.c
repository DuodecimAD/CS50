#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>



int count_letters(string text);
int count_words(string text);


int main(void)
{
    string input = get_string("Text: ");
    printf("Text: %s\n", input);

    int letters = count_letters(input);
    printf("letters : %i\n", letters);

    int words = count_words(input);
    printf("words : %i\n", letters);


}

int count_letters(string text)
{
    int j = 0;

    for (int i = 0; i < strlen(text); i++)
    {
        if(isalpha(text[i]))
        {
            j++;
        }

    }
    return j;
}

int count_words(string text)
{
    int j = 0;

    for (int i = 0; i < strlen(text); i++)
    {
        if(isspace(text[i]))
        {
            j++;
        }

    }
    return j;
}
