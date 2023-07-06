SELECT
    title
FROM
    movies
WHERE
    id IN (
        SELECT
            both.movie_id
        FROM
            (
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
                                name = 'Johnny Depp'
                        )
                ) AS depp
                INNER JOIN (
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
                                name = 'Helena Bonham Carter'
                        )
                ) AS helena ON depp.movie_id = helena.movie_id
            ) AS both
    );