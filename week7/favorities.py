import csv

from cs50 import SQL

db = SQL("sqlite:///shows.db")

rows = db.execute("SELECT title FROM shows WHERE id IN (SELECT show_id FROM stars WHERE person_id = (SELECT id FROM people WHERE name = 'Steve Carell'))")

for i in range(len(rows)):
    print(rows[i])

