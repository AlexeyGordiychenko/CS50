# Week 1

## Lab: [*Population Growth*](population.c)

Complete the implementation of `population.c`, such that it calculates the number of years required for the population to grow from the start size to the end size.

+ Your program should first prompt the user for a starting population size.
    + If the user enters a number less than 9 (the minimum allowed population size), the user should be re-prompted to enter a starting population size until they enter a number that is greater than or equal to 9. (If we start with fewer than 9 llamas, the population of llamas will quickly become stagnant!)
+ Your program should then prompt the user for an ending population size.
    + If the user enters a number less than the starting population size, the user should be re-prompted to enter an ending population size until they enter a number that is greater than or equal to the starting population size. (After all, we want the population of llamas to grow!)
+ Your program should then calculate the (integer) number of years required for the population to reach at least the size of the end value.
+ Finally, your program should print the number of years required for the llama population to reach that end size, as by printing to the terminal `Years: n`, where `n` is the number of years.

Your program should behave per these examples below.

```
$ ./population
Start size: 1200
End size: 1300
Years: 1
```
```
$ ./population
Start size: -5
Start size: 3
Start size: 9
End size: 5
End size: 18
Years: 8
```
```
$ ./population
Start size: 20
End size: 1
End size: 10
End size: 100
Years: 20
```
```
$ ./population
Start size: 100
End size: 1000000
Years: 115
```

## Problem Set

---
### [*Hello*](hello.c)

Modify this program in such a way that it first prompts the user for their name and then prints `hello, so-and-so`, where `so-and-so` is their actual name.

---
### [*Mario-more*](mario.c)

Toward the beginning of World 1-1 in Nintendo’s Super Mario Brothers, Mario must hop over adjacent pyramids of blocks, per the below.

Let’s recreate those pyramids in C, albeit in text, using hashes (`#`) for bricks, a la the below. Each hash is a bit taller than it is wide, so the pyramids themselves will also be taller than they are wide.
```
   #  #
  ##  ##
 ###  ###
####  ####
```

The program we’ll write will be called `mario`. And let’s allow the user to decide just how tall the pyramids should be by first prompting them for a positive integer between, say, 1 and 8, inclusive.

Here’s how the program might work if the user inputs `8` when prompted:

```
$ ./mario
Height: 8
       #  #
      ##  ##
     ###  ###
    ####  ####
   #####  #####
  ######  ######
 #######  #######
########  ########
```
Here’s how the program might work if the user inputs `2` when prompted:
```
$ ./mario
Height: 2
 #  #
##  ##
```

If the user doesn’t, in fact, input a positive integer between 1 and 8, inclusive, when prompted, the program should re-prompt the user until they cooperate:
```
$ ./mario
Height: -1
Height: 0
Height: 42
Height: 50
Height: 4
   #  #
  ##  ##
 ###  ###
####  ####
```

Notice that width of the “gap” between adjacent pyramids is equal to the width of two hashes, irrespective of the pyramids’ heights.

---

### [*Credit*](credit.c)

A credit (or debit) card, of course, is a plastic card with which you can pay for goods and services. Printed on that card is a number that’s also stored in a database somewhere, so that when your card is used to buy something, the creditor knows whom to bill. There are a lot of people with credit cards in this world, so those numbers are pretty long: American Express uses 15-digit numbers, MasterCard uses 16-digit numbers, and Visa uses 13- and 16-digit numbers.

All American Express numbers start with 34 or 37; most MasterCard numbers start with 51, 52, 53, 54, or 55 (they also have some other potential starting numbers which we won’t concern ourselves with for this problem); and all Visa numbers start with 4. But credit card numbers also have a “checksum” built into them, a mathematical relationship between at least one number and others. That checksum enables computers (or humans who like math) to detect typos (e.g., transpositions), if not fraudulent numbers, without having to query a database, which can be slow. Of course, a dishonest mathematician could certainly craft a fake number that nonetheless respects the mathematical constraint, so a database lookup is still necessary for more rigorous checks.

<details> 
  <summary>Luhn’s Algorithm</summary>
  
---
So what’s the secret formula? Well, most cards use an algorithm invented by Hans Peter Luhn of IBM. According to Luhn’s algorithm, you can determine if a credit card number is (syntactically) valid as follows:

+ Multiply every other digit by 2, starting with the number’s second-to-last digit, and then add those products’ digits together.
+ Add the sum to the sum of the digits that weren’t multiplied by 2.
+ If the total’s last digit is 0 (or, put more formally, if the total modulo 10 is congruent to 0), the number is valid!

That’s kind of confusing, so let’s try an example with David’s Visa: 4003600000000014.

1. For the sake of discussion, let’s first underline every other digit, starting with the number’s second-to-last digit:

    <u>4</u>0<u>0</u>3<u>6</u>0<u>0</u>0<u>0</u>0<u>0</u>0<u>0</u>0<u>1</u>4

    Okay, let’s multiply each of the underlined digits by 2:

    1•2 + 0•2 + 0•2 + 0•2 + 0•2 + 6•2 + 0•2 + 4•2

    That gives us:

    2 + 0 + 0 + 0 + 0 + 12 + 0 + 8

    Now let’s add those products’ digits (i.e., not the products themselves) together:

    2 + 0 + 0 + 0 + 0 + 1 + 2 + 0 + 8 = 13

2. Now let’s add that sum (13) to the sum of the digits that weren’t multiplied by 2 (starting from the end):

    13 + 4 + 0 + 0 + 0 + 0 + 0 + 3 + 0 = 20

3. Yup, the last digit in that sum (20) is a 0, so David’s card is legit!

So, validating credit card numbers isn’t hard, but it does get a bit tedious by hand. Let’s write a program.

---
</details>

In the file called `credit.c` in the `credit` directory, write a program that prompts the user for a credit card number and then reports (via `printf`) whether it is a valid American Express, MasterCard, or Visa card number, per the definitions of each’s format herein. So that we can automate some tests of your code, we ask that your program’s last line of output be `AMEX\n` or `MASTERCARD\n` or `VISA\n` or `INVALID\n`, nothing more, nothing less. 

For simplicity, you may assume that the user’s input will be entirely numeric (i.e., devoid of hyphens, as might be printed on an actual card) and that it won’t have leading zeroes. But do not assume that the user’s input will fit in an `int`! Best to use `get_long` from CS50’s library to get users’ input.

Consider the below representative of how your own program should behave when passed a valid credit card number (sans hyphens).

```
$ ./credit
Number: 4003600000000014
VISA
```
Now, `get_long` itself will reject hyphens (and more) anyway:

```
$ ./credit
Number: 4003-6000-0000-0014
Number: foo
Number: 4003600000000014
VISA
```
But it’s up to you to catch inputs that are not credit card numbers (e.g., a phone number), even if numeric:

```
$ ./credit
Number: 6176292929
INVALID
```

## Practice Problems
---
### [*Debug*](debug.c)


Learning Goals
+ Become familiar with C syntax
+ Learn what C compiler error messages mean
+ Get practice debugging

This lab starts with distribution code which has several syntactical errors. The idea is for you to try to compile (`make`) the program, learn to interpret the rather cryptic error messages output by the compiler, and **debug** the program.

Your program should behave per the examples below.

```
debug/ $ ./debug
What is your name? Carter
Where do you live? Cambridge
Hello, Carter, from Cambridge!
```
```
debug/ $ ./debug
What is your name? Margaret
Where do you live? New York
Hello, Margaret, from New York!
```
---
### [*Half*](half.c)
Learning Goals
+ Work with different data types
+ Practice type casting
+ Use math operations
+ Create a function with input parameters and return value

Your function should use the input parameters, `bill`, `tax`, and `tip`, to calculate the final amount. However, since these values are percentages, you’ll have to do some work to convert these to more appropriate formats to use for your calculation.

The tax should be added to the bill amount *before* calculating the tip. Finally, you will return exactly half of the full amount, including the bill amount, the tax and the tip.

Your program should behave per the examples below.

```
half/ $ ./half
Bill before tax and tip: 12.50
Sale Tax Percent: 8.875
Tip percent: 20
You will owe $8.17 each!
```
```
half/ $ ./half
Bill before tax and tip: 23.50
Sale Tax Percent: 7  
Tip percent: 15
You will owe $14.46 each!
```
```
half/ $ ./half
Bill before tax and tip: 100
Sale Tax Percent: 6.25
Tip percent: 18
You will owe $62.69 each!
```
---
### [*Prime*](prime.c)

Learning Goals
+ Practice using `for` loops
+ Using modulo
+ Creating a Boolean function

The easiest way to check if a number is prime, is to try dividing it by every number from 2 up to, but not including, the number itself. If any number divides into it with no remainder, that number is not prime.

The `main` function in the distribution code contains a `for` loop that iterates through the range specified by the user, with both ends inclusive. For example, if the user types in `1` for `min` and `100` for `max`, the `for` loop will test each number, 1 to 100. Each of these numbers is passed to a function, `prime`, that you will implement to return either `true` or `false` depending on whether the number is prime.

Your program should behave per the examples below.
```
prime/ $ ./prime
Minimum: 1
Maximum: 100
2
3
5
7
11
13
17
19
23
29
31
37
41
43
47
53
59
61
67
71
73
79
83
89
97
```