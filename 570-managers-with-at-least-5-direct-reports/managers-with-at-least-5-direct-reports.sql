# Write your MySQL query statement below
-- SELECT a.name
-- FROM Employee as a
-- JOIN Employee as b
-- ON a.id=b.managerId
-- GROUP BY b.managerId
-- HAVING COUNT(b.managerID)>=5

SELECT name 
FROM Employee 
WHERE id IN (
    SELECT managerId 
    FROM Employee 
    GROUP BY managerId 
    HAVING COUNT(*) >= 5)