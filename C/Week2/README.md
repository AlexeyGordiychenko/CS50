# [Week 2](../../README.md)

## Lab: [*Scrabble*](scrabble.c)

In the game of Scrabble, players create words to score points, and the number of points is the sum of the point values of each letter in the word.


| A   | B   | C   | D   | E   | F   | G   | H   | I   | J   | K   | L   | M   | N   | O   | P   | Q   | R   | S   | T   | U   | V   | W   | X   | Y   | Z   |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| 1   | 3   | 3   | 2   | 1   | 4   | 2   | 4   | 1   | 8   | 5   | 1   | 3   | 1   | 1   | 3   | 10  | 1   | 1   | 1   | 1   | 4   | 4   | 8   | 4   | 10  |

For example, if we wanted to score the word `Code`, we would note that in general Scrabble rules, the `C` is worth `3` points, the o is worth `1` point, the `d` is worth `2` points, and the `e` is worth `1` point. Summing these, we get that `Code` is worth `3 + 1 + 2 + 1 = 7` points.

Complete the implementation of `scrabble.c`, such that it determines the winner of a short scrabble-like game, where two players each enter their word, and the higher scoring player wins.

+ Notice that we’ve stored the point values of each letter of the alphabet in an integer array named `POINTS`.
    + For example, `A` or `a` is worth `1` point (represented by `POINTS[0]`), `B` or `b` is worth `3` points (represented by `POINTS[1]`), etc.
+ Notice that we’ve created a prototype for a helper function called `compute_score()` that takes a string as input and returns an `int`. Whenever we would like to assign point values to a particular word, we can call this function. Note that this prototype is required for C to know that `compute_score()` exists later in the program.
+ In `main()`, the program prompts the two players for their words using the `get_string()` function. These values are stored inside variables named `word1` and `word2`.
+ In `compute_score()`, your program should compute, using the `POINTS` array, and return the score for the string argument. Characters that are not letters should be given zero points, and uppercase and lowercase letters should be given the same point values.
    + For example, `!` is worth `0` points while `A` and a are both worth `1` point.
    + Though Scrabble rules normally require that a word be in the dictionary, no need to check for that in this problem!
+ In `main()`, your program should print, depending on the players’ scores, `Player 1 wins!`, `Player 2 wins!`, or `Tie!`.

Your program should behave per the examples below.

```
$ ./scrabble
Player 1: Question?
Player 2: Question!
Tie!
```
```
$ ./scrabble
Player 1: Oh,
Player 2: hai!
Player 2 wins!
```
```
$ ./scrabble
Player 1: COMPUTER
Player 2: science
Player 1 wins!
```
```
$ ./scrabble
Player 1: Scrabble
Player 2: wiNNeR
Player 1 wins!
```

## Problem Set

---
### [*Readability*](readability.c)

Design and implement a program, readability, that computes the Coleman-Liau index of text.

The Coleman-Liau index of a text is designed to output that (U.S.) grade level that is needed to understand some text. The formula is
```
index = 0.0588 * L - 0.296 * S - 15.8
```
where `L` is the average number of letters per 100 words in the text, and `S` is the average number of sentences per 100 words in the text.

+ Implement your program in a file called `readability.c` in a directory called `readability`.
+ Your program must prompt the user for a `string` of text using `get_string`.
+ Your program should count the number of letters, words, and sentences in the text. You may assume that a letter is any lowercase character from a to z or any uppercase character from `A` to `Z`, any sequence of characters separated by spaces should count as a word, and that any occurrence of a period, exclamation point, or question mark indicates the end of a sentence.
+ Your program should print as output `"Grade X"` where `X` is the grade level computed by the Coleman-Liau formula, rounded to the nearest integer.
+ If the resulting index number is 16 or higher (equivalent to or greater than a senior undergraduate reading level), your program should output `"Grade 16+"` instead of giving the exact index number. If the index number is less than 1, your program should output `"Before Grade 1"`.

---
### [*Substitution*](substitution.c)

Design and implement a program, substitution, that encrypts messages using a substitution cipher.

In a substitution cipher, we “encrypt” (i.e., conceal in a reversible way) a message by replacing every letter with another letter. To do so, we use a key: in this case, a mapping of each of the letters of the alphabet to the letter it should correspond to when we encrypt it. To “decrypt” the message, the receiver of the message would need to know the key, so that they can reverse the process: translating the encrypt text (generally called ciphertext) back into the original message (generally called plaintext).

A key, for example, might be the string `NQXPOMAFTRHLZGECYJIUWSKDVB`. This 26-character key means that `A` (the first letter of the alphabet) should be converted into `N` (the first character of the key), `B` (the second letter of the alphabet) should be converted into `Q` (the second character of the key), and so forth.

+ Implement your program in a file called `substitution.c` in a directory called `substitution`.
+ Your program must accept a single command-line argument, the key to use for the substitution. The key itself should be case-insensitive, so whether any character in the key is uppercase or lowercase should not affect the behavior of your program.
+ If your program is executed without any command-line arguments or with more than one command-line argument, your program should print an error message of your choice (with `printf`) and return from `main` a value of `1` (which tends to signify an error) immediately.
+ If the key is invalid (as by not containing 26 characters, containing any character that is not an alphabetic character, or not containing each letter exactly once), your program should print an error message of your choice (with `printf`) and return from `main` a value of `1` immediately.
+ Your program must output `plaintext:` (without a newline) and then prompt the user for a `string` of plaintext (using `get_string`).
+ Your program must output `ciphertext:` (without a newline) followed by the plaintext’s corresponding ciphertext, with each alphabetical character in the plaintext substituted for the corresponding character in the ciphertext; non-alphabetical characters should be outputted unchanged.
+ Your program must preserve case: capitalized letters must remain capitalized letters; lowercase letters must remain lowercase letters.
+ After outputting ciphertext, you should print a newline. Your program should then exit by returning `0` from `main`.

Here are a few examples of how the program might work:

```
$ ./substitution YTNSHKVEFXRBAUQZCLWDMIPGJO
plaintext:  HELLO
ciphertext: EHBBQ
Here’s how the program might work if the user provides a key of VCHPRZGJNTLSKFBDQWAXEUYMOI and a plaintext of hello, world:
```
```
$ ./substitution VCHPRZGJNTLSKFBDQWAXEUYMOI
plaintext:  hello, world
ciphertext: jrssb, ybwsp
```
```
$ ./substitution ABC
Key must contain 26 characters.
```
```
$ ./substitution
Usage: ./substitution key
```
```
$ ./substitution 1 2 3
Usage: ./substitution key
```

---
### [*Wordle50*](wordle.c)

Design and implement a program, `wordle`, that completes the implementation of our Wordle50 clone of the game. You’ll notice that some large pieces of this program have already been written for you–you are not allowed to modify any of those parts of the program. Instead, your work should be constrained to the seven TODOs we’ve left behind for you to fill in. Each one of those parts solves a specific problem, and we recommend you tackle them in order from 1 to 7. Each numbered `TODO` corresponds to the same item in the below list.

1. In the first `TODO`, you should ensure the program accepts a single command-line argument. Let’s call it 
 for the sake of discussion. If the program was not run with a single command-line argument, you should print the error message as we demonstrate above and return `1`, ending the program.
2. In the second `TODO`, you should make sure that 
 is one of the acceptable values (5, 6, 7, or 8), and store that value in `wordsize`; we’ll need to make use of that later. If the value of 
 is not one of those four values exactly, you should print the error message as we demonstrate above and return `1`, ending the program.

After that, the staff has already written some code that will go through and open the word list for the length of word the user wants to guess and randomly selects one from the 1000 options available. Don’t worry about necessarily understanding all of this code, it’s not important for purposes of this assignment. We’ll see something similar though in a later assignment, and it will make a lot more sense then! This is a good place to stop and test, before proceeding to the next `TODO`, that your code behaves as expected. It’s always easier to debug programs if you do so methodically!

3. For the third `TODO`, you should help defend against stubborn users by making sure their guess is the correct length. For that, we’ll turn our attention to the function `get_guess`, which you’ll need to implement in full. A user should be prompted (as via get_string) to type in a 
-letter word (remember, that value is passed in as a parameter to `get_guess`) and if they supply a guess of the wrong length, they should be re-prompted (much like in Mario) until they provide exactly the value you expect from them. Right now, the distribution code doesn’t do that, so you’ll have to make that fix! Note that unlike the real Wordle, we actually don’t check that the user’s guess is a real word, so in that sense the game is perhaps a little bit easier. All guesses in this game should be in **lowercase** characters, and it is acceptable for you to assume that the user will not be so stubborn as to provide anything other than lowercase characters when making a guess. Once a legitimate guess has been obtained, it can be returned.
4. Next, for the fourth `TODO`, we need to keep track of a user’s “score” in the game. We do this both on a per-letter basis—by assigning a score of 2 (which we `#define`d as `EXACT`) to a letter in the correct place, 1 (which we `#define`d as `CLOSE`) to a letter that’s in the word but in the wrong place, or 0 (which we `#define`d as `WRONG`)—and a per-word basis, to help us detect when we’ve potentially triggered the end of the game by winning. We’ll use the individual letter scores when we color-code the printing. In order to store those scores, we need an array, which we’ve called `status`. At the start of the game, with no guesses having taken place, it should contain all 0s.

This is another good place to stop and test your code, particularly as it pertains to item 3, above! You’ll notice that at this point, when you finally enter a legitimate guess (that is to say, one that’s the correct length), your program will likely look something like the below:
```
Input a 5-letter word: computer
Input a 5-letter word: games
Guess 1:
Input a 5-letter word:
```
That’s normal, though! Implementing `print_word` is `TODO` number 6, so we should not expect the program to do any processing of that guess at this time. Of course, you can always add additional `printf` calls (just make sure to remove them before you submit) as part of your debugging strategy!

5. The fifth `TODO` is definitely the largest and probably most challenging. Inside of the `check_word` function, it’s up to you to compare each of the letters of the `guess` with each of the letters of the `choice` (which, recall, is the “secret word” for this game), and assign scores. If the letters match, award `EXACT` (2) points and `break` out of the loop—there’s no need to continue looping if you already determined the letter is in the right spot. Technically, if that letter appears in the word twice, this could result in a bit of a bug, but fixing that bug overcomplicates this problem a bit more than we want to now, so we’re going to accept that as a feature of our version! If you find that the letter is in the word but not in the right spot, award `CLOSE` (1) points but don’t `break`! After all, that letter might later show up in the right spot in the `choice` word, and if we `break` too soon, the user would never know it! You don’t actually need to explicitly set `WRONG` (0) points here, since you handled that early in Step 4. Ultimately though, you should also be summing up the total score of the word when you know it, because that’s what this function is supposed to ultimately return. Again, don’t be afraid to use `debug50` and/or `printf`s as necessary in order to help you figure out what the values of different variables are at this point – until you implement `print_word`, below, the program won’t be offering you much in the way of a visual checkpoint!
6. For the sixth `TODO` you will complete the implementation of `print_word`. That function should look through the values you populated the `status` array with and print out, character by character, each letter of the `guess` with the correct color code. You may have noticed some (scary-looking!) `#define`s at the top of the file wherein we provide a simpler way of representing what’s called an ANSI color code, which is basically a command to change the font color of the terminal. You don’t need to worry about how to implement those four values (`GREEN`, `YELLOW`, `RED`, and `RESET`, the latter of which simply returns to the terminal’s default font) or exactly what they mean; instead, you can just use them (the power of abstraction!). Note as well that we provide an example in the distribution code up where we print some green text and then reset the color, as part of the game’s introduction. Accordingly, you should feel free to use the below line of code for inspiration as to how you might try to toggle colors:
```
printf(GREEN"This is WORDLE50"RESET"\n");
```
Of course, unlike our example, you probably don’t want to print a newline after each character of the word (instead, you just want one newline at the end, also resetting the font color!).

7. Finally, the seventh `TODO` is just a bit of tidying up before the program terminates. Whether the main `for` loop has ended normally, by the user running out of guesses, or because we broke out of it by getting the word exactly right, it’s time to report to the user on the game’s outcome. If the user did win the game, a simple `You won!` suffices to print here. Otherwise, you should print a message telling the user what the target word was, so they know the game was being honest with them (and so that you have a means to debug if you look back and realize your code was providing improper clues along the way!)


## Practice Problems
---
### [*Hours*](hours.c)

Learning Goals
+ Practice using arrays
+ Using an array as a parameter to a function
+ Adding values in a loop
+ Integer division and type casting

The `main` function prompts the user for the number of weeks a user has been taking CS50, then creates an array with as many elements. Notice that, after retrieving some data, the program prompts the user to type in either “T” or “A”—”T” should (but doesn’t yet!) print the total number of hours the user entered, while “A” should (but doesn’t yet!) print the average hours the user entered. Notice that the `do while` loop uses `toupper` to capitalize the letter that’s input before it is saved in the variable output. Then, the `printf` function calls `calc_hours`. Note the syntax involved when passing an array to a function.

To complete `calc_hours`, first total up the hours saved in the array into a new variable. Then, depending on the value of `output`, return either this sum, or the average number of hours.

Your program should behave per the examples below.

```
hours/ $ ./hours
Number of weeks taking CS50: 3
Week 0 HW Hours: 3
Week 1 HW Hours: 7
Week 2 HW Hours: 10
Enter T for total hours, A for average hours per week: A
6.7 hours
```
```
hours/ $ ./hours
Number of weeks taking CS50: 2
Week 0 HW Hours: 2
Week 1 HW Hours: 8
Enter T for total hours, A for average hours per week: T
10.0 hours
```
---
### [*N0 V0w3ls*](no-vowels.c)

Learning Goals
- Practice using strings
- Practice using command-line arguments
- Write a program entirely from scratch

Task:

- Implement your program in a file called no-vowels.c in a directory called no-vowels.
- Your program must accept a single command-line argument, which will be the word that you want to convert.
- If your program is executed without any command-line arguments or with more than one command-line argument, your program should print an error message of your choice (with printf) and return from main a value of 1 (which tends to signify an error) immediately.
- Your program must contain a function called replace which takes a string input and returns a string output.
- This function will change the following vowels to numbers: a becomes 6, e becomes 3, i becomes 1, o becomes 0 and u does not change.
- The input parameter for the replace function will be argv[1] and the return value is the converted word.
- The main function will then print the converted word, followed by \n.
- You may want to try using the switch statement in your replace function.

Your program should behave per the examples below.

```
no-vowels/ $ ./no-vowels
Usage: ./no-vowels word
```
```
no-vowels/ $ ./no-vowels hello
h3ll0
```
```
no-vowels/ $ ./no-vowels pseudocode
ps3ud0c0d3
```
---
### [*Password*](password.c)

Learning Goals

- Practice iterating through a string
- Practice using the ctype library
- Practice using Boolean variables

Your function will iterate through the password that’s supplied to it as an argument. Since you have to find at least one lower case letter, one upper case letter, one number and one symbol, you may want to create a boolean variable for each and set each to `false` before you iterate through the string. If you then find a number, for instance you can set that boolean to `true`. If all booleans are `true` at the end of the function, it means all criteria are met, and you would return `true`.

Your program should behave per the examples below.

```
password/ $ ./password
Enter your password: hello
Your password needs at least one uppercase letter, lowercase letter, number and symbol!
```
```
password/ $ ./password
Enter your password: h3ll(
Your password needs at least one uppercase letter, lowercase letter, number and symbol!
```
```
password/ $ ./password
Enter your password: h3LL0!
Your password is valid!
```