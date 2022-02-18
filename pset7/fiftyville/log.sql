-- Keep a log of any SQL queries you execute as you solve the mystery.

-- Who the thief is,
-- What city the thief escaped to
-- Who the thief’s accomplice is who helped them escape

-- the theft took place on July 28, 2020 and that it took place on Chamberlin Street.
------------------------------------------------------------------------------------------------
-- Note1:use crime_scene_reports to find the description and id
SELECT id, description FROM crime_scene_reports
WHERE year = 2020 AND month = 7 AND day = 28 AND street = "Chamberlin Street";

--  id = 295
--  description = Theft of the CS50 duck took place at 10:15am at the Chamberlin Street courthouse. 
--  Interviews were conducted today with three witnesses who were present at the time — each of their 
--  interview transcripts mentions the courthouse.

-- Note2:use interviews find the witnesses transcripts
SELECT id, name, transcript FROM interviews 
WHERE year = 2020 AND month = 7 AND day = 28 AND transcript LIKE "%courthouse%";

-- 161 | Ruth | Sometime within ten minutes of the theft, I saw the thief get into a car in the courthouse parking lot 
-- and drive away. If you have security footage from the courthouse parking lot, you might want to look for cars that 
-- left the parking lot in that time frame.
-- 162 | Eugene | I don't know the thief's name, but it was someone I recognized. Earlier this morning, before I arrived 
-- at the courthouse, I was walking by the ATM on Fifer Street and saw the thief there withdrawing some money.
-- 163 | Raymond | As the thief was leaving the courthouse, they called someone who talked to them for less than a minute. 
-- In the call, I heard the thief say that they were planning to take the earliest flight out of Fiftyville tomorrow. The 
-- thief then asked the person on the other end of the phone to purchase the flight ticket.

-- Note3: use courthouse_security_logs (161) / atm_transactions (162) / flights(163)
SELECT id, activity, license_plate FROM courthouse_security_logs 
WHERE year = 2020 AND month = 7 AND day = 28 AND hour = 10;

SELECT account_number FROM atm_transactions
WHERE year = 2020 AND month = 7 AND day = 28 AND atm_location = "Fifer Street" AND transaction_type ="withdraw";

-- find the airports.id for Fiftyville ( id = 8 )
SELECT id FROM airports WHERE city = "Fiftyville";
-- find the earliest flight out of id = 8 from flights (id = 36 / destination_airport_id = 4 / hour = 8 / minute = 20)
SELECT id, destination_airport_id, hour, minute FROM flights
WHERE year = 2020 AND month = 7 AND day = 29 AND origin_airport_id = 8
ORDER BY hour ASC;

-- find the escaped city (destination_airport_id = 4)
SELECT city FROM airports WHERE id = 4;

-- NOTE4: ( bank_accounts cross atm_transactions to find person_id ) 
--        ( courthouse_security_logs cross people to fin person_id)
--        person_id be matched 
-- id | name
-- 686048 | Ernest
-- 514354 | Russell
-- 396669 | Elizabeth
-- 467400 | Danielle
-- 449774 | Madison

with bank as (
    SELECT people.id, people.name FROM people
    JOIN bank_accounts ON people.id = bank_accounts.person_id
    JOIN atm_transactions ON bank_accounts.account_number = atm_transactions.account_number
    WHERE atm_transactions.year = 2020 AND atm_transactions.month = 7 AND atm_transactions.day = 28 
    AND atm_transactions.atm_location = "Fifer Street" AND atm_transactions.transaction_type ="withdraw"),
courthouse as(
    SELECT people.id, people.name FROM people
    JOIN courthouse_security_logs ON people.license_plate = courthouse_security_logs.license_plate
    WHERE year = 2020 AND month = 7 AND day = 28 AND hour = 10)
select b.id, b.name
from bank b
join courthouse c on b.id = c.id;

-- NOTE5 : (passengers cross people use passport_number to find id and name)
-- id | name
-- 953679 | Doris
-- 398010 | Roger
-- 686048 | Ernest
-- 651714 | Edward
-- 560886 | Evelyn
-- 449774 | Madison
-- 395717 | Bobby
-- 467400 | Danielle

SELECT people.id, people.name FROM people
JOIN passengers ON people.passport_number = passengers.passport_number 
WHERE flight_id = 36;

-- NOTE6 : find the thief’s accomplice (thief_id = 449774 | Madison or 686048 | Ernest)
SELECT phone_number FROM people WHERE id = 449774 OR id = 686048; -- phone_number (286) 555-6063 / (367) 555-5533

SELECT people.name, people.id FROM people
JOIN phone_calls ON people.phone_number = phone_calls.receiver
WHERE phone_calls.caller = "(286) 555-6063" AND phone_calls.year = 2020 AND month = 7
AND day = 28;

SELECT duration, caller, receiver FROM phone_calls
WHERE caller = "(286) 555-6063" OR caller = "(367) 555-5533" AND year = 2020 
AND month = 7 AND day = 28
ORDER BY duration ASC;

SELECT name FROM people WHERE phone_number = "(375) 555-8161";
------------------------------------------------------------------------------
SELECT a.id, a.name, a.phone_number, a.passport_number, a.license_plate,
b.year, b.month, b.day, b.hour, b.minute, b.activity,
c.account_number, d.flight_id, d.seat
FROM people a
JOIN courthouse_security_logs b ON a.license_plate = b.license_plate
JOIN bank_accounts c ON a.id = c.person_id
JOIN passengers d ON a.passport_number = d.passport_number
WHERE a.id = 449774 OR a.id = 686048
AND b.year = 2020 AND b.month = 7 AND b.day = 28;

-- id | name | phone_number | passport_number | license_plate | year | month | day | hour | minute | activity | account_number | flight_id | seat
-- 449774 | Madison | (286) 555-6063 | 1988161715 | 1106N58 | 2020 | 7 | 28 | 8 | 34 | entrance | 76054385 | 36 | 6D
-- 449774 | Madison | (286) 555-6063 | 1988161715 | 1106N58 | 2020 | 7 | 28 | 10 | 35 | exit | 76054385 | 36 | 6D
-- 686048 | Ernest | (367) 555-5533 | 5773159633 | 94KL13X | 2020 | 7 | 28 | 8 | 23 | entrance | 49610011 | 36 | 4A
-- 686048 | Ernest | (367) 555-5533 | 5773159633 | 94KL13X | 2020 | 7 | 28 | 10 | 18 | exit | 49610011 | 36 | 4A

