-- write a SQL query to list the names of all people who starred in a movie in which Kevin Bacon also starred.

SELECT DISTINCT name FROM people WHERE id IN
(SELECT person_id FROM stars WHERE movie_id IN
(SELECT movie_id FROM stars WHERE person_id = (SELECT id FROM people WHERE  name ="Kevin Bacon" AND  birth = 1958)))
AND name !="Kevin Bacon";


-- with base as (
--     SELECT movie_id
--     FROM people a
--     JOIN stars b ON a.id = b.person_id
--     where name = "Kevin Bacon" and birth = 1958
-- ),
-- person as (
--     SELECT DISTINCT(person_id)
--     FROM stars a
--     WHERE movie_id in (SELECT * FROM base))
-- select count(name)
-- from people a
-- join person b on a.id = b.person_id
-- where name != "Kevin Bacon";