--Create DATABASE sqlbaichua;
Use sqlbaichua;
create table Suppliers(
[SID] int,
Sname nvarchar(100),
[Address] nvarchar(100)
)

drop table Suppliers

create table Products(
	PID int,
	Pname nvarchar(100)	
)

create table Orders (
	SID int,
	PID int,
	Price int
)

alter table Orders
alter column Price float

alter table Suppliers
add Phone varchar(20)

insert Suppliers values (1, 'Hải Hà', 'Hà Nội', '11111111')
insert Suppliers values (2, 'Kinh Đô', 'Hồ Chí Minh', '2222222')

insert Orders values (1, 1, 100)
insert Orders values (1, 2, 150)
insert Orders values (1, 3, 200)
insert Orders values (2, 1, 120)
insert Orders values (3, 3, 150)

select  Sname as 'Name', Address, Phone from Suppliers