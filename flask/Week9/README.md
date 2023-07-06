# [Week 9](../../README.md)

## Lab: [Birthdays](birthdays/app.py)

Complete the implementation of a web application to let users store and keep track of birthdays.


  - When the `/` route is requested via `GET`, your web application should display, in a table, all of the people in your database along with their birthdays.
    
      - First, in `app.py`, add logic in your `GET` request handling to query the `birthdays.db` database for all birthdays. Pass all of that data to your `index.html` template.
      - Then, in `index.html`, add logic to render each birthday as a row in the table. Each row should have two columns: one column for the person’s name and another column for the person’s birthday.
    
  
  - When the `/` route is requested via `POST`, your web application should add a new birthday to your database and then re-render the index page.
    
      - First, in `index.html`, add an HTML form. The form should let users type in a name, a birthday month, and a birthday day. Be sure the form submits to `/` (its “action”) with a method of `post`.
      - Then, in `app.py`, add logic in your `POST` request handling to `INSERT` a new row into the `birthdays` table based on the data supplied by the user.
    
  


Optionally, you may also:


  - Add the ability to delete and/or edit birthday entries.
  - Add any additional features of your choosing!


## Problem Set

---
### [C$50 Finance](finance/app.py)


**REGISTER**

Complete the implementation of `register` in such a way that it allows a user to register for an account via a form.


  - Require that a user input a username, implemented as a text field whose `name` is `username`. Render an apology if the user’s input is blank or the username already exists.
  - Require that a user input a password, implemented as a text field whose `name` is `password`, and then that same password again, implemented as a text field whose `name` is `confirmation`. Render an apology if either input is blank or the passwords do not match.
  - Submit the user’s input via `POST` to `/register`.
  - `INSERT` the new user into `users`, storing a hash of the user’s password, not the password itself. Hash the user’s password with [generate_password_hash](https://werkzeug.palletsprojects.com/en/1.0.x/utils/#werkzeug.security.generate_password_hash) Odds are you’ll want to create a new template (e.g., `register.html`) that’s quite similar to `login.html`.


Once you’ve implemented `register` correctly, you should be able to register for an account and log in (since `login` and `logout` already work)! And you should be able to see your rows via phpLiteAdmin or `sqlite3`.

**QUOTE**

Complete the implementation of `quote` in such a way that it allows a user to look up a stock’s current price.


  - Require that a user input a stock’s symbol, implemented as a text field whose `name` is `symbol`.
  - Submit the user’s input via `POST` to `/quote`.
  - Odds are you’ll want to create two new templates (e.g., `quote.html` and `quoted.html`). When a user visits `/quote` via GET, render one of those templates, inside of which should be an HTML form that submits to `/quote` via POST. In response to a POST, `quote` can render that second template, embedding within it one or more values from `lookup`.


**BUY**

Complete the implementation of `buy` in such a way that it enables a user to buy stocks.


  - Require that a user input a stock’s symbol, implemented as a text field whose `name` is `symbol`. Render an apology if the input is blank or the symbol does not exist (as per the return value of `lookup`).
  - Require that a user input a number of shares, implemented as a text field whose `name` is `shares`. Render an apology if the input is not a positive integer.
  - Submit the user’s input via `POST` to `/buy`.
  - Upon completion, redirect the user to the home page.
  - Odds are you’ll want to call `lookup` to look up a stock’s current price.
  - Odds are you’ll want to `SELECT` how much cash the user currently has in `users`.
  - Add one or more new tables to `finance.db` via which to keep track of the purchase. Store enough information so that you know who bought what at what price and when.
    
      - Use appropriate SQLite types.
      - Define `UNIQUE` indexes on any fields that should be unique.
      - Define (non-`UNIQUE`) indexes on any fields via which you will search (as via `SELECT` with `WHERE`).
    
  
  - Render an apology, without completing a purchase, if the user cannot afford the number of shares at the current price.
  - You don’t need to worry about race conditions (or use transactions).


Once you’ve implemented `buy` correctly, you should be able to see users’ purchases in your new table(s) via phpLiteAdmin or `sqlite3`.

**INDEX**

Complete the implementation of `index` in such a way that it displays an HTML table summarizing, for the user currently logged in, which stocks the user owns, the numbers of shares owned, the current price of each stock, and the total value of each holding (i.e., shares times price). Also display the user’s current cash balance along with a grand total (i.e., stocks’ total value plus cash).


  - Odds are you’ll want to execute multiple `SELECT`s. Depending on how you implement your table(s), you might find `GROUP BY` `HAVING` `SUM` and/or `WHERE` of interest
  - Odds are you’ll want to call `lookup` for each stock.


**SELL**

Complete the implementation of `sell` in such a way that it enables a user to sell shares of a stock (that he or she owns).


  - Require that a user input a stock’s symbol, implemented as a `select` menu whose `name` is `symbol`. Render an apology if the user fails to select a stock or if (somehow, once submitted) the user does not own any shares of that stock.
  - Require that a user input a number of shares, implemented as a text field whose `name` is `shares`. Render an apology if the input is not a positive integer or if the user does not own that many shares of the stock.
  - Submit the user’s input via `POST` to `/sell`.
  - Upon completion, redirect the user to the home page.
  - You don’t need to worry about race conditions (or use transactions).


**HISTORY**

Complete the implementation of `history` in such a way that it displays an HTML table summarizing all of a user’s transactions ever, listing row by row each and every buy and every sell.


  - For each row, make clear whether a stock was bought or sold and include the stock’s symbol, the (purchase or sale) price, the number of shares bought or sold, and the date and time at which the transaction occurred.
  - You might need to alter the table you created for `buy` or supplement it with an additional table. Try to minimize redundancies.


**PERSONAL TOUCH**

Implement at least one personal touch of your choice:


  - Allow users to change their passwords.
  - Allow users to add additional cash to their account.
  - Allow users to buy more shares or sell shares of stocks they already own via `index` itself, without having to type stocks’ symbols manually.
  - Require users’ passwords to have some number of letters, numbers, and/or symbols.
  - Implement some other feature of comparable scope.


**TESTING** 

Be sure to test your web app manually, as by


  - registering a new user and verifying that their portfolio page loads with the correct information,
  - requesting a quote using a valid stock symbol,
  - purchasing one stock multiple times, verifying that the portfolio displays correct totals,
  - selling all or some of a stock, again verifying the portfolio, and
  - verifying that your history page shows all transactions for your logged in user.


Also test some unexpected usage, as by


  - inputting alphabetical strings into forms when only numbers are expected,
  - inputting zero or negative numbers into forms when only positive numbers are expected,
  - inputting floating-point values into forms when only integers are expected,
  - trying to spend more cash than a user has,
  - trying to sell more shares than a user has,
  - inputting an invalid stock symbol, and
  - including potentially dangerous characters like `'` and `;` in SQL queries.


## Practice Problems

---
### [Hello, Flask](helloflask/app.py)


Learning Goals

  - Build a simple flask app to gain an understanding of how to use this framework
  - Become familiar with Jinja, a templating language used with Flask


The most simple Flask app uses just one file, `app.py`. This will create an html page and say hello. Add the following into `app.py` to get started.

```
from flask import Flask

app = Flask(__name__)


@app.route("/")
def index():
    return "Hello, World!"
```

This bit of code starts by importing `Flask` from the `flask` library. Though we don’t need to get too far into the weeds here, `Flask` is what programmers call a “[class](https://cs50.harvard.edu/python/2022/notes/8/#classes)”. Suffice to say for now, it’s like a template for the application we’ll be building. The line `app = Flask(__name__)` tells Python to create a particular app, henceforth called “app”, from the template. To create the particular application, we give the `Flask` class the name of the current Python file (represented by `__name__`), which allows our application to find other files we might later add to it. In this case, the name of the file is also “app” for consistency.

The most mysterious line in the application you’ve written is probably the one where you wrote:

```
@app.route("/")
```

This kind of function is called a decorator. Decorators allow you to take a basic function, like `app.route`, and extend its functionality with something custom: the function you write after the decorator. You can [read more](https://realpython.com/primer-on-python-decorators/) about decorators if you want, or you can just keep using them for now.

This line tells Flask that if an HTTP request comes in for “/”, the `index` function should be run. Note that, if we renamed the function to be `homepage`, this line would tell Flask that—every time it receives an HTTP request for “/”—it should run the `homepage` function.

Notice that the `index` function returns a piece of text, “Hello, World!”. This text is what Flask will render to the user when their request to the “/” route is complete. The returned text could be (and often is!) the text of an entire HTML file, which the browser then renders accordingly. But it’s just a piece of text for now, for brevity’s sake.

To run your app, type `flask run` into the terminal, and you will get a link to click, similar to when you run `http-server`. You’ve written a Flask app!  Try returning different text, like `<h1>Hello, World!</h1>`. How does this change what you see?
