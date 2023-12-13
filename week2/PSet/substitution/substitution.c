#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int validation(string key_valid);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Key must contain 26 different alphabetical characters.\n");
        return 1;
    }
    string key = argv[1];
    if (validation(key) == 1) // calling function for validating key
    {
        printf("Key must contain 26 different alphabetical characters.\n");
        return 1;
    }

    string plain_text = get_string("plaintext: ");  // input plain text and store it

    int plain_text_length = strlen(plain_text);

    char *cipher_text = malloc(plain_text_length + 1);  // alocating memory for cipher text

    for (int m = 0; m < plain_text_length; m++)
    {
        if (isalpha(plain_text[m]) == 0)  // condition if not aplphabetical keep the same value
        {
            cipher_text[m] = plain_text[m];
        }

        if (islower(plain_text[m]) != 0)  // cipher alphabetical char if it is lowercase
        {
            int index1 = plain_text[m] - 97;
            cipher_text[m] = tolower(key[index1]);
        }

        if (isupper(plain_text[m]) != 0)  // cipher alphabetical char if it is uppercase
        {
            int index2 = plain_text[m] - 65;
            cipher_text[m] = toupper(key[index2]);
        }
    }

    printf("ciphertext: %s\n", cipher_text); // printing ciphered text
    free(cipher_text);
    return 0;
}

int validation(string key_valid) // function to validate key
{
    int key_length = strlen(key_valid);
    if (key_length != 26)
    {
        return 1;
    }

    for (int i = 0; i < key_length; i++) //loops to check if all alphabetical
    {
        if (isalpha(key_valid[i]) == 0)
        {
            return 1;
        }
    }

    for (int j = 0; j < key_length - 1; j++) // loop to check if all letters are different
    {
        for (int k = j + 1; k < key_length - 1; k++)
        {
            if (toupper(key_valid[j]) == toupper(key_valid[k]))
            {
                return 1;
            }
        }
    }
    return 0;
}