
-- query to extract all values with no relatoins in second table(left join-b values)

-- SELECT Visits.visit_id,costumer_id
-- FROM Visits as a
-- LEFT JOIN Transactions as b
-- USING(visit_id)
-- WHERE b.visit_id IS NULL;

-- query to calculate the count and group by value(embed inside the from statement)

SELECT customer_id, COUNT(visit_id) AS count_no_trans
FROM (  SELECT visit_id,customer_id
        FROM Visits AS a
        LEFT JOIN Transactions as b
        USING(visit_id)
        WHERE b.visit_id IS NULL) AS no_transaction
GROUP BY customer_id;

