import os

from cs50 import SQL
from flask import Flask, flash, redirect, render_template, request, session
from flask_session import Session
from tempfile import mkdtemp
from werkzeug.security import check_password_hash, generate_password_hash
from datetime import datetime

from helpers import apology, login_required, lookup, usd

# Configure application
app = Flask(__name__)

# Custom filter
app.jinja_env.filters["usd"] = usd

# Configure session to use filesystem (instead of signed cookies)
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///finance.db")

# Make sure API key is set
if not os.environ.get("API_KEY"):
    raise RuntimeError("API_KEY not set")


@app.after_request
def after_request(response):
    """Ensure responses aren't cached"""
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response


@app.route("/")
@login_required
def index():
    """Show portfolio of stocks"""
    user_id = session.get("user_id")
    shares = db.execute(
        "SELECT symbol, SUM(quantity) as quantity FROM purchases WHERE user_id=? GROUP BY symbol", user_id)
    cash = db.execute("SELECT cash FROM users WHERE id=?", user_id)[
        0].get("cash")
    stocks = []
    total = 0
    for share in shares:
        quotes = lookup(share["symbol"])
        sum = int(share["quantity"])*quotes["price"]
        total += sum
        stocks.append({
            'symbol': share["symbol"],
            'company': quotes["name"],
            'quantity': share["quantity"],
            'price': quotes["price"],
            'sum': sum
        })

    return render_template("index.html", stocks=stocks, cash=cash, total=total)


@app.route("/buy", methods=["GET", "POST"])
@login_required
def buy():
    """Buy shares of stock"""
    if request.method == "POST":
        symbol = request.form.get("symbol")
        shares = request.form.get("shares")
        if shares.isdigit():
            shares = int(shares)
        else:
            shares = -1
        if not symbol or shares <= 0:
            return apology("Please provide a symbol and a number of shares (positive number)")
        quote = lookup(symbol)
        if quote:
            price = quote["price"]
            sum = price * shares
            if sum > 0:
                cash = db.execute("SELECT cash FROM users WHERE id=?", session.get("user_id"))[
                    0].get("cash")
                cash = cash - sum
                if cash >= 0:
                    db.execute("INSERT INTO purchases (user_id, date, symbol, quantity, price) VALUES (?, ?, ?, ?, ?)",
                               session.get("user_id"), datetime.now(), symbol, shares, price)
                    db.execute("UPDATE users SET cash=? WHERE id=?",
                               cash, session.get("user_id"))
                else:
                    return apology("Not enough cash")
            flash("Bought!")
            return redirect("/")
        else:
            return apology("Symbol not found")

    else:
        return render_template("buy.html")


@app.route("/history")
@login_required
def history():
    """Show history of transactions"""
    user_id = session.get("user_id")
    history = db.execute(
        "SELECT symbol, date, quantity, price, quantity*price as sum FROM purchases WHERE user_id=?", user_id)

    return render_template("history.html", history=history)


@app.route("/login", methods=["GET", "POST"])
def login():
    """Log user in"""

    # Forget any user_id
    session.clear()

    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":

        # Ensure username was submitted
        if not request.form.get("username"):
            return apology("must provide username", 403)

        # Ensure password was submitted
        elif not request.form.get("password"):
            return apology("must provide password", 403)

        # Query database for username
        rows = db.execute("SELECT * FROM users WHERE username = ?",
                          request.form.get("username"))

        # Ensure username exists and password is correct
        if len(rows) != 1 or not check_password_hash(rows[0]["hash"], request.form.get("password")):
            return apology("invalid username and/or password", 403)

        # Remember which user has logged in
        session["user_id"] = rows[0]["id"]

        # Redirect user to home page
        flash("Welcome!")
        return redirect("/")

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("login.html")


@app.route("/logout")
def logout():
    """Log user out"""

    # Forget any user_id
    session.clear()

    flash("See you!")
    # Redirect user to login form
    return redirect("/")


@app.route("/quote", methods=["GET", "POST"])
@login_required
def quote():
    """Get stock quote."""
    if request.method == "POST":
        symbol = request.form.get("symbol")
        if not symbol:
            return apology("Please provide a symbol")
        quote = lookup(symbol)
        if quote:
            return render_template("quoted.html", quote=quote)
        else:
            return apology("Symbol not found")
    else:
        return render_template("quote.html")


@app.route("/register", methods=["GET", "POST"])
def register():
    """Register user"""
    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":
        username = request.form.get("username")
        password = request.form.get("password")
        confirmation = request.form.get("confirmation")
        if not username or not password or password != confirmation:
            return apology("Please, provide username and password, passwords must match.")
        if db.execute("SELECT username FROM users WHERE username=?", username):
            return apology("Username already exist")
        id = db.execute("INSERT INTO users (username, hash) VALUES (?, ?)",
                        username, generate_password_hash(password))
        session["user_id"] = id
        flash("Registered!")
        return redirect("/")
    else:
        return render_template("register.html")


@app.route("/sell", methods=["GET", "POST"])
@login_required
def sell():
    """Sell shares of stock"""
    if request.method == "POST":
        symbol = request.form.get("symbol")
        shares = request.form.get("shares")
        if shares.isdigit():
            shares = int(shares)
        else:
            shares = -1
        if not symbol or shares <= 0:
            return apology("Please provide a symbol and a number of shares (positive number)")
        quote = lookup(symbol)
        if quote:
            price = quote["price"]
            sum = price * shares
            if sum > 0:
                user_id = session.get("user_id")
                quantity = db.execute("SELECT SUM(quantity) as quantity FROM purchases WHERE user_id=? AND symbol=?", user_id, symbol)[
                    0].get("quantity")
                quantity = quantity - shares
                if quantity >= 0:
                    cash = db.execute("SELECT cash FROM users WHERE id=?", user_id)[
                        0].get("cash")
                    db.execute("INSERT INTO purchases (user_id, date, symbol, quantity, price) VALUES (?, ?, ?, ?, ?)",
                               user_id, datetime.now(), symbol, -shares, price)
                    db.execute("UPDATE users SET cash=? WHERE id=?",
                               cash+sum, user_id)
                else:
                    return apology("Not enough shares")
            flash("Sold!")
            return redirect("/")
        else:
            return apology("Symbol not found")
    else:
        stocks = db.execute(
            "SELECT symbol, SUM(quantity) as quantity FROM purchases WHERE user_id=? GROUP BY symbol", session.get("user_id"))
        return render_template("sell.html", stocks=stocks)


@app.route("/pwdchange", methods=["GET", "POST"])
def pwdchange():
    """Change user's password"""
    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":
        password = request.form.get("password")
        confirmation = request.form.get("confirmation")
        if not password or password != confirmation:
            return apology("Please, provide password and confirmation, passwords must match.")
        current_password = request.form.get("current_password")
        user_id = session["user_id"]
        current_password_hash = db.execute(
            "SELECT hash FROM users WHERE id=?", user_id)[0].get("hash")
        if not check_password_hash(current_password_hash, current_password):
            return apology("Invalid current password")
        db.execute("UPDATE users SET hash=? WHERE id=?",
                   generate_password_hash(password), user_id)
        flash("Password changed!")
        return redirect("/")
    else:
        return render_template("pwdchange.html")


@app.route("/addcash", methods=["GET", "POST"])
def addcash():
    """Add specified amount of cash to the user's account"""
    if request.method == "POST":
        amount = request.form.get("amount")
        if amount.replace(".", "", 1).isdigit():
            amount = float(amount)
        else:
            amount = -1
        if amount <= 0:
            return apology("Invalid amount")
        user_id = session["user_id"]
        current_cash = db.execute("SELECT cash FROM users WHERE id=?", user_id)[
            0].get("cash")
        db.execute("UPDATE users SET cash=? WHERE id=?",
                   current_cash + amount, user_id)
        flash("Cash added succesfully!")
        return redirect("/")

    else:
        return render_template("addcash.html")
