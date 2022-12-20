#include <cs50.h>
#include <stdio.h>
#include <string.h>

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
    return strlen(text);


}
