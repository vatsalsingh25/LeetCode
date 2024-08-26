# Write your MySQL query statement below
-- SELECT project_id, AVG(experience_years) as average_years
-- FROM Project 
-- LEFT JOIN Employee 
-- USING(employee_id)
-- GROUP BY project_id;
-- correct just needs to be rounded off

SELECT project_id, ROUND(AVG(experience_years),2) as average_years
FROM Project 
LEFT JOIN Employee 
USING(employee_id)
GROUP BY project_id;