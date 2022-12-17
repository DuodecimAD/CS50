#include <cs50.h>
#include <stdio.h>

long input;
int length = 0;
int mult = 0;
int digit = 0;
int sum1 = 0;

int main(void)
{
    input = get_long("credit card number :");


    // get length of card number
    while(input!=0)
    {
       input=input/10;
       length++;
    }
    long a_number[length];
    a_number[] = input;

    printf("card array is : %d\n", a_number[]);

    for (int i = length-1; i >= 0; i-=2)
    {

        mult = a_number[i] * 2;

        if(mult<10){
            sum1 = sum1 + mult;
        }else{
              sum1 = sum1 + (mult % 10);
              mult = mult / 10;
              sum1 = sum1 + mult;
        }


    }
    printf("somme is : %d\n",sum1);

}