#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height;
    do{
        // get height
        height = get_int("Height :\n");

        for(int i = 1; i <= height; i++){
            for(int j = 1; j <= i; j++){
                 for(int s = height-1; s > 0; s--){
                    printf(" ");
                 }
                 printf("#");
            }
            printf("\n");
        }
        printf("\n");

    }while(height > 1 && height <=8);

}