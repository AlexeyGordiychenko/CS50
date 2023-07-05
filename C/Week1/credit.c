#include <cs50.h>
#include <stdio.h>

int main(void)
{

    long CC_number = get_long("Enter a credit card number:\n");

    //less than 13 digits, more than 16
    if (CC_number < 1000000000000 || CC_number >= 10000000000000000)
    {
        printf("INVALID\n");
        return 0;
    }

    int multiply = 1;
    int total = 0;
    int length = 0;
    int first_two = 0;
    //check every digit, add to total and increase length
    //multiply switching between 1 and 2 with every digit
    //after only two digits left remember it and then check later
    while (CC_number > 0)
    {
        int digit = CC_number % 10;
        length++;

        int tmp = digit * multiply;
        if (tmp > 9)
        {
            total += tmp % 10 + tmp / 10;
        }
        else
        {
            total += tmp;
        }

        multiply = (multiply == 1) ? 2 : 1;

        CC_number = CC_number / 10;

        if (CC_number < 100 && CC_number > 9)
        {
            first_two = CC_number;
        }
    }

    //AMEX - 15 digits, 34, 37
    //MasterCard - 16 digits, 51, 52, 53, 54, or 55
    //Visa - 13 or 16 digits, 4

    if (length == 14 || total % 10 != 0)
    {
        printf("INVALID\n");
        return 0;
    }

    if (length == 15 && (first_two == 34 || first_two == 37))
    {
        printf("AMEX\n");
    }
    else if (length == 16 && first_two >= 51 && first_two <= 55)
    {
        printf("MASTERCARD\n");
    }
    else if ((length == 13 || length == 16) && first_two >= 40 && first_two <= 49)
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }

}