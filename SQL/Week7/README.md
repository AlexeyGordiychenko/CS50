# [Week 7](../../README.md)

## Lab: [*Songs*](songs/)

For each of the following problems, you should write a single SQL query that outputs the results specified by each problem. Your response must take the form of a single SQL query, though you may nest other queries inside of your query. You **should not** assume anything about the `id`s of any particular songs or artists: your queries should be accurate even if the `id` of any particular song or person were different. Finally, each query should return only the data necessary to answer the question: if the problem only asks you to output the names of songs, for example, then your query should not also output each song’s tempo.


  1. In `1.sql`, write a SQL query to list the names of all songs in the database.
    
      - Your query should output a table with a single column for the name of each song.
    
  
  1. In `2.sql`, write a SQL query to list the names of all songs in increasing order of tempo.
    
      - Your query should output a table with a single column for the name of each song.
    
  
  1. In `3.sql`, write a SQL query to list the names of the top 5 longest songs, in descending order of length.
    
      - Your query should output a table with a single column for the name of each song.
    
  
  1. In `4.sql`, write a SQL query that lists the names of any songs that have danceability, energy, and valence greater than 0.75.
    
      - Your query should output a table with a single column for the name of each song.
    
  
  1. In `5.sql`, write a SQL query that returns the average energy of all the songs.
    
      - Your query should output a table with a single column and a single row containing the average energy.
    
  
  1. In `6.sql`, write a SQL query that lists the names of songs that are by Post Malone.
    
      - Your query should output a table with a single column for the name of each song.
      - You should not make any assumptions about what Post Malone’s `artist_id` is.
    
  
  1. In `7.sql`, write a SQL query that returns the average energy of songs that are by Drake.
    
      - Your query should output a table with a single column and a single row containing the average energy.
      - You should not make any assumptions about what Drake’s `artist_id` is.
    
  
  1. In `8.sql`, write a SQL query that lists the names of the songs that feature other artists.
    
      - Songs that feature other artists will include “feat.” in the name of the song.
      - Your query should output a table with a single column for the name of each song.
    
  


As well as running your queries in `sqlite3`, you can test your queries in the VS Code terminal by running

```
$ cat filename.sql | sqlite3 songs.db
```

where `filename.sql` is the file containing your SQL query.


## Problem Set

---
### [*Movies*](movies/)

For each of the following problems, you should write a single SQL query that outputs the results specified by each problem. Your response must take the form of a single SQL query, though you may nest other queries inside of your query. You **should not** assume anything about the `id`s of any particular movies or people: your queries should be accurate even if the `id` of any particular movie or person were different. Finally, each query should return only the data necessary to answer the question: if the problem only asks you to output the names of movies, for example, then your query should not also output each movie’s release year.

You’re welcome to check your queries’ results against [IMDb](https://www.imdb.com/) itself, but realize that ratings on the website might differ from those in `movies.db`, as more votes might have been cast since we downloaded the data!


  1. In `1.sql`, write a SQL query to list the titles of all movies released in 2008.
    
      - Your query should output a table with a single column for the title of each movie.
    
  
  1. In `2.sql`, write a SQL query to determine the birth year of Emma Stone.
    
      - Your query should output a table with a single column and a single row (not counting the header) containing Emma Stone’s birth year.
      - You may assume that there is only one person in the database with the name Emma Stone.
    
  
  1. In `3.sql`, write a SQL query to list the titles of all movies with a release date on or after 2018, in alphabetical order.
    
      - Your query should output a table with a single column for the title of each movie.
      - Movies released in 2018 should be included, as should movies with release dates in the future.
    
  
  1. In `4.sql`, write a SQL query to determine the number of movies with an IMDb rating of 10.0.
    
      - Your query should output a table with a single column and a single row (not counting the header) containing the number of movies with a 10.0 rating.
    
  
  1. In `5.sql`, write a SQL query to list the titles and release years of all Harry Potter movies, in chronological order.
    
      - Your query should output a table with two columns, one for the title of each movie and one for the release year of each movie.
      - You may assume that the title of all Harry Potter movies will begin with the words “Harry Potter”, and that if a movie title begins with the words “Harry Potter”, it is a Harry Potter movie.
    
  
  1. In `6.sql`, write a SQL query to determine the average rating of all movies released in 2012.
    
      - Your query should output a table with a single column and a single row (not counting the header) containing the average rating.
    
  
  1. In `7.sql`, write a SQL query to list all movies released in 2010 and their ratings, in descending order by rating. For movies with the same rating, order them alphabetically by title.
    
      - Your query should output a table with two columns, one for the title of each movie and one for the rating of each movie.
      - Movies that do not have ratings should not be included in the result.
    
  
  1. In `8.sql`, write a SQL query to list the names of all people who starred in Toy Story.
    
      - Your query should output a table with a single column for the name of each person.
      - You may assume that there is only one movie in the database with the title Toy Story.
    
  
  1. In `9.sql`, write a SQL query to list the names of all people who starred in a movie released in 2004, ordered by birth year.
    
      - Your query should output a table with a single column for the name of each person.
      - People with the same birth year may be listed in any order.
      - No need to worry about people who have no birth year listed, so long as those who do have a birth year are listed in order.
      - If a person appeared in more than one movie in 2004, they should only appear in your results once.
    
  
  1. In `10.sql`, write a SQL query to list the names of all people who have directed a movie that received a rating of at least 9.0.
    
      - Your query should output a table with a single column for the name of each person.
      - If a person directed more than one movie that received a rating of at least 9.0, they should only appear in your results once.
    
  
  1. In `11.sql`, write a SQL query to list the titles of the five highest rated movies (in order) that Chadwick Boseman starred in, starting with the highest rated.
    
      - Your query should output a table with a single column for the title of each movie.
      - You may assume that there is only one person in the database with the name Chadwick Boseman.
    
  
  1. In `12.sql`, write a SQL query to list the titles of all movies in which both Johnny Depp and Helena Bonham Carter starred.
    
      - Your query should output a table with a single column for the title of each movie.
      - You may assume that there is only one person in the database with the name Johnny Depp.
      - You may assume that there is only one person in the database with the name Helena Bonham Carter.
    
  
  1. In `13.sql`, write a SQL query to list the names of all people who starred in a movie in which Kevin Bacon also starred.
    
      - Your query should output a table with a single column for the name of each person.
      - There may be multiple people named Kevin Bacon in the database. Be sure to only select the Kevin Bacon born in 1958.
      - Kevin Bacon himself should not be included in the resulting list.
    
  


To test your queries in VS Code, you can query the database by running

```
$ cat filename.sql | sqlite3 movies.db
```

where `filename.sql` is the file containing your SQL query.


---
### [Fiftyville](fiftyville/answers.txt)

The CS50 Duck has been stolen! The town of Fiftyville has called upon you to solve the mystery of the stolen duck. Authorities believe that the thief stole the duck and then, shortly afterwards, took a flight out of town with the help of an accomplice. Your goal is to identify:


  - Who the thief is,
  - What city the thief escaped to, and
  - Who the thief’s accomplice is who helped them escape


All you know is that the theft **took place on July 28, 2021** and that it **took place on Humphrey Street**.

How will you go about solving this mystery? The Fiftyville authorities have taken some of the town’s records from around the time of the theft and prepared a SQLite database for you, `fiftyville.db`, which contains tables of data from around the town. You can query that table using SQL `SELECT` queries to access the data of interest to you. Using just the information in the database, your task is to solve the mystery.


For this problem, equally as important as solving the mystery itself is the process that you use to solve the mystery. In `log.sql`, keep a log of all SQL queries that you run on the database. Above each query, label each with a comment (in SQL, comments are any lines that begin with `--`) describing why you’re running the query and/or what information you’re hoping to get out of that particular query. You can use comments in the log file to add additional notes about your thought process as you solve the mystery: ultimately, this file should serve as evidence of the process you used to identify the thief!

As you write your queries, you may notice that some of them can become quite complex. To help keep your queries readable, see principles of good style at [sqlstyle.guide](https://www.sqlstyle.guide). The [indentation](https://www.sqlstyle.guide/#indentation) section may be particularly helpful!

Once you solve the mystery, complete each of the lines in `answers.txt` by filling in the name of the thief, the city that the thief escaped to, and the name of the thief’s accomplice who helped them escape town. (Be sure not to change any of the existing text in the file or to add any other lines to the file!)

Ultimately, you should submit both your `log.sql` and `answers.txt` files.


## Practice Problems

---
### [Favorites](favorites/favorites.sql)

Learning Goals
- Become familiar with SQL
- Practice using `SELECT` and `UPDATE` operations


Let’s first take a look at the data. Recall that you’ll need to use [SQLite](https://www.sqlite.org/index.html), a lightweight “database engine”, to open `favorites.db`. We’ll use the third (and latest) version of SQLite. You can open `favorites.db`, then, by executing

```
sqlite3 favorites.db
```

so long as your terminal’s working directory is the same directory in which `favorites.db` is located.

In your `sqlite3` prompt, try executing

```
.schema
```

to see the commands used to create the two tables in this database, `shows` and `genres`.

Now try viewing the data inside of `shows` by executing

```
SELECT * FROM shows;
```

Scrolling up, notice that the very first title in `shows` already looks like it might pose a problem. We want “How i met your mother” to be title-cased! Let’s `UPDATE` this title by executing

```
UPDATE shows SET title = "How I Met Your Mother" WHERE title = "How i met your mother";
```

While you *could* retype each incorrectly entered show title, it’s much more efficient to select muliple variations of the same show and `UPDATE` these to the correct spelling. Maybe the `LIKE` keyword could come in handy! There are many titles to clean up, including all of the below:


  - Adventure Time
  - Arrow
  - Avatar: The Last Airbender
  - Brooklyn Nine-Nine
  - Community
  - Family Guy
  - Friends
  - Game of Thrones
  - Gilmore Girls
  - Grey’s Anatomy
  - How I Met Your Mother
  - It’s Always Sunny in Philadelphia
  - Parks and Recreation
  - Sherlock
  - Squid Game
  - The Bachelorette
  - The Crown
  - The Office
  - The Queen’s Gambit
  - The Untamed


If pressed for time, though, some of the more interesting clean-ups involve these shows:


  - Brooklyn Nine-Nine
  - Game of Thrones
  - Grey’s Anatomy
  - It’s Always Sunny in Philadelphia
  - Parks and Recreation
  - The Office


Be sure to save each of these SQL statements to store in a new file `favorites.sql`.


Once you have completed all of your database `UPDATE`s, you may want to `SELECT` all titles and list these alphabetically to make sure that all are correct.


---
### [Hall of Prophecy](prophecy/fill_db.py)


Learning Goals
  - “Refactor” a `SQL` database to eliminate redundancies
  - Use `SELECT`, `CREATE`, and `INSERT` statements to reorganize data
  - Write Python to load new `SQL` tables


You will use the existing data in `roster.db` to create a new database, one with a table for students, a table for houses, and a table for house assignments. You can do this with individual `SQL` queries, though we recommend ultimately writing your own Python program to automate the process! Notice we’ve given you the data from the `students` table of `roster.db` in CSV format, `students.csv`, for your convenience.

Developing a Schema

First, let’s develop a new schema for the database. In `schema.sql`, document the three `CREATE TABLE` commands you’ll need to create your three new tables.

Keep in mind you’ll want each table to represent a single entity: that is, your students table should represent *only* students, your houses table should represent only *houses*, and your house assignments table should represent *only* house assignments. You might find it helpful to first consider the pieces of information you’ll need in each table, and then about which SQLite data type best represents that information. For example, this was the `CREATE TABLE` command for `students`:

```
CREATE TABLE students (
    id INTEGER,
    student_name TEXT,
    house TEXT,
    head TEXT,
    PRIMARY KEY(id)
);
```

Keep in mind that every table should have a primary key: a column that uniquely identifies every row in the table. Some tables may be best designed with foreign keys: columns that reference the primary keys of another table.

When you’re ready to configure your database with your new schema, run your three new `CREATE TABLE` queries. Type `.schema` to see your results.

Inserting Data

After you’ve configured your database with your new schema, you can begin inserting data into your new database (using your new schema!). It’s best to write a Python program here, which can save you the trouble of writing many `INSERT` queries. Keep in mind that you have `students.csv`, which contains the data from the previous database’s `students` table.


You’ll likely find the following commands helpful for testing your code:


  - `.schema` to check the schema of your database
  - `SELECT * FROM table;` where `table` is the name of the table you’d like to see data from
