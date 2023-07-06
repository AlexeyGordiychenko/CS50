SELECT
    movies.title
FROM
    (
        SELECT
            movie_id
        FROM
            stars
        WHERE
            person_id = (
                SELECT
                    id
                FROM
                    people
                WHERE
                    name = 'Chadwick Boseman'
            )
    ) as boseman_movies
    LEFT JOIN ratings ON boseman_movies.movie_id = ratings.movie_id
    LEFT JOIN movies on boseman_movies.movie_id = movies.id
ORDER BY
    ratings.rating DESC
LIMIT
    5;