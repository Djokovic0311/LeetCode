# Write your MySQL query statement below
SELECT DISTINCT num as ConsecutiveNums
FROM logs
WHERE (id + 1, num) IN (SELECT * FROM logs) AND (id + 2, num) IN (SELECT * FROM logs)