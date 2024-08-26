# Write your MySQL query statement below
-- SELECT project_id, AVG(experience_years) as average_years
-- FROM Project 
-- LEFT JOIN Employee 
-- USING(employee_id)
-- GROUP BY project_id;
-- correct just needs to be rounded off

SELECT p.project_id, ROUND(AVG(e.experience_years),2) as average_years
FROM Project p
JOIN Employee e
ON p.employee_id=e.employee_id
GROUP BY p.project_id;