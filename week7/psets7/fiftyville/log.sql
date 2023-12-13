-- Keep a log of any SQL queries you execute as you solve the mystery.
-- All you know is that the theft took place on July 28, 2021
-- and that it took place on Humphrey Street.

-- Sometime within ten minutes of the theft, I saw the thief get into a car in the bakery parking lot and drive away. If you have security footage from the bakery parking lot, you might want to look for cars that left the parking lot in that time frame.

-- I don't know the thief's name, but it was someone I recognized. Earlier this morning, before I arrived at Emma's bakery, I was walking by the ATM on Leggett Street and saw the thief there withdrawing some money.

-- As the thief was leaving the bakery, they called someone who talked to them for less than a minute. In the call, I heard the thief say that they were planning to take the earliest flight out of Fiftyville tomorrow. The thief then asked the person on the other end of the phone to purchase the flight ticket.

-- Plate susp (within 15min after robery): 5P2BI95 - Vanessa 94KL13X - Bruce 6P58WS2 - Barry 4328GD8 - Luca G412CB7 - Sofia L93JTIZ - Iman 322W7JE - Diana 0NTHK55 - Kelsey


SELECT * FROM crime_scene_reports
WHERE year = '2021' AND month = '7' AND day = '28' AND street = 'Humphrey Street';

SELECT * FROM people
WHERE name = 'Bruce';

SELECT * FROM bakery_security_logs
WHERE year = '2021' AND month = '7' AND day = '28' AND hour = '10' AND minute >= 15 AND minute <= 30;

SELECT * FROM interviews
WHERE year = '2021' AND month = '7' AND day = '28';

SELECT name, license_plate from people
WHERE license_plate = '5P2BI95' OR  license_plate = '94KL13X' OR license_plate = '6P58WS2' OR license_plate = '4328GD8' OR license_plate = 'G412CB7' OR license_plate = 'L93JTIZ' OR license_plate = '322W7JE' OR license_plate = '0NTHK55';

SELECT * FROM atm_transactions
WHERE year = '2021' AND month = '7' AND day = '28' AND atm_location = 'Leggett Street';

SELECT * FROM phone_calls
WHERE year = '2021' AND month = '7' AND day = '28' AND duration < 60 AND caller = '(367) 555-5533';


SELECT * FROM people
JOIN passengers ON passengers.passport_number = people.passport_number
JOIN flights ON flights.id = passengers.flight_id
JOIN airports ON airports.id = flights.origin_airport_id
WHERE year = '2021' AND month = '7' AND day = '29'  AND hour < 12 AND hour > 0 AND city = 'Fiftyville';

-- Name of Thief
SELECT name AS Thief FROM people
JOIN bank_accounts ON bank_accounts.person_id = people.id
JOIN atm_transactions ON atm_transactions.account_number = bank_accounts.account_number
WHERE year = '2021' AND month = '7' AND day = '28' AND atm_location = 'Leggett Street'
AND license_plate IN
(SELECT license_plate FROM bakery_security_logs
WHERE year = '2021' AND month = '7' AND day = '28' AND hour = '10' AND minute >= 15 AND minute <= 30)
AND phone_number IN
(SELECT caller FROM phone_calls
WHERE year = '2021' AND month = '7' AND day = '28')
AND name IN
(SELECT name FROM people
JOIN passengers ON passengers.passport_number = people.passport_number
JOIN flights ON flights.id = passengers.flight_id
JOIN airports ON airports.id = flights.origin_airport_id
WHERE year = '2021' AND month = '7' AND day = '29'  AND hour < 12 AND hour > 0 AND city = 'Fiftyville');

-- Thiefs accomlice
SELECT name AS Thiefs_accomplice FROM people
JOIN phone_calls ON phone_calls.receiver = people.phone_number
WHERE phone_calls.caller = (SELECT phone_number FROM people
JOIN bank_accounts ON bank_accounts.person_id = people.id
JOIN atm_transactions ON atm_transactions.account_number = bank_accounts.account_number
WHERE year = '2021' AND month = '7' AND day = '28' AND atm_location = 'Leggett Street'
AND license_plate IN
(SELECT license_plate FROM bakery_security_logs
WHERE year = '2021' AND month = '7' AND day = '28' AND hour = '10' AND minute >= 15 AND minute <= 30)
AND phone_number IN
(SELECT caller FROM phone_calls
WHERE year = '2021' AND month = '7' AND day = '28')
AND name IN
(SELECT name FROM people
JOIN passengers ON passengers.passport_number = people.passport_number
JOIN flights ON flights.id = passengers.flight_id
JOIN airports ON airports.id = flights.origin_airport_id
WHERE year = '2021' AND month = '7' AND day = '29'  AND hour < 12 AND hour > 0 AND city = 'Fiftyville'))
AND year = '2021' AND month = '7' AND day = '28' AND duration < 60;

--Destination airport
SELECT city AS Destination_City FROM airports
JOIN flights ON flights.destination_airport_id = airports.id
JOIN passengers ON passengers.flight_id = flights.id
WHERE year = '2021' AND month = '7' AND day = '29'  AND hour < 12 AND hour > 0
AND passengers.passport_number = (SELECT passport_number FROM people
JOIN bank_accounts ON bank_accounts.person_id = people.id
JOIN atm_transactions ON atm_transactions.account_number = bank_accounts.account_number
WHERE year = '2021' AND month = '7' AND day = '28' AND atm_location = 'Leggett Street'
AND license_plate IN
(SELECT license_plate FROM bakery_security_logs
WHERE year = '2021' AND month = '7' AND day = '28' AND hour = '10' AND minute >= 15 AND minute <= 30)
AND phone_number IN
(SELECT caller FROM phone_calls
WHERE year = '2021' AND month = '7' AND day = '28')
AND name IN
(SELECT name FROM people
JOIN passengers ON passengers.passport_number = people.passport_number
JOIN flights ON flights.id = passengers.flight_id
JOIN airports ON airports.id = flights.origin_airport_id
WHERE year = '2021' AND month = '7' AND day = '29'  AND hour < 12 AND hour > 0 AND city = 'Fiftyville'));