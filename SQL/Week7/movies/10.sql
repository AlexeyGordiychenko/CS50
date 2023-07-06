SELECT
    name
FROM
    people
WHERE
    id IN (
        SELECT
            person_id
        FROM
            directors
            INNER JOIN ratings ON directors.movie_id = ratings.movie_id
        WHERE
            ratings.rating >= 9
    )
GROUP BY
    id;