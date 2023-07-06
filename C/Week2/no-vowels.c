// Write a function to replace vowels with numbers
// Get practice with strings
// Get practice with command line
// Get practice with switch

#include <cs50.h>
#include <string.h>
#include <stdio.h>

string replace(string s);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./no-vowels word\n");
        return 1;
    }

    printf("%s\n", replace(argv[1]));
}

string replace(string s)
{
    //a becomes 6, e becomes 3, i becomes 1, o becomes 0
    int l = strlen(s);
    for (int i = 0; i < l; i++)
    {
        switch (s[i])
        {
            case 'a':
                s[i] = '6';
                break;
            case 'e':
                s[i] = '3';
                break;
            case 'i':
                s[i] = '1';
                break;
            case 'o':
                s[i] = '0';
                break;
        }
    }
    return s;
}