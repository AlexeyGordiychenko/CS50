# [Week 6](../../README.md)

## Lab: [*World Cup*](world-cup/tournament.py)

Complete the implementation of `tournament.py`, such that it simulates a number of tournaments and outputs each team’s probability of winning.

First, in `main`, read the team data from the CSV file into your program’s memory, and add each team to the list `teams`.
- The file to use will be provided as a command-line argument. You can access the name of the file, then, with `sys.argv[1]`.
- Recall that you can open a file with `open(filename)`, where `filename` is a variable storing the name of the file.
- Once you have a file `f`, you can use `csv.DictReader(f)` to give you a “reader”: an object in Python that you can loop over to read the file one row at a time, treating each row as a dictionary.
- By default, all values read from the file will be strings. So be sure to first convert the team’s `rating` to an `int` (you can use the `int` function in Python to do this).
- Ultimately, append each team’s dictionary to `teams`. The function call `teams.append(x)` will append `x` to the list `teams`.
- Recall that each team should be a dictionary with a `team` name and a `rating`. 
  
Next, implement the `simulate_tournament` function. This function should accept as input a list of teams and should repeatedly simulate rounds until you’re left with one team. The function should the return the name of that team.
- You can call the `simulate_round` function, which simulates a single round, accepting a list of teams as input and returning a list of all of the winners. 
- Recall that if `x` is a list, you can use `len(x)` to determine the length of the list. 
- You should not assume the number of teams in the tournament, but you may assume it will be a power of 2.

Finally, back in the `main` function, run `N` tournament simulations, and keep track of how many times each team wins in the `counts` dictionary.
- For example, if Uruguay won 2 tournaments and Portugal won 3 tournaments, then your `counts` dictionary should be `{"Uruguay": 2, "Portugal": 3}`.
- You should use your `simulate_tournament` to simulate each tournament and determine the winner.
- Recall that if `counts` is a dictionary, then syntax like `counts[team_name] = x` will associate the key stored in `team_name` with the value stored in `x`.
- You can use the `in` keyword in Python to check if a dictionary has a particular key already. For example, `if "Portugal" in counts:` will check to see if `"Portugal"` already has an existing value in the `counts` dictionary.

Your program should behave per the examples below. Since simulations have randomness within each, your output will likely not perfectly match the examples below.

```
$ python tournament.py 2018m.csv
Belgium: 20.9% chance of winning
Brazil: 20.3% chance of winning
Portugal: 14.5% chance of winning
Spain: 13.6% chance of winning
Switzerland: 10.5% chance of winning
Argentina: 6.5% chance of winning
England: 3.7% chance of winning
France: 3.3% chance of winning
Denmark: 2.2% chance of winning
Croatia: 2.0% chance of winning
Colombia: 1.8% chance of winning
Sweden: 0.5% chance of winning
Uruguay: 0.1% chance of winning
Mexico: 0.1% chance of winning
```
```
$ python tournament.py 2019w.csv
Germany: 17.1% chance of winning
United States: 14.8% chance of winning
England: 14.0% chance of winning
France: 9.2% chance of winning
Canada: 8.5% chance of winning
Japan: 7.1% chance of winning
Australia: 6.8% chance of winning
Netherlands: 5.4% chance of winning
Sweden: 3.9% chance of winning
Italy: 3.0% chance of winning
Norway: 2.9% chance of winning
Brazil: 2.9% chance of winning
Spain: 2.2% chance of winning
China PR: 2.1% chance of winning
Nigeria: 0.1% chance of winning
```

## Problem Set

---
### [*Hello*](hello.py)

Write, in a file called `hello.py`, a program that prompts a user for their name, and then prints `hello, so-and-so`, where `so-and-so` is their provided name, exactly as you did in [Problem Set 1](../Week1/hello.c), except that your program this time should be written in Python.

Your program should behave per the example below.

```
$ python hello.py
What is your name?
Emma
hello, Emma
```

---
### [*Mario*](mario.py)

Task:

  - Write, in a file called `mario.py`, a program that recreates these half-pyramids using hashes (`#`) for blocks, exactly as you did in <a href="../../../1/">Problem Set 1</a>, except that your program this time should be written in Python.
  - To make things more interesting, first prompt the user with `get_int` for the half-pyramid’s height, a positive integer between `1` and `8`, inclusive. (The height of the half-pyramids pictured above happens to be `4`, the width of each half-pyramid `4`, with a gap of size `2` separating them).
  - If the user fails to provide a positive integer no greater than `8`, you should re-prompt for the same again.
  - Then, generate (with the help of `print` and one or more loops) the desired half-pyramids.
  - Take care to align the bottom-left corner of your pyramid with the left-hand edge of your terminal window, and ensure that there are two spaces between the two pyramids, and that there are no additional spaces after the last set of hashes on each row.


Your program should behave per the example below.

```$ python mario.py
Height: 4
   #  #
  ##  ##
 ###  ###
####  ####
```

---
### [*Credit*](credit.py)

Task:

  - In `credit.py`, write a program that prompts the user for a credit card number and then reports (via `print`) whether it is a valid American Express, MasterCard, or Visa card number, exactly as you did in <a href="../../1/">Problem Set 1</a>, except that your program this time should be written in Python.
  - So that we can automate some tests of your code, we ask that your program’s last line of output be `AMEX\n` or `MASTERCARD\n` or `VISA\n` or `INVALID\n`, nothing more, nothing less.
  - For simplicity, you may assume that the user’s input will be entirely numeric (i.e., devoid of hyphens, as might be printed on an actual card).
  - Best to use `get_int` or `get_string` from CS50’s library to get users’ input, depending on how you to decide to implement this one.



Your program should behave per the example below.

```
$ python credit.py
Number: 378282246310005
AMEX
```


---
### [*Readability*](sentimental-readability/readability.py)

Task:

  - Write, in a file called `readability.py`, a program that first asks the user to type in some text, and then outputs the grade level for the text, according to the Coleman-Liau formula, exactly as you did in <a href="../../2/">Problem Set 2</a>, except that your program this time should be written in Python.
    
      - Recall that the Coleman-Liau index is computed as `0.0588 * L - 0.296 * S - 15.8`, where `L` is the average number of letters per 100 words in the text, and `S` is the average number of sentences per 100 words in the text.
    
  
  - Use `get_string` from the CS50 Library to get the user’s input, and `print` to output your answer.
  - Your program should count the number of letters, words, and sentences in the text. You may assume that a letter is any lowercase character from `a` to `z` or any uppercase character from `A` to `Z`, any sequence of characters separated by spaces should count as a word, and that any occurrence of a period, exclamation point, or question mark indicates the end of a sentence.
  - Your program should print as output `"Grade X"` where `X` is the grade level computed by the Coleman-Liau formula, rounded to the nearest integer.
  - If the resulting index number is 16 or higher (equivalent to or greater than a senior undergraduate reading level), your program should output `"Grade 16+"` instead of giving the exact index number. If the index number is less than 1, your program should output `"Before Grade 1"`.


Your program should behave per the example below.


```
$ python readability.py
Text: Congratulations! Today is your day. You're off to Great Places! You're off and away!
Grade 3
```


---
### [*DNA*](dna/dna.py)

In a file called `dna.py`, implement a program that identifies to whom a sequence of DNA belongs.


  - The program should require as its first command-line argument the name of a CSV file containing the STR counts for a list of individuals and should require as its second command-line argument the name of a text file containing the DNA sequence to identify.
    
      - If your program is executed with the incorrect number of command-line arguments, your program should print an error message of your choice (with `print`). If the correct number of arguments are provided, you may assume that the first argument is indeed the filename of a valid CSV file and that the second argument is the filename of a valid text file.
    
  
  - Your program should open the CSV file and read its contents into memory.
    
      - You may assume that the first row of the CSV file will be the column names. The first column will be the word `name` and the remaining columns will be the STR sequences themselves.
    
  
  - Your program should open the DNA sequence and read its contents into memory.
  - For each of the STRs (from the first line of the CSV file), your program should compute the longest run of consecutive repeats of the STR in the DNA sequence to identify. Notice that we’ve defined a helper function for you, `longest_match`, which will do just that!
  - If the STR counts match exactly with any of the individuals in the CSV file, your program should print out the name of the matching individual.
    
      - You may assume that the STR counts will not match more than one individual.
      - If the STR counts do not match exactly with any of the individuals in the CSV file, your program should print `No match`.
    
  
Your program should behave per the example below:

```
$ python dna.py databases/large.csv sequences/5.txt
Lavender
```

```
$ python dna.py
Usage: python dna.py data.csv sequence.txt
```

```
$ python dna.py data.csv
Usage: python dna.py data.csv sequence.txt
```


## Practice Problems

---
### [*Bank*](bank.py)

In a file called `bank.py`, implement a program that prompts the user for a greeting. If the greeting starts with “hello”, output `$0`. If the greeting starts with an “h” (but not “hello”), output `$20`. Otherwise, output `$100`. Ignore any leading whitespace in the user’s greeting, and treat the user’s greeting case-insensitively.

Here’s how to test your code manually:


  - Run your program with `python bank.py`. Type `Hello` and press Enter. Your program should output:
    ```
    $0
    ```
  
  - Run your program with `python bank.py`. Type `Hello, Newman` and press Enter. Your program should output:
    ```
    $0
    ```
  
  - Run your program with `python bank.py`. Type `How you doing?` and press Enter. Your program should output
    ```
    $20
    ```
  
  - Run your program with `python bank.py`. Type `What's happening?` and press Enter. Your program should output
    ```
    $100
    ```
  


---
### [*Frank, Ian and Glen’s Letters*](figlet.py)

In a file called `figlet.py`, implement a program that:


  - Expects zero or two command-line arguments:
    
      - Zero if the user would like to output text in a random font.
      - Two if the user would like to output text in a specific font, in which case the first of the two should be `-f` or `--font`, and the second of the two should be the name of the font.
    
  
  - Prompts the user for a `str` of text.
  - Outputs that text in the desired font.


If the user provides two command-line arguments and the first is not `-f` or `--font` or the second is not the name of a font, the program should exit via `sys.exit` with an error message.

Here’s how to test your code manually:


  - Run your program with `python figlet.py test`. Your program should exit via `sys.exit` and print an error message:
```
Invalid usage
```
  
  - Run your program with `python figlet.py -a slant`. Your program should exit via `sys.exit` and print an error message:
```
Invalid usage
```
  
  - Run your program with `python figlet.py -f invalid_font`. Your program should exit via `sys.exit` and print an error message:
```
Invalid usage
```
  
  - Run your program with `python figlet.py -f slant`. Type `CS50`. Your program should print the following:
```
   ___________ __________ 
  / ____/ ___// ____/ __ \
 / /    \__ \/___ \/ / / /
/ /___ ___/ /___/ / /_/ / 
\____//____/_____/\____/  
```
  
  - Run your program with `python figlet.py -f rectangles`. Type `Hello, world`. Your program should print the following:
```
 _____     _ _                        _   _ 
|  |  |___| | |___      _ _ _ ___ ___| |_| |
|     | -_| | | . |_   | | | | . |  _| | . |
|__|__|___|_|_|___| |  |_____|___|_| |_|___|
                  |_|                       
```
  
  - Run your program with `python figlet.py -f alphabet`. Type `Moo`. Your program should print the following:
```
M   M         
MM MM         
M M M ooo ooo 
M   M o o o o 
M   M ooo ooo                     
```
  


---
### [*Jar*](jar.py)

Suppose that you’d like to implement a <a href="https://en.wikipedia.org/wiki/Cookie_jar">cookie jar</a> in which to store cookies. In a file called `jar.py`, implement a `class` called `Jar` with these methods:


  - `__init__` should initialize a cookie jar with the given `capacity`, which represents the maximum number of cookies that can fit in the cookie jar. If `capacity` is not a non-negative `int`, though, `__init__` should instead raise a `ValueError` (via `raise ValueError`).
  - `__str__` should return a `str` with \(n\) `🍪`, where \(n\) is the number of cookies in the cookie jar. For instance, if there are 3 cookies in the cookie jar, then `str` should return `"🍪🍪🍪"`
  - `deposit` should add `n` cookies to the cookie jar. If adding that many would exceed the cookie jar’s capacity, though, `deposit` should instead raise a `ValueError`.
  - `withdraw` should remove `n` cookies from the cookie jar. Nom nom nom. If there aren’t that many cookies in the cookie jar, though, `withdraw` should instead raise a `ValueError`.
  - `capacity` should return the cookie jar’s capacity.
  - `size` should return the number of cookies actually in the cookie jar.


Structure your `class` per the below. You may not alter these methods’ parameters, but you may add your own methods.

```
class Jar:
    def __init__(self, capacity=12):
        ...

    def __str__(self):
        ...

    def deposit(self, n):
        ...

    def withdraw(self, n):
        ...

    @property
    def capacity(self):
        ...

    @property
    def size(self):
        ...
```

Here’s how to test your code manually:


  - Define a `main` function in your `jar.py` file, wherein you create a new instance of `Jar` with `jar = Jar()`. Test this `jar` has the capacity it should by calling `print(str(jar.capacity))`. Be sure your program calls `main` at the bottom of the file, as via `main()`.
  - Test that your `__str__` function works as intended by calling `print(str(jar))`.
  - Try calling `jar.deposit(2)` to deposit two cookies. Calling `print(str(jar))` should now show you the same number of cookies you’ve deposited.
  - Try calling `jar.withdraw(1)` to withdraw one cookie. Calling `print(str(jar))` should now show you one fewer cookie than you had before.
  - Try experimenting with depositing and withdrawing various amounts of cookies. Are you unable to withdraw past the jar’s size? Are you unable to deposit past the jar’s capacity?


---
### [*Seven Day Average*](seven-day-average.py)

Learning Goals
- Work with live data
- Get practice with CSV files and `csv.DictReader`
- Practice using dictionaries, lists and exceptions

The distribution code for this problem uses the python `requests` library to access the New York Times data stored in an accessible GitHub repository. This is stored as a CSV file. The program then uses `DictReader` to read the CSV file. It then creates a `states` list to use selected states for calculations.

You will be completing two functions, `calculate` and `comparative_averages`.

In `calculate`, you’ll be creating a dictionary, `new_cases`, which will keep track of 14 days of new COVID cases for each state. Keys in this `dict` will be the names of states, and the values for each of those keys will be the most recent 14 days of new cases. Since the data from the New York Times is cumulative, each day’s new cases must be calculated by subtracting the previous day’s cases. To do this, you may want to create a second dictionary, `previous_cases`, that keeps track of each day’s new cases as it’s calculated.


Your `calculate` function should ultimately return the `new_cases` dictionary.

Since your `new_cases` dictionary is passed to the `comparative_averages` function, you can calculate this week’s 7-day average by summing up the <em>last</em> 7 elements in the list for a selected state, then dividing this by 7. You can create a 7-day average for the previous week by doing the same with the <em>first</em> 7 elements in that same list.

You can then calculate the percent increase or decrease, by taking the difference of the two 7-day averages and dividing by last week’s average.

Your program should behave per the examples below.

```
seven-day-average/ $ python seven-day-average.py
Choose one or more states to view average COVID cases.
Press enter when done.

State: Massachusetts
State: New York
State: 

Seven-Day Averages
Massachusetts had a 7-day average of 1646 and an increase of 46%.
New York had a 7-day average of 7502 and a decrease of 1%.
```

```
seven-day-average/ $ python seven-day-average.py
Choose one or more states to view average COVID cases.
Press enter when done.

State: Maine
State: California
State: 

Seven-Day Averages
California had a 7-day average of 20461 and a decrease of 8%.
Maine had a 7-day average of 196 and a decrease of 10%.
```
Do note that the numbers will vary each day, since the data you are using is updated daily.

---
### [*Taqueria*](taqueria.py)

One of the most popular places to eat in [Harvard Square](https://en.wikipedia.org/wiki/Harvard_Square) is [Felipe’s Taqueria](https://www.felipesboston.com/), which offers a [menu](https://www.felipesboston.com/menu) of entrees, per the `dict` below, wherein the value of each key is a price in dollars:

```
{
    "Baja Taco": 4.00,
    "Burrito": 7.50,
    "Bowl": 8.50,
    "Nachos": 11.00,
    "Quesadilla": 8.50,
    "Super Burrito": 8.50,
    "Super Quesadilla": 9.50,
    "Taco": 3.00,
    "Tortilla Salad": 8.00
}
```

In a file called `taqueria.py`, implement a program that enables a user to place an order, prompting them for items, one per line, until the user inputs control-d (which is a common way of ending one’s input to a program). After each inputted item, display the total cost of all items inputted thus far, prefixed with a dollar sign (`$`) and formatted to two decimal places. Treat the user’s input case insensitively. Ignore any input that isn’t an item. Assume that every item on the menu will be [titlecased](https://docs.python.org/3/library/stdtypes.html#str.title)


Here’s how to test your code manually:


  - Run your program with `python taqueria.py`. Type `Taco` and press Enter, then type `Taco` again and press Enter. Your program should output:
    ```
    Total: $6.00  
    ```
    
    and continue prompting the user until they input control-d.
  
  - Run your program with `python taqueria.py`. Type `Baja Taco` and press Enter, then type `Tortilla Salad` and press enter. Your program should output:
    ```
    Total: $12.00
    ```
    
    and continue prompting the user until they input control-d.
  
  - Run your program with `python taqueria.py`. Type `Burger` and press Enter. Your program should reprompt the user.


Be sure to try other foods and vary the casing of your input. Your program should behave as expected, case-insensitively.
