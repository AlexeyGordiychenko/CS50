#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height = 0;
    //get height input
    do
    {
        height = get_int("Height: ");

    }
    while (height < 1 || height > 8);

    for (int i = 1; i <= height; i++)
    {
        //i*2 - for hashes
        //height - i - initial spaces
        for (int j = 1; j <= (i * 2) + (height - i); j++)
        {
            if (j > height - i)
            {
                //the middle of the hashes
                if (j == height + 1)
                {
                    printf("  ");
                }
                printf("#");
            }
            else
            {
                printf(" ");
            }
        }

        printf("\n");

    }
}