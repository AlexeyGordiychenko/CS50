# [ESCAPE THE ROOM](../README.md)
## Video Demo: [link](https://youtu.be/b4Wd3z8owZs)
## Prologue:

    You find yourself in a small room with a desk, a chair and an old computer on the desk. You notice a closed door in the wall in front of you. Looks like it has an electronic lock. You also notice a small piece of paper attached to the monitor. You grab it and read:

>*`I couldn't solve the riddle to get the code. Without it you can't do any changes to the database. But I looked around the database and I'm pretty sure you have to delete a certain module in order to be able to unlock the doors. After that you should be able to just set the doors' statuses to zero in order to open them up and escape. Good luck.`*

    You boot up the computer and see the text:

>*`Admin code is a 4 digit number:`*
>+ *`The first three digits are in descending order.`*
>+ *`The sum of the two smallest digits is 5.`*
>+ *`No pair of the digits has a difference of 1.`*
>+ *`The product of just one pair of the digits is a prime number.`*
>+ *`The 4 digit number is divisible by 6.`*
>+ *`The code consists of 4 different digits.`*
>
>*`To enter the database run: ./cli`*
>
>*`To check if you can get out run: ./check`*

## Description:

This is a small puzzle made in a form of a command-line program using C. The program implements a simple DBMS (database management system) based on binary files.

It has four basic commands SELECT, INSERT, UPDATE, DELETE.

## Files:

### ***cli.c cli.h:***
Contains main function `int main(void)` and functions to implement the menu of the program:
```
Welcome. Please choose one option:
     1.SELECT
     2.INSERT
     3.UPDATE
     4.DELETE
     5.MAIN MENU / EXIT
```
```
Please choose a table:
     1.login
     2.modules
     3.doors
     4.MAIN MENU / EXIT
```

### ***login.c login.h:***
Contains functions to interact with `login` table (file). Such as:

+ read
+ write
+ calculating the number or entries
+ process queries
+ get the current code[^1]

[^1]: to set it as a global variable at the start of the program (if a user exits and starts the program again)

_Note: I chose to make this functionality as a table and not as some kind of password, required at the start of the program, just to be able to leave instructions as a note in the prologue. So the person who left the note would be able to browse the tables, but not make any changes. Also this table utilizes the INSERT query._

### ***modules.c modules.h***
Contains functions to interact with `modules` table (file). Such as:

+ read
+ write
+ calculating the number of entries
+ process queries

### ***doors.c doors.h***
Contains functions to interact with `doors` table (file). Such as:

+ read
+ write
+ calculating the number of entries
+ process queries

### ***shared.c shared.h***
Contains helper-functions. Such as:

+ functions to output table's headers for SELECT queries
+ functions to get input from a user with validation (int and string)
+ function to open a table

Also contains:

+ definitions of the folder with tables and max length of a module name
+ global variable with the current login code
+ definitions of the structures that are used to write to the tables (files)

### ***check.c***

Contains only one main function designed to check all the conditions for the puzzle to be solved.

<details>
<summary>Conditions (SPOILERS)</summary>

+ correct code (9714) in the `login` table (file)
+ no module with name `security` in the `modules` table (file) [^2]
+ no entries with value `1` in the field `closed` in the `doors` table (file) [^3]

</details>

## Building from source

To build the program you can simply run `make` while in the project folder. It will build the executable and put them in the `build` folder.

There is also the `initial_tables` folder, it contains the default database files. So if you delete or damage database files, you can restore them from this folder. To quick copy the files you can run `make copy_db` from the `project` folder.

To run the program:

1. proceed into the build folder
2. make sure that there is the `db` folder in it with database files: `login`, `doors`, `modules`
3. run ./cli from the build folder
4. to check your solution run ./check

## Testing

I also created sort of autotests. The folder `testing` contains testing enviroment. You need to have `valgrind` installed in order to run it. There are:

+ reference files to compare an output of the programs to (`test_*_ref.txt`)
+ files with instructions which will be redirected to the program as an input (`test_*.txt`)

You can run from `testing` folder:

+ `make` to start all the tests
+ `make test_cli` to test the `cli` program
+ `make test_check` to test the `check` program

_Note: since input in the `cli` program organised in a while loop tests can stuck in the loop. To cancel the tests use Ctrl+C. Current tests should not stuck, but who knows what nasty bugs I've missed :D_



[^2]: you can either delete it or rename
[^3]: you can either update all the records or delete them
