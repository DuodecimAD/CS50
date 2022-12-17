#include <cs50.h>
#include <stdio.h>

int number;
int sum1 = 0;

int main(void)
{
    number = get_int("credit card number :");

    for (int i = number.length-1; i >= 0; i-=2)
    {
        if(i<10){
            sum1 = sum + i;
        }else{
            i
        }

        printf(sum1);
    }
}