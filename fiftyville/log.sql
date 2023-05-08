-- sqlite3 fiftyville.db
-- .headers on
-- .mode column
-- ^ This will format the output of your queries as columns, which is also easier to read.

-- Keep a log of any SQL queries you execute as you solve the mystery.

-- Retrieve the names of all tables in the database
SELECT name FROM sqlite_master WHERE type='table';

-- Get the interview transcripts:
SELECT name, transcript
  FROM interviews
 WHERE year = 2021
   AND month = 7
   AND day = 28;

-- The only witnesses whose statements make any sense are Ruth's, Eugene's and Raymond's
-- Ruth: "Check the parking lot footage. The thief got into a car there"
-- Eugene: "I saw the thief withdraw money at the ATM Leggett Street"
-- Raymond: "The thief talked to an accomplice on the phone and told them to buy flight tickets for the next day"

-- Get a list of transactions at the ATM
SELECT *
FROM atm_transactions
WHERE year = 2021 AND month = 7 AND day = 28 AND atm_location = 'Leggett Street';

-- Find person IDs associated with the account numbers from ATM transactions on Leggett Street on July 28, 2021
SELECT *
FROM bank_accounts
WHERE account_number IN (28500762, 28296815, 76054385, 49610011, 16153065, 86363979, 25506511, 81061156, 26013199);

-- Find people associated with the person IDs from the previous query
SELECT *
FROM people
WHERE id IN (person_s _id); -- Replace 'person_s_id' with the actual person IDs you got from the previous query

--id      name   phone_number    passport_number  license_plate
--------  -----  --------------  ---------------  -------------
--686048  Bruce   (367) 555-5533  5773159633       94KL13X
--948985  Kaelyn  (098) 555-1164  8304650265       I449449
--514354  Diana   (770) 555-1861  3592750733       322W7JE
--458378  Brooke  (122) 555-4581  4408372428       QX4YZN3
--395717  Kenny   (826) 555-1652  9878712108       30G67EN
--396669  Iman    (829) 555-5269  7049073643       L93JTIZ
--467400  Luca    (389) 555-5198  8496433585       4328GD8
--449774  Taylor  (286) 555-6063  1988161715       1106N58

-- Find phone calls made on July 28, 2021, where the callee bought flight tickets for the next day
SELECT *
FROM phone_calls
WHERE date = '2021-07-28' AND content LIKE '%buy flight tickets for the next day%';

-- Find phone calls made by potential suspects on July 28, 2021
SELECT *
FROM phone_calls
WHERE year = 2021 AND month = 7 AND day = 28 AND caller IN ('(367) 555-5533', '(098) 555-1164', '(770) 555-1861', '(122) 555-4581', '(826) 555-1652', '(829) 555-5269', '(389) 555-5198', '(286) 555-6063');

--id   caller          receiver        year  month  day  duration
-----  --------------  --------------  ----  -----  ---  --------
--233  (367) 555-5533  (375) 555-8161  2021  7      28   45
--236  (367) 555-5533  (344) 555-9601  2021  7      28   120
--245  (367) 555-5533  (022) 555-4052  2021  7      28   241
--254  (286) 555-6063  (676) 555-6554  2021  7      28   43
--255  (770) 555-1861  (725) 555-3243  2021  7      28   49
--268  (122) 555-4581  (831) 555-0973  2021  7      28   491
--279  (826) 555-1652  (066) 555-9701  2021  7      28   55
--284  (286) 555-6063  (310) 555-8568  2021  7      28   235
--285  (367) 555-5533  (704) 555-5790  2021  7      28   75

-- Find flights on July 29, 2021
SELECT *
FROM flights
WHERE year = 2021 AND month = 7 AND day = 29;

--id  origin_airport_id  destination_airport_id  year  month  day  hour  minute
--  -----------------  ----------------------  ----  -----  ---  ----  ------
--18  8                  6                       2021  7      29   16    0
--23  8                  11                      2021  7      29   12    15
--36  8                  4                       2021  7      29   8     20
--43  8                  1                       2021  7      29   9     30
--53  8                  9                       2021  7      29   15    20

-- Find passengers with matching passport numbers from the potential suspects
SELECT *
FROM passengers
WHERE passport_number IN (5773159633, 8304650265, 3592750733, 4408372428, 9878712108, 7049073643, 8496433585, 1988161715);

--flight_id  passport_number  seat
-----------  ---------------  ----
--11         8496433585       5D
--17         4408372428       9D
--18         3592750733       4C
--20         4408372428       2D
--24         3592750733       2C
--26         7049073643       2C
--36         5773159633       4A
--36         1988161715       6D
--36         9878712108       7A
--36         8496433585       7B
--48         8496433585       7C
--53         4408372428       3D
--54         3592750733       6C

--By cross-referencing the phone calls made by the suspects on July 28, 2021, it seems that Bruce (phone number (367) 555-5533) called (022) 555-4052,
--which matches the witness's description of the thief talking to an accomplice to buy flight tickets for the next day.

-- Find who is the owner of the number Bruce called the day of the theft
SELECT *
FROM people
WHERE phone_number = '(022) 555-4052';

-- Gregory SEEMS to be the accomplice
--315221  Gregory  (022) 555-4052  3355598951       V4C670D

-- Find the flight Bruce took
SELECT *
FROM passengers
WHERE passport_number = 5773159633
  AND flight_id IN (SELECT id FROM flights WHERE year = 2021 AND month = 7 AND day = 29);

--flight_id  passport_number  seat
-----------  ---------------  ----
--36         5773159633       4A

--Find what city Bruce fled to
SELECT *
FROM flights
WHERE id = 36;
-- Destination airport is number 4

--Get list of airports
SELECT *
FROM airports
WHERE id = 4;
--LaGuardia Airport, New York City

