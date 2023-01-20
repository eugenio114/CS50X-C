#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

//functions
float count_letters(string text);
float count_words(string text);
float count_sentences(string text);

//variables
float l;
float w;
float index;

int main(void)
{
    //Get string to ask for a text in prompt
    string text = get_string("Text: ");

    //Avg numbers of letters in 100 words.
    l = (count_letters(text) / count_words(text)) * 100;

    //Avg numbers of sentences in 100 words
    w = (count_sentences(text) / count_words(text)) * 100;

    //Coleman-Liau index formula
    index = (0.0588 * l - 0.296 * w - 15.8);

    // If statement that prints the Grade level depending on the value of index (rounded)
    if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %d\n", (int) round(index));
    }
}

////function that counts the number of letters in text bu using ASCII codes
float count_letters(string text)
{
    int letter_count = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if ((text[i] > 64 && text[i] < 91) || (text[i] > 96 && text[i] < 123))
        {
            letter_count += 1;
        }
        else
        {
            letter_count += 0;
        }
    }
    return letter_count;
}

////function that counts the number of words in text by counting all spaces +1
float count_words(string text)
{
    int word_count = 1;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if ((text[i] == ' ') || text[i] == '\0')
        {
            word_count++;
        }
        else
        {
            word_count += 0;
        }
    }
    return word_count;
}

//function that counts the number of sentences in text using punctuation (. || ! || ?)
float count_sentences(string text)
{
    int sentence_count = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if ((text[i] == '.') || (text[i] == '!') || (text[i] == '?'))
        {
            sentence_count++;
        }
        else
        {
            sentence_count += 0;
        }
    }
    return sentence_count;
}