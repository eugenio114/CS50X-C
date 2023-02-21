#include <cs50.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

// each of our text files contains 1000 words
#define LISTSIZE 1000

// values for colors and score (EXACT == right letter, right place; CLOSE == right letter, wrong place; WRONG == wrong letter)
#define EXACT 2
#define CLOSE 1
#define WRONG 0

// ANSI color codes for boxed in letters
#define GREEN   "\e[38;2;255;255;255;1m\e[48;2;106;170;100;1m"
#define YELLOW  "\e[38;2;255;255;255;1m\e[48;2;201;180;88;1m"
#define RED     "\e[38;2;255;255;255;1m\e[48;2;220;20;60;1m"
#define RESET   "\e[0;39m"

// user-defined function prototypes
string get_guess(int wordsize);
int check_word(string guess, int wordsize, int status[], string choice);
void print_word(string guess, int wordsize, int status[]);



int main(int argc, string argv[])
{
    int wordsize = 0;
    // ensure proper usage
    // ensure argv[1] is either 5, 6, 7, or 8 and store that value in wordsize instead
    if ((argv[1] == NULL) || (argv[2] != NULL))
    {
        printf("Usage: ./wordle wordsize\n");
    }
    else if ((argv[1][0] == '5') || (argv[1][0] == '6') || (argv[1][0] == '7') || (argv[1][0] == '8'))
    {
        wordsize = (int) argv[1][0] - 48;
        printf("your word size is %i\n", wordsize);
    }
    else
    {
        printf("Error: wordsize must be either 5, 6, 7, or 8\n");
    }
    // open correct file, each file has exactly LISTSIZE words
    char wl_filename[6];
    sprintf(wl_filename, "%i.txt", wordsize);
    FILE *wordlist = fopen(wl_filename, "r");

    if (wordlist == NULL)
    {
        printf("Error opening file %s.\n", wl_filename);
        return 1;
    }
    // load word file into an array of size LISTSIZE
    char options[LISTSIZE][wordsize + 1];

    for (int i = 0; i < LISTSIZE; i++)
    {
        fscanf(wordlist, "%s", options[i]);
    }

    // pseudorandomly select a word for this game
    srand(time(NULL));
    string choice = options[rand() % LISTSIZE];

    // allow one more guess than the length of the word
    int guesses = wordsize + 1;
    bool won = false;

    // print greeting, using ANSI color codes to demonstrate
    printf(GREEN"This is WORDLE50"RESET"\n");
    printf("You have %i tries to guess the %i-letter word I'm thinking of\n", guesses, wordsize);

    // main game loop, one iteration for each guess
    for (int i = 0; i < guesses; i++)
    {
        // obtain user's guess
        string guess = get_guess(wordsize);

        // array to hold guess status, initially set to zero
        int status[wordsize];

        // set all elements of status array initially to 0, aka WRONG
        for (int j = 0; j < wordsize; j++)
        {
            status[j] = 0;
        }


        // Calculate score for the guess
        int score = check_word(guess, wordsize, status, choice);

        printf("Guess %i: ", i + 1);
        print_word(guess, wordsize, status);

        // if they guessed it exactly right, set terminate loop
        if (score == EXACT * wordsize)
        {
            won = true;
            printf("You won!\n");
            break;
        }
    }
    printf("%s\n", choice);
}

string get_guess(int wordsize)
{

    string guess = "";
    // ensure users actually provide a guess that is the correct length
    do
    {
        guess = get_string("Input a %i-letter word: ", wordsize);
    }
    while (strlen(guess) != wordsize);
    return guess;
}

int check_word(string guess, int wordsize, int status[], string choice)
{
    // iterate over each letter of the guess
    // iterate over each letter of the choice
    // compare the current guess letter to the current choice letter
    // if they're the same position in the word, score EXACT points (green) and break so you don't compare that letter further
    // if it's in the word, but not the right spot, score CLOSE point (yellow)
    // keep track of the total score by adding each individual letter's score from above
    int score = 0;

    for (int i = 0, n = strlen(guess); i < n; i++)
    {
        for (int j = 0, m = strlen(choice); j < m; j++)
        {
            if ((guess[i] == choice[j]) && i != j)
            {
                status[i] = CLOSE;
                score += status[i];
            }
            else if ((guess[i] == choice[j]) && i == j)
            {
                status[i] = EXACT;
                score += status[i];
                break;
            }
        }
    }
    return score;


}

void print_word(string guess, int wordsize, int status[])
{
    //for loop that prints each letter of guess color-coded based on the values stored in status array
    for (int i = 0; i <= wordsize; i++)
    {
        if (status[i] == 2)
        {
            printf(GREEN"%c", guess[i]);
        }
        else if (status[i] == 1)
        {
            printf(YELLOW"%c", guess[i]);
        }
        else
        {
            printf(RED"%c", guess[i]);
        }
    }
    printf(RESET"\n");
    return;
}
