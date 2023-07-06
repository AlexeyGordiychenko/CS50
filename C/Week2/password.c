// Check that a password has at least one lowercase letter, uppercase letter, number and symbol
// Practice iterating through a string
// Practice using the ctype library

#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

bool valid(string password);

int main(void)
{
    string password = get_string("Enter your password: ");
    if (valid(password))
    {
        printf("Your password is valid!\n");
    }
    else
    {
        printf("Your password needs at least one uppercase letter, lowercase letter, number and symbol\n");
    }
}

// TODO: Complete the Boolean function below
bool valid(string password)
{
    int l = strlen(password);
    bool isUpperLetter = false;
    bool isLowerLetter = false;
    bool isDigit = false;
    bool isSymbol = false;

    //If the password contains at least one
    //upper case letter
    //one lower case letter
    //a number
    //a symbol (meaning a printable character that’s not a letter or number, such as ‘!’, ‘$’ and ‘#’
    //the function should return true. If not it should return false
    for (int i = 0; i < l; i++)
    {
        if (isalpha(password[i]))
        {
            if (islower(password[i]))
            {
                isLowerLetter = true;
            }
            else
            {
                isUpperLetter = true;
            }
        }
        else if (isdigit(password[i]))
        {
            isDigit = true;
        }
        else
        {
            isSymbol = true;
        }

        if (isUpperLetter && isLowerLetter && isDigit && isSymbol)
        {
            return true;
        }
    }

    return false;
}
