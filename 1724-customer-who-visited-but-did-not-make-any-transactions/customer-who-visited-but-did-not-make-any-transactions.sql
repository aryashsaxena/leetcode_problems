# Write your MySQL query statement below

select c.customer_id , count(c.visit_id) as count_no_trans from visits as c where c.visit_id not in (select visit_id from transactions) group by c.customer_id