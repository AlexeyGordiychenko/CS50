from cs50 import get_string


def main():
    input = get_string("Text: ")
    letters = 0
    words = 1
    sentences = 0

    for i in input:
        if i.isalpha():
            letters += 1
        elif i == ' ':
            words += 1
        elif i == '.' or i == '!' or i == '?':
            sentences += 1

    index = round(0.0588 * letters / words * 100 - 0.296 * sentences / words * 100 - 15.8)
    # cap at 16
    prefix = ""
    postfix = ""
    if index > 16:
        index = 16
        postfix = "+"

    if index < 1:
        index = 1
        prefix = "Before "

    print(f"{prefix}Grade {index}{postfix}")


if __name__ == '__main__':
    main()