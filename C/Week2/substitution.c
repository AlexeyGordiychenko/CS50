#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

bool check_key(string key);
string encode_text(string plaintext, string key);

int main(int argc, string argv[])
{
    //check if a user had passed exactly one argument (the key)
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    string key = argv[1];

    //if the key is not valid, exit
    if (!check_key(key))
    {
        return 1;
    }

    //get the string to decode from a user
    string plaintext = get_string("plaintext: ");

    //print the encoded text
    printf("ciphertext: %s\n", encode_text(plaintext, key));

    return 0;

}

//return true if the key is valid, false otherwise
//also converts the key to lowercase
bool check_key(string key)
{
    //first check if the key is 26 char long
    if (strlen(key) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return false;
    }

    //then check if chars are alphabetic and the letters don't repeat
    for (int i = 0; i < 26; i++)
    {
        if (!isalpha(key[i]))
        {
            printf("Key must only contain alphabetic characters.\n");
            return false;
        }

        for (int j = i + 1; j < 26; j++)
        {
            if (tolower(key[i]) == tolower(key[j]))
            {
                printf("Key must not contain repeated characters.\n");
                return false;
            }
        }

    }

    return true;
}

string encode_text(string plaintext, string key)
{
    int l = strlen(plaintext);

    //encode the text, all the alphabectic chars in the text
    //get its ascii value as an index for the key array
    for (int i = 0; i < l; i++)
    {
        if (isalpha(plaintext[i]))
        {
            bool isupper = isupper(plaintext[i]);
            int index = (isupper) ? (int)plaintext[i] - 65 : (int)plaintext[i] - 97;
            plaintext[i] = (isupper) ? toupper(key[index]) : tolower(key[index]);
        }
    }

    return plaintext;
}
