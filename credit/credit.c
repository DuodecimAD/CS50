#include <cs50.h>
#include <stdio.h>

int number;
int mult = 0;
int digit = 0;
int sum1 = 0;

int main(void)
{
    number = get_int("credit card number :");

    for (int i = number.length-1; i >= 0; i-=2)
    {

        mult = i * 2;

        if(mult<10){
            sum1 = sum + mult;
        }else{
              sum1 = sum1 + mult % 10;
              mult = mult / 10;
              sum1 = sum1 + mult % 10;
        }


    }
    printf(sum1);

}