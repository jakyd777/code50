SELECT AVG(rating) AS AVG_rating_2012_movies FROM ratings
WHERE movie_id IN
(SELECT id FROM movies
WHERE year = 2012);