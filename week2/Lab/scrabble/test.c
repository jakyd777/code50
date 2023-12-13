#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    char c = get_char("Input: ");

    string word[] = get_string("String imput: ");
    int string_length = strlen(word);
    for (int i = 0; i < string_length; i++)
    {
        printf("%c\n", word[i]);
    }

    printf("Output: %c\n", c);
    printf("Output ASCI: %i\n", c);
    printf("%s\n", word);
}
