-- write a SQL query to list the titles of the five highest rated movies (in order) that Chadwick Boseman starred in, 
-- starting with the highest rated.

-- SELECT title FROM movies WHERE id IN
-- (SELECT movie_id FROM ratings WHERE movie_id IN
-- (SELECT movie_id FROM stars WHERE person_id = (SELECT id FROM people WHERE name = "Chadwick Boseman"))
-- ORDER BY rating
-- LIMIT 5);
SELECT movies.title 
FROM people
JOIN stars ON people.id = stars.person_id
JOIN ratings ON stars.movie_id = ratings.movie_id
JOIN movies ON movies.id = ratings.movie_id
WHERE people.name = "Chadwick Boseman"
ORDER BY rating DESC
LIMIT 5;
