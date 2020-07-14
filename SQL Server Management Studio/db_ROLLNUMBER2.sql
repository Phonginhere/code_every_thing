DROP DATABASE db_ROLLNUMBER
CREATE DATABASE db_ROLLNUMBER
USE db_ROLLNUMBER
CREATE TABLE [tblUser] (
	[UserID] int not null,
	[UserName] nvarchar(30)
)
CREATE TABLE [tblOrder] (
[OrderID] int not null,
[UserID] int not null,
OrderDate datetime
)
CREATE TABLE [tblProduct](
[ProductID] int not null,
[ProductName] nvarchar(50),
[Price] money
) 
CREATE TABLE [tblOrderDetail](
[OrderID] int not null,
[ProductID] int not null,
[Quantity] int,
[UnitPrice] money
)
DROP TABLE [tblOrder]
DROP TABLE IF EXISTS [tblUser] , [tblProduct], [tblOrderDetail]
ALTER TABLE tblUser
ADD PRIMARY KEY (UserID)
ALTER TABLE tblOrder
ADD PRIMARY KEY (OrderID)
ALTER TABLE tblProduct
ADD PRIMARY KEY (ProductID)
ALTER TABLE tblOrderDetail
ADD PRIMARY KEY (orderID, ProductID)

ALTER TABLE tblOrder
ADD CONSTRAINT FK_table
FOREIGN KEY (OrderID) REFERENCES tblUser(UserID);
ALTER TABLE tblOrderDetail
ADD CONSTRAINT FK_order_id
FOREIGN KEY (ProductID) REFERENCES tblProduct(ProductID);
alter table [tblOrder]
add constraint FK_table foreign key references [tblUser](UserID)
ALTER TABLE [tblOrderDetail]
ADD CONSTRAINT FK_product_id FOREIGN KEY (ProductID) REFERENCES [tblProduct];

ALTER TABLE tblOrder 
ADD CONSTRAINT CK_Subject_SessionCount
 CHECK (OrderDate between'2000-01-01' and getdate())

ALTER TABLE [tblUser]
ADD CONSTRAINT UC_user_name UNIQUE ([UserName]);

insert tblUser values(1, 'User1')
insert tblUser values(2, 'User2')
insert tblUser values(3, 'User3')
insert tblUser values(4, 'User4')
insert tblUser values(5, 'User5')
insert tblUser values(6, 'User6')

insert tblOrder values(1, 2, '2002-12-01')
insert tblOrder values(2, 3, '2000-03-02')
insert tblOrder values(3, 2, '2004-08-03')
insert tblOrder values(4, 1, '2001-05-12')
insert tblOrder values(5, 4, '2002-10-04')
insert tblOrder values(6, 6, '2002-03-08')
insert tblOrder values(7, 5, '2002-05-02')

insert tblProduct values(1, 'Product1', 10)
insert tblProduct values(2, 'Product2', 20)
insert tblProduct values(3, 'Product3', 300)
insert tblProduct values(4, 'Product4', 80)
insert tblProduct values(5, 'Product5', 120)

insert [tblOrderDetail] values(1, 1, 10, 10)
insert [tblOrderDetail] values(1, 2, 4, 20)
insert [tblOrderDetail] values(2, 3, 5, 50)
insert [tblOrderDetail] values(3, 3, 6, 80)
insert [tblOrderDetail] values(4, 2, 21, 120)
insert [tblOrderDetail] values(5, 2, 122, 300)

CREATE CLUSTERED INDEX userid ON dbo.tblUser(UserID)
CREATE CLUSTERED INDEX orderid ON dbo.tblOrder(OrderID)
CREATE CLUSTERED INDEX productid ON dbo.tblProduct(ProductID)

GO
CREATE VIEW vwTop2Product
as SELECT [ProductID], sum(Quantity) as 'TOng so ban ra'
FROM [tblProduct]

SELECT TOP 2 * FROM vwTop2Product
--9
GO
CREATE PROC sp_totalQuantity @userID INT
AS
BEGIN
	declare @totalQuantity INT 

	select @totalQuantity = sum(Quantity)
	from [tblOrderDetail]
	where OrderID = (select TOP 1 OrderID from tbl Order where UserID = @userID)

	print 'the total Quantity of order is'
	END

sp_totalQuantity 1
--10
CREATE VIEW	vw_User_Order 
AS
SELECT tblOrder.OrderID, tblUser.UserName, tblProduct.ProductName, tblOrder.OrderDate 
from tblOrder
join tblUser
on tblOrder.UserID = tblUser.UserID
join [tblOrderDetail]
on 
--11

go
create trigger [FOR_UPDATE_Product]
on [tblProduct]
for insert
AS
BEGIN
    declare @price INT

    select @price = [Price] from inserted    

    if(@price < 0)
    BEGIN
        print 'don‟t update price less than 10'
        rollback
    end
END

insert tblProduct values(5, 'Product6', 120)
insert tblProduct values(5, 'Product6', -120)
--13
go 
create trigger Vidu_DDL_trigger
on database 
for create_table 
as
begin 
print 'you have created database successfully'
rollback
end

create table phongdangcap(
ten nvarchar(30)
);
