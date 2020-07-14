/*
No of clause: 6 
select (before last)

*/
select SID, count(*) as 'No of orders'
from Orders
where SID > 1
group by SID

select SID, count(*) as 'No of orders'
from Orders
where SID > 1
group by SID
order by 'No of orders' asc

select SID, count(*) as 'No of orders'
from Orders
group by SID
having count(*) > 1

select top 1 SID, count(*) as 'No  of orders'
from Orders
group by SID
order by 'No of Orders' desc

select * from Suppliers
where SID = (
	select top 1 SID
	from Orders
	group by SID
	order by count(*) desc
)
