# Write your MySQL query statement below
select employee_id ,
if(employee_id % 2 = 1 and name not Like "M%" , salary, 0) as bonus from employees 
ORDER BY employee_id;