#include <cs50.h>
#include <stdio.h>





int main(void)
{
    // TODO: Prompt for start size
    int startSize;
    do
    {
        startSize = get_int("Start size: ");
    }
    while (startSize < 9);

    // TODO: Prompt for end size
    int endSize;
    do
    {
        endSize = get_int("End size: ");
    }
    while (endSize < startSize);

    // TODO: Calculate number of years until we reach threshold
    int actSize = startSize;
    int n = 0;
    if (startSize == endSize) {
        printf("You are at the beginning. ");
    }
    else
    do
    {
        actSize = actSize + (actSize / 3) - (actSize / 4);
        n++;
    }
    while (actSize < endSize);

    // TODO: Print number of years
    printf("Years: %i\n ", n);
}
