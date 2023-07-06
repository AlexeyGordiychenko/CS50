from cs50 import SQL
import csv

db = SQL("sqlite:///roster.db")

with open("students.csv", "r") as file:
    houses = {}

    reader = csv.DictReader(file)
    for row in reader:
        house = row["house"]
        if house not in houses:
            houses[house] = db.execute(
                "INSERT INTO houses (house, head) VALUES (?, ?)", house, row["head"])

        db.execute("INSERT INTO students (id, student_name) VALUES (?, ?)",
                   row["id"], row["student_name"])
        db.execute("INSERT INTO assignments (student_id, house_id) VALUES (?, ?)",
                   row["id"], houses[house])
