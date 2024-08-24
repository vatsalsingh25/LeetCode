# Write your MySQL query statement below
SELECT a.name
FROM Employee as a
JOIN Employee as b
ON a.id=b.managerId
GROUP BY b.managerId
HAVING COUNT(b.managerID)>=5