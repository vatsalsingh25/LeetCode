# Write your MySQL query statement below
SELECT name, bonus
FROM Employee as a
LEFT JOIN Bonus as b
USING (empId)
WHERE bonus<1000 OR bonus IS NULL;