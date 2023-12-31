#include <cs50.h>
#include <stdio.h>

long input, copy, card;
int length = 0, mult = 0, digit1 = 0, digit2 = 0, sum1 = 0, sum2 = 0, checksum = 0;

int main(void)
{
    input = get_long("credit card number :");
    copy = input;
    card = input;

    // get length of card number
    while (copy != 0)
    {
        copy = copy / 10;
        length++;
    }

    // get which card it is
    for (int z = 0; z < length - 2; z++)
    {
        card = card / 10;
    }


    // calculate checksum
    for (int i = 0; i <= length; i += 2)
    {
        digit2 = input % 10;
        input = input / 10;
        sum2 = sum2 + digit2;

        digit1 = input % 10;
        input = input / 10;
        mult = digit1 * 2;

        if (mult < 10)
        {
            sum1 = sum1 + mult;
        }
        else
        {
            sum1 = sum1 + (mult % 10);
            mult = mult / 10;
            sum1 = sum1 + mult;
        }
        checksum = sum1 + sum2;
    }

    // final check first digits card, card length and checksum
    if (checksum % 10 == 0)
    {
        if ((card == 34 || card == 37) && length == 15)
        {
            printf("AMEX\n");
        }
        else if ((card > 50 && card < 56) && length == 16)
        {
            printf("MASTERCARD\n");
        }
        else
        {
            card =  card / 10;
            if (card == 4 && (length == 13 || length == 16))
            {
                printf("VISA\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
    }
    else
    {
        printf("INVALID\n");
    }

}