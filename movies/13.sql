SELECT DISTINCT(name) FROM people, stars
WHERE stars.movie_id IN(SELECT stars.movie_id FROM stars, people WHERE name = "Kevin Bacon" AND birth = 1958 AND people.id = stars.person_id)
AND stars.person_id = people.id
AND name != "Kevin Bacon";