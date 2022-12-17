#include <cs50.h>
#include <stdio.h>

long input;
long copy;
int length = 0;
int mult = 0;
int digit1 = 0;
int digit2 = 0;
int sum1 = 0;
int sum2 = 0;
int total = 0;

int main(void)
{
    input = get_long("credit card number :");
    copy = input;
    // get length of card number
    while(copy!=0)
    {
       copy=copy/10;
       length++;
    }

    for (int i = 0; i <= length; i+=2)
    {
        digit2 = input % 10;
        input = input / 10;
        sum2 = sum2 + digit2;

        digit1 = input % 10;
        input = input / 10;
        mult = digit1 * 2;

        if(mult<10){
            sum1 = sum1 + mult;
        }else{
            sum1 = sum1 + (mult % 10);
            mult = mult / 10;
            sum1 = sum1 + mult;
        }

        total = sum1 + sum2;

    }
    printf("somme is : %d\n", total);

}