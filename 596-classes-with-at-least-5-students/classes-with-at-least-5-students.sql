# Write your MySQL query statement below
-- select class from courses where (select count(student) >= 5 from courses group by class) order by class;

select class from (select class, count(student) as strength from courses group by class having strength >= 5) as class_wise_strength order by class;