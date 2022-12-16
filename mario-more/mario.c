#include <cs50.h>
#include <stdio.h>


int main(void)
{
    int height;

    do{
        // get height
        height = get_int("Height :\n");

        // check if between 1 and 8
        while(height < 1 || height > 8){
            height = get_int("Height :\n");
        }

        // go mario, jump above this and go deliver Peach
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