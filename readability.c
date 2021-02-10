#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

// Setting functions
int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

//Main stuff
int main(void)
{
    string text = get_string("Text: ");
    //Counting letters, words etc
    int l = count_letters(text);
    int w = count_words(text) + 1;
    int s = count_sentences(text);
    //Formula for the index
    float index = 0.0588 * (100 * (float) l / (float) w) - 0.296 * (100 * (float) s / (float) w) - 15.8;

    int grade = round(index);
    //Output
    if (grade < 1)
    {
        printf("Before Grade 1");
    }
    else if (grade >= 16)
    {
        printf("Grade 16+");
    }
    else
    {
        printf("Grade %i\n", grade);
        return 0;
    }
    printf("\n");
}

// Function for counting letters
int count_letters(string text)
{
    int letters = 0;

    for (int i = 0, len = strlen(text); i < len; i++)
    {
        if (isalpha(text[i]))
        {
            letters += 1;
        }
    }

    return letters;
}

// Function for counting words
int count_words(string text)
{
    int words = 0;

    for (int i = 0, len = strlen(text); i < len; i++)
    {
        if (isblank(text[i]))
        {
            words += 1;
        }
    }

    return words;
}

// Function for counting sentences
int count_sentences(string text)
{
    int sentences = 0;

    for (int i = 0, len = strlen(text); i < len; i++)
    {
        if (text[i] == '!' || text[i] == '.' || text[i] == '?')
        {
            sentences += 1;
        }
    }

    return sentences;
}
