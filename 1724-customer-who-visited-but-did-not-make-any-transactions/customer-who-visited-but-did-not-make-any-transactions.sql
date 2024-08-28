SELECT customer_id, COUNT(*) AS count_no_trans
FROM Visits as a 
LEFT JOIN Transactions as b
USING(visit_id)
WHERE b.visit_id IS NULL
GROUP BY customer_id;

