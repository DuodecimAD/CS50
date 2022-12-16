#include <cs50.h>
#include <stdio.h>


int main(void)
{
    int height;

    // get height
    height = get_int("Height :\n");

    do{

        if(height < 1 || height > 8){
            height = get_int("Height :\n");
        }

        for(int i = 1; i <= height; i++){
            for(int s = height-i; s > 0; s--){
                printf(" ");
            }
            for(int j = 1; j <= i; j++){
                printf("#");
            }
            printf(" ");
            for(int e = 1; e <= i; e++){
                printf("#");
            }
            printf("\n");
        }
        printf("\n");

    }while(height >= 1 && height <= 8);

}