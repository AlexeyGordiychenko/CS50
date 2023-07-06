#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <math.h>

int main(void)
{
    //get a text from a user
    string text = get_string("Text: ");

    //variables for all the counting
    int letters = 0;
    int words = 1;
    int sentences = 0;
    int i = 0;

    //every alphabetical char is a letter
    //every space is a word
    //every . ! ? is a sentence
    while (text[i] != '\0')
    {
        if isalpha(text[i])
        {
            letters++;
        }
        else if (isspace(text[i]))
        {
            words++;
        }
        else if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentences++;
        }
        i++;
    }

    //calculate the index
    //index = 0.0588 * L - 0.296 * S - 15.8
    //  L is the average number of letters per 100 words
    //  S is the average number of sentences per 100 words
    int index = round(0.0588 * letters / words * 100 - 0.296 * sentences / words * 100 - 15.8);
    //cap at 16
    index = (index > 16) ? 16 : index;

    printf("%sGrade %i%s\n", (index < 1) ? "Before " : "", (index < 1) ? 1 : index, (index == 16) ? "+" : "");

}

