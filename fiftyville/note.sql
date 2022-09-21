SELECT description FROM crime_scene_reports
WHERE year = 2021
AND month = 7
AND day = 28
AND street = "Humphrey Street";
/*
Theft of the CS50 duck took place at 10:15am at the Humphrey Street bakery. Interviews were conducted today with three witnesses who were present at the time – each of their interview transcripts mentions the bakery.
*/

SELECT name, transcript FROM interviews WHERE year = 2021
AND month = 7
AND day = 28;
/*
+---------+---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
|  name   |                                                                                                                                                     transcript                                                                                                                                                      |
+---------+---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
| Jose    | “Ah,” said he, “I forgot that I had not seen you for some weeks. It is a little souvenir from the King of Bohemia in return for my assistance in the case of the Irene Adler papers.”                                                                                                                               |
| Eugene  | “I suppose,” said Holmes, “that when Mr. Windibank came back from France he was very annoyed at your having gone to the ball.”                                                                                                                                                                                      |
| Barbara | “You had my note?” he asked with a deep harsh voice and a strongly marked German accent. “I told you that I would call.” He looked from one to the other of us, as if uncertain which to address.                                                                                                                   |
| Ruth    | Sometime within ten minutes of the theft, I saw the thief get into a car in the bakery parking lot and drive away. If you have security footage from the bakery parking lot, you might want to look for cars that left the parking lot in that time frame.                                                          |
| Eugene  | I don't know the thief's name, but it was someone I recognized. Earlier this morning, before I arrived at Emma's bakery, I was walking by the ATM on Leggett Street and saw the thief there withdrawing some money.                                                                                                 |
| Raymond | As the thief was leaving the bakery, they called someone who talked to them for less than a minute. In the call, I heard the thief say that they were planning to take the earliest flight out of Fiftyville tomorrow. The thief then asked the person on the other end of the phone to purchase the flight ticket. |
| Lily    | Our neighboring courthouse has a very annoying rooster that crows loudly at 6am every day. My sons Robert and Patrick took the rooster to a city far, far away, so it may never bother us again. My sons have successfully arrived in Paris.                                                                        |
+---------+---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
*/

-- 10:15am

SELECT license_plate, activity, hour, minute
FROM bakery_security_logs
WHERE year = 2021
AND month = 7
AND day = 28
AND hour = 10
AND minute BETWEEN 15 AND 25;

-- +---------------+----------+------+--------+
-- | license_plate | activity | hour | minute |
-- +---------------+----------+------+--------+
-- | 5P2BI95       | exit     | 10   | 16     |
-- | 94KL13X       | exit     | 10   | 18     |
-- | 6P58WS2       | exit     | 10   | 18     |
-- | 4328GD8       | exit     | 10   | 19     |
-- | G412CB7       | exit     | 10   | 20     |
-- | L93JTIZ       | exit     | 10   | 21     |
-- | 322W7JE       | exit     | 10   | 23     |
-- | 0NTHK55       | exit     | 10   | 23     |
-- +---------------+----------+------+--------+

SELECT caller, receiver FROM phone_calls
WHERE year = 2021
AND month = 7
AND day = 28
AND duration <= 60;

-- +----------------+----------------+
-- |     caller     |    receiver    |
-- +----------------+----------------+
-- | (130) 555-0289 | (996) 555-8899 |
-- | (499) 555-9472 | (892) 555-8872 |
-- | (367) 555-5533 | (375) 555-8161 |
-- | (609) 555-5876 | (389) 555-5198 |
-- | (499) 555-9472 | (717) 555-1342 |
-- | (286) 555-6063 | (676) 555-6554 |
-- | (770) 555-1861 | (725) 555-3243 |
-- | (031) 555-6622 | (910) 555-3251 |
-- | (826) 555-1652 | (066) 555-9701 |
-- | (338) 555-6650 | (704) 555-2131 |
-- +----------------+----------------+

-- Leggett Street, withdrawing
SELECT account_number FROM atm_transactions
WHERE year = 2021
AND month = 7
AND day = 28
AND atm_location = "Leggett Street"
AND transaction_type = "withdraw";
/*
+----------------+
| account_number |
+----------------+
| 28500762       |
| 28296815       |
| 76054385       |
| 49610011       |
| 16153065       |
| 25506511       |
| 81061156       |
| 26013199       |
+----------------+
*/

SELECT id FROM people
WHERE license_plate IN(
    SELECT license_plate
    FROM bakery_security_logs
    WHERE year = 2021
    AND month = 7
    AND day = 28
    AND hour = 10
    AND minute BETWEEN 15 AND 25
);

-- +--------+
-- |   id   |
-- +--------+
-- | 221103 |
-- | 243696 |
-- | 396669 |
-- | 398010 |
-- | 467400 |
-- | 514354 |
-- | 560886 |
-- | 686048 |
-- +--------+

SELECT person_id FROM bank_accounts
WHERE account_number IN (
    SELECT account_number FROM atm_transactions
    WHERE year = 2021
    AND month = 7
    AND day = 28
    AND atm_location = "Leggett Street"
    AND transaction_type = "withdraw"
);

-- +-----------+
-- | person_id |
-- +-----------+
-- | 686048    |
-- | 514354    |
-- | 458378    |
-- | 395717    |
-- | 396669    |
-- | 467400    |
-- | 449774    |
-- | 438727    |
-- +-----------+