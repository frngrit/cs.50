SELECT AVG(rating) FROM ratings, movies
WHERE movies.year = 2012
AND movies.id = ratings.movie_id;