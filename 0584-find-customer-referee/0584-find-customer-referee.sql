# Write your MySQL query statement below
select name 
from Customer
where COALESCE(REFEREE_ID,0)!=2;

