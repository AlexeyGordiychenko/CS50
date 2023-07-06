import os

from cs50 import SQL
from flask import Flask, flash, jsonify, redirect, render_template, request, session

# Configure application
app = Flask(__name__)

# Ensure templates are auto-reloaded
app.config["TEMPLATES_AUTO_RELOAD"] = True

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///birthdays.db")


@app.after_request
def after_request(response):
    """Ensure responses aren't cached"""
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response


@app.route("/", methods=["GET", "POST"])
def index():
    if request.method == "POST":

        # TODO: Add the user's entry into the database
        name = request.form.get("name")
        month = int(request.form.get("month"))
        day = int(request.form.get("day"))
        if name and 1 <= month <= 12 and 1<= day <= 31:
            db.execute("INSERT INTO birthdays (name, month, day) VALUES (?, ?, ?)", name, month, day)
        return redirect("/")

    else:

        # TODO: Display the entries in the database on index.html
        rows = db.execute("SELECT * FROM birthdays")
        return render_template("index.html", birthdays=rows)

@app.route("/edit", methods=["POST"])
def edit():
    id = request.form.get("id")
    if id:
        action = request.form.get("action")
        if action == "Remove":
            db.execute("DELETE FROM birthdays WHERE id = ?", id)
        elif action == "Update":
            name = request.form.get("name")
            month, day = map(int, request.form.get("date").split('/'))
            if name and 1 <= month <= 12 and 1<= day <= 31:
                db.execute("UPDATE birthdays SET name=?, month=?, day=? WHERE id = ?", name, month, day, id)

    return redirect("/")


