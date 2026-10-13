# Write your MySQL query statement below
-- select (select distinct salary from employee order by salary DESC limit 1 offset 1) as SecondHighestSalary;

-- select dense_rank() over (order by salary) as "SecondHighestSalary" from employee limit 1 offset 1;
WITH cte AS (
    SELECT salary,
           DENSE_RANK() OVER (ORDER BY salary DESC) AS `rank`
    FROM employee
)
SELECT (
    SELECT DISTINCT salary
    FROM cte
    WHERE `rank` = 2
) AS SecondHighestSalary;