# TODO
import re
import sys


def validate(ccn):
    ccn_backwards = ccn[::-1]
    # Multiply every other digit by 2, starting with the number’s second-to-last digit
    ccn_mult = [int(i)*2 for i in ccn_backwards[1::2] if i != '0']
    # then add those products’ digits together
    sum1 = sum([sum(map(int, str(n))) for n in ccn_mult])
    # sum of the digits that weren’t multiplied by 2
    sum2 = sum(map(int, ccn_backwards[::2]))

    return (sum1 + sum2) % 10 == 0


def main():

    ccn = input('Number: ')

    if len(ccn) not in [13, 15, 16]:
        print('INVALID')
        sys.exit(1)

    # regexps for every type of a card
    cards = {
        # AMEX - 15 digits, 34, 37
        'AMEX': '(^34|^37)\d{13}$',
        # MasterCard - 16 digits, 51, 52, 53, 54, or 55
        'MASTERCARD': '^5[1-5]\d{14}$',
        # Visa - 13 or 16 digits, 4
        'VISA': '^4(\d{12}|\d{15})$'
    }

    for card, regexp in cards.items():
        if re.match(regexp, ccn) and validate(ccn):
            print(card)
            sys.exit(0)

    print('INVALID')
    sys.exit(1)


if __name__ == '__main__':
    main()