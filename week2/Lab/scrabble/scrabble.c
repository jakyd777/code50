#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // TODO: Print the winner
    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }

    if (score1 < score2)
    {
        printf("Player 2 wins!\n");
    }

    if (score1 == score2)
    {
        printf("Tie!\n");
    }
}

int compute_score(string word)
{
    // TODO: Compute and return score for string
    int word_score = 0;

    for (int i = 0; i < strlen(word); i++) //loop for each char of string
    {
        if (word[i] > 64 && word[i] < 91) // condition if char is uppercase
        {
            word_score = word_score + POINTS[word[i] - 65]; // will add points to score
        }

        if (word[i] > 96 && word[i] < 123) // condition if char lowercase
        {
            word_score = word_score + POINTS[word[i] - 97]; // will add points to score
        }

        else
        {
            word_score = word_score + 0; // in case other char then upper or lower case will add 0
        }
    }

    return word_score;

}
