#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int count_letters(string text, int length);
int count_words(string text, int length);
int count_sentences(string text, int length);

int main(void)
{
    string text_to_judge = get_string("Text: "); // Getting text from user
    //printf("%s\n", text_to_judge);

    int string_length = strlen(text_to_judge); //Calculating length of text

    int letters_number = count_letters(text_to_judge, string_length);   // Calling functions one by one
    int words_number = count_words(text_to_judge, string_length);
    int sentences_number = count_sentences(text_to_judge, string_length);

    //printf("%i letters.\n", letters_number);
    //printf("%i words.\n", words_number);
    //printf("%i sentences.\n", sentences_number);

    double av_letters = (double) letters_number / (double) words_number * 100; // average number of letters per 100 words
    //printf("Average letters per 100 words: %.2f\n", av_letters);

    double av_sentences = (double) sentences_number / (double) words_number * 100; // average number of sentences per 100 words
    //printf("Average sentences per 100 words: %.2f\n", av_sentences);

    double index = (0.0588 * av_letters) - (0.296 * av_sentences) - 15.8; //Calculating index number
    //printf("Index is: %.2f\n", index);

    if (index < 1)
    {
        printf("Before Grade 1\n");
        return 0;
    }

    if (index > 16)
    {
        printf("Grade 16+\n");
        return 0;
    }

    if (index >= 1 || index < 16)
    {
        printf("Grade %i\n", (int)round(index)); //Printing Grade number
        return 0;
    }

}

int count_letters(string text, int length) //Function for letter counting
{
    int a = 0;

    for (int i = 0; i < length; i++)
    {
        if (isalpha(text[i]))
        {
            a++;
        }
    }

    return a;
}

int count_words(string text, int length) //Function for words counting
{
    int a = 0;
    int w = 0;

    for (int i = 0; i <= length; i++)
    {
        if (isalpha(text[i]))
        {
            a++;
        }
        if (text[i] == 32 && a > 0)
        {
            w++;
            a = 0;
        }
        if (text[i] == 0 && a > 0)
        {
            w++;
        }
    }

    return w;
}

int count_sentences(string text, int length) //Functions for sentences counting
{
    int a = 0;
    int s = 0;
    for (int i = 0; i <= length; i++)
    {
        if (isalpha(text[i]))
        {
            a++;
        }
        if (a > 0)
        {
            if (text[i] == 46 || text[i] == 63 || text[i] == 33)
            {
                s++;
                a = 0;
            }
        }
    }

    return s;
}