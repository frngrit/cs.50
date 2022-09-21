SELECT title FROM movies, ratings, stars, people
WHERE people.name = "Chadwick Boseman"
AND people.id = stars.person_id
AND stars.movie_id = ratings.movie_id
AND movies.id = ratings.movie_id
ORDER BY rating DESC
LIMIT 5;