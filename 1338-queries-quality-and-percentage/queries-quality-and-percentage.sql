# Write your MySQL query statement below
-- SELECT query_name, AVG(rating/position) as quality,
-- FROM Queries
-- GROUP BY query_name 

SELECT query_name , ROUND(AVG(rating/position),2) as quality, ROUND(SUM(rating<3)*100/COUNT(query_name),2) as poor_query_percentage
FROM Queries
WHERE query_name is not null
GROUP BY query_name

-- if we use COUNT(rating<3)  "rating<3" returns boolean value 0 or 1 and count also takes 0 as a value...but SUM<3 only adds conditions that are satistied