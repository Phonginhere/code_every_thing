CREATE DATABASE QLSanPham
USE QLSanPham
--bai 1
CREATE TABLE Customers(
	MaKhach char(5),
	TenKhach nvarchar(50),
	DienThoai int
)
CREATE TABLE Items (
	MaHang char(3),
	TenHang nvarchar(30), 
	DonGia int
)
CREATE TABLE CustomerItems(
	MaKhach char(5), 
	MaHang char (3),
	DonGia int,
	SoLuong int
)

--bai 2
INSERT INTO Customers (MaKhach, TenKhach, DienThoai)
VALUES ('KH001', 'Đinh Trường Sơn', '0975278196')
INSERT INTO Customers (MaKhach, TenKhach, DienThoai)
VALUES ('KH002', 'Mai Thanh Minh', '0974878123')
INSERT INTO Customers (MaKhach, TenKhach, DienThoai)
VALUES ('KH003', 'Nguyễn Hồng Hà', '0975278729')
INSERT INTO Customers (MaKhach, TenKhach, DienThoai)
VALUES ('KH004', 'Hoàng Trung Dũng', '0972278124')
INSERT INTO Customers (MaKhach, TenKhach, DienThoai)
VALUES ('KH005', 'Bùi Minh Ngọc', '0917650718')

INSERT INTO Items (MaHang, TenHang, DonGia)
VALUES ('H01', 'Tủ Lạnh', '3500000')
INSERT INTO Items (MaHang, TenHang, DonGia)
VALUES ('H02', 'Tivi', '2500000')
INSERT INTO Items (MaHang, TenHang, DonGia)
VALUES ('H03', 'Điều hòa', '5000000')
INSERT INTO Items (MaHang, TenHang, DonGia)
VALUES ('H04', 'Quạt Đá', '500000')
INSERT INTO Items (MaHang, TenHang, DonGia)
VALUES ('H05', 'Máy Giặt', '4500000')

INSERT INTO CustomerItems(MaKhach, MaHang, DonGia, SoLuong)
VALUES ('KH001', 'H01', '3500000', '4')
INSERT INTO CustomerItems(MaKhach, MaHang, DonGia, SoLuong)
VALUES ('KH001', 'H02', '2500000', '5')
INSERT INTO CustomerItems(MaKhach, MaHang, DonGia, SoLuong)
VALUES ('KH002', 'H01', '3000000', '1')
INSERT INTO CustomerItems(MaKhach, MaHang, DonGia, SoLuong)
VALUES ('KH002', 'H02', '2500000', '8')
INSERT INTO CustomerItems(MaKhach, MaHang, DonGia, SoLuong)
VALUES ('KH003', 'H02', '2600000', '2')
INSERT INTO CustomerItems(MaKhach, MaHang, DonGia, SoLuong)
VALUES ('KH003', 'H03', '5000000', '4')
INSERT INTO CustomerItems(MaKhach, MaHang, DonGia, SoLuong)
VALUES ('KH004', 'H01', '3500000', '2')
INSERT INTO CustomerItems(MaKhach, MaHang, DonGia, SoLuong)
VALUES ('KH004', 'H03', '500000', '3')
INSERT INTO CustomerItems(MaKhach, MaHang, DonGia, SoLuong)
VALUES ('KH005', 'H04', '2000000', '4')
INSERT INTO CustomerItems(MaKhach, MaHang, DonGia, SoLuong)
VALUES ('KH005', 'H05', '5000000', '4')

--bai 3
--bai 3.1
SELECT SUM(DonGia) AS "Tong tien"
FROM Items
SELECT SUM(DonGia) AS "Tong tien"
FROM CustomerItems
--bai3.2
SELECT * FROM CustomerItems
ORDER BY SoLuong DESC

SELECT TenHang FROM Items;
--bai 3.3
SELECT  top 25 percent *
FROM CustomerItems
 ORDER BY SoLuong DESC
 --bai 3.4
SELECT * FROM CustomerItems
WHERE SoLuong < 1
--3.5

SELECT CustomerItems.MaKhach,Customers.MaKhach,Customers.TenKhach, COUNT(*)as'n hon 1 hàng'
FROM CustomerItems 
INNER JOIN Customers 
ON CustomerItems.MaKhach = Customers.MaKhach
group by Customers.MaKhach,CustomerItems.MaKhach,Customers.TenKhach
having count(*)>1


--3.6


SELECT CustomerItems.MaKhach, Customers.TenKhach
FROM CustomerItems 
INNER JOIN Customers 
ON CustomerItems.MaKhach = Customers.MaKhach
where Soluong>1