#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>


int count_letters(string text);
int count_words(string text);
int count_sentences(string text);


int main(void)
{
    string input = get_string("Text: ");
    printf("Text: %s\n", input);

    int letters = count_letters(input);
    // printf("letters : %i\n", letters);

    int words = count_words(input);
    // printf("words : %i\n", words);

    int sentences = count_sentences(input);
    // printf("sentences : %i\n", sentences);

    int index = round((0.0588 * (((float) letters / (float) words) * 100)) - (0.296 * (((float) sentences /
                      (float) words) * 100)) - 15.8);

    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }


}

int count_letters(string text)
{
    int j = 0;

    for (int i = 0; i < strlen(text); i++)
    {
        if (isalpha(text[i]))
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
        if (isspace(text[i]))
        {
            j++;
        }

    }
    return j + 1;
}

int count_sentences(string text)
{
    int j = 0;

    for (int i = 0; i < strlen(text); i++)
    {
        if (text[i] == 33 || text[i] == 46 || text[i] == 63)
        {
            j++;
        }

    }
    return j;
}
