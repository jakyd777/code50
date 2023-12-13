#include <cs50.h>
#include <stdio.h>


int main(void)
{
    int length;
    int i = 0;
    do
    {
        length = get_int("Length (1 - 31): ");
    }
    while (length < 1 || length > 31);

    int array[length];
    array[0] = 1;
      printf("%i\n", array[i]);
    for (i = 1; i < length; i++)
    {
        array[i] = array[i - 1] * 2;
    }
    for (i = 1; i < length; i++)
    {
        printf("%i\n", array[i]);
    }
}