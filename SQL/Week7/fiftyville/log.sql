-- Keep a log of any SQL queries you execute as you solve the mystery.
-- check crime reports of the time of the theft
SELECT
    *
FROM
    crime_scene_reports
WHERE
    year = 2021
    AND month = 7
    AND day = 28
    AND street = 'Humphrey Street';

--check the conducted interviews: a transcript mentions bakery, conducted on the same day as the theft
SELECT
    *
FROM
    interviews
WHERE
    year = 2021
    AND month = 7
    AND day = 28
    AND transcript LIKE '%bakery%';

-- check clues from the first interview: camera footage at the time within 10 minutes of the theft
SELECT
    *
FROM
    bakery_security_logs
WHERE
    year = 2021
    AND month = 7
    AND day = 28
    AND hour = 10
    AND minute >= 15
    AND minute <= 25;

-- check clues from the second interview: withdrawing money from the ATM at Leggett Street
SELECT
    *
FROM
    people
WHERE
    id in (
        SELECT
            person_id
        FROM
            bank_accounts
        WHERE
            account_number IN (
                SELECT
                    account_number
                FROM
                    atm_transactions
                WHERE
                    atm_location = 'Leggett Street'
                    AND transaction_type = 'withdraw'
                    AND year = 2021
                    AND month = 7
                    AND day = 28
            )
    );

-- both tables from first and second interview contain a licence plate, we can use only rows with the same plate
SELECT
    *
FROM
    people
WHERE
    id in (
        SELECT
            person_id
        FROM
            bank_accounts
        WHERE
            account_number IN (
                SELECT
                    account_number
                FROM
                    atm_transactions
                WHERE
                    atm_location = 'Leggett Street'
                    AND transaction_type = 'withdraw'
                    AND year = 2021
                    AND month = 7
                    AND day = 28
            )
    )
    AND license_plate IN (
        SELECT
            license_plate
        FROM
            bakery_security_logs
        WHERE
            year = 2021
            AND month = 7
            AND day = 28
            AND hour = 10
            AND minute >= 15
            AND minute <= 25
    );

-- check clues from the third interview: call less than a minute
SELECT
    *
FROM
    phone_calls
WHERE
    year = 2021
    AND month = 7
    AND day = 28
    AND duration <= 60;

-- we can use only phones that we've got from the previous table
SELECT
    *
FROM
    phone_calls
WHERE
    year = 2021
    AND month = 7
    AND day = 28
    AND duration <= 60
    AND caller IN (
        SELECT
            phone_number
        FROM
            people
        WHERE
            id in (
                SELECT
                    person_id
                FROM
                    bank_accounts
                WHERE
                    account_number IN (
                        SELECT
                            account_number
                        FROM
                            atm_transactions
                        WHERE
                            atm_location = 'Leggett Street'
                            AND transaction_type = 'withdraw'
                            AND year = 2021
                            AND month = 7
                            AND day = 28
                    )
            )
            AND license_plate IN (
                SELECT
                    license_plate
                FROM
                    bakery_security_logs
                WHERE
                    year = 2021
                    AND month = 7
                    AND day = 28
                    AND hour = 10
                    AND minute >= 15
                    AND minute <= 25
            )
    );

-- check clues from the third interview: earliest flight tomorrow from Fiftyville
SELECT
    *
FROM
    flights
WHERE
    origin_airport_id IN (
        SELECT
            id
        FROM
            airports
        WHERE
            city = 'Fiftyville'
    )
    AND year = 2021
    AND month = 7
    AND day = 29
ORDER BY
    hour,
    minute
LIMIT
    1;

-- check who the passengers of the flight
SELECT
    *
FROM
    passengers
WHERE
    flight_id IN (
        SELECT
            id
        FROM
            flights
        WHERE
            origin_airport_id IN (
                SELECT
                    id
                FROM
                    airports
                WHERE
                    city = 'Fiftyville'
            )
            AND year = 2021
            AND month = 7
            AND day = 29
        ORDER BY
            hour,
            minute
        LIMIT
            1
    );

-- final query: intersect between  passports of suspects and passengers of the flight
-- additional info: flight destination and accomplice's name by the reciever's phone number
SELECT
    thief_and_partner.name AS thief,
    people.name AS accomplice,
    airports.city AS destination
FROM
    (
        SELECT
            flight_id,
            passport_number
        FROM
            passengers
        WHERE
            flight_id IN (
                SELECT
                    id
                FROM
                    flights
                WHERE
                    origin_airport_id IN (
                        SELECT
                            id
                        FROM
                            airports
                        WHERE
                            city = 'Fiftyville'
                    )
                    AND year = 2021
                    AND month = 7
                    AND day = 29
                ORDER BY
                    hour,
                    minute
                LIMIT
                    1
            )
    ) AS flight
    INNER JOIN (
        SELECT
            suspects.name,
            suspects.passport_number,
            phone_call.receiver
        FROM
            (
                SELECT
                    caller,
                    receiver
                FROM
                    phone_calls
                WHERE
                    year = 2021
                    AND month = 7
                    AND day = 28
                    AND duration <= 60
            ) AS phone_call
            INNER JOIN (
                SELECT
                    name,
                    phone_number,
                    passport_number
                FROM
                    people
                WHERE
                    id in (
                        SELECT
                            person_id
                        FROM
                            bank_accounts
                        WHERE
                            account_number IN (
                                SELECT
                                    account_number
                                FROM
                                    atm_transactions
                                WHERE
                                    atm_location = 'Leggett Street'
                                    AND transaction_type = 'withdraw'
                                    AND year = 2021
                                    AND month = 7
                                    AND day = 28
                            )
                    )
                    AND license_plate IN (
                        SELECT
                            license_plate
                        FROM
                            bakery_security_logs
                        WHERE
                            year = 2021
                            AND month = 7
                            AND day = 28
                            AND hour = 10
                            AND minute >= 15
                            AND minute <= 25
                    )
            ) AS suspects ON phone_call.caller = suspects.phone_number
    ) AS thief_and_partner ON flight.passport_number = thief_and_partner.passport_number
    LEFT JOIN flights ON flight.flight_id = flights.id
    LEFT JOIN airports ON flights.destination_airport_id = airports.id
    LEFT JOIN people ON thief_and_partner.receiver = people.phone_number;