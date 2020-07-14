CREATE DATABASE ShopDB
USE ShopDB

CREATE TABLE tblProduct (
	prodID char(15) NOT NULL PRIMARY KEY,
	prodName nvarchar(50) NULL,
	prodPrice float NULL check (prodPrice>0)
)
CREATE TABLE tblCustomer(
	custID char(15) NOT NULL PRIMARY KEY,
	custName nvarchar(50) NOT NULL,
	Gender bit NULL DEFAULT '1',
	Address nvarchar(100) NULL,
	Telephone char(20) NOT NULL
)
CREATE TABLE tblSales (
	custID char(15) NOT NULL foreign key references tblCustomer(custID),
	prodID char(15) NOT NULL foreign key references tblProduct(prodID),
	saleDate datetime NOT NULL,
	quantity int NULL,
	PRIMARY KEY(custID, prodID, saleDate)
) 
--4

INSERT INTO tblProduct (prodID, prodName, prodPrice)
VALUES ('stock01', 'Thịt Lợn', '70000')
INSERT INTO tblProduct (prodID, prodName, prodPrice)
VALUES ('stock02', 'Thịt Chó', '55000')
INSERT INTO tblProduct (prodID, prodName, prodPrice)
VALUES ('stock03', 'Thịt Mèo', '50000')

INSERT INTO tblCustomer (custID, custName, Gender, Address, Telephone)
VALUES ('cust01', 'Nguyễn Thanh', '0', 'Hà Nội', '0166123456')
INSERT INTO tblCustomer (custID, custName, Gender, Address, Telephone)
VALUES ('cust02', 'Trần Trung', '1', 'Hà Nam', '0123456778')
INSERT INTO tblCustomer (custID, custName, Gender, Address, Telephone)
VALUES ('cust03', 'Lê Hằng', '0', 'Hải Phòng', '0912123456')

INSERT INTO tblSales (custID, prodID, saleDate, quantity)
VALUES ('cust01', 'stock01', '20200408 10:34:09 AM', '5')
INSERT INTO tblSales (custID, prodID, saleDate, quantity)
VALUES ('cust02', 'stock02', '20200406 12:50:12 PM', '6')
INSERT INTO tblSales (custID, prodID, saleDate, quantity)
VALUES ('cust03', 'stock03', '20200404 6:03:55 PM', '4')

--5
CREATE NONCLUSTERED INDEX IX_CustName ON tblCustomer(custName);

DROP INDEX IX_CustName ON tblCustomer;
--6
SELECT tblSales.custID AS 'Mã Khách Hàng', tblCustomer.custName AS 'Tên Khách Hàng', tblProduct.prodName AS 'Tên Hàng Hóa', tblSales.quantity AS 'Số lượng', tblProduct.prodPrice AS 'Đơn Giá', SUM(tblProduct.prodPrice * tblSales.quantity) AS 'Thành Tiền'
FROM tblSales
join tblCustomer
ON tblSales.custID = tblCustomer.custID
join tblProduct
ON tblSales.prodID = tblProduct.prodID
--WHERE tblCustomer.custName LIKE 'Trung'
GROUP BY tblSales.custID, tblCustomer.custName, tblProduct.prodName, tblSales.quantity, tblProduct.prodPrice HAVING custName like '%Trung%';


SELECT tblSales.custID AS 'Mã Khách Hàng', tblCustomer.custName AS 'Tên Khách Hàng', SUM(tblSales.quantity) AS 'Tổng Số Lượng' , SUM(tblProduct.prodPrice * tblSales.quantity) AS 'Tổng Tiền Trả'
FROM tblSales
join tblCustomer
ON tblSales.custID = tblCustomer.custID
join tblProduct
ON tblSales.prodID = tblProduct.prodID
GROUP BY tblSales.custID, tblCustomer.custName

select tblSales.custID, SUM(tblSales.quantity) AS 'Tổng số lượng'
from tblSales
	join tblCustomer
		on tblCustomer.custID = tblSales.custID
	join tblProduct
		on tblProduct.prodID = tblSales.custID
group by tblSales.custID, custName

SELECT TOP 1 tblSales.custID AS 'Mã Khách Hàng', tblCustomer.custName AS 'Tên Khách Hàng', tblProduct.prodName AS 'Tên Hàng Hóa', tblSales.quantity AS 'Số lượng', tblProduct.prodPrice,  tblProduct.prodPrice * tblSales.quantity AS 'Thành Tiền'
FROM tblSales
join tblCustomer
ON tblSales.custID = tblCustomer.custID
join tblProduct
ON tblSales.prodID = tblProduct.prodID
where tblCustomer.custID = (select top 1 custID from tblSales order by saleDate desc)
GROUP BY tblSales.custID, tblCustomer.custName, tblProduct.prodName, tblSales.quantity, tblProduct.prodPrice

-- 7
go
CREATE VIEW Inform 
AS 
SELECT tblSales.custID AS 'Mã Khách Hàng', tblCustomer.custName AS 'Tên Khách Hàng', tblProduct.prodName AS 'Tên Hàng Hóa', tblSales.quantity AS 'Số lượng', tblProduct.prodPrice AS 'Đơn Giá', SUM(tblProduct.prodPrice * tblSales.quantity) AS 'Thành Tiền'
FROM tblSales
join tblCustomer
ON tblSales.custID = tblCustomer.custID
join tblProduct
ON tblSales.prodID = tblProduct.prodID
GROUP BY tblSales.custID, tblCustomer.custName,  tblProduct.prodName, tblSales.quantity, tblProduct.prodPrice

SELECT * FROM Inform;

go
SELECT TOP 3 * FROM Inform
ORDER BY 'Tên Khách Hàng' DESC

EXEC sp_helptext 'Inform';



--8 
--cách 1
DROP PROC PriceIncrease
CREATE PROC PriceIncrease
AS
BEGIN 
 UPDATE tblProduct
 SET prodPrice = prodPrice + 100000	
 END
 
 PriceIncrease

 sp_helptext PriceIncrease

 --cách 2
 go
 create proc PriceIncrease @price float
 AS
 BEGIN 
	update tblProduct
	set prodPrice = prodPrice + 200000
END
 PriceIncrease 200000

 sp_helptext PriceIncrease
 --9
 go
alter trigger tg_Insert_Sales
 on tblSales
 for insert 
 AS
 BEGIN 
	declare @quant INT

	select @quant = quantity from inserted

	if @quant < 0 
	BEGIN
		print 'Quantity must be greater than 0'
		rollback -- cancel current operation
	END
END
SELECT * FROM tblProduct

alter table tblSales
drop constraint CK__tblSales__quanti__778AC167

insert tblSales values('cust03', 'stock03', '3/29/2011 12:00:00 AM', 6)
insert tblSales values('cust03', 'stock03', '3/28/2011 12:00:00 AM', -1)

--2 
go
create trigger UpdateValid
on tblProduct	
for Update
AS
BEGIN
	if update(prodPrice)
	BEGIN
		print 'U cant update value for prodPrice column'
		rollback
		END
	end

	UPDATE tblProduct
	set prodName = 'test'
	where prodID = 'prod01'

update tblProduct
set prodPrice = 9999
where prodID = 'prod01'

--10
drop database ShopDB
 drop proc PriceIcrease
DROP TABLE tblCustomer;
DROP TABLE tblProduct;
DROP TABLE tblSales;
DROP TABLE IF EXISTS tblCustomer, tblProduct, tblSales;

