#include <cs50.h>
#include <stdio.h>
#include <string.h>

const int BITS_IN_BYTE = 8;

void print_bulb(int bit);

int main(void)
{
    string input_string = get_string("Message: ");      // Get input string
    int input_string_length = strlen(input_string);     // Set input string length

    for (int i = 0; i < input_string_length; i++)       // Initializing loop according to string length
    {
        int bulbs[BITS_IN_BYTE];                        // Initialiying array of 8 bits
        int a = input_string[i];                        // changing char to integer

        for (int j = 0; j < 8; j++)                     // transformation integer to binary
        {
            if (a % 2 != 0)
            {
                bulbs[j] = 1;
            }

            if (a % 2 == 0)
            {
                bulbs[j] = 0;
            }

            a = a / 2;
        }

        for (int k = 7; k >= 0; k--)                    // Loop for printing each of 8 bulbs
        {
            print_bulb(bulbs[k]);
        }

        printf("\n");
    }

}

void print_bulb(int bit)
{
    if (bit == 0)
    {
        // Dark emoji
        printf("\U000026AB");
    }
    else if (bit == 1)
    {
        // Light emoji
        printf("\U0001F7E1");
    }
}
