#include <cs50.h>
#include <stdio.h>

long input;

int length = 0;
int mult = 0;
int digit = 0;
int sum1 = 0;
int sum2 = 0;

int main(void)
{
    input = get_long("credit card number :");
  printf("card  is : %ld\n", input);


    // get length of card number
    while(input!=0)
    {
       input=input/10;
       length++;
    }


    printf("length is : %d\n", length);

    for (int i = length-1; i >= 0; i-=2)
    {
        sum2 = sum2 + (input % 10);
        input = input / 10;

        digit = input % 10;
        input = input / 10;
        //printf("digit is : %d\n", digit);


        mult = digit * 2;

        printf("sum2 is : %d\n", sum2);

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