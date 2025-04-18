# Write your MySQL query statement below
select a.machine_id,  ROUND(AVG(b.timestamp-a.timestamp),3) AS processing_time
from activity as a
join activity as b 
on a.machine_id = b.machine_id 
where a.activity_type="start" and b.activity_type="end"
group by machine_id 

