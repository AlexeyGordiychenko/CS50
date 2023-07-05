#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int start = 0;
    int end = 0;

    // TODO: Prompt for start size
    while (start < 9)
    {
        start = get_int("What is the start size of population?\n");
    }

    // TODO: Prompt for end size
    while (end < start)
    {
        end = get_int("What is the end size of population?\n");
    }

    // TODO: Calculate number of years until we reach threshold
    int total = start;
    int years = 0;
    while (total < end)
    {
        total += (total / 3) - (total / 4);
        years += 1;
    }

    // TODO: Print number of years
    printf("Years: %i\n", years);
}
