#include <cs50.h>
#include <stdio.h>

long input;
long copy1;
int length = 0;
int mult = 0;
int digit = 0;
int sum1 = 0;

int main(void)
{
    input = get_long("credit card number :");
    copy1 = input;


    // get length of card number
    while(input!=0)
    {
       input=input/10;
       length++;
    }


 //   printf("card array is : %d\n", a_number);

    for (int i = length; i >= 0; i-=2)
    {
        copy1 = copy1 / 10;
        digit = copy1 % 10;
        printf("digit is : %d\n",digit);

        mult = digit * 2;

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