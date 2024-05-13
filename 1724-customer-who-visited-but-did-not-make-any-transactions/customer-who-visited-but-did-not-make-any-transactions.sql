# Write your MySQL query statement below
SELECT v.customer_id,COUNT(customer_id) as count_no_trans
FROM Visits v
Left join Transactions t
ON v.visit_id=t.visit_id
where transaction_id is NULL
GROUP BY customer_id
