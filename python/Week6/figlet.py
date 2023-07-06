import argparse
import sys
from cs50 import get_string
from pyfiglet import Figlet
import random

def main():

    parser = argparse.ArgumentParser()
    parser.add_argument('-f', '--font', type=str)
    args = parser.parse_args()

    figlet = Figlet()
    fonts = figlet.getFonts()

    font = args.font
    if font:
        if font not in fonts:
            sys.exit("No such font")
    else:
        font = random.choice(fonts)

    figlet.setFont(font=font)
    input = get_string("Input: ")
    print("Output:")
    print(figlet.renderText(input))

if __name__ == "__main__":
    main()