#include <cs50.h>
#include <stdio.h>

// I picked mario-more not because i feel more comfortable but because i like challenges
// Never did any C by the way, i should go watch the 3h video of week 1 now that i'm done
// It was fun, i wish it was an accomplishement but it's probably a basic exercise ...

int height;

int main(void)
{
    // get height
    height = get_int("Height :");

    // check if not between 1 and 8
    while (height < 1 || height > 8)
    {
        height = get_int("Height :");
    }

    // go mario, go, jump above this and go deliver Peach
    for (int i = 1; i <= height; i++)
    {
        for (int s = height - i; s > 0; s--)
        {
            printf(" ");
        }
        for (int j = 1; j <= i; j++)
        {
            printf("#");
        }
        printf("  ");
        for (int e = 1; e <= i; e++)
        {
            printf("#");
        }
        printf("\n");
    }
}