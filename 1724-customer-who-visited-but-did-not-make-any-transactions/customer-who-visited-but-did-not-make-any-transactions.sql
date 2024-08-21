# Write your MySQL query statement below
-- SELECT Visits.visit_id,costumer_id
-- FROM Visits as a
-- LEFT JOIN Transactions as b
-- USING(visit_id)
-- WHERE b.visit_id IS NULL;

SELECT customer_id, COUNT(visit_id) AS count_no_trans
FROM (  SELECT visit_id,customer_id
        FROM Visits AS a
        LEFT JOIN Transactions as b
        USING(visit_id)
        WHERE b.visit_id IS NULL) AS no_transaction
GROUP BY customer_id;

