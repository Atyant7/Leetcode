# Write your MySQL query statement below
with ok as (select player_id, min(event_date) as first_login from activity group by player_id) select player_id, first_login from ok;