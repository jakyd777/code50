#include <cs50.h>
#include <stdio.h>

bool prime(int number);

int main(void)
{
    int min;
    do
    {
        min = get_int("Minimum: ");     // Setting minimum number
    }
    while (min < 1);                    // Checking if min is greatter than 0

    int max;
    do
    {
        max = get_int("Maximum: ");     // Setting maximum number
    }
    while (min >= max);                 // Checking if min is greatter or equal to max

    for (int i = min; i <= max; i++)    // Loop for printing prime numbers
    {
        if (prime(i))                   // calling Prime function
        {
            printf("%i\n", i);
        }
    }
}

bool prime(int number)                  // Prime function
{
    int j = 2;
    int temp = 0;
    while (j <= number / 2)             // do from 2 to whatever input number /2
    {
        if (number % j == 0)            // checking if the number is divisible by number from 2 to number/2
        {
            temp++;                     // setting temps +1

            break;
        }
        j++;                            // setting j +1
    }

    if (temp == 0 && number != 1)       // If number of temps remain 0 and number is NOT 1 then function will retun true
    {
        return true;
    }
    else                                    
    {
        return false;
    }
}
