#include <cs50.h>
#include <stdio.h>

int number;
int mult = 0;
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
            for (j = mult; j <= mult.length; j--){
                mult % 10;
            }
        }


    }
    printf(sum1);

}