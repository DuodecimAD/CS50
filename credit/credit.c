#include <cs50.h>
#include <stdio.h>

int input;
int length;
int mult = 0;
int digit = 0;
int sum1 = 0;

int main(void)
{
    input = get_int("credit card number :");
    length = sizeof(input);

    while(n!=0)
   {
       n=n/10;
       count++;
   } 

    printf("%d\n", length);

    for (int i = length-1; i >= 0; i-=2)
    {

        mult = i * 2;

        if(mult<10){
            sum1 = sum1 + mult;
        }else{
              sum1 = sum1 + mult % 10;
              mult = mult / 10;
              sum1 = sum1 + mult % 10;
        }


    }
    printf("%d",sum1);

}