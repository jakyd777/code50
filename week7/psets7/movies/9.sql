SELECT DISTINCT name AS Stars_in_2004 FROM people
JOIN stars ON people.id = stars.person_id
JOIN movies ON movie_id = movies.id
WHERE year = 2004
ORDER BY birth;