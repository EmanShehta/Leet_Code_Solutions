
select a1.machine_id,Round(avg(a2.timestamp-a1.timestamp),3) as processing_time
from Activity a1
Inner join Activity a2 
on a1.machine_id=a2.machine_id
and a1.process_id =a2.process_id
AND a1.timestamp < a2.timestamp
GROUP BY  a1.machine_id

